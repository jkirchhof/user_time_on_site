<?php

/**
 * @file
 * Default views for user_time_on_site.
 */

/**
 * Implements hook_views_default_views().
 */
function user_time_on_site_views_default_views() {
  $view = new view();
  $view->name = 'user_sessions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'user_time_on_site';
  $view->human_name = 'User sessions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE;

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User sessions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer users';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = [
    0 => [
      'field' => 'realname',
      'rendered' => 0,
      'rendered_strip' => 0,
    ],
  ];
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Active User Session: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'user_time_on_site';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Active User Session: First_time */
  $handler->display->display_options['fields']['first_time']['id'] = 'first_time';
  $handler->display->display_options['fields']['first_time']['table'] = 'user_time_on_site';
  $handler->display->display_options['fields']['first_time']['field'] = 'first_time';
  $handler->display->display_options['fields']['first_time']['label'] = 'Login';
  $handler->display->display_options['fields']['first_time']['date_format'] = 'short';
  $handler->display->display_options['fields']['first_time']['second_date_format'] = 'long';
  /* Field: Active User Session: Last_time */
  $handler->display->display_options['fields']['last_time']['id'] = 'last_time';
  $handler->display->display_options['fields']['last_time']['table'] = 'user_time_on_site';
  $handler->display->display_options['fields']['last_time']['field'] = 'last_time';
  $handler->display->display_options['fields']['last_time']['label'] = 'Logout';
  $handler->display->display_options['fields']['last_time']['date_format'] = 'short';
  $handler->display->display_options['fields']['last_time']['second_date_format'] = 'long';
  /* Field: Realname: Real name */
  $handler->display->display_options['fields']['realname']['id'] = 'realname';
  $handler->display->display_options['fields']['realname']['table'] = 'realname';
  $handler->display->display_options['fields']['realname']['field'] = 'realname';
  $handler->display->display_options['fields']['realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['realname']['exclude'] = TRUE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user-sessions';

  $views[$view->name] = $view;
  return $views;
}
