<?php

/**
 * @file
 * loop_user_contact_list.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function loop_user_contact_list_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'loop_user_contact_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Contact list';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Medlemmer';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'contact';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No contacts found.';
  /* Field: Bruger: User image */
  $handler->display->display_options['fields']['field_user_image']['id'] = 'field_user_image';
  $handler->display->display_options['fields']['field_user_image']['table'] = 'field_data_field_user_image';
  $handler->display->display_options['fields']['field_user_image']['field'] = 'field_user_image';
  $handler->display->display_options['fields']['field_user_image']['label'] = '';
  $handler->display->display_options['fields']['field_user_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_image']['empty'] = '<img src="sites/default/files/styles/profile/public/default-user-icon.png" width="500" height="500" alt="">';
  $handler->display->display_options['fields']['field_user_image']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_user_image']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_user_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_image']['settings'] = array(
    'image_style' => 'profile',
    'image_link' => 'content',
  );
  /* Field: Bruger: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: Bruger: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_first_name] [field_last_name]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Bruger: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  /* Field: Bruger: Organization */
  $handler->display->display_options['fields']['field_organization']['id'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['table'] = 'field_data_field_organization';
  $handler->display->display_options['fields']['field_organization']['field'] = 'field_organization';
  $handler->display->display_options['fields']['field_organization']['label'] = '';
  $handler->display->display_options['fields']['field_organization']['element_label_colon'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: Bruger: Phone number */
  $handler->display->display_options['fields']['field_phone_number']['id'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['table'] = 'field_data_field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['field'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['label'] = '';
  $handler->display->display_options['fields']['field_phone_number']['element_label_colon'] = FALSE;
  /* Field: Bruger: Place / Department */
  $handler->display->display_options['fields']['field_location_place']['id'] = 'field_location_place';
  $handler->display->display_options['fields']['field_location_place']['table'] = 'field_data_field_location_place';
  $handler->display->display_options['fields']['field_location_place']['field'] = 'field_location_place';
  $handler->display->display_options['fields']['field_location_place']['label'] = '';
  $handler->display->display_options['fields']['field_location_place']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_location_place']['element_label_colon'] = FALSE;
  /* Field: Bruger: Address */
  $handler->display->display_options['fields']['field_location_address']['id'] = 'field_location_address';
  $handler->display->display_options['fields']['field_location_address']['table'] = 'field_data_field_location_address';
  $handler->display->display_options['fields']['field_location_address']['field'] = 'field_location_address';
  $handler->display->display_options['fields']['field_location_address']['label'] = '';
  $handler->display->display_options['fields']['field_location_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_location_address']['element_label_colon'] = FALSE;
  /* Field: Bruger: Postal code */
  $handler->display->display_options['fields']['field_location_postal_code']['id'] = 'field_location_postal_code';
  $handler->display->display_options['fields']['field_location_postal_code']['table'] = 'field_data_field_location_postal_code';
  $handler->display->display_options['fields']['field_location_postal_code']['field'] = 'field_location_postal_code';
  $handler->display->display_options['fields']['field_location_postal_code']['label'] = '';
  $handler->display->display_options['fields']['field_location_postal_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_location_postal_code']['element_label_colon'] = FALSE;
  /* Field: Bruger: City */
  $handler->display->display_options['fields']['field_location_city']['id'] = 'field_location_city';
  $handler->display->display_options['fields']['field_location_city']['table'] = 'field_data_field_location_city';
  $handler->display->display_options['fields']['field_location_city']['field'] = 'field_location_city';
  $handler->display->display_options['fields']['field_location_city']['label'] = '';
  $handler->display->display_options['fields']['field_location_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_location_city']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_location_place]
[field_location_address]
[field_location_city]
[field_location_postal_code]';
  $handler->display->display_options['fields']['nothing']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['nl2br'] = TRUE;
  $handler->display->display_options['fields']['nothing']['element_class'] = 'views-field views-field-field-location';
  $handler->display->display_options['fields']['nothing']['element_label_class'] = 'views-field views-field-field-location';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['filter_groups']['operator'] = 'OR';
  /* Filter criterion: User: Active status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Bruger: Show in contact list (field_show_in_contact_list) */
  $handler->display->display_options['filters']['field_show_in_contact_list_value']['id'] = 'field_show_in_contact_list_value';
  $handler->display->display_options['filters']['field_show_in_contact_list_value']['table'] = 'field_data_field_show_in_contact_list';
  $handler->display->display_options['filters']['field_show_in_contact_list_value']['field'] = 'field_show_in_contact_list_value';
  $handler->display->display_options['filters']['field_show_in_contact_list_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_show_in_contact_list_value']['group'] = 1;
  /* Filter criterion: Bruger: Show in public contact list (field_show_in_contact_list_publi) */
  $handler->display->display_options['filters']['field_show_in_contact_list_publi_value']['id'] = 'field_show_in_contact_list_publi_value';
  $handler->display->display_options['filters']['field_show_in_contact_list_publi_value']['table'] = 'field_data_field_show_in_contact_list_publi';
  $handler->display->display_options['filters']['field_show_in_contact_list_publi_value']['field'] = 'field_show_in_contact_list_publi_value';
  $handler->display->display_options['filters']['field_show_in_contact_list_publi_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_show_in_contact_list_publi_value']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'search';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['combine']['group_info']['label'] = 'Combine fields filter';
  $handler->display->display_options['filters']['combine']['group_info']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['combine']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_job_title' => 'field_job_title',
    'field_organization' => 'field_organization',
    'mail' => 'mail',
    'field_phone_number' => 'field_phone_number',
    'field_location_place' => 'field_location_place',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['display_description'] = 'Contact list';
  $handler->display->display_options['path'] = 'contacts';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Medlemmer';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-loop-primary-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['loop_user_contact_list'] = $view;

  return $export;
}
