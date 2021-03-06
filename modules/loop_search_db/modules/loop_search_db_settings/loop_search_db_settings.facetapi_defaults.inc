<?php

/**
 * @file
 * loop_search_db_settings.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function loop_search_db_settings_facetapi_default_facet_settings() {
  $export = array();

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@loop_search_db_index::field_subject:name';
  $facet->searcher = 'search_api@loop_search_db_index';
  $facet->realm = '';
  $facet->facet = 'field_subject:name';
  $facet->enabled = FALSE;
  $facet->hash = 'QxB67ZvpKjXP10xPmuatC7Sj8J1k0GV7';
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => TRUE,
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@loop_search_db_index::field_subject:name'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@loop_search_db_index::type';
  $facet->searcher = 'search_api@loop_search_db_index';
  $facet->realm = '';
  $facet->facet = 'type';
  $facet->enabled = FALSE;
  $facet->hash = 'wd0t5wPwesz90Ub8neJGoMr8vgRBPkp1';
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => TRUE,
    'facet_search_ids' => array(),
    'exclude' => 0,
  );
  $export['search_api@loop_search_db_index::type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@loop_search_db_index:block:field_subject:name';
  $facet->searcher = 'search_api@loop_search_db_index';
  $facet->realm = 'block';
  $facet->facet = 'field_subject:name';
  $facet->enabled = TRUE;
  $facet->hash = 'bPhNe51bhJ9GMX2XrSTi4O62zQtzyXTN';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(),
    'active_sorts' => array(
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'display_count' => 0,
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'title_override' => 0,
    'title' => 'Subject » Name',
    'soft_limit' => '0',
    'nofollow' => '1',
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'html',
    ),
  );
  $export['search_api@loop_search_db_index:block:field_subject:name'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@loop_search_db_index:block:type';
  $facet->searcher = 'search_api@loop_search_db_index';
  $facet->realm = 'block';
  $facet->facet = 'type';
  $facet->enabled = TRUE;
  $facet->hash = 'i7k4PFt3cAUtDbpsOCSE84FQVKO1nmM6';
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_links',
    'filters' => array(),
    'active_sorts' => array(
      'active' => 'active',
      'count' => 'count',
      'display' => 'display',
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'display_count' => 1,
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'title_override' => 0,
    'title' => 'Indholdstype',
    'soft_limit' => '0',
    'nofollow' => '1',
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'html',
    ),
  );
  $export['search_api@loop_search_db_index:block:type'] = $facet;

  return $export;
}
