# Installation

## Requirements

Loop is built on Drupal 7 and requires PHP 7.2. See [System requirements for
Drupal 7](https://www.drupal.org/docs/7/system-requirements) for further
details.

## Building the profile

[Install `drush 8.x`](https://docs.drush.org/en/8.x/) and run this command to build
the `loopdk` profile (in the `htdocs` folder):

```sh
drush make https://raw.githubusercontent.com/os2loop/profile/release/covid-19/drupal.make htdocs
```

If you want a developer version with _working copies_ of the Git repositories,
run this command instead:

```sh
drush make --working-copy https://raw.githubusercontent.com/os2loop/profile/release/covid-19/drupal.make htdocs
```

## Installing Loop

After running the make file you can install the site as any other Drupal
website, i.e. by using `drush site-install loopdk` or visiting the website and
going through the regular Drupal installation process.

**Note**: During the installation you may experience the error “Call to undefined function field_attach_load()”. See https://www.drupal.org/project/drupal/issues/481758 for troubleshooting this error. Most notably, using a database name with a length less than 8 may remedy the problem.  

By default only the core features are enabled so you should visit the features
overview and enable any additional features you need.

### Post-installation

#### Permissions

To create default roles and permissions in Loop, go to
`/admin/config/people/secure_permissions` and check “Disable permissions and roles
forms” and “Load permissions from code” and click “Save settings”.

```sh
drush secure-permissions on
drush secure-permissions-rebuild
```

Afterwards you can uncheck these settings if you want to manually change roles
or permissions in Loop.

```sh
drush secure-permissions off
```

**Note**: If you want to be able to see the items in the menu “Loop Primary
Menu” when logged in as the admin user ([“user
1”](https://www.drupal.org/docs/7/understanding-drupal/users-permissions-and-roles#s-associating-more-information-with-users)),
you have to add the “administrator” role to the admin user (go to `/user/1/edit`
to add this role).

```sh
drush user-add-role administrator admin
```

#### Menus

To make menus fall into place, go to `/admin/structure/features/loop_post`,
check all boxes and click “Revert components”.

```sh
drush --yes features-revert loop_post
```

Drupal handles translations of menu links in peculiar way, so if the menu link
“Create post” is not translated to Danish (“Opret spørgsmål”) you have to go to
`/admin/structure/menu/manage/main-menu`, click “translate” (“oversæt”) next to
the “Create post” item and translate the item to “Opret spørgsmål” or something
similar.

#### Optional Loop modules

After installing the base Loop profile, you can install additional modules (go
to `/admin/modules#loop` to see the full list).

Some highlight are:

##### User pages

* [Loop user page views
  (`loop_user_page_views`)](modules/loop_user_page_views/README.md): Holds
  public views used on the users profile pages

  After installing this module you may have to go to `/admin/structure/pages`
  and click “Activate” in the “user_view” row.

##### Search

Loop comes with a number of search modules built on top of Drupal's [Search
API](https://www.drupal.org/project/search_api)

Install one of the Loop search modules to enable search in the site:

* [Loop search database (loop_search_db)](modules/loop_search_db/README.md):
  Search using the database
  * Install Loop search database settings (loop_search_db_settings) to get the
    default settings for the search module
* [loop_search](modules/loop_search/README.md): Search using Solr
  * Install Loop search settings (loop_search_settings) to get the default
    settings for the search module
* [loop_search_node](modules/loop_search_node/README.md): Search using [Search
  node](https://github.com/search-node)
  * Install Loop search node settings (loop_search_node_settings) to get the
    default settings for the search module

**Note**: After installing a search module you may want to go to
`/admin/config/search/search_api` and delete the default search index (the one
named “Default node index”) which is not used by Loop.

##### Miscellaneous

* [Loop post wysiwyg (loop_post_wysiwyg)](modules/loop_post_wysiwyg/README.md):
  Make posts/comments use WYSIWYG editor
* [Loop documents (loop_documents)](modules/loop_documents/README.md): Documents
  and document collections. See [the module
  documentation](modules/loop_documents/README.md) for important
  post-installation instructions and requirements.
* [Loop SAML (loop_saml)](modules/loop_saml/README.md): Allow user to login via
  a SAML IdP (Check out the [notes on the Loop saml
  module](modules/loop_saml/README.md) if installing it).
* [Loop user contact list](modules/loop_user_contact_list/README.md): Shows a
  contact list

## Adding taxonomies

After installing the Loop profile you should create some taxomony terms in the
vocabularies Keyword, Profession and Subject. At lease one term must be defined
in the Subject vocabulary before users can create new posts.

Go to `/admin/structure/taxonomy` to add terms to the vocabularies.

## Search configuration

@TODO

## Loop skins

Loop comes with a number af default skins used for styling the site and the
active skin can be changed in the Loop theme settings
(`/admin/appearance/settings/loop`). See [Building a custom
skin](themes/loop/README.md#building-a-custom-skin) for instruction how to add
your own custom skin if needed.
