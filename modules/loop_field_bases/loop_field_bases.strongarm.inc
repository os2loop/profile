<?php

/**
 * @file
 * loop_field_bases.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function loop_field_bases_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_string_source_language';
  $strongarm->value = 'en';
  $export['i18n_string_source_language'] = $strongarm;

  return $export;
}
