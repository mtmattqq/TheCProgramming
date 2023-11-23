#ifndef BIDDING_H
#define BIDDING_H
#include "bidding.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct bidder {
    int id, item_idx;
} Bidder;

typedef struct {
    int bidderID;
    int itemID;
    int bidPrice;
    int order;
} Bidd;

int cmp_item_min_price(const void *a, const void *b) {
    ItemMinPrice *ia = (ItemMinPrice *) a;
    ItemMinPrice *ib = (ItemMinPrice *) b;
    return ia->itemID - ib->itemID;
}

int cmp_bid(const void *a, const void *b) {
    Bidd *ba = (Bidd *) a;
    Bidd *bb = (Bidd *) b;
    if(ba->itemID != bb->itemID) 
        return ba->itemID - bb->itemID;
    if(ba->bidPrice != bb -> bidPrice)
        return ba->bidPrice - bb -> bidPrice;
    return bb->order - ba->order;
}

int cmp_bidder(const void *a, const void *b) {
    Bidder *ba = (Bidder *) a;
    Bidder *bb = (Bidder *) b;
    if(ba->id != bb->id) {
        return ba->id - bb->id;
    }
    return ba->item_idx - bb->item_idx;
}

int find_item(ItemMinPrice minPriceSeq[], int n, int item_id) {
    int l = 0, r = n;
    while(r - l > 1) {
        int mid = l + r >> 1;
        if(minPriceSeq[mid].itemID <= item_id) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return l;
}

void bidding(Bid bidSeq[], int m, ItemMinPrice minPriceSeq[], int n) {
    qsort(minPriceSeq, n, sizeof(ItemMinPrice), cmp_item_min_price);
    
    Bidd bid_seq[10005];
    for(int i = 0; i < m; ++i) {
        bid_seq[i].bidderID = bidSeq[i].bidderID;
        bid_seq[i].bidPrice = bidSeq[i].bidPrice;
        bid_seq[i].itemID = bidSeq[i].itemID;
        bid_seq[i].order = i;
    }
    
    qsort(bid_seq, m, sizeof(Bidd), cmp_bid);
    
    Bidder bidders[10005] = {0};
    for(int i = 0; i < m; ++i) {
        bidders[i].id = bidders[i].item_idx = -1;
    }

    int bidder_idx = 0;
    for(int i = 0; i < m; ++i) {
        int this_item_idx = i;
        while(this_item_idx < m && bid_seq[this_item_idx].itemID == bid_seq[i].itemID) {
            this_item_idx++;
        }

        this_item_idx--;
        i = this_item_idx;
        if(bid_seq[this_item_idx].bidPrice < minPriceSeq[find_item(minPriceSeq, n, bid_seq[this_item_idx].itemID)].minPrice) {
            continue;
        }
        
        bidders[bidder_idx].id = bid_seq[this_item_idx].bidderID;
        bidders[bidder_idx].item_idx = this_item_idx;
        bidder_idx++;
    }

    qsort(bidders, bidder_idx, sizeof(Bidder), cmp_bidder);

    for(int i = 0; i < bidder_idx; ++i) {
        printf("Bidder %d gets item %d with %d dollars\n",
            bidders[i].id, 
            bid_seq[bidders[i].item_idx].itemID,
            bid_seq[bidders[i].item_idx].bidPrice
        );
    }
}

#endif