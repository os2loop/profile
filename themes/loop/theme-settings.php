<?php

/**
 * @file
 * Loop theme settings.
 */

require_once __DIR__ . '/template.php';

/**
 * @file
 * Theme setting callbacks for the loop theme.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function loop_form_system_theme_settings_alter(&$form, &$form_state) {
  $form['theme_settings']['show_breadcrumbs'] = [
    '#type' => 'checkbox',
    '#title' => t('Show breadcrumbs'),
    '#default_value' => theme_get_setting('show_breadcrumbs', 'loop'),
    '#description' => t("Show breadcrumbs at the top each page."),
  ];
  $form['theme_settings']['loop_skin'] = [
    '#type'          => 'select',
    '#title'         => t('Skin'),
    '#options' => [
      '' => t('(default)'),
      'red' => t('Red'),
      'blue' => t('Blue'),
      'green' => t('Green'),
      'custom' => t('Custom'),
    ],
    '#default_value' => theme_get_setting('loop_skin'),
    '#description'   => t('Choose a skin for the site.'),
  ];

  $form['theme_settings']['loop_skin_custom'] = [
    '#type' => 'fieldset',
    '#title' => t('Custom skin'),
    '#states' => [
      'visible' => [':input[name="loop_skin"]' => ['value' => 'custom']],
    ],
  ];

  $form['theme_settings']['loop_skin_custom']['loop_skin_custom_path'] = [
    '#type' => 'textfield',
    '#title' => t('Path to custom skin'),
    '#description' => t('The path to the file you would like to use as your custom skin.'),
    '#default_value' => theme_get_setting('loop_skin_custom_path'),
  ];

  $form['theme_settings']['loop_skin_custom']['loop_skin_custom_upload'] = [
    '#type' => 'file',
    '#title' => t('Upload custom skin'),
    '#maxlength' => 40,
    '#description' => t("If you don't have direct file access to the server, use this field to upload your custom skin."),
  ];

  $form['login_settings'] = [
    '#type' => 'fieldset',
    '#title' => t('Log in settings'),
    '#collapsible' => FALSE,
    '#description' => t("Settings for log in behaviour"),
  ];

  $form['login_settings']['show_login_for_regular_users'] = [
    '#type' => 'checkbox',
    '#title' => t('Show regular log in button'),
    '#default_value' => theme_get_setting('show_login_for_regular_users', 'loop'),
    '#description' => t("Show log in button for regular users, i.e. username and password fields"),
  ];

  $login_service_options = ['' => t('None')];
  foreach (_loop_get_login_services() as $name => $service) {
    if ($name !== 'loop-login') {
      $login_service_options[$name] = $service['name'];
    }
  }

  $form['login_settings']['default_login_service_name'] = [
    '#type' => 'select',
    '#title' => t('Default login service name'),
    '#options' => $login_service_options,
    '#default_value' => theme_get_setting('default_login_service_name'),
    '#description' => t("Default login service to redirect anonymous users to"),
  ];

  $form['login_settings']['default_login_service_path'] = [
    '#type' => 'textfield',
    '#title' => t('Default login service path'),
    '#default_value' => theme_get_setting('default_login_service_path') ? theme_get_setting('default_login_service_path') : 'user/login',
    '#description' => t("Path on which to check for default login service"),
    '#required' => TRUE,
  ];

  $form['logout_settings'] = [
    '#type' => 'fieldset',
    '#title' => t('Logout button settings'),
    '#collapsible' => FALSE,
    '#description' => t("Settings determining behaviour of the logout button"),
  ];

  $form['logout_settings']['show_logout_for_regular_users'] = [
    '#type' => 'checkbox',
    '#title' => t('Show logout button for regular users'),
    '#default_value' => theme_get_setting('show_logout_for_regular_users', 'loop'),
    '#description' => t("Show logout button when logged in as a regular user"),
  ];

  $form['logout_settings']['show_logout_for_saml_users'] = [
    '#type' => 'checkbox',
    '#title' => t('Show logout button for SAML users'),
    '#default_value' => theme_get_setting('show_logout_for_saml_users', 'loop'),
    '#description' => t("Show logout button when logged via SAML"),
  ];

  $form['content_search'] = [
    '#type' => 'fieldset',
    '#title' => t('Content search'),
    '#collapsible' => FALSE,
    '#description' => t('Settings determining when to show the content search box'),
  ];

  $form['content_search']['content_search_visibility'] = [
    '#type' => 'radios',
    '#options' => [
      'exclude' => t('All pages except those listed'),
      'include' => t('Only the listed pages'),
    ],
    '#default_value' => theme_get_setting('content_search_visibility') ?: 'exclude',
  ];

  $form['content_search']['content_search_pages'] = [
    '#type' => 'textarea',
    '#title' => t('Pages'),
    '#default_value' => theme_get_setting('content_search_pages') ?: 'contacts',
    '#description' => t("Specify pages by using their paths. Enter one path per line. The '*' character is a wildcard. Example paths are %blog for the blog page and %blog-wildcard for every personal blog. %front is the front page.",
                        [
                          '%blog' => 'blog',
                          '%blog-wildcard' => 'blog/*',
                          '%front' => '<front>',
                        ]),
  ];

  $form['#validate'][] = 'loop_form_system_theme_settings_validate';
  $form['#submit'][] = 'loop_form_system_theme_settings_submit';
}

/**
 * Validator for the system_theme_settings() form.
 */
function loop_form_system_theme_settings_validate(&$form, &$form_state) {
  $validators = ['file_validate_extensions' => ['css']];

  // Check for a new uploaded logo.
  $file = file_save_upload('loop_skin_custom_upload', $validators);
  if (isset($file)) {
    // File upload was attempted.
    if ($file) {
      // Put the temporary file in form_values so we can save it on submit.
      $form_state['values']['loop_skin_custom_upload'] = $file;
    }
    else {
      // File upload failed.
      form_set_error('loop_skin_custom_upload', t('The custom skin could not be uploaded.'));
    }
  }

  // If the user provided a path for a custom skin, make sure a file
  // exists at that path.
  if (!empty($form_state['values']['loop_skin_custom_path'])) {
    $path = _system_theme_settings_validate_path($form_state['values']['loop_skin_custom_path']);
    if (!$path) {
      form_set_error('loop_skin_custom_path', t('The custom skin path is invalid.'));
    }
  }
}

/**
 * Process system_theme_settings() form submissions.
 */
function loop_form_system_theme_settings_submit(&$form, &$form_state) {
  $values = &$form_state['values'];

  // If the user uploaded a new custom skin, save it to a permanent location
  // and use it in place of the default theme-provided file.
  if (!empty($values['loop_skin_custom_upload'])) {
    $file = $values['loop_skin_custom_upload'];
    unset($values['loop_skin_custom_upload']);
    $filename = file_unmanaged_copy($file->uri);
    $values['loop_skin_custom_path'] = $filename;
  }

  if (!empty($values['loop_skin_custom_path'])) {
    $values['loop_skin_custom_path'] = _system_theme_settings_validate_path($values['loop_skin_custom_path']);
  }
}
