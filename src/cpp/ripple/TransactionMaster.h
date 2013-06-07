#ifndef __TRANSACTIONMASTER__
#define __TRANSACTIONMASTER__

#include "Transaction.h"

// Tracks all transactions in memory

class TransactionMaster
{
public:
	TransactionMaster();

	Transaction::pointer			fetch(const uint256&, bool checkDisk);
	SerializedTransaction::pointer	fetch(SHAMapItem::ref item, SHAMapTreeNode:: TNType type,
		bool checkDisk, uint32 uCommitLedger);

	// return value: true = we had the transaction already
	bool inLedger(const uint256& hash, uint32 ledger);
	bool canonicalize(Transaction::pointer& txn, bool maybeNew);
	void sweep(void) { mCache.sweep(); }

private:
	TaggedCache <uint256, Transaction, UptimeTimerAdapter> mCache;
};

#endif
// vim:ts=4