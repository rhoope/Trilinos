#@HEADER
# ***********************************************************************
#
#                           Rythmos Package
#                 Copyright (2006) Sandia Corporation
#
# Under terms of Contract DE-AC04-94AL85000, there is a non-exclusive
# license for use of this work by or on behalf of the U.S. Government.
#
# This library is free software; you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as
# published by the Free Software Foundation; either version 2.1 of the
# License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301
# USA
# Questions? Contact Todd S. Coffey (tscoffe@sandia.gov)
#
# ***********************************************************************
#@HEADER

EXAMPLE = RefCountPtrExample2

EXEEXT = .exe

#np# List the names of all exe's in this directory here
noinst_PROGRAMS = $(EXAMPLE)

#np# One SOURCES primary is needed for EACH exe listed above.  (Notice for all 
#np# of the  following primaries that the pattern is 
#np# "(Exe_name)_(PRIMARY_NAME) = ").
#np# List all source files needed to compile the exe.
RefCountPtrExample2_SOURCES = $(srcdir)/cxx_main.cpp 

#np# One DEPENDENCIES primary is needed for each exe listed above.  List any
#np# libraries that the exe depends on.  (This primary is not absolutely
#np# essential.)
RefCountPtrExample2_DEPENDENCIES = $(common_dependencies)


#np# One CXXFLAGS primary can be defined for each exe listed above.  Include 
#np# any -I's necessary for building the exe.
RefCountPtrExample2_CXXFLAGS = \
	-I$(top_srcdir)/src \
	-I$(top_srcdir)/../epetra/src \
	-I$(top_builddir)/../epetra/src \
	-I$(top_srcdir)/../epetra/thyra/src \
	-I$(top_builddir)/../epetra/thyra/src 

#np# One LDADD primary can be defined for each exe listed above.  Include any
#np# LDFLAGS  necessary for building the exe.
RefCountPtrExample2_LDADD = \
	$(top_builddir)/src/librythmos.a \
	$(top_builddir)/../epetra/src/libepetra.a \
	$(top_builddir)/../epetra/thyra/src/libepetrathyra.a \
	$(common_ldadd) \
	$(LIBS) $(BLAS_LIBS) $(FLIBS)

common_dependencies=$(top_builddir)/src/librythmos.a \
  $(top_builddir)/../epetra/src/libepetra.a

include $(top_builddir)/Makefile.export.rythmos

if USING_GNUMAKE
EXPORT_INCLUDES = $(shell $(PERL_EXE) $(top_srcdir)/config/strip_dup_incl_paths.pl $(RYTHMOS_INCLUDES))
EXPORT_LIBS = $(shell $(PERL_EXE) $(top_srcdir)/config/strip_dup_libs.pl $(RYTHMOS_LIBS))
else
EXPORT_INCLUDES = $(RYTHMOS_INCLUDES)
EXPORT_LIBS = $(RYTHMOS_LIBS)
endif

AM_CPPFLAGS = $(EXPORT_INCLUDES)

common_ldadd = $(EXPORT_LIBS)

