<?php
/**
 * @file
 * loop_notification.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function loop_notification_default_rules_configuration() {
  $items = array();
  $items['loop_notification_autosubscribe_node_comment_author'] = entity_import('rules_config', '{ "loop_notification_autosubscribe_node_comment_author" : {
      "LABEL" : "Autosubscribe node comment author",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "flag", "loop_notification", "rules", "comment" ],
      "ON" : { "comment_insert" : [] },
      "DO" : [
        { "flag_flagnode" : {
            "flag" : "subscribe_node",
            "node" : [ "comment:node" ],
            "flagging_user" : [ "comment:author" ],
            "permission_check" : "0"
          }
        },
        { "entity_fetch" : {
            "USING" : { "type" : "node", "id" : [ "comment:node:nid" ] },
            "PROVIDE" : { "entity_fetched" : { "entity_fetched" : "Fetched entity" } }
          }
        }
      ]
    }
  }');
  $items['loop_notification_create_notification_on_collection_create'] = entity_import('rules_config', '{ "loop_notification_create_notification_on_collection_create" : {
      "LABEL" : "Create notification on collection create",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "loop_notification", "rules" ],
      "USES VARIABLES" : {
        "active_user_object" : { "label" : "Active user objject", "type" : "user" },
        "node_author" : { "label" : "node_author", "type" : "user" },
        "node" : { "label" : "node", "type" : "node" }
      },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } },
            "IF" : [
              { "NOT data_is" : { "data" : [ "active-user-object" ], "value" : [ "node-author" ] } }
            ],
            "DO" : [
              { "entity_create" : {
                  "USING" : {
                    "type" : "message",
                    "param_type" : "document_collection_added",
                    "param_user" : [ "active-user-object" ]
                  },
                  "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
                }
              },
              { "data_set" : {
                  "data" : [ "entity-created:field-message-node-reference" ],
                  "value" : [ "node" ]
                }
              },
              { "entity_save" : { "data" : [ "entity-created" ], "immediate" : 1 } }
            ],
            "LABEL" : "Create notification"
          }
        }
      ]
    }
  }');
  $items['loop_notification_create_notification_on_collection_edit'] = entity_import('rules_config', '{ "loop_notification_create_notification_on_collection_edit" : {
      "LABEL" : "Create notification on collection edit",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "loop_notification", "rules" ],
      "USES VARIABLES" : {
        "active_user_object" : { "label" : "Active user objject", "type" : "user" },
        "node_author" : { "label" : "node_author", "type" : "user" },
        "node" : { "label" : "node", "type" : "node" }
      },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } },
            "IF" : [
              { "NOT data_is" : { "data" : [ "active-user-object" ], "value" : [ "node-author" ] } }
            ],
            "DO" : [
              { "entity_create" : {
                  "USING" : {
                    "type" : "message",
                    "param_type" : "document_collection_edited",
                    "param_user" : [ "active-user-object" ]
                  },
                  "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
                }
              },
              { "data_set" : {
                  "data" : [ "entity-created:field-message-node-reference" ],
                  "value" : [ "node" ]
                }
              },
              { "entity_save" : { "data" : [ "entity-created" ], "immediate" : 1 } }
            ],
            "LABEL" : "Create notification"
          }
        }
      ]
    }
  }');
  $items['loop_notification_create_notification_on_comment_edit'] = entity_import('rules_config', '{ "loop_notification_create_notification_on_comment_edit" : {
      "LABEL" : "Create notification on comment edit",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "loop_notification", "rules" ],
      "USES VARIABLES" : {
        "active_user_object" : { "label" : "Active user objject", "type" : "user" },
        "comment_author" : { "label" : "comment_author", "type" : "user" },
        "comment" : { "label" : "comment", "type" : "comment" }
      },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } },
            "IF" : [
              { "NOT data_is" : { "data" : [ "active-user-object" ], "value" : [ "comment-author" ] } }
            ],
            "DO" : [
              { "entity_create" : {
                  "USING" : {
                    "type" : "message",
                    "param_type" : "comment_added_to_post",
                    "param_user" : [ "active-user-object" ]
                  },
                  "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
                }
              },
              { "data_set" : {
                  "data" : [ "entity-created:field-message-node-reference" ],
                  "value" : [ "comment:node" ]
                }
              },
              { "entity_save" : { "data" : [ "entity-created" ], "immediate" : 1 } }
            ],
            "LABEL" : "Create notification"
          }
        }
      ]
    }
  }');
  $items['loop_notification_create_notification_on_document_create'] = entity_import('rules_config', '{ "loop_notification_create_notification_on_document_create" : {
      "LABEL" : "Create notification on document create",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "loop_notification", "rules" ],
      "USES VARIABLES" : {
        "active_user_object" : { "label" : "Active user objject", "type" : "user" },
        "node_author" : { "label" : "node_author", "type" : "user" },
        "node" : { "label" : "node", "type" : "node" }
      },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } },
            "IF" : [
              { "NOT data_is" : { "data" : [ "active-user-object" ], "value" : [ "node-author" ] } }
            ],
            "DO" : [
              { "entity_create" : {
                  "USING" : {
                    "type" : "message",
                    "param_type" : "document_added",
                    "param_user" : [ "active-user-object" ]
                  },
                  "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
                }
              },
              { "data_set" : {
                  "data" : [ "entity-created:field-message-node-reference" ],
                  "value" : [ "node" ]
                }
              },
              { "entity_save" : { "data" : [ "entity-created" ], "immediate" : 1 } }
            ],
            "LABEL" : "Create notification"
          }
        }
      ]
    }
  }');
  $items['loop_notification_create_notification_on_document_edit'] = entity_import('rules_config', '{ "loop_notification_create_notification_on_document_edit" : {
      "LABEL" : "Create notification on document edit",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "loop_notification", "rules" ],
      "USES VARIABLES" : {
        "active_user_object" : { "label" : "Active user objject", "type" : "user" },
        "node_author" : { "label" : "node_author", "type" : "user" },
        "node" : { "label" : "node", "type" : "node" }
      },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } },
            "IF" : [
              { "NOT data_is" : { "data" : [ "active-user-object" ], "value" : [ "node-author" ] } }
            ],
            "DO" : [
              { "entity_create" : {
                  "USING" : {
                    "type" : "message",
                    "param_type" : "document_edited",
                    "param_user" : [ "active-user-object" ]
                  },
                  "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
                }
              },
              { "data_set" : {
                  "data" : [ "entity-created:field-message-node-reference" ],
                  "value" : [ "node" ]
                }
              },
              { "entity_save" : { "data" : [ "entity-created" ], "immediate" : 1 } }
            ],
            "LABEL" : "Create notification"
          }
        }
      ]
    }
  }');
  $items['loop_notification_create_notification_on_node_create'] = entity_import('rules_config', '{ "loop_notification_create_notification_on_node_create" : {
      "LABEL" : "Create notification on node create",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "loop_notification", "rules" ],
      "USES VARIABLES" : {
        "active_user_object" : { "label" : "Active user objject", "type" : "user" },
        "node_author" : { "label" : "node_author", "type" : "user" },
        "node" : { "label" : "node", "type" : "node" }
      },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } },
            "IF" : [
              { "NOT data_is" : { "data" : [ "active-user-object" ], "value" : [ "node-author" ] } }
            ],
            "DO" : [
              { "entity_create" : {
                  "USING" : {
                    "type" : "message",
                    "param_type" : "node_added",
                    "param_user" : [ "active-user-object" ]
                  },
                  "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
                }
              },
              { "data_set" : {
                  "data" : [ "entity-created:field-message-node-reference" ],
                  "value" : [ "node" ]
                }
              },
              { "entity_save" : { "data" : [ "entity-created" ], "immediate" : 1 } }
            ],
            "LABEL" : "Create notification"
          }
        }
      ]
    }
  }');
  $items['loop_notification_create_notification_on_node_edit'] = entity_import('rules_config', '{ "loop_notification_create_notification_on_node_edit" : {
      "LABEL" : "Create notification on node edit",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "loop_notification", "rules" ],
      "USES VARIABLES" : {
        "active_user_object" : { "label" : "Active user objject", "type" : "user" },
        "node_author" : { "label" : "node_author", "type" : "user" },
        "node" : { "label" : "node", "type" : "node" }
      },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } },
            "IF" : [
              { "NOT data_is" : { "data" : [ "active-user-object" ], "value" : [ "node-author" ] } }
            ],
            "DO" : [
              { "entity_create" : {
                  "USING" : {
                    "type" : "message",
                    "param_type" : "node_edited",
                    "param_user" : [ "active-user-object" ]
                  },
                  "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
                }
              },
              { "data_set" : {
                  "data" : [ "entity-created:field-message-node-reference" ],
                  "value" : [ "node" ]
                }
              },
              { "entity_save" : { "data" : [ "entity-created" ], "immediate" : 1 } }
            ],
            "LABEL" : "Create notification"
          }
        }
      ]
    }
  }');
  $items['rules_autosubscribe_node_loop_documents_collection_author'] = entity_import('rules_config', '{ "rules_autosubscribe_node_loop_documents_collection_author" : {
      "LABEL" : "Autosubscribe node loop_documents_collection author",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "flag", "rules" ],
      "ON" : { "node_insert--loop_documents_collection" : { "bundle" : "loop_documents_collection" } },
      "DO" : [
        { "flag_flagnode" : {
            "flag" : "subscribe_node",
            "node" : [ "node" ],
            "flagging_user" : [ "node:author" ],
            "permission_check" : 0
          }
        }
      ]
    }
  }');
  $items['rules_autosubscribe_node_loop_documents_document_author'] = entity_import('rules_config', '{ "rules_autosubscribe_node_loop_documents_document_author" : {
      "LABEL" : "Autosubscribe node loop_documents_document author",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "flag", "rules" ],
      "ON" : { "node_insert--loop_documents_document" : { "bundle" : "loop_documents_document" } },
      "DO" : [
        { "flag_flagnode" : {
            "flag" : "subscribe_node",
            "node" : [ "node" ],
            "flagging_user" : [ "node:author" ],
            "permission_check" : 0
          }
        }
      ]
    }
  }');
  $items['rules_autosubscribe_node_post_author'] = entity_import('rules_config', '{ "rules_autosubscribe_node_post_author" : {
      "LABEL" : "Autosubscribe node post author",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "flag", "rules" ],
      "ON" : { "node_insert--post" : { "bundle" : "post" } },
      "DO" : [
        { "flag_flagnode" : {
            "flag" : "subscribe_node",
            "node" : [ "node" ],
            "flagging_user" : [ "node:author" ],
            "permission_check" : 0
          }
        }
      ]
    }
  }');
  $items['rules_create_notification'] = entity_import('rules_config', '{ "rules_create_notification" : {
      "LABEL" : "Create notification on comment create",
      "PLUGIN" : "rule set",
      "OWNER" : "rules",
      "REQUIRES" : [ "loop_notification", "rules" ],
      "USES VARIABLES" : {
        "active_user_object" : { "label" : "Active user objject", "type" : "user" },
        "comment_author" : { "label" : "comment_author", "type" : "user" },
        "comment" : { "label" : "comment", "type" : "comment" }
      },
      "RULES" : [
        { "RULE" : {
            "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } },
            "IF" : [
              { "NOT data_is" : { "data" : [ "active-user-object" ], "value" : [ "comment-author" ] } }
            ],
            "DO" : [
              { "entity_create" : {
                  "USING" : {
                    "type" : "message",
                    "param_type" : "comment_added_to_post",
                    "param_user" : [ "active-user-object" ]
                  },
                  "PROVIDE" : { "entity_created" : { "entity_created" : "Created entity" } }
                }
              },
              { "data_set" : {
                  "data" : [ "entity-created:field-message-node-reference" ],
                  "value" : [ "comment:node" ]
                }
              },
              { "entity_save" : { "data" : [ "entity-created" ], "immediate" : 1 } }
            ],
            "LABEL" : "Create notification"
          }
        }
      ]
    }
  }');
  $items['rules_remove_subscription'] = entity_import('rules_config', '{ "rules_remove_subscription" : {
      "LABEL" : "Remove subscription",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "Subscriptions" ],
      "REQUIRES" : [ "flag" ],
      "ACCESS_EXPOSED" : "1",
      "USES VARIABLES" : { "node" : { "label" : "node", "type" : "node" } },
      "DO" : [
        { "flag_unflagnode" : {
            "flag" : "subscribe_node",
            "node" : [ "node" ],
            "flagging_user" : [ "site:current-user" ],
            "permission_check" : 0
          }
        }
      ]
    }
  }');
  $items['rules_set_message_read'] = entity_import('rules_config', '{ "rules_set_message_read" : {
      "LABEL" : "Set message read",
      "PLUGIN" : "rule",
      "OWNER" : "rules",
      "TAGS" : [ "notification" ],
      "REQUIRES" : [ "flag" ],
      "USES VARIABLES" : { "message_read" : { "label" : "Set message read", "type" : "message" } },
      "DO" : [
        { "flag_flagmessage" : {
            "flag" : "message_read",
            "message" : [ "message-read" ],
            "flagging_user" : [ "site:current-user" ],
            "permission_check" : 0
          }
        }
      ]
    }
  }');
  return $items;
}
