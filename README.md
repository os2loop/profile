# Installation


## Requirements

Loop is built on Drupal 7 and requires PHP 7.2. See [System requirements for Drupal 7](https://www.drupal.org/docs/7/system-requirements) for further details.

## Building the profile

Run this command to build the `loop` profile:

```sh
drush make https://raw.github.com/os2loop/profile/master/drupal.make htdocs
```

If you want a developer version with _working copies_ of the Git repositories,
run this command instead.

```sh
drush make --working-copy https://raw.github.com/os2loop/profile/master/drupal.make htdocs
```

## Installing Loop

After running the make file you should install the site as any other Drupal website.

First, create a database (`loop`) and a database user (`loop`) with access to the database or use an exiting database, e.g.

```sh
mysql --user=root --password --host=localhost
[enter root password]
create database `loop`;
create user 'loop'@'localhost' identified by 'loop';
grant all privileges on `loop`.* to 'loop'@'localhost';
quit
```

Then install Loop by visiting the website and going through the regular Drupal installation process.

By default only the core features are enabled so you should visit the features overview and enable any additional features you need.

### Important post-installation notes

Check out the notes on the [Loop saml](modules/loop_saml/README.md) module if it's installed.

## Adding taxonomies

After installing the Loop profile you should create some taxomony terms in the vocabularies Keyword, Profession and Subject. At lease one term must be defined in the Subject vocabulary before users can create new posts.

Go to `/admin/structure/taxonomy` to add terms to the vocabularies.

As an alternative to manually creating terms, you can install the module [Loop taxonomy terms (loop_taxonomy_terms)](/admin/modules#loop_content) and get the default Loop taxonomy terms.

## Search configuration

@TODO
