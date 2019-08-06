<?php

/**
 * @file
 * Views modifications for loop user contact list module.
 */

/**
 * Implements hook_views_query_alter().
 */
function loop_user_contact_list_views_query_alter(&$view, &$query) {
  if ('loop_user_contact_list' === $view->name) {
    // Remove condition on "Show in contact list (public)" if user is
    // authenticated.
    if (user_is_logged_in()) {
      foreach ($query->where[1]['conditions'] as $index => $condition) {
        if ('field_data_field_show_in_contact_list_publi.field_show_in_contact_list_publi_value' === $condition['field']) {
          unset($query->where[1]['conditions'][$index]);
        }
      }
    }
  }
}
