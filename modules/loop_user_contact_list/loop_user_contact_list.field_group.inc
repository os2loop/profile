<?php

/**
 * @file
 * loop_user_contact_list.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function loop_user_contact_list_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_list|user|user|form';
  $field_group->group_name = 'group_contact_list';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact list',
    'weight' => '54',
    'children' => array(
      0 => 'field_show_in_contact_list',
      1 => 'field_show_in_contact_list_authe',
      2 => 'field_show_in_contact_list_publi',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contact-list field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_contact_list|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact list');

  return $field_groups;
}
