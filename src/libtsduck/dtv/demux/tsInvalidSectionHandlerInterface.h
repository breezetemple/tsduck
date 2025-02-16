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
//!  Abstract interface to receive invalid MPEG section from a SectionDemux.
//!
//----------------------------------------------------------------------------

#pragma once
#include "tsDemuxedData.h"

namespace ts {

    class SectionDemux;

    //!
    //! Abstract interface to receive an invalid MPEG section from a SectionDemux.
    //! @ingroup mpeg
    //!
    //! This abstract interface must be implemented by classes which need to be
    //! notified of the content of invalid sections using a SectionDemux.
    //!
    class TSDUCKDLL InvalidSectionHandlerInterface
    {
        TS_INTERFACE(InvalidSectionHandlerInterface);
    public:
        //!
        //! This hook is invoked when an invalid section is detected.
        //! @param [in,out] demux The demux which sends the section.
        //! @param [in] data The invalid section from the demux.
        //!
        virtual void handleInvalidSection(SectionDemux& demux, const DemuxedData& data) = 0;
    };
}
