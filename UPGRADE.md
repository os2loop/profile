# Upgrading OS2Loop

## From 1.x to 2.x

A number of modules have been removed in OS2Loop 2.x. To handle this you can either uninstall the modules

* google_analytics_counter
* googleanalytics
* loop_configure_theme
* loop_external_data
* loop_external_sources_content
* loop_instruction
* metatag
* page_title
* style_settings

before upgrading, or clean up your database after upgrading:

```sh
drush sql-query "delete from system where name in ('google_analytics_counter', 'googleanalytics', 'loop_configure_theme', 'loop_external_data', 'loop_external_sources_content', 'loop_instruction', 'metatag', 'page_title', 'style_settings')"
```
