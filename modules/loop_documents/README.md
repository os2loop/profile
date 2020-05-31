# Loop documents

Documents and document collections.

## Installation

Activate the `loop_documents` module.

### Post installation

Rebuild secure permissions (go to `/admin/reports/status/rebuild`).

#### PDF generation

This module requires [`wkhtmltopdf`](https://wkhtmltopdf.org/) [version
0.12.5](https://github.com/wkhtmltopdf/wkhtmltopdf/releases/tag/0.12.5) to
export content as PDF.

Make sure that `wkhtmltopdf` is installed on the server (see [“How do I use
it?”](https://wkhtmltopdf.org/index.html)) and go to
`/admin/config/content/entityprint` to check that “WkhtmlToPdf Location”
contains to correct path to the `wkhtmltopdf` binary.

## Settings

A few setting are available on the configuration page *Administration »
Configuration » Content authoring » Loop documents settings*
(`/admin/config/content/loop_documents`)

## Text formats and wysiwyg profiles

This module provides (and depends on) a text format and a wysiwyg profile, both
named `loop_documents`. These are created when the module is installed and can
be modified to fit specific needs on a site.

If neeed be, the editor configuration can be reset by running the `drush`
command `loop-documents-reset-editor-configuration`:

```sh
drush loop-documents-reset-editor-configuration
```
