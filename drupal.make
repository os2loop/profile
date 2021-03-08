api = 2
core = 7.x

; Core
; As d.o is having issues with the update XML file, we are using this form for downloading core.
; See this: https://drupal.org/node/2126123
projects[drupal][type] = core
projects[drupal][version] = 7.75
projects[drupal][patch][] = "https://drupal.org/files/drupal-menu_navigation_links-1018614-83.patch"
projects[drupal][patch][] = "https://drupal.org/files/issues/translate_role_names-2205581-1.patch"
projects[drupal][patch][] = "https://raw.githubusercontent.com/os2loop/profile/main/patches/rebuild_local_js_alter.patch"

; Install profile.
projects[loopdk][type] = "profile"
projects[loopdk][download][type] = "git"
projects[loopdk][download][url] = "https://github.com/os2loop/profile.git"
projects[loopdk][download][tag] = "2.2.2"
