/*
** Copyright 2011 Merethis
**
** This file is part of Centreon Connector ICMP.
**
** Centreon Connector ICMP is free software: you can redistribute it
** and/or modify it under the terms of the GNU Affero General Public
** License as published by the Free Software Foundation, either version
** 3 of the License, or (at your option) any later version.
**
** Centreon Connector ICMP is distributed in the hope that it will be
** useful, but WITHOUT ANY WARRANTY; without even the implied warranty
** of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
** Affero General Public License for more details.
**
** You should have received a copy of the GNU Affero General Public
** License along with Centreon Connector ICMP. If not, see
** <http://www.gnu.org/licenses/>.
*/

#include <iostream>
#include "com/centreon/exceptions/basic.hh"
#include "com/centreon/connector/icmp/check.hh"
#include "com/centreon/logging/engine.hh"

using namespace com::centreon::connector::icmp;
using namespace com::centreon;

/**
 *  Check check constructor.
 *
 *  @return 0 on success.
 */
int main() {
  int ret(0);
  logging::engine::load();
  try {
    check c1;
    if (c1.get_command_id() != 0)
      throw (basic_error() << "constructor failed");
    check c2(42, "./test");
    if (c2.get_command_id() != 42)
      throw (basic_error() << "constructor failed");
  }
  catch (std::exception const& e) {
    std::cerr << "error: " << e.what() << std::endl;
    ret = 1;
  }
  logging::engine::unload();
  return (ret);
}