<?php

/**
 * @file
 * loop_user_contact_list.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function loop_user_contact_list_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'user-user-field_show_in_contact_list'.
  $field_instances['user-user-field_show_in_contact_list'] = array(
    'bundle' => 'user',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_show_in_contact_list',
    'label' => 'Show in contact list',
    'required' => 0,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 50,
    ),
  );

  // Exported field_instance: 'user-user-field_show_in_contact_list_publi'.
  $field_instances['user-user-field_show_in_contact_list_publi'] = array(
    'bundle' => 'user',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'If checked, the user information will be shown publicly (to non-authenticated users).',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 18,
      ),
    ),
    'entity_type' => 'user',
    'field_name' => 'field_show_in_contact_list_publi',
    'label' => 'Show in public contact list',
    'required' => 0,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 51,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('If checked, the user information will be shown publicly (to non-authenticated users).');
  t('Show in contact list');
  t('Show in public contact list');

  return $field_instances;
}
