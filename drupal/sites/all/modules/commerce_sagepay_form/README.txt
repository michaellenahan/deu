CONTENTS OF THIS FILE
---------------------

 * Introduction
 * Installation
 * Known issues
 * Alternatives
 * Support
 * Sponsorship


INTRODUCTION
------------

This module allows Drupal Commerce customers to pay using the SagePay Form implementation. 
This is an offsite redirect payment method - customers are redirected to the SagePay servers to enter
their credit card information and are then returned to your servers.


INSTALLATION
------------

 1. Copy the 'commerce_sagepay_form' folder into the modules directory
    usually: '/sites/all/modules/'.

 2. In your Drupal site, enable the module under Administration -> Modules
    The module will be in the group Commerce - Payment.

 3. You will need to change how the billing address is captured under
    Administration -> Store -> Customer Profiles -> Billing Information
    -> Manage Fields '?q=admin/commerce/customer-profiles/types/billing/fields/
    commerce_customer_address'. Change the 'Default to the following name entry
    format' to either 'First and last name text fields' or 'First and last name
    textfields with an optional company text field'.

 4. Enter your SagePay API details under Administration -> Store ->
    Payment Methods -> Credit Card (via SagePay) -> Reaction.
    You will need your SagePay vendor name and the encryption key that was sent to you when your SagePay account was set up.


KNOWN ISSUES
------------

 * SagePay allows the basket to be sent to the offsite server - this feature is yet to be implemented.
 * The delivery / shipping address that is sent to SagePay is not fully implemented (waiting for the Shipping module to be further developed).

ALTERNATIVES
------------

There are other methods of integrating SagePay with Drupal Commerce. You should also look at:

 * SagePay Direct Integration for Drupal Commerce [http://drupal.org/project/commerce_sagepay_direct]
 * SagePay Server Integration for Drupal Commerce [http://drupal.org/project/commerce_sagepay_server]
 
 
SUPPORT
-------

If the encounter any issues, please file a support request
at http://drupal.org/project/issues/commerce_sagepay_form


SPONSORSHIP
-----------

This module is sponsored by i-KOS (http://www.i-kos.com), a SagePay
partner.