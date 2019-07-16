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
  $handler->display->display_options['title'] = 'Contacts';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['columns'] = array(
    'mail' => 'mail',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_phone_number' => 'field_phone_number',
  );
  $handler->display->display_options['style_options']['default'] = 'field_last_name';
  $handler->display->display_options['style_options']['info'] = array(
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_phone_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No contacts found.';
  /* Field: User: First name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  /* Field: User: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  /* Field: User: Phone number */
  $handler->display->display_options['fields']['field_phone_number']['id'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['table'] = 'field_data_field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['field'] = 'field_phone_number';
  /* Field: Field: Profession */
  $handler->display->display_options['fields']['field_profession']['id'] = 'field_profession';
  $handler->display->display_options['fields']['field_profession']['table'] = 'field_data_field_profession';
  $handler->display->display_options['fields']['field_profession']['field'] = 'field_profession';
  $handler->display->display_options['fields']['field_profession']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profession']['delta_offset'] = '0';
  /* Field: User: Area of expertise */
  $handler->display->display_options['fields']['field_area_of_expertise']['id'] = 'field_area_of_expertise';
  $handler->display->display_options['fields']['field_area_of_expertise']['table'] = 'field_data_field_area_of_expertise';
  $handler->display->display_options['fields']['field_area_of_expertise']['field'] = 'field_area_of_expertise';
  $handler->display->display_options['fields']['field_area_of_expertise']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_area_of_expertise']['delta_offset'] = '0';
  /* Field: User: Job title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  /* Field: User: Place / Department */
  $handler->display->display_options['fields']['field_location_place']['id'] = 'field_location_place';
  $handler->display->display_options['fields']['field_location_place']['table'] = 'field_data_field_location_place';
  $handler->display->display_options['fields']['field_location_place']['field'] = 'field_location_place';
  $handler->display->display_options['fields']['field_location_place']['label'] = '';
  $handler->display->display_options['fields']['field_location_place']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_location_place']['element_label_colon'] = FALSE;
  /* Field: User: Address */
  $handler->display->display_options['fields']['field_location_address']['id'] = 'field_location_address';
  $handler->display->display_options['fields']['field_location_address']['table'] = 'field_data_field_location_address';
  $handler->display->display_options['fields']['field_location_address']['field'] = 'field_location_address';
  $handler->display->display_options['fields']['field_location_address']['label'] = '';
  $handler->display->display_options['fields']['field_location_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_location_address']['element_label_colon'] = FALSE;
  /* Field: User: Postal code */
  $handler->display->display_options['fields']['field_location_postal_code']['id'] = 'field_location_postal_code';
  $handler->display->display_options['fields']['field_location_postal_code']['table'] = 'field_data_field_location_postal_code';
  $handler->display->display_options['fields']['field_location_postal_code']['field'] = 'field_location_postal_code';
  $handler->display->display_options['fields']['field_location_postal_code']['label'] = '';
  $handler->display->display_options['fields']['field_location_postal_code']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_location_postal_code']['element_label_colon'] = FALSE;
  /* Field: User: City */
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
  $handler->display->display_options['fields']['nothing']['label'] = 'Location';
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
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Show in contact list (field_show_in_contact_list) */
  $handler->display->display_options['filters']['field_show_in_contact_list_value']['id'] = 'field_show_in_contact_list_value';
  $handler->display->display_options['filters']['field_show_in_contact_list_value']['table'] = 'field_data_field_show_in_contact_list';
  $handler->display->display_options['filters']['field_show_in_contact_list_value']['field'] = 'field_show_in_contact_list_value';
  $handler->display->display_options['filters']['field_show_in_contact_list_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_show_in_contact_list_value']['group'] = 1;
  /* Filter criterion: User: Show in public contact list (field_show_in_contact_list_publi) */
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
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
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
    'mail' => 'mail',
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'field_phone_number' => 'field_phone_number',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['display_description'] = 'Contact list';
  $handler->display->display_options['path'] = 'contacts';
  $export['loop_user_contact_list'] = $view;

  return $export;
}
