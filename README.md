# Installation

## Requirements

Loop is built on Drupal 7 and requires PHP 7.2. See [System requirements for
Drupal 7](https://www.drupal.org/docs/7/system-requirements) for further
details.

## Building the profile

[Install `drush`](https://docs.drush.org/en/8.x/) and run this command to build
the `loopdk` profile (in the `htdocs` folder):

```sh
drush make https://raw.github.com/os2loop/profile/master/drupal.make htdocs
```

If you want a developer version with _working copies_ of the Git repositories,
run this command instead.

```sh
drush make --working-copy https://raw.github.com/os2loop/profile/master/drupal.make htdocs
```

## Installing Loop

After running the make file you can install the site as any other Drupal
website, i.e. by using `drush site-install loopdk` or visiting the website and
going through the regular Drupal installation process.

By default only the core features are enabled so you should visit the features
overview and enable any additional features you need.

### Post-installation

#### User pages

* [`loop_user_page_views`](modules/loop_user_page_views/README.md)
* [`loop_user_related_content_profession`](modules/loop_user_related_content_profession/README.md)
* [`loop_user_related_content_competence`](modules/loop_user_related_content_competence/README.md)

#### Search

Install one of the Loop search modules:

* [`loop_search_db`](modules/loop_search_db/README.md)
* [`loop_search`](modules/loop_search/README.md)
* [`loop_search_node`](modules/loop_search_node/README.md)

Go to `/admin/appearance/settings/loop` and save settings (you don't have to
change anything).

#### Miscellaneous

* [`loop_post_wysiwyg`](modules/loop_post_wysiwyg/README.md)
* [`loop_documents`](modules/loop_documents/README.md)

### Important post-installation notes

Check out the notes on the [Loop saml](modules/loop_saml/README.md) module if
it's installed.

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
