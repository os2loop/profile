Loop theme
==========

This repository is the default theme for the Loop web application.

Sass is based on ITK Designs boilerplate found here,
https://github.com/aakb/frontend-boilerplate


Building the stylesheet
-----------------------

First, install requirements:

```
npm install
```

Then build the stylesheet by running this command

```
gulp sass
```

To continuosly update the stylesheet when editing the source scss
files you can run

```
gulp watch sass
```

Add `--env=dev` to the command to include source maps in the generated
stylesheet:

```
gulp watch sass --env=dev
```

Finally, you should build the stylesheet for production like this
```
gulp build
```


Building the icon font
----------------------

A custom font is used for icons on the site. The font is built using
[Fontello](http://fontello.com/).

Perform these steps to update the font:

1. `cd icons/`
2. `make fontopen`
3. Make any changes on the opened web page and click `Save session`.
4. `make fontsave`

Building a custom skin
----------------------

To build a custom Loop skin you must first install all the requirements:

```sh
git clone --branch=master https://github.com/os2loop/profile
cd profile/
mkdir libraries
cd libraries
git clone --branch=1.4 https://github.com/JohnAlbin/zen-grids
cd ../themes/loop
npm install
```

Then you can add your custom skin in the `sass` folder, e.g.

```scss
# sass/custom.scss

// Change colors.
$green:               #ff00ff;
$green-lighter:       #d6ff9a;
$red:                 #ff6138;
$yellow-light:        #fff98f;
$gray-background:     #f2f2f2;
$gray-color:          #999;
$link-color:          $green;

// Set to icons font base path. Update this to match your actual server setup.
$icons-font-base-path: '/profiles/loopdk/themes/loop/icons';

// Import the Loop styles.
@import "styles";
```

Build your skin by running

```sh
gulp sass
```

If successful, your custom skin is now built in the file `css/custom.css`.

Finally, go to the Loop theme settings (`/admin/appearance/settings/loop`),
choose “Skin > Custom” and upload the skin (`css/custom.css`) to your Loop site.
```
