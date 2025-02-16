//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2023, Thierry Lelegard
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//
//----------------------------------------------------------------------------
//!
//!  @file
//!  Command line arguments for --pager or --no-pager.
//!
//----------------------------------------------------------------------------

#pragma once
#include "tsOutputPager.h"
#include "tsCerrReport.h"

namespace ts {

    class Args;
    class DuckContext;

    //!
    //! Command line arguments for @c -\-pager or @c -\-no-pager.
    //! @ingroup cmd
    //!
    class TSDUCKDLL PagerArgs
    {
        TS_NOCOPY(PagerArgs);
    public:
        // Public fields
        bool page_by_default {false}; //!< Use a page process by default.
        bool use_pager {false};       //!< Actually use a page process.

        //!
        //! Default constructor.
        //! @param [in] pageByDefault If true, paging is enabled by default and option @c -\-no-pager
        //! is defined. If false, do not page by default and option @c -\-pager is defined.
        //! @param [in] stdoutOnly If true, use only stdout. If false, if stdout is not a terminal but
        //! stderr is one, then use stderr for paging.
        //!
        PagerArgs(bool pageByDefault = false, bool stdoutOnly = true);

        //!
        //! Destructor.
        //!
        ~PagerArgs();

        //!
        //! Add command line option definitions in an Args.
        //! @param [in,out] args Command line arguments to update.
        //!
        void defineArgs(Args& args);

        //!
        //! Load arguments from command line.
        //! Args error indicator is set in case of incorrect arguments.
        //! @param [in,out] duck TSDuck execution context.
        //! @param [in,out] args Command line arguments.
        //! @return True on success, false on error in argument line.
        //!
        bool loadArgs(DuckContext& duck, Args& args);

        //!
        //! Return the output device for display.
        //! @param [in,out] report Where to report errors.
        //! @return A reference to the output device, either @c std::cout or a pager stream.
        //!
        std::ostream& output(Report& report = CERR);

    private:
        OutputPager _pager;
    };
}
