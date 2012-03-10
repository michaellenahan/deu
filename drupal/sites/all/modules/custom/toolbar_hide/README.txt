Making Toolbar and Administration Menu co-exist in Drupal 7
Submitted by Joel Stein on Mon, 04/18/2011 - 12:13

The new Toolbar and Shortcut modules in Drupal 7 present a solution which most people had been solving with the Administration Menu module. They are great for non-admins who frequently need access to a handful of admin pages.

However, I can't shake the Administration Menu habit—all those nice drop-down menus make site administration a breeze. How do you enable all three modules without making your website look like a browser with two many plugins installed?

There are two easy solutions.
Administration Menu select http://drupal.org/project/admin_select

This handy module lets each user choose which admin menu they want to use when editing their profile. There is support for Admin, Administration Menu, the core Toolbar module, and support will soon be added for the Quickbar module.
hook_page_alter()

However, sometimes you don't want to give your users this flexibility. If you want non-admins to have access to only Toolbar+Shortcut, you can grant them access to the toolbar at admin/people/permissions. Then, in your custom module, you can hide the Toolbar from administrators with this lightweight solution using hook_page_alter:

/**
 * Implements hook_page_alter().
 */
function mymodule_page_alter(&$page) {
  // Hide Toolbar for those who can access the Admin Menu.
  if (user_access('access administration menu') && !empty($page['page_top']['toolbar'])) {
    $page['page_top']['toolbar']['#access'] = FALSE;
  }
}

From:  http://steindom.com/articles/making-toolbar-and-administration-menu-co-exist-drupal-7


Install:
Copy the toolbar_hide folder to your sites/all/modules folder. 
Then enable through http://www.yoursite.com/admin/modules page.