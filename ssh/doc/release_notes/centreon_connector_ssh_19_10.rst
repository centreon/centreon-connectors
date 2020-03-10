==============================
Centreon SSH Connector 19.10.1
==============================

*********
Bug fixes
*********

wrong check timeout
===================

The timeout given by Engine to the connector was decremented by 1. Moreover it
was not sufficiently accurate, so the timeout was reached too soon. Now it is
considered as milliseconds with the good value.
