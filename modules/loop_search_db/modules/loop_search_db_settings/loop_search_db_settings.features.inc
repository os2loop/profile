<?php

/**
 * @file
 * loop_search_db_settings.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function loop_search_db_settings_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function loop_search_db_settings_default_search_api_index() {
  $items = array();
  $items['loop_search_db_index'] = entity_import('search_api_index', '{
    "name" : "Post",
    "machine_name" : "loop_search_db_index",
    "description" : null,
    "server" : "loop_search_db_server",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [] },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "body:summary" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "comments" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "comment" },
        "comments:comment_body:value" : { "type" : "list\\u003Ctext\\u003E" },
        "created" : { "type" : "date" },
        "field_description:value" : { "type" : "text" },
        "field_keyword:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_profession:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_subject:name" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "title" : { "type" : "text", "boost" : "2.0" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "loop_documents_document" : "loop_documents_document",
              "loop_documents_collection" : "loop_documents_collection",
              "external_sources" : "external_sources",
              "instruction" : "instruction",
              "post" : "post"
            }
          }
        },
        "search_api_metatag_alter_callback" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "field_keyword:name" : true,
              "field_subject:name" : true,
              "field_profession:name" : true,
              "comments:comment_body:value" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "body:value" : true,
              "body:summary" : true,
              "field_keyword:name" : true,
              "field_subject:name" : true,
              "field_description:value" : true,
              "field_profession:name" : true,
              "comments:comment_body:value" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : { "status" : 0, "weight" : "15", "settings" : { "fields" : [] } },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "field_keyword:name" : true,
              "field_subject:name" : true,
              "field_profession:name" : true,
              "comments:comment_body:value" : true
            },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : [],
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_porter_stemmer" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "fields" : {
              "title" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_keyword:name" : true,
              "field_subject:name" : true,
              "field_description:value" : true,
              "field_profession:name" : true,
              "comments:comment_body:value" : true
            },
            "exceptions" : "texan=texa"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always",
            "highlight_partial" : 0
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_page().
 */
function loop_search_db_settings_default_search_api_page() {
  $items = array();
  $items['default'] = entity_import('search_api_page', '{
    "index_id" : "loop_search_db_index",
    "path" : "search",
    "name" : "Database",
    "machine_name" : "default",
    "description" : "",
    "options" : {
      "mode" : "terms",
      "fields" : [],
      "max_length" : "128",
      "per_page" : "10",
      "result_page_search_form" : 1,
      "get_per_page" : 0,
      "view_mode" : "search_api_page_result",
      "empty_behavior" : "blocks"
    },
    "enabled" : "1"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function loop_search_db_settings_default_search_api_server() {
  $items = array();
  $items['loop_search_db_server'] = entity_import('search_api_server', '{
    "name" : "Database",
    "machine_name" : "loop_search_db_server",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "3",
      "partial_matches" : 0,
      "indexes" : { "loop_search_db_index" : {
          "search_api_language" : {
            "table" : "search_api_db_loop_search_db_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "type" : {
            "table" : "search_api_db_loop_search_db_index",
            "column" : "type_1",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_loop_search_db_index_text_1",
            "type" : "text",
            "boost" : "2.0"
          },
          "status" : {
            "table" : "search_api_db_loop_search_db_index",
            "column" : "status_1",
            "type" : "integer",
            "boost" : "1.0"
          },
          "comments" : {
            "table" : "search_api_db_loop_search_db_index_comments_1",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_loop_search_db_index_text_1",
            "type" : "text",
            "boost" : "1.0"
          },
          "body:summary" : {
            "table" : "search_api_db_loop_search_db_index_text_1",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_description:value" : {
            "table" : "search_api_db_loop_search_db_index_text_1",
            "type" : "text",
            "boost" : "1.0"
          },
          "field_keyword:name" : {
            "table" : "search_api_db_loop_search_db_index_text_1",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_profession:name" : {
            "table" : "search_api_db_loop_search_db_index_text_1",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "field_subject:name" : {
            "table" : "search_api_db_loop_search_db_index_text_1",
            "type" : "text",
            "boost" : "1.0"
          },
          "comments:comment_body:value" : {
            "table" : "search_api_db_loop_search_db_index_text_1",
            "type" : "list\\u003Ctext\\u003E",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_loop_search_db_index",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_sort().
 */
function loop_search_db_settings_default_search_api_sort() {
  $items = array();
  $items['loop_search_db_index__created'] = entity_import('search_api_sort', '{
    "index_id" : "loop_search_db_index",
    "field" : "created",
    "name" : "Date created",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "loop_search_db_index__created",
    "default_sort" : "1",
    "default_sort_no_terms" : "1",
    "default_order" : "desc",
    "options" : { "field_name" : "Date created" }
  }');
  $items['loop_search_db_index__search_api_relevance'] = entity_import('search_api_sort', '{
    "index_id" : "loop_search_db_index",
    "field" : "search_api_relevance",
    "name" : "Relevance",
    "enabled" : "1",
    "weight" : "0",
    "identifier" : "loop_search_db_index__search_api_relevance",
    "default_sort" : "0",
    "default_sort_no_terms" : "0",
    "default_order" : "desc",
    "options" : { "field_name" : "search_api_relevance" }
  }');
  return $items;
}
