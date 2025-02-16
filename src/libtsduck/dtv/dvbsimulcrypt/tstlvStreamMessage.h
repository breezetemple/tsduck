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
//!  Base class for DVB SimulCrypt TLV messages operating on streams.
//!
//----------------------------------------------------------------------------

#pragma once
#include "tstlvChannelMessage.h"

namespace ts {
    namespace tlv {
        //!
        //! Base class for DVB SimulCrypt TLV messages operating on streams.
        //! @ingroup tlv
        //!
        class TSDUCKDLL StreamMessage : public ChannelMessage
        {
            TS_RULE_OF_FIVE(StreamMessage, override);
        protected:
            //!
            //! Alias for the superclass of subclasses.
            //!
            using superclass = StreamMessage;

        public:
            // Protocol-documented fields:
            // uint16_t channel_id;
            uint16_t stream_id = 0;  //!< Stream id.

            //!
            //! Constructor.
            //! @param [in] tag Message tag.
            //! @param [in] ch_id Channel id.
            //! @param [in] st_id Stream id.
            //!
            StreamMessage(TAG tag, uint16_t ch_id = 0, uint16_t st_id = 0);

            //!
            //! Constructor.
            //! @param [in] protocol_version Protocol version.
            //! @param [in] tag Message tag.
            //! @param [in] ch_id Channel id.
            //! @param [in] st_id Stream id.
            //!
            StreamMessage(VERSION protocol_version, TAG tag, uint16_t ch_id = 0, uint16_t st_id = 0);

            //!
            //! Constructor.
            //! @param [in] fact Message factory containing a binary message.
            //! @param [in] tag_ch_id Message tag for the channel id field.
            //! @param [in] tag_st_id Message tag for the stream id field.
            //!
            StreamMessage(const tlv::MessageFactory& fact, TAG tag_ch_id, TAG tag_st_id);
        };
    }
}
