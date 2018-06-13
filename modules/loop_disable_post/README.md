# Loop disable post
A module for disabling loop post content type and related functionality

* Depends on loop_post module to ensure any loop post hooks are run before we
 disable it with hooks in this module.
* This module is an alternative to disabling loop post module,
which is not always a viable option due to the dependency tree of the Loop project.

## Features
* Removes post related config during install.
* Denies access to post related menu items
* Hides post related sections with js.