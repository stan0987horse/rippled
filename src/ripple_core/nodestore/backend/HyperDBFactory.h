//------------------------------------------------------------------------------
/*
    This file is part of rippled: https://github.com/ripple/rippled
    Copyright (c) 2012, 2013 Ripple Labs Inc.

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================


#ifndef RIPPLE_NODESTORE_HYPERDBFACTORY_H_INCLUDED
#define RIPPLE_NODESTORE_HYPERDBFACTORY_H_INCLUDED

#if RIPPLE_HYPERLEVELDB_AVAILABLE

namespace NodeStore
{

/** Factory to produce HyperLevelDB backends for the NodeStore.

    @see Database
*/
class HyperDBFactory : public NodeStore::Factory
{
private:
    HyperDBFactory ();
    ~HyperDBFactory ();

public:
    class BackendImp;

    static HyperDBFactory* getInstance ();

    String getName () const;

    NodeStore::Backend* createInstance (size_t keyBytes,
                                        Parameters const& keyValues,
                                        NodeStore::Scheduler& scheduler);
};

}

#endif

#endif
