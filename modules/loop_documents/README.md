Loop documents
==============

Documents and document collections.

# Installation

Activate the `loop_documents` module:

```
drush --yes pm-enable loop_documents
```

## Post installation

Rebuild secure permissions:

```
drush secure-permissions-rebuild
```

*Note*: This may fail if the default site language is not English
(en). To work around this do something like this:

```
drush --yes pm-download drush_language
# Remember current default language
drupal_default_language=$(drush php-eval "echo language_default('language'), PHP_EOL;")
drush language-default en
drush secure-permissions-rebuild
drush language-default en $drupal_default_language
```

You may also have to rebuild node access:

```
drush php-eval 'node_access_rebuild();'
```

# Settings

A few setting are available on the configuration page
*Administration » Configuration » Content authoring »
Loop documents settings* (/admin/config/content/loop_documents)

# Text formats and wysiwyg profiles

This module provides (and depends on) a text format and a wysiwyg profile, both
named `loop_documents`. These are created when the module is installed and can
be modified to fit specific needs on a site.

If neeed be, the editor configuration can be reset by running the `drush`
command `loop-documents-reset-editor-configuration`:

```sh
drush loop-documents-reset-editor-configuration
```
