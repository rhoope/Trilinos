// Copyright(C) 1999-2010, 2020
// Sandia Corporation. Under the terms of Contract
// DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
// certain rights in this software.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above
//       copyright notice, this list of conditions and the following
//       disclaimer in the documentation and/or other materials provided
//       with the distribution.
//     * Neither the name of Sandia Corporation nor the names of its
//       contributors may be used to endorse or promote products derived
//       from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include <data_warehouse/Iodw_DatabaseIO.h>

#include <Ioss_CodeTypes.h>
#include <Ioss_SubSystem.h>
#include <Ioss_Utils.h>

#include <kelpie/Kelpie.hh>

#include <algorithm>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace {
  // Output a message that the operation is unsupported and die...
  void unsupported(const char *operation)
  {
    std::ostringstream errmsg;
    std::errmsg << "ERROR: Unsupported functionality called: " << operation << '\n';
    IOSS_ERROR(errmsg);
  }

  int get_file_pointer() { return 0; }

  const char *Version() { return "Iodw_DatabaseIO.C 2010/09/22"; }

  void datawarehouse_error(int exoid, int lineno, int /* processor */)
  {
    std::ostringstream errmsg;

    errmsg << "DataWarehouse error at line " << lineno << " in file '" << Version()
           << "' Please report to gdsjaar@sandia.gov if you need help.";

    IOSS_ERROR(errmsg);
  }
} // namespace

namespace Iodw {
  // ========================================================================
  const IOFactory *IOFactory::factory()
  {
    static IOFactory registerThis;
    return &registerThis;
  }

  IOFactory::IOFactory() : Ioss::IOFactory("data_warehouse") {}

  Ioss::DatabaseIO *IOFactory::make_IO(const std::string &filename, Ioss::DatabaseUsage db_usage,
                                       MPI_Comm                     communicator,
                                       const Ioss::PropertyManager &properties) const
  {
    return new DatabaseIO(nullptr, filename, db_usage, communicator, properties);
  }

  // ========================================================================
  DatabaseIO::DatabaseIO(Ioss::Region *region, const std::string &filename,
                         Ioss::DatabaseUsage db_usage, MPI_Comm communicator,
                         const Ioss::PropertyManager &props)
      : Ioss::DatabaseIO(region, filename, db_usage, communicator, props), spatialDimension(3),
        nodeBlockCount(0), elementBlockCount(0), nodesetCount(0), sidesetCount(0),
        commsetNodeCount(0), commsetElemCount(0)
  {
    if (is_input()) {
      dbState = Ioss::STATE_UNKNOWN;
    }
    else {
      std::ostringstream errmsg;
      errmsg << "DataWarehouse mesh option is only valid for input mesh.";
      IOSS_ERROR(errmsg);
    }
  }

  DatabaseIO::~DatabaseIO() {}

  void DatabaseIO::read_meta_data__()
  {
    // get_step_times_();

    get_edgeblocks();
    get_elemblocks();
    get_faceblocks();
    get_nodeblocks();

    get_edgesets();
    get_elemsets();
    get_facesets();
    get_nodesets();
  }

  void DatabaseIO::read_region() {}

  void DatabaseIO::read_communication_metadata() {}

  void DatabaseIO::get_edgeblocks() { std::cerr << "\tget_edgeblocks\n"; }

  void DatabaseIO::get_elemblocks() { std::cerr << "\tget_elemblocks\n"; }

  void DatabaseIO::get_faceblocks() { std::cerr << "\tget_faceblocks\n"; }

  void DatabaseIO::get_nodeblocks() { std::cerr << "\tget_nodeblocks\n"; }

  void DatabaseIO::get_edgesets() { std::cerr << "\tget_edgesets\n"; }

  void DatabaseIO::get_elemsets() { std::cerr << "\tget_elemsets\n"; }

  void DatabaseIO::get_facesets() { std::cerr << "\tget_facesets\n"; }

  void DatabaseIO::get_nodesets() { std::cerr << "\tget_nodesets\n"; }

  int64_t DatabaseIO::get_field_internal(const Ioss::Region *reg, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::get_field_internal(const Ioss::NodeBlock *nb, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::get_field_internal(const Ioss::EdgeBlock *nb, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::get_field_internal(const Ioss::FaceBlock *nb, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::get_field_internal(const Ioss::ElementBlock *eb, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::get_field_internal(const Ioss::SideBlock *fb, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::get_field_internal(const Ioss::NodeSet *ns, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::get_field_internal(const Ioss::EdgeSet *ns, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::get_field_internal(const Ioss::FaceSet *ns, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::get_field_internal(const Ioss::ElementSet *ns, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::get_field_internal(const Ioss::SideSet *fs, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::get_field_internal(const Ioss::CommSet *cs, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::get_field_internal(const Ioss::StructuredBlock *sb, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::put_field_internal(const Ioss::Region *reg, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::put_field_internal(const Ioss::NodeBlock *nb, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::put_field_internal(const Ioss::EdgeBlock *nb, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::put_field_internal(const Ioss::FaceBlock *nb, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::put_field_internal(const Ioss::ElementBlock *eb, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::put_field_internal(const Ioss::SideBlock *fb, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::put_field_internal(const Ioss::NodeSet *ns, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::put_field_internal(const Ioss::EdgeSet *ns, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::put_field_internal(const Ioss::FaceSet *ns, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::put_field_internal(const Ioss::ElementSet *ns, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::put_field_internal(const Ioss::SideSet *fs, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::put_field_internal(const Ioss::CommSet *cs, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
  int64_t DatabaseIO::put_field_internal(const Ioss::StructuredBlock *sb, const Ioss::Field &field,
                                         void *data, size_t data_size) const
  {
    return -1;
  }
} // namespace Iodw
