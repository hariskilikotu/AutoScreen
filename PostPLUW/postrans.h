/*
Who			When		What
---			--------	----
YKL			23/06/16	#COMPOSTR: changed the Priceline code to use common postrans.h. 
						Added few structs. Some conflicts were resolved by #ifdef PRJ_PRICELINE
YKL			12/05/16	#452297: 90/1C is not needed.
YuliaB      04/05/16    FSD448663 Polling File Ingevoucher - added info transaction 90x1D.
YKL		    21/04/16	#452297: promotion apportionment (priceline)
Hila		04/04/16	BUG 451799 - message on total for tender promotion is not displayed when customer language <> store language
YuliaB      30/03/16    FSD450223 - added new flag 'bReportPrintingRequired' to the transactions TRANS_FLOAT(0x07) and TRANS_CASH_LIFT(0x09).
DrorBa      28/03/16    FSD451172 New ASW-Fiscal Turkey(NCR)-Invoice Enhancements- add new transaction - 90x1A
Helena		10/03/16	FSD#442000 Credit allowed for invoice: new field "bCreditAllowedInv" in trs. 60xD0
JacoR       02/02/16    CR448058. Moneymarket Shoprite South Africa
Helena		01/02/16	FSD#450005_FlyBuyCardScanningCardEnhancement: new field "bDisplayCardIndicatorSegmentBCP" in trans. 60x3B
Helena		01/02/16	FSD#450005_FlyBuyCardScanningCardEnhancement: new fields "bFlyBuyAsSegmentBCP", "FixedSegment" in trans. 60x3B
DrorBa      26/01/16    FSD447653 New ASW-Fiscal Turkey(NCR)- add new transaction - TrsInfo4TaxDetails_
AlbertoA 	14/01/16	FSD 441887 StoreLine Online Food Stamps and Industry Cards
AndrewP		06/01/16	#14813 Add trs_media_ext4_::lTenderCount for when  count when trs_media_::count overflows (< -128 or > 127)
Helena		15/12/15	FSD#444616 NWCC Card Handling: new flag "bMemberCardRequired" in trs 70xA0.
Helena		26/11/15	FSD#444616 NWCC Card Handling: added new field TypeNWCC in trs. 60x3B.
YKL			19/11/15	#436096: trs_discount_::bPickPackFee Used by Foodtuffs Wellington to indicate that a promotion requires a member card
Helena		17/11/15	FSD#444616 NWCC Card Handling: added field bClubCardIndicator to the trs. 60x3D.
YKL			22/10/15	#436096: NWCC FSW: added clubcard field to the 603D TRS.
AndrewP     28/09/15    Epic#435446 US 1 - added department to TRANS_INFO4_POINTS_APPORTIONMENT for dept sale
Helena		24/09/15	FSD438581 Service coupons: added new trs 90x12 TRANS_INFO4_EXT_BARCODE_PRG_TENDER_TYPE, 90x13 TRANS_INFO4_EXT_TENDER_TRS_BARCODE_LINKED_TENDER.
Helena		21/09/15	FSD438581 Service coupons: added new field "bExtensionTrsTenderUsed" to trans. 60xD9
Helena		10/06/15	TD#435542: Part of electronic journal printed in loyalty slip when adding loyalty in consolidation document or retreived document
YuliaB      17/05/15    TD#434067 - additional fields in transaction TRANS_MEDIA_EXT11
Helena		27/04/15	TD#432674:  (Cop!) Not all files in Retroactive directory are processed.
Helena		14/04/15	FSD#226065_Ver5 Parking Exit code: new field "bcdExitCode" in trs. 70x2B trs_info_parking_card_
YuliaB      22/02/15    FSD365329 - added field into 0x07 transaction: indication for SCO loan. 
YuliaB      11/02/15    FSD406085 - Vouchers Issued and Redeemed Report: added new transaction TRANS_INFO4_TRIGGER_PROMOTION
Helena		29/01/15	FSD#421963 - Combine Multiple Archived Documents: Added new transaction TRANS_INFO4_COMBINE_MULTIPLE_DOCUMENTS 90x0A.
Helena		19/01/15	FSD#421963 Combine Multiple Archived Documents: Added bit "bAllowConsolidationDocument" to transaction 70x0F.
Helena		18/01/15	FSD#411629 - Sales per Item Tax IDs	: added new trans. 90x07.
YuliaB      11/01/15    FSD417498 Additional Customer Delivery Information - added subopcodes 40,41,42 into trs.60-11.
YuliaB      11/01/15    FSD420151 StoreLine Partial Rescan Override - trs 90-05 is updated
YuliaB      24/12/14    FSD420610 - Added 2 new transactions 90-05 and 90-06.
jacor		03/12/14	CRD413428. Shoprite Giftcard (TRANS_INFO4_GIFT_CARD)
ykl			07/11/14	#418554 FSW: added 90/02. this tranasction is used to identify what type of slip is to come. it is used for reprint last tranaction from compressed text
YuliaB      03/11/14    FSD415354: Added new field 'uchAgeRequired' to transaction TRANS_INFO_EJ_AGE_ID6 (0xA3).
YuliaB      02/11/14    FSD415370: Added new field 'IssueNo' to PLU sale extention record 6 (opcode 0xD0)
MosheBe		21/10/14	FSD#391853_V7: Added new opcode for info transactions TRANS_INFO4 (0x90) and added trs_info4_link_points_ext2_ (TRANS_INFO4_LINK_POINTS_EXT2)
PaulG		29/08/14	FSD#409559 Added bPrintOnlyBarCode to trs_info2_print_line
MosheBe		07/07/14	FSD#394167: added TRANS_INFO3_NRIC 80xFF
MosheBe		12/06/14	FSD#391853: added trs_info3_link_points_ext_ (TRANS_INFO3_LINK_POINTS_EXT). 80xFE.
Helena		05/06/14	FSD#397828 CIF on fiscal ticket. New transaction TRANS_INFO3_CIF (0xFD).
MosheBe		18/05/14	FSD#391853: added fields to trs_info3_link_points_ (TRANS_INFO3_LINK_POINTS).
Helena		13/05/14	CR_TD#400922_CPN_EOT: new flag "bCoupon" in transaction 70x31.
YuliaB      28/04/14    FSD392122 - Online Purchase - added new info transaction TRANS_INFO3_ALLOWABLE_TENDERS (80xFC).
YuliaB      23/04/14    FSD392122 - Online Purchase - added new fields to transaction TRANS_INFO3_ONLINE_PURCHASE_EXT (80x03).
ykl			23/04/14	FSD397810: WOW prompt for customer details after refund - new flag on POS forms 0x70EA
DrorBa      07/04/14    CR402221/CR402214 - WTC-TR - 0x70-0x82
ShaharK     31/03/14    FSD395537 - added alert ALERT_INV_PDF_FAILURE structure.
MosheBe		30/03/14	FSD#391853: added trs_info3_link_points_ (TRANS_INFO3_LINK_POINTS). The fields will be added later.
ShaharK     13/03/14    FSD395537 - added alert ALERT_INV_PDF_FAILURE.
Helena		25/02/14	FSD#387067: Enhance Extract 51 With MA Promotion. New field "lRewardDestinationType" in info transaction 80x44.
YuliaB      05/02/14    FSD394424 - added new fields to transaction 70-91.
ykl			05/02/14	#387582: new clubcard member signup flag 
YuliaB      13/01/14    FSD#218589(V.13) - added new field "lRejectBoxResetCounterAmount" to trans.70x8D.
Helena		19/06/13	FSD???ReceiptNonFiscal: new transaction 80xF3 TRANS_INFO3_DOCUMENT_NUM_FISCAL_FORMAT.
MFe			04/03/13	FSD347594 GSE Balance enquiry
IliaS		26/02/13	CR#357297 - Adding new transaction 80-77 with field "lOverTender" contain Overtender 
Helena		25/02/12	TD#357677: Added new field "bcdExpirationTyme" to transaction 0x80,0x46.
AndrewP     20/02/13    Epic350305 - added trs_info3_online_purchase_nzl_ik_ for storing Instant Kiwi details
AndrewP     11/02/13    Epic350305 - added trs_info3_online_purchase_nzl_id_ for storing NZ Lotteries transaction ID
AlexR		04/02/13	added new promotion section type for 0x70-93 for general purpose
MFe			22/01/13	MorA changes: added trs_info3_plu_sell_end_
ykl			24/11/12	#334477: Log control-check reasons in TRS file
AndrewP     08/11/12    Epic316907 - new field in "add loan" (float) = other pos involved with transfer funds
Helena		22/10/12	TD#336203 - new field "bShouldBeBadRecord" in struct trans_tail_.
Helena		21/10/12	TD#332305 - new INFO3 transaction 80XEF (TRANS_INFO3_DISCOUNT_EXT1).
Jacor		17/09/12	CR334690 Added online coupon reward transactions
Helena		02/08/12	FSD34249_V4 SweetMartCouponInterfaceWumart: new trans. 80X5B TRANS_INFO3_EXT_MEDIA6.
MFe			30/07/12	TD#328451 Undid changes made on 24/07/12 since it was decided not to write special trs with GST on fees but to redistribute GST on fees by updating transactions
Helena		29/07/12	FSD34249_V4: new field "uchExternalCouponProviderTenderTypeID" in trs. 60x43 TRANS_INFO_COUPON.
MFe			24/07/12	TD#328451 Incorrect GST on Del/Pnp displayed on Salefile (Print Mode 2) 
MFe			23/07/12	TD#327990 Del&PnP(Type Percentage and Record Id 30- col 163 & 339)when using Print Mode "1", "2" - wrong recorded into SALEFILE. 
Helena		22/07/12	FSD#325552 - Weighed items presentation enhancement: new field "uchEmbeddedTypeFromBarcode" in transaction trs_plu_sale_ext_4_  0x70; 0xE0 (TRANS_INFO2_PLU_SALE_EXT4).
MFe			12/07/12	TD#325092 Calculate separately Del/PnP fee per item and write into D1x8D trs
MFe			27/06/12	TD#323733 Exten item price due to del/pnp charges - write it into a separate trs D1xD8
Helena		05/06/12	FSD#159243 Item description from Box file: new info3 trans. TRANS_INFO3_SS_INFO_PLU_DEP_EXT.
MFe			25/05/12	TD#317757 write exten price into a separate trs D1xD8
AndrewP     15/05/12    Epic316907 Add "type" field to trs_float_ (0x07) and trs_cash_lift_ (0x09)
ykl			29/04/12	#306903 FSW fuel voucher used 80/67
Helena		19/04/12	TD#313047 - Seal Money - added fields "opt_reprocess", "ushAuthCashierId"  to trans. 80x54  trs_info3_sealed_bag_info_
MFe			21/03/12	FSD264423 Tender cheque: changed just comment (func=2: BankID instead of BankName)
MFe			08/03/12	FSD264423 Tender cheque
EvgenyZ     06/03/12    FSD230254 added 3 new transaction records for customer account flow
Helena		05/03/12	FSD#139444_ApportTrsPoints: 1. trs "trs_info3ApportionmentInfoRewardTenderOrPoints_" changed to "trs_info3ApportionmentInfoVariousRewards_"
						TRANS_INFO3_APPORTIONMENT_INFO_REWARD_TENDER_ORPOINTS changed to TRANS_INFO3_APPORTIONMENT_INFO_VARIOUS_REWARDS.
Helena		29/02/12	FSD#139444_ApportTrsPoints: 1. changed description from TRANS_INFO3_APPORTIONMENT_INFO_REWARD_TENDER to TRANS_INFO3_APPORTIONMENT_INFO_REWARD_TENDER_ORPOINTS;
							2. changed  from trs_info3ApportionmentInfoRewardTender_  to  trs_info3ApportionmentInfoRewardTenderOrPoints_
							3. added new fields "bRewardAsTender", "bRewardAsPoints" to trs.0x80; 0x44.
PaulG		10/02/11	FSD#294724: Added sWiCodeProduct[2] to trs_media_ext8_
PaulG		10/02/11	FSD#294724: Added new info3 transaction _WIWALLET_SKU 0x80,0x58
JacoR		10/02/11	FSD#257939: Added new info3 transaction TRANS_INFO3_DISCOUNT_EXT 0x80,0x57
MosheBe		11/12/11	FSD#268329: Added new transaction TRANS_INFO3_TRS_SEND_CONTROL 0x80,0x52
RoniB		09/11/11	FSD#266668 - Metrobank EFT Support
PaulG		03/11/11	TD276983 - Added bBalanceAmountAvail and bNewBalanceAmountAvail flags to "trs_ola_gift_card_addInf_" 0x60 0x28 0x37
DrorBa      02/11/11    FSD259732-  Added New trans. TRANS_INFO3_NON_FISCAL_SALE_CROSS_REF 0x80, 0x4F.
LeonX		01/11/11	FSD245239 added bExtraCodeSale flag in trans_plu
MFe			01/11/11	Minor change: change name "substitution item" to "substituted item" (trs 0xD0)
MFe			27/10/11	FSD254275 Tobacco order enhancement: added inf7 to  struct trs_cust_at_sot_
MFe			07/10/11	FSD265316 Refunds enhancement - added new transaction 80x4D
MFe			21/09/11	FSD251772 Customer orders enhancement and product substitutions: added new trs 0xD0
Helena		21/09/11	FSD#253338: Automatic Customer account discount. new info3 trs. TRANS_INF03_EXT_CUSTOMER_ACCOUNT	0x4A
EvgenyKo	25/08/11	TD261267 new info3 frame extanded trs added 0x80 0x49
LeonX		22/08/11	FSD240285: Added bBillingAddress flag in 60xF1 and new sub function code in 60x11.
Helena		12/07/11	FSD234817: Added new transaction 0x80,0x46 TRANS_INFO3_UNIQUE_SERIAL_ISSUANCE.
Helena		12/07/11	FSD234817: Added new fields to trs "trs_info_rtn_voucher_" 0x60, 0x7D: bStoreLineIssued, bReturnVoucherPrinted, ushSerialNumber, bcdExpirationDate.
elinao      08/07/11    new trans TRANS_INFO3_PROMO_TRIGER_ITEMS   	0x45 //FSD75153
Helena		03/07/11	FSD#139444_ApportTrs: Added DepId  to trans. TRANS_INFO3_APPORTIONMENT_INFO_REWARD_TENDER 0x80,0x44
Helena		30/06/11	FSD#139444_ApportTrs: added new trans. 0x80,0x44 TRANS_INFO3_APPORTIONMENT_INFO_REWARD_TENDER.
LeonX		23/05/11	FSD214852 expand customer reference number size
MosheBe		15/05/11	Added missing tail to trans. trs_info2_tax_voucher_printed_ (0x70 0x55)
MosheBe		03/05/11	Bug #222023: Added New trans. TRANS_INFO3_CHANGE_POS_STATUS 0x80, 0x42.
Helena		29/03/11	FSD#139444: added "bFallbackCoupon" to trs_info2_member_account_ (70,32, sub func 7).
YuliaB		22/03/11	FDS#221424: trs_info3_breakdown_data (0x80 0x3D) and trs_info3_summary_data (0x80 0x3E).
Helena		21/03/11	FSD#13444: Coupon Validation Enhancement. New trans. TRANS_INFO3_COUPON_CONDITIONAL_OVERRIDE 0x80, 0x3C.
						Added "bCouponConditionalOverride"  to trans. trs_info_barcode_details_.
EvgenyKo	17/03/11	TD143070 Latvia 2011 new field bOlaPartDone is added to trs_info3_ola_session_ext
EvgenyKo	28/02/11	TD217931 - It was added new subopcode 13 for trs 0x70 0x32 (trs_info2_member_account) and new struct inf8 which supported by new subopcode
DavidHu     23/02/11    #220804 - added bSTDSale, bRefundSale, bLaybySale, bLaybyModify, bDocSetting, bNonPurchase to TRANS_INFO3_ATTRIBUTE_TRANSACTION	(0x80 0x2A)
LeonX		19/01/11	#213941 - added opt_cod_customer flag in trs_cust_at_sot_
OmerR		01/01/11	FSD157230 2 new transactions
DavidHu     22/11/10    FSD121160 - added trs_info3_attribute_transaction_ transaction (0x80 0x2A)
Tatiana		22/11/10	Removed ulLongStoreNumber from transaction 0x60 0x46 
Tatiana		31/10/10	Bug #155699 - added DEPOSIT_MONEY_INTO_DISPENSER_ACTION info ticket action.
SharonS		28/10/10	bug #146006- Handling of restricted items on SCO
SharonS		20/10/10	FSD134730 - Rimi external loyalty - added trs_info3_ticket_total_data_
DarrenO     12/10/10    Added internal_plu flag to trs_cust_at_sot.
Tatiana		05/10/10	Changed structure  trs_customer_count_ for transaction 0x70 0xAD. Used old offset in transaction for signed long value.
Meytald		15/09/10	FSD126489 + FSD112346  - added uchFuelCardPaymentType and bDisallowLoyalty to TRANS_MEDIA_EXT5
Darren		01/09/10	TD108436: Prism Emv Data for Recovery, added TRANS_INFO3_PRISM_EMV_DATA (0x80  0x28)
KobiM		22/07/10	FSD121574 - Added new segment sales transaction: Opcode 0xCE.
Helena		08/07/10	FSD90244: added action for the ticket info frame transaction (TRANS_INFO_TICKET_FRAME)  REMOTE_MONEY_REQUEST_APPROVED_AT_POS_ACTION (65).
IlanM		07/07/10	FSD#30638, CR#96167 - Added new parameter to (0x70,0x53) (unsigned char uchOfflineEftTenderId at offset 30)
SharonS		10/06/10	Sainsbury's bugs. Trs 60 78: Moved reason_type from offset 38 to 42, to align the structure with FO structure.
Helena		08/06/10	FSD90244 - new transactions 0x80,0x24 (TRANS_INFO3_REMOTE_REQUEST_HDR), 0x80,0x25 (TRANS_INFO3_REMOTE_REQUEST_DETAIL).
YuliaB      02/06/10    FSD61185 - changes in non-payment trs (80x19) and debt.coverage (60x28xA5)   trs.
DrorA		25/05/10	TD#122834 - added cancel indication to transaction 70-9B (TRANS_INFO2_BARCODE_DISPLAY)
KwongC		25/05/10	FSD93620 Changed 0x80 0x23 unsigned char uchActionStatus to unsigned short ushActionStatus
MFe			21/05/10	Added byte-counter (just comments) to trs_clubcard_
DavidHu     10/05/10    FSD93620: Added sTrack2 to trs_manualy_settlement_ext_ (0x70 0x27) 
KwongC		14/05/10	#117215 Need identify tender correction ticket in resume payment in 0x70 0xC9
Tatiana		12/05/10	Removed unused TRANS_INFO2_SPECIAL_CANCEL subopcode.
MosheBe		12/05/10	Removed un-used trs_info2_special_cancel_ trs.
MosheBe		11/05/10	Bug #121898: Added uchLastSubStateInSaleMode field to struct trs_total_key_ (0x60,0x26)
YoavP       10/05/10    FSD102401: Added to 0x60-16 bOutstandingPayment, to 0x60-78 reason_type, to trs_plu_ext5 uchFuelFunctionCode 
KwongC		04/05/10	FSD93620: Added to 0x80 x23 uchActionStatus to indicate EFT Action Status for Token Notification in SAF Print request
DavidHu     03/05/10    FSD93620: added bGiftCardActivationFailed bOfflineEFTtran to trs_info2_giftcard_activate_ (0x70 0x35)
ykl			29/04/10:	trs_prom_info_: i needed the lQualifySpent and uchTriggerScheme for porting PE
						to Foodstuffs. From what I checked, qty_attached_ttl and qty_attached_bucket 
						are not in use.
RoiA		28/04/10	FSD93620: PCI Interface Change. Added trs_info3_eft_status_ transaction (0x80 0x23)
MosheBe		27/04/10	FSD#89180: Added ushLineID to trs_info2_prom_ext2_ (0x70 0xA0)
DavidHu     19/04/10    FSD93620: added bNewVoucherEntry bProcessingType bManualVoucherEntered to trs_eft_info_data (0x60 0xC2)
AndrewP     29/03/10    FSD93620 - added enum TrackType for trs_track_ (60-1D) to handle new data types (ePAN, token, truncated PAN)
OmriS		22/03/2010	FSD102391 StoreLine Product Restriction Enhancement - add restiction_message_id to trs_birthday_
YaelB		17/03/10	FSD90246 - added bCashLiftVoided flag to trs_info_cash_lift_ transaction (TRANS_INFO2_CASH_LIFT)
YuliaB      15/03/10    FSD61185 - added ola info debt coverage transactions (60-28-A5 and 60-28-A6).
YuliaB      10/03/10    FSD61180 MMiles (added info3 80-21 transaction)
Tatiana		11/03/10	Added info ticket action REPRINT_TRANSACTION_ACTION
RoiA		11/03/10	FSD93620: Added Token flag to 60-1D
Sharons		09/03/10	FSD89659 - added sub opcode 3 and action type 11 + 12 to trs_info2_atm_data_
KobiM		03/03/10	FSD75178 - Added discount amount for sales person transaction
Assafm		01/03/10	FSD102391 - added declination reason code to 60-A3
Meytald		01/03/10	FSD61181+FSD61182+FSD61183 add MM_INQUIRY_ACTION,MM_TRANSFER_ACTION,MM_RECLAIM_ACTION  to action list of 0x50 transaction.
IlanM		25/02/10	FSD#96110 - Added ulAutomaticLocalSegment1 & ulAutomaticLocalSegment2 in struct trs_info_document_seq_ (0x60, 0xEC)
AlexanderS	23/02/10	FSD95450 added new trs (0x80, 0x1B) for Home Shopping
YaelB		21/02/10	Added original ticket date to transaction 60-0D for FSD#90612
MosheBe		16/02/10	Bug #108211: added new info3 trans. TRANS_INFO3_PROM_TOTALS, 0x80, 0x20
MosheBe		02/02/10	Bug #103665 - Added shPromCount to struct trs_finish_media_ (0x60,0x35)
MosheBe		14/01/10	CR#89180 - Added bRepeat flag to struct trs_dep_sale_ext2_ (0x98)
DavidHu     12/01/10    FSD71759: add bDisplayBalanceonCustScreen to TRANS_INFO2_MEMBER_ACCOUNT 0x70 0x32
MFe			11/01/10	FSD56986: Added fields "order_type" and "placed_by" to struct trs_cust_at_sot_ . inf5
MosheBe		06/01/10	CR#89180 - Added bPM flag to struct trs_plu_sale_ext_3_ (0x70,0x04)
DavidHu     04/01/10    FSD70677: add opt_duplicate_receipt to 0x60,0x18 by Duplicate Receipt for FrontOffice 
DavidHu     11/12/09    FSD70677 Add SCO_type to struct trs_msg5_plu_
Diana		09/12/09    FSD58650 - Transaction uploading From Storeline To HQ
MFe			03/12/09	D#93600 Added 	MISCTF_NOSALE=3, MISCTF_GTTL=4 to enum misc_trans_func_
DavidHu     25/11/09    FSD65262: Add new DisplayControlCheckOnTotal to 0x22 transaction
Tatiana		18/11/09	Added UNKNOWN_ITEM_ACTION to action list of 0x50 transaction.
ShaharK     28/10/09    NSCO - Moved RSCL Subopcodes to INFO3. 
LeonidO		26/10/09	FSD#59806 - new trs 80x01 - vending adapter & new field at 70x0e (added previously)
ykl			26/10/09	#3939: bSignPIN on 60/28/4C
RoiA		22/10/09	FSD69851: added WithholdSales and WithholdTax flags to 70-C3 and 70-C9
ykl			17/10/09	60/28/4C: added account type
YuliaB      14/10/09    FSD71422 - added new fields for Item message printing to trs 60x8A and 70x2A.
ykl			11/10/09	#3919:the EFTPOS transaction was done offline and required signature 
Helena		06/10/09	FSD67194: added new info3 trans. TRANS_INFO3_ONLINE_PURCH_ITEM_EXT, 0x80, 0x0E
RoiA		02/10/09	#70725,#72200: Added bThirdPartyLoyalty flag for 60-C4 
Helena		01/10/09	CR71648: Support ITF barcode. Added changes to trans. 70x57, 70x71
Tatiana		22/09/09	Moved here from posdef.h list of actions for the ticket info frame transaction TRANS_INFO_TICKET_FRAME
AlexanderS	17/09/09	FSD55426 and FSD61519 added new TRANS_INFO3  TRANS_INFO3_OCTOPUS_DETAILS
Helena		16/09/09	FSD66628: Added new info3 trans. TRANS_INFO3_VOUCHER_DETAILS_EXT
EvgenyKo	15/09/09	FSD28013 - Added new flag bDataBarItemSale to trs_plu_sale_ext2_ 0x22
EvgenyKo	15/09/09	FSD28013 - Added new DataBar trs 0x80 0x0B
MosheBe		14/09/09	CR53695 - new changes: added chSubAction to trs_info_ticket_frame_
ykl			11/09/09	#3900: 60/B2: extra_fee2 might be used to hold the standard price
KwongC		03/09/09	#70529 Need to save manual pan entry for offline eft. 70x27 bManualPanKey
Tatiana		02/09/09	Added more actions for TRANS_INFO_TICKET_FRAME transaction
Assafm		26/08/09	FSD64199 - adding new coupon details and barcode details extension transactions.
Tatiana		25/08/09	Added struct TrsSeqTail_ and removed lSavedStartSequenceNumber from trs_info2_update_trs_ structure.
AlexR		25/08/09	Added new trs 0x80-09
Meytald		23/08/09	FSD58656 - Added new trs (0x80, 0x08) for ANPR data
KwongC		20/08/09	#70371 Added to 70x32 unsigned char uchNumberOfDecimalPlaces. Need to get Member account decimal places from general tables
Tatiana		19/08/09	Added lSavedStartSequenceNumber to trs_info2_update_trs_ structure.
DavidHu     18/08/09    #70523: tank_no added to trs 0x11
Tatiana		13/08/09	Added and deleted TRANS_INFO2_SPECIAL_REPEAT subopcode
KwongC		30/07/09	#69900 uchRewardTender added to 70xA0
ykl         29/07/09 1. 60/BC: Alternate cust# on 
                     2. 60/28/4c: OLA card data
KwongC		27/07/09	#69782 Added lWghDecimalValApportion to 70xA0 to allow partial apportionment of weight/decimal item
EvgenyKo	15/07/09	FSD67680 - Added new trs (0x80, 0x05) for fiscal item sale errors
ykl			08/07/09	80/04 - purchase order number
DrorBa      23/06/09    #68341 - Remove security number field from trs_saved_ticket_ and trs_info2_accumulated_vat_retrn_ 
DavidHu     19/06/09    FSD63383 - Gift Card Purchase with Barcode Activation 
Tatiana		18/06/09	Added subopcode LOG_FUNC_LOCK_CASHIER_POS_AFTER_SIGN_OFF for FO transaction
YuliaB      18/06/09    FSD58646 - Added new info transaction for fuel function triggering (0x80 0x02).
TomerG		15/06/09	CR 65207 - Add RPO ticket indication to 60x31 (after 0x21 trs)
YKL			12/06/09	#67417: Ezipay Gift Card redemption
MosheBe		02/06/09	Renamed bPriceModificationCancelItem flag to bSpecialCancel for TRANS_INFO, TRANS_INFO_PRICE_OVERRIDE
Tatiana		28/05/09	Added new structure trs_info2_update_trs_ for 0x70 0xDF
Tatiana		27/05/09	Added new opcode for info transactions TRANS_INFO3 
ykl			21/05/09	added opt_StdPriceOnly
YuliaB      12/05/09    FSD62787 - Added new trs (0x70, 0x7F) for Ticket Reference number
YuliaB      07/05/09    FSD62787 - Added Ref.number to transaction 0x60 0x78 (save transaction).
RoiA		30/04/09	FSD52846: sPosProductId size increased to 12 in qdx 155
Igors		13/04/09	CR55882 - Changed 60x31, Extending Store Number from 5 to 7 digits
Tatiana		13/04/09	FSD57488 - Added bIsHomeGroup and bIsHomeStore bits for member card information
ykl			08/04/09	60/28/38: EFTPOS trans ID for Syncro (cr#2888).
IlanM		06/04/09	TD#64966 - New Customer survey extension transaction
EvgenyKo	25/03/09	FSD59807 - Added new fields to parking card info trs (0x70 0x2B)
EvgenyKo	25/03/09	FSD59807 - Added flag ParkingItem to PLU sale extension trs 2 (0x22)
IlanM		25/03/09	FSD#59744 - New EFT transaction TRANS_INFO2_EXTRA_CARD_INFO (0xAF) holding module name and extra EFT data
RoiA		17/03/09    FSD52846: Supporting EMV Chip Cards
KwongC		06/03/09	#63258 Void Manual EFT if signature cancelled. 0x70 0x27 bVoidManualSettlement 
IlanM		05/03/09	FSD#59750 - New Inge voucher transaction TRANS_INFO2_INGE_VOUCHER_EXT 0xFC
IlanM		25/02/09	FSD#59750 - Changed trs_info2_mobile_card_ to trs_info2_inge_voucher_ and added gift card details.
									Changed TRANS_INFO2_RELOAD_MOBILE to TRANS_INFO2_INGE_VOUCHER
HenryW		21/02/09	FSD57577 New field added into trs 0x12 dep_sale 
AmyG		16/02/09	SL_US Issue #17615: Lanehawk [ShlomitG]
AmyG		12/02/09	SL_LA Issue #18981: Save POS report totals to tlog (Latin America)
EL1G		13/01/09	SL_US Issue #18249 - PDX Pharmacy [EL1G+TammyE] - TRANS_INFO2_RX_SALE_EXT and TRANS_INFO2_RX_SALE_EXT2 for SL US
EvgenyKo	26/01/09	FSD58540 Added new trs (0x70,0xF4) TRANS_INFO2_CASH_VOUCHER for Cash Voucher Dev
ykl			26/01/09	changed layout of 70/7C
Meytald		22/01/09	FSD55825 - remove bOlaPartDone from trs_info2_ola_session_
HenryW		22/01/09	FSD53587: Updated trs trs_info2_init_loyalty_card_; added trs_info2_init_loyalty_card_ext_
ykl			05/01/09	#60096: declined Evolution transactions not printing balance on receipt
AmyG		17/12/08	Issue #10996SN: Added databar coupon transaction
ykl			09/11/08	#55079: Foodstuffs Kiosk Promotions: added 70 / 7C
Meytald		23/11/08	FSD54877: add 2 new transactions (70-EB and 70-EC)
Igors		17/11/08	FSD52912: added extension to POS_FORM transaction (60-DB) - 70-EA
Igors		17/11/08	FSD52912: added new transaction 0x70 0xE9 - for Parent Return Type
Helena		15/09/08	FSD55061: added flag "bVoucherApproved" to transaction 0x19 trs_media_ext4_ .
EyalAl		07/09/08	Generic Services : 0x70 0xE4 trs_info2_ola_identifier_Key_ added.
Kwongc		04/09/08	FSD46688 Added Settlement date to 0x60 0x47 sBCDSettlementDate
ykl			29/07/08	added trans_no to trs_info2_remac_response_
ykl			01/07/08	#50704: Remote account response - for Foodstuffs Evolution integration
AmyG		24/06/08	Issue #16122SL - Added new gift card ext trs
AmyG		09/06/08	Added new trs for 15446SL
MinC		02/06/08	#51173 added flag for TPL timeout in trs_info2_init_loyalty_card_
Helena		01/06/08	FSD45186 Added new info2 trans. 0x70; 0xD7; TC transaction confirmation; from field "IssuerAuthenticationData".
EitanN					FSD45975: Added TRANS_INFO2_GIFTCARD_EXTRA_DATA (0x70 0xD6)
MinC		28/05/08	FSD48165,FSD28354 Added new trs(0x70-0xd5) for RPC&CC
RoiA		20/05/08	#50377: Added uchPrinterNo and uchPrintType to 0x60 0xEC
MinC		15/05/08	#50333 Added field of decimal in price for barcode 0x70-0x76
RafiH		11/05/08	#42898 Intervention Report - RSCL
KwongC		30/04/08	#46253 Added bFinaliseReversal to 0x70 0x34
MinC		22/04/08	FSD42113:Added new trs 0x70-0xD2 for long item desc
MinC		22/04/08	#48994 :Added card number for EDRC trs
RoiA		21/04/08	FSD46987: Added struct to tran 0x70 0xB3 and bDisplayCaseRefundSaleLine to tran 0x70 0x9E
MINC		04/04/08	FSD42120: Added new info2 trans. 0x70;0xD1.
Helena		30/03/08	FSD46343: Added new info2 trans. 0x70; 0xD0.
MosheBe		26/03/08	#47327 - Added lFirstOrgPrice to trs_price_override_ (0x60 0x14)
EitanN		23/03/08	FSD45606: Added TRANS_INFO2_ETOPUP_ITEM_DATA (0x70 0xCE) and TRANS_INFO2_ETOPUP_ITEM_DATA_EXT1 (0x70 0xCF)
GinatB		16/03/08	FSD28467 - Added definition ALERT_SELF_SCAN_ERROR
								   Added transaction 0x70 0xCD
RoiA		13/03/08	FSD36846 - Added pickup date and time to 0x70 0xCA
RoiA		12/03/08	FSD36846 - Add NON_PAYMENT function to 0x70 0xC9
HativA		11/03/08	FSD40471: Added "uchDeadLine" to transaction "trs_info_document_seq_"
RoiA		03/03/08	FSD36846 - Increase size of uchFormNumber to 9 bytes in 0x70 0xC9
RoiA		29/02/08	FSD36846 - Added fields to 0x70 0xC9
Tatiana		28/02/08	Added TAIL_FLUSH for send transaction functions.
VincentB	26/02/08	TD#45246 - Added definitions for uchTransMode of trs_info2_ticket_scheme.
GillesF		20/02/08	FSD41208 - Added transaction 0x70 0xCB
RoiA		14/02/08	FSD36846 - Added transactions 0x70 0xC9 and 0x70 0xCA 	
EvgenyKo	13/02/08	TD45784, TD45960 - Added flag trs_info2_member_account.inf7.bUpdateMemberAccountBalance,
										   By this flag we know execute or not UpdateMemberAccountBalanceInPromEngine function
										   on recovery.
KwongC		12/02/08	FSD42115 - Added lConfigRewardAmount, uchDecimalPlaceInReward to trs_info2_prom_ext2_ 0x70 0xA0
EvgenyKo	10/02/08	TD#45367 - Added flag trs_info2_member_account.inf7.bExtractRewardCoupon,
								   if it's TRUE - transaction was written from AddCoupon2PromEngineFromList.
								   This issue is related to TD27820.
Helena		07/02/08	FSD41937 - Added flag "bVoidTenderIfEftNotConfirm" to info transaction trs_eft_nomad_media_ 0x60, 0x70.
KwongC		05/02/08	FSD42115 - Added new INFO2 Trans, TRANS_INFO2_ELECTRONIC_VOUCHER 0x70 0xC8
KwongC		01/02/08	FSD39882 - Removed ushDocNum from 60xEC because it is same as ushDocType
KwongC		31/01/08	FSD39882 - Added ushDocType to 70x47
DrorBa		28/01/08    FSD40047 - Added new INFO2 transaction ,TRANS_INFO2_ONLINE_PURCHASE_EXT3, 0x70-0xC7
KwongC		18/01/08	FSD39882 - Added uchTransMode to 70xC3
KwongC		15/01/08	FSD39882 - Updated trs 70x47 trs_trs_info2_item_additional_info_ with print location and indicator for item
LeonX		10/01/08	FSD39682 - updated transaction trs_info_document_seq with print location
Igors		09/01/08    FSD41496 - Added transaction, TRANS_INFO2_DYNAMIC_ATT_VALUE     0x70 - 0xC5  
KobiM		08/01/08	CR40512  - Added uchLastTriggeredPromotion to 70xA0
KwongC		03/01/08	FSD32316 - Added fields to 70x78 and changed 70xA6
EvgenyKo	10/01/08	TD#43238 - Added field trs_info2_member_account.inf7.chCreditPointsType in order
							   to distinguish between promotion points and basic points	 
EvgenyKo	01/01/08	FSD39274 - Added alert self scanning file not found
EvgenyKo	01/01/08	FSD39175 - Added alert parking server 2 - response checksum error
EvgenyKo	01/01/08	FSD39175 - Added alert parking server 2 - response error code
GinatB		01/01/08	TD#42705 - Added opt_weightToQtyItemto trs_dep_sale_ - Indication of item is weight
DrorBa		26/12/07    FSD21868 - Added new INFO2 transaction ,TRANS_INFO2_ONLINE_PURCHASE_EXT2, 0x70-0xC4
KwongC		27/12/07	FSD32316 - Added bReprocess to 70x78 Flags
RoiA		14/12/07	TD#41836 - Added a sub function to 0x70-0xA6, ASK_PROM_WHAT_TRIGGERED.
RoiA		12/12/07	FSD32316 - Added sub function 31 to transaction 0x60 0x11
shahark		11/12/07    FSD36846 - Added new transaction - ticket scheme info.(70xC3).
ChrisB		07/12/07	TD#13919 - FSA Legal requirements for USA, bits for FSA, prescription and healthcare items
LeonX		05/12/07	FSD39873 - Added ushCashierID in 70x6F
RoiA		28/11/07	TD#40716 - Added bExcludePriceModifiedFromProm flag to 0x70 0x04 transaction.
RoiA		27/11/07	TD#40427 - Added a function to 0x20: LOG_FUNC_ASK_PROM_WHAT_TRIGGERED
RoiA		16/11/07	FSD32316 - Added bDetailedTender to transaction trs_media_ext4_ 0x19
MinC		14/11/07	FSD34074 - added flag bUpdateAddress 0x60 0xF1
IlanM		14/11/07	FSD28462 - 1. Removed 0x70 0xAF
								   2. Updates to trs_info2_inge_voucher_
RoiA		13/11/07	FSD32316 - Added bAmountEdited flag and lNewAmount field to trs_info2_pick_up_tender_  (0x70, 0x78)
Tatiana		11/11/07	Added ulTaxVoucherNum to 0x70 0x20 and to 0x70 0x55								
Helena		11/11/07	CR#38963 - V876 + new promotion.
LeonX		09/11/07	TD#40131 - Mark bExtraFeeSale flag in plu_sale_ext2
GillesF		09/11/07	FSD39676 - added sBIN to trs 0x60-0x47
LeonX		02/11/07	FSD39873 - added uchClockingType and bEmployeeClockInOut in 0x70, 0x6F
NemerN		29/10/07    FSD35059 - Added MediRiteType to trs_pharmacy_item 0x70, 0xA8
NemerN		29/10/07    FSD35059 - Added LocationNum to trs_pharmacy_item  0x70, 0xA8
NemerN		29/10/07    FSD35059 - Added DocketNum to trs_pharmacy_item    0x70, 0xA8
NemerN		29/10/07    FSD35059 -  Added IssueLocationNum to trs_pharmacy_item 0x70, 0xA8
AmyG		24/10/07	FSD9797SN - Use MTX receipts - new INFO2 transaction
MosheBe		22/10/07	TD#30168, TD#35586 - Added shSubtractedQty to transaction 0x70,0x04
Chrisb		18/10/07	FSD9849  - Support for multiple recalls in single ticket
RoiA		17/10/07	FSD32316 - Added bTenderCorrected to trs_info2_pick_up_tender_ transaction (0x70 0x78)
Helena		01/10/07	FSD31954 - Supervisor number has been added to info transaction 0x60;0x9F.
Helena		20/09/07	FSD31954 - Invoice value (Amount) has been added to info transaction 0x60;0x9F.
MorA		18/09/07	FSD30255 - New iinfo2 (Tax Location)
KwongC		18/09/07	FSD31972 - Updated 70x32 member account sub_function value 9, 10, 11, for relations, and removed from inf2
Adish		17/09/07	FSD27835 - Added new transaction trs_info_t7e_ext_
DrorBa		10/09/07    FSD28669 - Accumulate vat return:  Add new info2 transcations(0x70,0xBD),(0x70,0xBE). 
AlbertoA	04/09/07	FSD29649 - Added trs_info2_eft_ext_session (0x70 0xBC)
TomerG		28/08/07	TD#34702 - Performance issue, new trs for redemption summary in order to flush all data at once.
KwongC		27/08/07	FSD31972 - Need to define member account relationship to promotion. 0x70 0x32 trs_info2_member_account_  uchRelationToProm
LeonX		24/08/07	FSD30871 - Added bBadAcctValidated and bBadAcct in 60x4c
GinatB		15/08/07	FSD24617 - Added sub functions 6-8 to transaction 0x60 0xE5
ShaharK		17/08/07    FSD29811 - Added uchChargeRelatedTndr to trans 0x70/0x04.
Helena		15/08/07	FSD29721 - Added new field "" to trs_ola_gift_card_addInf_ (0x60;0x28;0x37).
NillyI		13/08/07    FSD34869 - Add bIgnoreSurchargeItemQty flag to transaction 0x70 0x8F
ShaharK		10/08/07    FSD29811 - Added flags to transaction 0x19 - media ext4
GillesF		01/08/07	FSD30357 - New sub alert trs_alert_auto_fuel_mngt_ (ALERT_AUTO_FUEL_MNGT 0x63, 176)
NillyI		31/07/07    TD#33897 - Add pre track2 field on trs 0x70, 0x87
Helena		26/07/07	FSD6916  - New info2 transaction 0xBA with field "EmployeeCorporateNumber"(for MM).
TomerG		23/07/07	FSD32829 - trs modify 60x28x47 (trs_ola_e_pay_result_ext2_) - adding AuthNumber field. coming from online response property.
EitanN		18/07/07	FSD26154 - sec. 7.4-7.8 - added trs_info2_fuel (0x70 0xB9)
EitanN		18/07/07	FSD26154 - sec. 7.4-7.8 - added trs_info2_fuel_mode_changed_ (0x70 0xB9 0x01)
IlanM		18/07/07    FSD30642 - added new info trans. (0x70, 0xB8)
Helena		17/07/07	FSD29721 - added new info trans. 0x60;0x28;0x37.
GillesF		13/07/07	FSD - added uchSchemeNo to transaction trs_info2_add_segment_ (0x70, 0x51)
RoiA		11/07/07	FSD14086 - bWasCancelled is added to transaction 0x70 (0xB3 TRANS_INFO2_ALTERNATIVE_PLU_SALE)
ShaharK		06/07/07    FSD29690 - Added End of ticket endorsement file sequence  to trs 0x19 media_ext4.
MosheBe		04/07/07	FSD16273 - added trs_manual_eod (0x70, 0xB6)
GillesF		29/06/07	FSD29692 - added uchSchemeNo in trs_info2_init_loyalty_card_, created new transaction trs_info2_general_card_ (0x70, 0xB5)
LeonX		28/06/07	FSD29687 - removed sBCDSubstractedQty in trs_plu_sale_ext_2_, replace with flags
RoiA		27/06/07	FSD14086 - bItemFollowsLinkItemChild is added to trs_plu_sale_ext_3_ transaction
AlecM		20/06/07    Enh #14437SL - customer age verification by supervisor
LeonX		19/06/07	FSD25302 - ushLinkRatio added to 70x9E and 70xB3
RoiA		18/06/07	FSD14086 - lOverrideAttValue and bIAValueIsOverride flag are added to trs_info2_dynamic_attribute_ structure
Tatiana		18/06/07	Removed opt_ext_cashier from the tail.
GillesF		18/06/07	FSD23594: added a new alert: ALERT_HOME_SHOPPING (175)
Tatiana		17/06/07	Removed TRANS_POS_LOCK_REQUEST 0x46
AmyG		15/06/07	FSD13919SL - FSA
EitanN		13/06/07	FSD27622 - added trs_info2_eft_inserted_in_tender_mode_ (0x70 0xB4)
MosheBe		10/06/07	FSD24344 - added bPriceModification & bPriceModificationCancelItem flags to TRANS_INFO, TRANS_INFO_PRICE_OVERRIDE
RoiA		06/06/07	FSD14086 - bItemFollowsLinkedItem flag is added to TRANS_INFO_EXTRA_PLU_DATA (0x70/0x04) transaction 
ChrisB		04/06/07	9849SL - New bit in 0x60 0x46 transaction for Miltiple Recalls (Publix)
Igors		04/06/07	FSD26800 - added LOG_FUNC_EMERGENCY_DRAWER_OPENING to LOG transaction (0x20)functions
LeonX		04/06/07	FSD25302 - added flag bOldLaybyTicket in Trans_info2_data
Igors		03/06/07	FSD26795 - added flag percentage to TRANS_INFO, TRANS_INFO_PRICE_OVERRIDE
ShaharK		01/06/07    FSD27844 - added flad to item attribute transaction to indiacte data trs follows .
Sharons		24/05/07	FSD28462 - added transaction 70 AF ('Seperate receipt info2').
AlexR		17/05/07	FSD25302 - added new field bPrntDiscTotalAmnt to 0x50
EitanN		16/05/07	FSD28793 - added bit field bExtensionTransExists to struct trs_ola_e_pay_result_ (0x60 0x28 0x32) 
EitanN		16/05/07	FSD28793 - changed (0x70, 0x87) - trs_info2_online_purchase_ext_::sPinSerialNum[15] to sPinSerialNum[28], changed not_used accordingly
EitanN		16/05/07	FSD28793 - added trs_ola_e_pay_result_ext2_ (0x60 0x28 0x47) & writer function, updated trs_ola_e_pay_result_, trs_info_online_purchase_item and trs_info2_online_purchase_ext.
LeonX		14/05/07	FSD25302 - added new flag bStandardAndInfoLine in 70x9E
YuliaB		13/05/07    FSD25612 - added new field 'Barcode Value' into trs 60D9.
MosheBe		11/05/07    FSD24344 - added trs 0x70 0xAE , info2 ignore.
AmyG		10/05/07	Checked in structs for previously defined transaction types to synch up US and IL for 12593SL, 13526SL and 8897SN. Also added a field to struct trs_coupon_info_ for 8897SN.
RichL		09/05/07    TD#29984 - add Customer count transaction.
LeonX		07/05/07	FSD25302 - added uchORScheme to 70x7A transaction
Sharons		06/05/07    FSD28462 - added trs 0x70 0xAB , info2 mobile card.
YuliaB		06/05/07    Shift_Management in Remote Office (added new action numbers 10-14 to trans. 0x50).
YuliaB		06/05/07    Shift_Management in Remote Office (added new transaction 0x70 0xAA).
MosheBe		03/05/07	FSD16283 - added new transaction 0x70 0xA7
Helena		02/05/07	FSD25862 - LayBy_Reliance. Added field "price_type" to trans. trs_plu_sale_ext_3_ .
MosheBe		25/04/07	FSD16270 - Added field "bManualAdjustmentTicket" to info trans.0x60, 0x31
AmyG		23/04/07	Issue #9270SN - manual fuel bit added to 0x11
ChrisB		18/04/07	SL14148 - Added prepay ticket number to 0x11 in case of multiple prepay ticket recalls
KireetG		18/04/07	FSD27939 - Two new alert number (230,231) added, and new structure (trs_alert_file_distribution_) for the same.
KireetG		16/04/07	Only one Transaction 70-9C for gift redemption, 70-97 removed
LeonX		16/04/07	FSD25302 - added new transaction 0x70 0xA6
SharonM		10/04/07	FSD16242 - added new transaction 0x70 0xA5
Yulia		26/03/07    FSD14667 - Added new alert number 246 (transfer from SafePay Cash to Manual Cash due to SafePay problem).
RoiA		23/03/07	FSD23593 - add masking fields to struct trs_ola_printing_
Sharons		22/03/07    changed discount percentage field from  unsigned char to unsigned long in 0x60 0xDF trs.
AmyG		21/03/07	Issue #13256SL: HF freedom lane
LeonX		21/03/07	FSD25302 add lWghDecimalVal to 70x7A transaction and new data type to trs_ext_data (0x95) transaction
DannyF		18/03/07    #18119_U add bit bOrderNumberAsTransNUmber to 0x60,0xC6 identify self scan trans by Trans number
GillesF		16/03/07	#27235: Added flag "bRtcEmbeddedBarcode" to trs 0x70 0x04 (TRANS_INFO2, TRANS_INFO_EXTRA_PLU_DATA)
AmyG		13/03/07	Issue #12593SL: fiscal sales info trs for LA
YuliaB		08/03/07    FSD23009: added 3 new OLA info transactions for saving 3D-Secure Data record.
HananR		28/02/07	Added a new info trs TRANS_INFO2_CONFIRM_EXT_CARD_UPDATED we use this trs to confirm that we succeed to update the chip card or any ext device.
YaelB		26/02/07	Added struct trs_info2_ola_result_ext3_ - 0x70 0x9D to support Alpha-Numeric terminal id.
Sharons		19/02/07	Added struct trs_info2_barcode_display_ - 0x70 0x9B .
LeonX		13/02/07	#25872 add flag bLaybyDueDateChanged to trs_gnrl_cust_info transaction for organize receipt
ChrisB		09/02/07	Index/Defect #13482SL/#13482SL - Added new bits in 0x11 for Postpay transaction states
KwongC		09/02/07	FSD14082 - Added trs 0x70 0x9A TRANS_INFO2_DYNAMIC_ATTRIBUTE for dynamic plu attribute
ShaharK		06/02/07    FSD22200 - (Organize Receipt) Added target message fields to trs x13
KwongC		06/02/07	FSD18888 Added to 0x60 0xC4 bMasterCardFromBarcode, bVoidBarcodeWhenSchemeVoided
LeonX		02/02/07	FSD14255 use sOutOfStockCode[5] in plu_sale_ext2 for PRJ_ROW
LeonX		02/02/07	added new flag bVoidLaybyFee in trs_info2_layby_financial_ transaction
TomerG		30/01/07	FSD16259 Add alerts 244, 245
YuliaB		24/01/07    FSD16129  Added new field "Zip code id" into trs 605E.
AmyG		23/01/07	Issue #8897SN: EBTWIC Integration
MosheB		10/01/07	FSD16207: added trs_info2_confirmed_promotion_ 0x70 0x96
LeonX		08/01/07	FSD18818: added bInsertLaybyPromo to ItemAddtionalInfoTransaction
GillesF		03/02/07	FSD18888: added ushBarcodeProgReference in trs TRANS_INFO2_LOCAL_BARCODE_ISSUED_EXT(0x70, 0x76).
YuliaB		27/12/06    FSD18361 Added new transaction 7095 for keep trigger count quantity.
LeonX		28/12/06	#23033 add uchServiceFeeType to fee_transaction to mark service fee as percentage or by amount
MosheB		13/12/06	Added a union inside transaction 0x70 0x8c (trs_info2_member_account_update_) [LaviS made me do it].
GillesF		13/12/06	FSD18888: added bValidated in trs TRANS_INFO_BARCODE_DETAILS (0x60, 0xD9)
GillesF		07/12/06	FSD18888: added uchPosNo and ushStoreNo in trs TRANS_INFO2_LOCAL_BARCODE_ISSUED(0x70, 0x31)
GillesF		06/12/06	FSD18888: added shReward1 to shReward4 and ushTicketNo in trs TRANS_INFO2_LOCAL_BARCODE_ISSUED_EXT(0x70, 0x76) and added flag "bProduced" to TRANS_INFO_BARCODE_DETAILS (0x60, 0xD9)
GillesF		04/12/06	FSD18888: Defined a new transaction TRANS_INFO2_PROM_COUPON_REQ (0x91) and added a flag "bExtTrs" to TRANS_INFO_PROM_COUPON 0x87
ShulamitH	04/12/06	FSD14741 - added opt_markdown in trs_dep_sale_ - flag to indicate that this sale took part in promotion.
LeonX		30/11/06	FSD18818: Added bLaybyResellItem to trs_info2_item_additional_info_
LeonX		30/11/06	FSD18818: Added bLaybyItemPromo and bLaybyTicketProm flags in trs_prom_info_
Sharons		29/11/06	#20415 fix : unknownItmReplacementPluCode added to trs 0x70 0x04. meaning code of the item used for creating the unknown item.
Helena		28/11/06	FSD16243: 1.Added field "bTicketPriceUpdate" to info trans.0x60, 0x31; 2. New fields in info trans. 0x70, 0x90
GillesF		28/11/06	FSD14089: Added flag bPriceQuote to trs TRANS_TICKET_FRAME (0x21)
GillesF		17/11/06	#22364: Added field sPinSerialNum to trs TRANS_INFO2_ONLINE_PURCHASE_EXT (0x70 0x87)
GillesF		17/11/06	#22364: Added flag bExtendedAlphaNumPinSerialNum to trs TRANS_INFO_ONLINE_PURCHASE_ITEM (0x60 0xF3)
Helena		16/11/06	FSD16243 - Added new info transaction TRANS_INFO2_PRICE_UPDATED_AT_POS (0x70; 0x90).
CedricM		02/11/06	FSD20957 - Added TRANS_INFO2_SUBITEM
EranM		12/11/06	FSD19186 - Transaction 0x70 0x8E for Self Scan Text to Print TRANS_INFO2_SELF_SCAN_TEXT_LINE.
YuliaB		12/11/06    FSD14667 - added new info transaction 0x70 0x8D
BradM		07/11/06	FSD16191 - StoreLine Pickups Correction
Tatiana		24/10/06	FSD16261 - Quick Save function, added quick_save_flag to transaction 0x60 0x78 ( trs_saved_ticket_ structure) and quick_recall_flag to 0x60 0x46 (trs_recall_trans_ structure).
LeonX		19/10/06	FSD14423 - import 60x0B info_expense transaction from system
GillesF		19/10/06	FSD20162 - added the flag(bBadBatchDateEntry) to trs 0x60 0x8A: this flag indicates if a bad batch entry was a date or an alphanumeric string
GillesF		19/10/06	FSD20162 - added sInternalCode to trs 0x60 0x8A: Internal code of an item
GillesF		19/10/06	FSD20162 - added the flag(bInternalCodeIndentified) to trs 0x60 0x8A: this flag indicates if a bad batch item was identified by its internal code
DrorBa		16/10/06	FSD16061 - trs_info2_member_account_
Sharons		16/10/06	FSD19134 - added startDate, externalTenderNumber, uchRedemptionType to 70 31 .
LeonX		10/10/06	TD#20633 - added ushDenomEntryID to denomination transaction 60xFF
YuliaB		08/10/06    FSD14667 - added flag to 0x21 for ATM ticket indication.
Tatiana		08/10/06	TD#20789 - added TRANS_INFO2_TICKET_TAX (0x3F, ticket tax information in the middle of the ticket) and struct trs_ticket_info_tax_.
LeonX		04/10/06	FSD18814 - added bAttachFlag to trs_info2_item_additional_info_
MarcellaR	25/09/06	FSD16055 - Add new alert number 240 (ALERT_FISCAL_EJ_NEAR_END)
NaamaW		14/09/06	FSD5189  - added  uchControlCheck ushSegment to transaction 60xF0
Tatiana		13/09/06	FSD15885 - Sweet Mart Coupon, added ushProjectId and ushTemplateId to transaction 0x60 0x43 (TRANS_INFO_COUPON).
MosheB		12/09/06	FSD16201 - New Trans trs_info2_member_account_update_ 0x70 0x8C
SharonS		12/09/06	FSD18554 - Added bNextAppearanceNoticeDislpayed on 60 DF trs . FSD 18554 .
GillesF		05/09/06	FSD18705 - added the flag(bProhibitedSaleItem) to trs 0x70 0x04: this flag indicates if a prohibited item was sold by the approval of a control check
Sharons		04/09/06	FSD18554 - trs 0x70 0x14 : added  acct_num field. meaning: customer account number .
AmyG		31/08/06	FSD16204 - Added new tax structure for reward by tender
YuliaB		22/08/06    FSD16729 - add flag 'Cust.Acct discount' to 0x03 to mark a discount transaction as customer account transaction.
MosheB		16/08/06	FSD18556 - Add unpaid document data to (0x60 0xE5)
LeonX		16/08/06	added flag to indicate PinSerialNumber is BCD and new transaction TRANS_INFO2_ONLINE_PURCHASE_EXT
GillesF		11/08/06	Fuel Demo: added a new ticket start type: TICKET_START_NO_CLEAR_TRS_CACHE
Vered		09/08/06	FSD14741 - add flag to 0x60/0x18 for buffer printing indication.
ShaharK		04/08/06    FSD17863 - Provider ID added to trans :60x28x42.
YuliaB		31/07/06    FSD16729 - Custome Account Enhancement. 
AlecM		28/07/06    FSD9896SL - added new info transaction for Kroll Pharmacy Interface
NaamaW		27/07/06	FSD14741 - add flags to trs_msg5_plu_ (0x60 0x8A) for organize receipt
NaamaW		25/07/06	FSD14741 - add flag to media_ext3 (0x18) for organize receipt
AmyG		20/07/06	Issue #9564SL - Updates for Gift Card Batch Activation
MosheB		20/07/06	FSD16187 - new cheque details transaction
HananR		18/07/06	FSD14348 - TRANS_INFO2_HEADER_TRIGGER_PROM - A new transaction will be created as a 'header' for each triggered promotion in the ticket, right before the 03 transactions are generated at the Finish Media stage (for all items participating in it).
NaamaW		13/07/06	FSD14741 - new promotion extra info trans 70/7A.
DrorBa		12/07/06    Add TRANS_INFO_DUMMY_POINTS  
CedricM		05/07/06	FSD13078 - Added reference number length to trs_media_ext4_
DrorBa		06/07/06    FSD11893 - changes in trs_info2_local_barcode_
YuliaB		03/07/06    FSD15846 - added structures for trs 0x60 0x56 (info store count) and 0x91 (plu stock count).
ChrisB		30/06/06	Issue #3754SL - Sub-Return functionality - Hannaford
CedricM		28/06/06	FSD13078 - Added sRoadyOrderNumber to trs_info_self_scanning_ (sOrderNumber was too small for roady).
AmyG		28/06/06	Issue #9564SL - Gift Card Batch Activation
LeonX		27/06/06	FSD12431 - add bChangeOrder to 0x60/0xFF to mark the denomination transaction as change order
SharonS		22/06/06	FSD 12841 , added 0x70/ 0x3E transaction. requesting for new store unique issue number.
Helena		22/06/06	FSD14517 - (StockCount) - Added flag "save_at_StockCount" to info transaction (0x60;0x78) trs_saved_ticket_.
HananR		20/06/06    FSD14348 - UPDATED 0x70  0x32 (new field promotionId)
Vered		20/06/06	FSD14741 - Added master flag in trans_tail for organized receipt.
ShaharK		20/06/06    FSD11575 - Trs 70/x76 	added the conditions  the barcode met.
Helena		14/06/06	FSD16283 - Added flag "bCashChangeCalcul" to info transaction 0x60;0x31 (trs_location).
GillesF		13/06/06	FSD16142 - Added a flag in trs_media_ext3_(0x18) indicating if a transaction is a pre-swipe one
HananR		07/06/06    FSD14348 - new info2 transaction TRANS_INFO2_VOUCHER_REWARD_PROM(0x77) //FSD14348
SharonS		07/06/06	FSD14665 - added trs_info2_pickup_bag_ 0x70 / 0x6E
Helena		06/06/06	FSD15007 - Cash Limit Enhancements. Added new field DrawerLimit to info trans.0x60;1E.
Tatiana		05/06/06	FSD10094 - 2 Person Operation, added  ALERT_REMOTE_SIGN_OFF_PROBLEM alert.
Helena		04/06/06	FSD15007 - Cash Limit Enhancements. Added new field SupervisorNo to info trans.0x60;1E.
ElyS		28/05/06    TD#16820, TD#16821 - 0x60 0x28 - 0xA0 0xA1
SharonS		28/05/06	TD#16616 - fix - added bPrintOnReceipt flag to 0x70/0x46 .  This bit is set to the value of the flag with the 
								   same name on the relevant POS item message.
CedricM		24/05/06	FSD13078 - Added trs_info2_local_barcode_ext_ (0x70 / 0x76)
						FSD13078 - Removed referenceNumber from trs_info2_local_barcode_
						FSD13078 - Added flag in trs_info2_local_barcode_, set if trs_info2_local_barcode_ext_ is present
						FSD13078 - Added referenceNumber to trs_media_ext4_
CliffR		23/05/06	Added structure for x70x6C (TRANS_INFO_CAR_WASH_EXT)
YaelB		22/05/06	CR#8389  - Add flag - opt_recovered_ticket to trs #0x21 in order to label the ticket as recovered in the EJ.
ShaharK		28/04/06    REMOVED defines that were defined in posdef ( No link between the files).AGAIN
Elis		21/05/06	FSD2615  - 0x70 : 0x73 ,0x74,0x75
ShaharK		15/05/06    FSD11575 - Added sup data to 60/x87 trs.
Helena		11/05/06	FSD15007 - Cash Limit Enhancements. Added new field CashInDrawer to info trans.0x60;1E.
YaelB		08/05/06	add unsigned char  reason_type to trs_info2_forms_collection_
YaelB		08/05/06	add short ushOriginalPluSeqNo	to trs_plu_sale_ext2, move bOptBillPayment and  sBCDSubstractedQty[2]
KwongC		03/05/06	TD#16068 - Changed 0x70 0x47 flag bPresentFlag to bNotPresentFlag
ShulamitB	02/05/06	TD#15639 - Added sub_type to 60-F8 transaction: TRANS_INFO_FORM
ShulamitB	01/05/06	TD#15639 - Add 0x70,0x72 transaction: TRANS_INFO2_FORMS_COLLECTION
EliS		01/05/06	Info2 0x71 TRANS_INFO2_PRINT_ITEM_FOOTER fsd7315
LeonX		27/04/06	TD#3051  - added sBCDSubstractedQty in trs_plu_sale_ext2 to record long qty in a BCD value
ShaharK		28/04/06    REMOVED defines that were defined in posdef ( No link between the files).
RandyB		27/04/06	US Enh #9806 - Encrypted Data Info Trans - Added new TRANS_INFO2_ENCRYPTED_DATA 0x70\0x70
Sharons		10/04/06	TD#15618 - added lLastDirectSegmentPromsPotentialRewards to 0x70 0x3D trs.
YuliaB		06/04/06    FSD10281 - Added flag for 'tender purchase' tender in the sale/tender mode.
Tatiana		05/04/06	TD#15302 - Added new transaction opcode 0x50 TRANS_INFO_TICKET_FRAME.
CedricM		24/03/06	FSD13078 - Added reference number to 0x70/0x31 : TRANS_INFO2_LOCAL_BARCODE_ISSUED
YaelB		22/03/06	FSD11254 - Add bStockAllocationType flag to trs_plu_sale_ext2_
CliffR		30/03/06	US CR# 8665SL - Car Wash Tax - Added new Info Trans 2 - TRANS_INFO_CAR_WASH_EXT
SharonS		30/03/06	TD#15336 - Added uchNumberOfRewardsTriggered to 0x70 0x51 transaction.
GillesF		30/03/06	FSD12648 - New fiels (barcode and barcode length) added in the add_segment trs 0x70\0x51:
ShaharK		29/03/06    FSD11575 - New fields in trs (x19) mediaext4.
ShaharK		27/03/06    Plu price added to plu additional data transaction(70-47)
Helena		22/03/06	FSD13992 - Pick&Pack fee exclusions.
ShaharK		22/03/06    FSD12648 - Added flags to 60/x40  added support for more cross types ( segments).
ShaharK		22/03/06    FSD12648 - Added flags to 60/x1a to indicated collected promotions and Promotions triggered by segments.Plus added field to trs x13.
GillesF		21/03/06	FSD12648 - Defined type that triggered a barcode programing trs 0x60\0xD9: #define  BARCODE_PROGRAMING_SEG_TRIGGER = 0,  MANUAL_FUNCTION_SEG_TRIGGER	= 1, LAYBY_SEG_TRIGGER = 2
GillesF		21/03/06	FSD11575 - Added opt_descOnCustomerDisplay and opt_descOnOperatorDisplay flags to  0x60\0xD9 transaction
ShaharK		17/03/06	FSD11575 - Added indication which promotion triggered reward tender in trs medi aext 4 (x19).
GillesF		08/03/06	FSD11575 - Added opt_ignore flag and uchUniqueKeyIdentifier to  0x60\0xD9 transaction
YaelB		10/03/06	FSD13459 - add new sub-opcode (44) for transaction 0x20, and new struct trs_log_func_long_password_
YaelB		08/03/06	FSD11803 - Add TRANS_INFO2_COMPLEMENTARY_GROUP 0x6A
DrorBa		08/03/06    FSD11022 - Add TRANS_INFO2_PROMPT_CASHIER_RESPONSE  0x69 
NillyI		07/03/06	TD#10194 - Add a dep tax apportionment flag in dep trs (0x02)
ElyS		06/03/06    FSD2615  - 0x70 - 0x66 0x67 0x68 
SharonS		05/03/06    Added manualDiscountAmount on trs 0x60  0x1A  , fix of N#13479 .
SharonS		28/02/06    Added TRANS_INFO2_GEN_SEGMENT_INFO - 0x70 0x3D, for C4 Carta - Pass .
ElyS		20/02/06    FSD2615  - BILL PAYMENTS info2 0x64 0x65 
Tatiana		16/02/06	FSD10094 - 2 Person Operation, added special 2PO transaction 0x70 0x2F
ElyS		16/02/06    FSD2615  - media ext2 
ElyS		16/02/06    FSD2615  - BILL PAYMENTS 0x62 0x63
MorA		09/02/06    Fortress - Need a transaction description (for TF Server flat file)
Vered		08/02/06    FSD10286 - Update sub type values for 0x60\0x11 transaction (according posdef.h).
AndreiK		07/02/06	FSD10094 - Tail bit for External cashier transaction.
Vered		02/02/06    FSD10286 - New sub type values for 0x60\0x11 transaction.
Helena		31/01/06	FSD10576 - added flags "OptReturnTrans", "OptReturnItem" to info trans.0x68
SharonS		31/01/06	Version 871X - added uchPromFiscalReportingMethod to 0x60 0x1A trs. 
NillyI		19/01/06	FSD11780 - update trs_redemption_ struct (trs 0x60 0x22)
NillyI		19/01/06	FSD11780 - add sub function 6 ( member account updated manually) to 0x70 0x32 trs 
ElyS		18/01/06    FSD7315  - 0x70 : 0x57,0x58,0x59 - for lines printing
HananR		16/01/06	UPDATE 0x70 0x30 - Transaction.
ElyS		15/01/06    FSD7315  - 0x70 0x56  
NillyI		12/01/06	FSD11780 - added new trs 0x60 0x28 0x46 - loyalty server update result.
Tatiana		12/01/06	FSD11944 - Updated trs_file_refresh_ structure.
ElyS		10/01/06    FSD7315  - trs_info_online_purchase_item_
ElyS		10/01/06    FSD7315  - to trs_plu_sale_ext2_
MorA		08/01/06	FSD11254 - add bDeliveryItem to plu_sale_ext2.
YuliaB		02/02/06    FSD9306  - Added info trs 0x70 0x3C for Resell and Post Void process.
Tatiana		20/12/05	Added trs 0x70 0x2E (TRANS_INFO2_LAYBY_MESSAGE) with response data of the Lay By messages.
SharonS		19/12/05	Added trs 0x70 0x3B, telling the end of ticket apportionment data has been  requested from prom engine.
SharonS		13/12/05	FSD9797  - Added  bTndrSwap field transaction 0x21 .
YuliaB		01/12/05    FSD10526 - Add new alert number 131 for parking server timeout.
Helena		01/12/05	FSD7148  - OfflineGiftVouch: added new info2 transaction 0x70, 0x2D.
Eranm		29/11/05	TD#10485 - Added to Transaction 0x6031 uchLocalWeekInYear (Week of year of local time (January 1-7 == 0))
HananR		28/11/05	FSD11456
AndreiK		24/11/05	trs_info2_ticket_type_ 70 33 updated.
ElyS		21/11/05    FSD7148  - add extra media transaction 
Yulia		20/11/05    FSD10526 - Add new info trans 702B for parking card.
Eranm		20/11/05	Added new info2 transaction TRANS_INFO2_END_TICKET_VOUCHERS	// FSD9034
Dannyf		20/11/05	rename struct trs_info_reason_code_US_VERSION_ was compliation error
CliffR		16/11/05	Added structures for various transactions that were missing
HananR		15/08/05	FSD7786  - added a new flag to TRANS_LOG_FUNC forceSuperVisor
						the new flag is TRUE in case that supervisor exit the secure mode used barcode.

-------- Until here TRS DOC update by Melanie Zion version of 11/2005
SharonS		14/11/05	N#11007 , added lPromEngineAllocatedPromNo on trs_prom_info_ 
ShaharK		14/11/05	New field to 60\xdd (seq number.)
MorA  		10/11/05	FSD7610  - Add new info transaction (0x70/0x53 - eft session).
SharonS		09/11/05	FSD8152  - New flag: bTriggeredByManSegmentFunc on trs_prom_info_
Sharon		01/11/05	FSD8152  - Add new info2 transaction (0x1F) for delayed promotions fiscal lines to print at end of ticket.
Vered		27/10/05    FSD6795  - Add new info2 transaction (0x1E) for loyalty card initialize
Vered		23/10/05    FSD6795  - Add SecurityCode info to transaction 0x70/0x45
DannyF		23/10/05	FSD10343 - new transaction 70,52 for declartion line info - like 60,FF
Vered		21/10/05    FSD6795  - Add Rocks Loyalty info to transaction 0x70/0x45
Helena		17/10/05	FSD5483  - Added Amount to info2 transaction 0x42.
DannyF		16/10/05	N#10425  - add new transaction 0x70,0x51 add segment to prom engine
Tatiana		16/10/05	FSD6248  - Add bLaybyModifyRefundItem flag to plu_sale_ext2
Vered		14/10/05    FSD6795  - Add new bit in transaction 0x60/0xC4 "bRocksLoyaltyCard".
GillesF		11/10/05	FSD6248  - add ushDueDateExtension offset 39 trans 0x70 0x4A
SharonS		02/10/05	Added trs_info2_fiscal_sub_total_ :( 0x70 0x50 ).
AndreiK		28/09/05	new 0x95 TRANS_EXT_DATA transaction for External messages to send via T-LOG
Vered		27/09/05    FSD9032  - Add new info transaction (0x70/0x4F).
DannyF		26/09/05	CR#9351  - add TaxSystemType offset 41 trans 0x63 80 pos version alert
Tatiana		25/09/05	Added bcdLayByPaymentDate to trs_info2_layby_financial_ structure
AndreiK		25/09/05	Loyalty messages ticket type added to trs_info2_ticket_type_.
Helena		25/09/05    FSD5483  - added new fields to info2 trans. 0x70, 0x42.
AmyG		23/09/05	Issue #8532SL: Prepaid Wireless and Phone Card
KwongC		23/09/05	FSD6248	Added TRANS_INFO2_LAYBY_ACC_DETAIL (0x70/0x4A)
Helena		22/09/05	Foodstuff. CR#9244:price embedded barcodes in rescan shows unit price and not selling price.
						Added new info2 transaction TRANS_INFO2_PLU_EMB_PRICE.
CedricM		22/09/05	FSD8951  - Added TAIL_RETURN tail option for return of barcodes (tender vouchers for example).
DAnnyF		22/09/05	CR#9351  - update trans 0x60 0x04 trs_tax_exempt_
DannyF		21/09/05	CR#9351  - update trans 0x60 0xEE trs_info_reduce_tax_scheme
HananR		19/09/05	FSD8900  - TRUE if use discount instead of promotion.
Helena		14/09/05    CC&C. CR#7805: PDA serial number is added to customer order grid,
						in the customer order maintenance, in the new info transaction 0x60 0xBC(info5).
Tatiana		14/09/05	FSD6248  - Added LOG_FUNC_LAYBY_OLD_TICKET_START and LOG_FUNC_LAYBY_OLD_TICKET_END to transaction 0x20
CedricM		09/09/05	#9547    - Added cashier_no & pos_no to TRANS_INFO_TICKET_TRAILER (0x60/0x34)
GillesF		09/09/05	FSD6248  - Added general customer info transaction: TRANS_GNRL_CUST_INFO(0xC4)
							       Added trs_gnrl_cust_info_ to trans_ for TRANS_GNRL_CUST_INFO(0xC4)
							       Added new sub function (14-25) for trs_ext_cust_info_ 0x70 0x39
TomerG		25/08/08	CD9266   - Mark transaction as prohibit Post Void
KwongC		23/08/05	FSD6248  - Added minor location to trs_info_parcel_ 0x70 0x05
Dannyf		23/08/05	Add Fiscal grand total to 0x70 0x42
SharonS		19/08/05	FS3585   - Added bItemSoldByBarcodeProgramming flag on trs_plu_sale_ext2_  .
CedricM		17/08/05	CRL 8442 - Added plu code & internal code to trs 0x70 0x04
Dannyf		10/08/05	Add Fiscal info to transaction 0x70 0x42
TomerG 		09/08/05	#8558    - Changing byte 19 of transaction 0x60 0x28 0x44 from reward earned to actual R$ available.
CedricM		08/08/05	Added denomCount to TRANS_INFO_DENOMINATION for multiple denomination bug
CedricM		08/08/05	#8628    - Added bNotFoundSale to TRANS_PLU_SALE_EXT2, for not found sale with plu groups.
Tatiana		07/08/05	Changed name TRANS_INFO2_LAYBY_ITEM_ADDITIONAL_INFO to TRANS_INFO2_ITEM_ADDITIONAL_INFO
Tatiana		04/08/05	FSD6248  - Added new info2 0x70/0x47 (TRANS_INFO2_LAYBY_ITEM_ADDITIONAL_INFO) transaction.
Guyr		01/08/05	Shoprite, CR#6910 - Item message capture, added new TRS 0x70/0x46.
Tatiana		01/08/05	FSD5123  - Added bIgnore flag to 0x60 0xDD transaction, for cancel HD/PP
ShaharK		01/08/05	#7405    - Added indication of gift card balancing item sale in transaction x22.
Tatiana		31/07/05	FSD5123  - changed order of fields in trs_info_order_number_ (for future using).
ShaharK		31/07/05	FSD6248  - layby - Added parcel type field to 70/x05.
Tatiana		28/07/05	FSD5123  - Added to orderType and extendedID to 0x60 0xDD transaction, deleted from 0x60 0x8D.
SharonS		27/07/05	FS3585   - added numOfSendRetries to 0x70 0x41 trnasaction.			
Tatiana		27/07/05	FSD5123  - Added sDeliveryID to 0x60 0x8D transaction.
SharonS		27/07/05	FS3585   - added responseCode to 0x70 0x41 trnasaction.
ShaharK		26/07/05	Layby processing - added flag to 70/x06 ( return indication).
Guyr		20/07/05	N#6933   - Self scan save and recall, added new TRS 0x60 0xB7.
SharonS		19/07/05	FS3585   - trs 0x70 0x45 - extrenal loyalty reward info2.
YuliaB		11/07/05    FSD6814  - update archive trs 0x70 0x0F for system process.
Helena		07/07/05    FSD2733  - Added new info2 trans "TRANS_INFO2_POS_REPORT_BN" for pos report.
CliffR		06/07/05	Added new info trans2 (0x70) function code (TRANS_INFO2_CCMS_TIMESTAMP 0x1D) for SL Issue #7962/Enh #7962
CliffR		05/07/05	Added new info trans2 (0x70) function code (TRANS_INFO2_MICR_DATA 0x1C) for SL Issue #7934/Enh #7934
YuliaB		05/07/05    FSD6814  - added new info2 trans 0x43 for extract invoice details.
Helena		04/07/05    FSD2733  - 1.Added new info2 transaction, opcode 0x42.For project with BIG_NUMBER;
								   2.Added new fields to transactions "trs_cash_lift_", "trs_info_cash_lift_".
SharonS		03/07/05	FS3585   - added 'auditNumber' to 0x70/0x41 .
SharonS		03/07/05	FS3585   - added 'bInstantRedemption' to trs_media_ext2_ .
SharonS		03/07/05	FS3585   - added 'bProhibitDiscount' to trs_plu_sale_ext2_ .
SharonS		30/06/05	FS3585   - added 'ushTenderNo' to 0x60/0xC4 .
Jonathand	30/06/05	Add RTAPS Alerts
AmyG		28/06/05	Issue #8270SL: Add new alert ALERT_CHECK_TENDER
SharonS		21/06/05	FS3585: add 'Transaction pointer transaction' 
NillyI		23/06/05	FSD6785  - Cheque verification. Added new info2 Cheque Verification data (0x40)
NillyI		23/06/05	FSD6785  - Cheque verification. Added new info2 Customer data extended transaction (0x39)
AmyG		22/06/05	Issue #6426SN: VISA requirements new SNF/offline EFT trs for StorelineEPS 
DannyF		06/06/05	N#6755: add new bit to 0x60 0xF3 if have extra trans 60 28 42
Guyr		05/06/05	N#6755: add new transaction 0x60 / 0x28 / 0x42 in case serial number is biggerthe 15
NillyI		02/06/05	FSD3598 - update trs_eft_print_reject 

-------- Until here TRS DOC update by Melanie Zion version of 06/2005
RoeiA		02/06/05	CR #6695: add promotion number to plu ext3 transaction
YuliaB		31/05/05    FS5721 Octopus: added new flag to trs_cubcard_info_ (0x60 0xC4). 
AmyG		27/05/05	Issue #7350SL Alt id lookup for HOST member
YuliaB		25/05/05    FS5721 Octopus : added new flags to trs_media_ext3_ (0x18). 
GuyR		25/05/05	Clicks N#6546, Increase ITEMSERIALNUMBER from 15 to 31
AmyG		24/05/05	Issue #7703SL: Modified trs_birthday and added trs_clubcard_ext
CliffR		24/05/05	Added new info trans2 function code (TRANS_INFO2_MAKE_ITEM_DATA 0x1B) for SL Issue #7737/Enh #7737 (Publix QSR Dev)
GuyR		24/05/05	Clicks N#6546, In case pinnumber length is bigger then 24, split the pin to PinNumber[24] and PinNumber_ext[8];
GuyR		22/05/05	Clicks CR#6387 - Added a new TRS for GUID (0x60/0x28/0x36)
CedricM		19/05/05	FSD4930 - Zip Code. Added a new info trs (0x70/0x36).
ShaharK		18/05/05	Fs1333 - Added flags to media_ext2 (x15) and plu_ext2_ (x22) layby balancing item and layby fee sale (replace payment item.
TomerG		17/05/05	Bug #6157 - Temp solution for offline bill payments - add flag to trs 0x60/0x8A
Tatiana		16/05/05	FSD1798 - Added	added new ifno trs (0x70/0x35 - gift card activate)
ShaharK		15/05/05	FS1333 - Layby: added 2 new ifno trs (0x70/0x33 - ticket type and 0x70/0x34 layby financial).
AndreiK		15/05/05	Removed Tesco flag opt_ctp  from 0x21
YuliaB		12/04/05    FSD3649 - Added new info2 Member account trs. (0x70 0x32).
GUyr		12/04/05	CR 852 - Transaction 0x60/0xED - Enum update
CedricM		12/04/05	FSD3938 - SECODIP customers
SharonS		11/04/05	FSD3582 - addition of local issued barcode transaction.
CedricM		10/04/05	FSD4906 - Manual Secure Mode Log
AndreiK		03/04/05	Use of tesco ALERT_FISCAL_ERROR - 102 in StoreLine
CedricM		30/03/05	FSD3580 - Additional Receipt Item - Adding bAdditionalReceiptItem in trs_plu_sale_ext2_
ShmuelP		21/03/05	FSD3928 - LayBy Payment: Adding  opt_LayByDefaultItem in trs_plu_sale_ext2_.
ShmuelP		21/03/05	FSD3928 - LayBy Payment: Adding bcdCustomerID in trs_info_lay_by_.
ShaharK		17/03/05    FSD1332 (BigW Eft Interfaces) 0x60/0xc2 reduced field size.
CliffR		01/03/05	Enh# 6864SL - SYSTEM Dev || #define  ALERT_TRS_RECOVER_PROBLEM 173 ||
						This alert will be triggered when there are problems recovering the transaction
TomerG		10/03/05	FS4002 - Adding trs 60x28x35 for Bill Payment Result.
Guyr		10/03/05	CR N#852, CLICKS, Copied customer return transaction from version 8.6.3.0
DannyF		07/03/05	Update online purchase Auth trans 60 28 33
Tatiana		07/03/05	FSD1798 - Added ALERT_GIFT_CARD_ENQUIRY (xA7) and trs_alert_giftcard_enquiry_ for Gift Card Enquiry development.
YuliaB		07/03/05    FS4716 - Added New field (VAT Return tender) in the media ext. trs 0x14.
ShaharK		06/03/05    FSD1798 - New parameter (sponsor id) to ola refferal trs.
DrorBa		03/03/05    CR4862 -New transaction,trs_discount_ext_  0x13
CliffR		01/03/05	Enh# 6864SL - SYSTEM Dev || #define  ALERT_MAINTENANCE_PROBLEM 172 ||
						This alert will be triggered when there are problems with maintenance
Tatiana		01/03/05	FSD1798 - New transaction 70x29 Gift Card Balance Enquiry
DannyF		28/02/05	Update online purchase Auth trans 60 28 33
DannyF		28/02/05	change cvv2 to pak in trans 60 27
CliffR		24/02/05	Enh# 7503SL - Added new alert subopcode (ALERT_FISCAL_TOTALS_DIFF - 171) for Latin America Fiscal Totals difference --
						This alert is sent when there is a difference between POS and Fiscal Totals
						Added info transaction (TRANS_INFO2_FISCAL_TOTALS_DIFF (unsigned char) 70x1A) for 7503SL
Tatiana		24/02/05	FSD1798 - New transaction 70x28 bulk gift card sale. Added bBulkGiftCardSale to x31.
ShaharK		22/02/05    FSD1798 - New transaction 70x27 manual settlement ext.
YuliaB		17/02/05    FS3025 - updated 0x03 trs. (added minimum Delivery Fee indicator).
DannyF		14/02/05	CR6665 N#4731 AQTEST add defines
Tatiana		13/02/05	FSD3788 - Added date_type to trs_info_form_ structure.
Tatiana		10/02/05	FSD3788 - Refund voucher and account sales, added trans_processing_type to trs_info_form 0x60/0xF8
CliffR		09/02/05	Enh# 6531SL - Added new alert subopcode (170) for Offline Mgr Override --
						This alert will be sent when an offline mgr override is used, once the POS comes online
YuliaB		09/02/05    FS4002 - updated trs. 0x60 0xF3 (added bill payment flag).
YuliaB		09/02/05    FS4002 - New info transaction for Bill payment number(0x70 0x26).
ShaharK		09/02/05    FSD1332 (BigW Eft Interfaces) New parameters in trs 0x18 and 0x60/0xc2..
SharonS		08/02/05    FSD3583 (Stime) , gross Sub-totals info transaction .
DrorBa		02/02/05    change for ROW only- struct trs_media_ (offset 40), CR3037.
KarenP		31/1/05		added 0x70 0x23 and changed 0x70 0x19 trxn name
Yulia		26/01/05    CR#4005 - added info trs. 7021.
Yulia		23/01/05    ROW CR#3024 - Update 0x22 external plu trs. (added Internal item code).
Yulia		19/01/05    FS3025 - Update 0x01 trans.(added Delivery and Pick&Pack fee indication).
Yulia		13/01/05    FS3026 - Update 60 BC 04 trans. (added WebOrderID).
KarenP		12/01/05	added 0x609D, 0x609E, 0x7019
Yulia		11/01/05    FS3025 - Update 60 8D trans. (added Pick&Pack values)
Yulia		10/01/05    FS3025 - Update 03 trans. (added Pick&Pack fee indicator).
Yulia		09/01/05    FS3025 - Update 60 BC for CC&C (Pick&Pack charge).
AndreiK		04/01/05	FS3742 - New Info2  for Fiscal EOD counters 0x70 0x18
DannyF		03/01/05	N#3831 Add called func number to 60 0D  superviser func
DannyF		02/01/05	Update 60 E0 + 60 31 ( for Metro )
DannyF		02/01/05	Add body of 60 EA ( from 87370 Metro) 
DannyF		29/12/04	Add ( from ROW version ) body of 60FA,C1
Tatiana		13/12/04	CR N#3693 Added KeyStrokeData for the key stroke tracing.

-------- Until here TRS DOC update by Melanie Zion
Tatiana		08/12/04	CR N#3693 Added size of window to the soft key trace information.
Yulia		05/12/04    FS3012 - added new trs 0x60 0x28 0x34 - gift card authorisation result.
BoazZ		05/12/04    CR N#619 - update 0x18,60 27 
Tatiana		02/12/04	Added more button types to trace transaction.
Yulia		02/12/04    FS3012 - added field in trs 60F3 to indicated authorizer configuration used.
Tatiana		02/12/04    Added OperationTime structure for trace transaction - 0xC3 for logging cashier activity (trace).
Yulia		02/12/04    FS3012 - added flag in TRANS_PLU_SALE_EXT2 transaction to indication online purchase item.
Tatiana		01/12/04    Add new transaction - 0xC3 for looging cashier activity (trace).
CliffR		09/11/04	Enh #5413SN - Fuel Promo Trans for SN
DannyF		09/11/04	add to 0x21 bRecallPrepay N#3269
DannyF		01/11/04	Add Yaron K. changes ( remark !Yaron! )
DannyF		28/10/04	Merge with ROW 875X
TomerG		12/10/04	Adding shEftTerminalId value to trs_info_t7e_
ShaharK		11/10/04    60x47 was 63 in size.
DannyF		27/09/04    new alert 166 ALERT_TRANS_MANAGER_STUCK
ShaharK		10/09/04    Added flag in 60x41 ignore in recovery (#2553)
ShaharK		03/09/04    #2166 - Add flag in 60x14 to indicated price override as a result of refund confirm price.
YuliaB		01/09/04    FS1870 (ENA) - Added TRANS_INFO2_RETRIEVE_INVOICE for retrieve ticket info.	   
CliffR		30/08/04	Issue #5768SL - Added TRANS_INFO2_FUND_RAISING for Sweetbay Fund Raising Days Development
AmyG		26/08/04	Issue #5215SL: Added TRANS_MEDIA_EXT5 for Albs PO development
Yulia		22/08/04    FS1870 - Add Info archive invoice transaction 0x70 0x0F.
ShaharK		18/08/04    Added indication in trans 60x31 for deposit that was requested in previous ticket.
ShaharK		11/08/04    new param to 60x28 (org tender).
Ronny		10/09/04	Change trap for 0x60FF - split of nu to nu3-7
ShaharK		10/08/04    #1935 - new flag to 60x28 To inticated processing after recall.
ShaharK		05/04/04    Added new field to trs x22 plu ext 2.
ShaharK		22/07/04    Changed field error code intrans 70/x01 from unsigned char to unsigned char[2].
ShaharK		22/07/04    New flags in trs 60x47.
ShaharK		22/07/04    Added tndr param to trs 70/x01.
Vered		20/07/04    Add void flag to denomination transaction (60\FF).7
Vered		18/07/04    Bug #1585 - New flag for immediate messages in 20\1C (instead of signon).
ChrisB		15/07/04	New Info for 4632SL - Food stamp eligible
Vered		15/07/04    Bug #1585 - New flag for signon messages in 20\1C.
Vered		08/07/04    Bug #955 - New info transaction for ecca auth buffer (70/10).
AmyG		25/06/04	Issue #3778SL: Error correct key new functionality
Yulia		22/06/04    FS18347 - added new trs 70x0F for linked usage list barcode.
ShaharK		17/06/04	#23807-New flags in trs x14 for cash purchase recovery.
ShaharK		16/06/04	New Alert 165 - unknown item host lookup failure.
TomerG		15/06/04	Added flag to plu_sale_ext2 (0x22) to indicate that extra code value is valid
Eranm		04/05/04	Added lSavebackValue  parameter to trs_media_ext3_ to solve Bug #23538
ShaharK		11/06/04    FS18343 - Change qty parameter in 70/x05 tp char from unsigned char.
ShaharK		08/06/04    FS18343 - New flags to trs:x22,60x11,70x05,70x06 removed FS18343 flags from x02.
Yonatan		02/06/04	FS22935 - vensafe vending machine transaction added
AmyG		01/06/04	Issue #4293SN: MobiLime interface for Storenext
TomerG		20/05/04	SM-EFT - adding original_pos_number flag to t7e trans (0x17), used by refund eft
Vered		06/05/04    FS22354 - Add tax rate to tax transaction (0x06).
Eranm		04/05/04	Added variable_pan_length and uchPANlength parameters to trs_ola_printing_ to solve Bug #22923
TomerG		03/05/04	#23041 - Added field to 70x04 for Comparison Price
Vered		03/05/04    FS22354 - Add tax type to tax transaction (0x06).
ChrisB		30/04/04	New transaction bits for 3456SL
ShaharK		28/04/04    FS18341 - New trs for deposit (redenition) 60x41.
ShaharK		28/04/04    FS18341 - New flags for deposit in trs 0x14.
Eranm		22/04/04	Add trs_s_card_icc_ext_ new info transaction for ICC extra info like Application label.
Vered		04/18/04	FS21416 - Enhanced pickup
TomerG		04/15/04	FS21416 - Enhanced pickup
ChrisB		04/07/04	3122SL - New info transactions for RSS14 barcodes
Helena		04/04/04    Bug21971: added flag "bCancelSubtrItem" to info transaction 0xED.
DannyF		01/04/04	#22084 Add new flag to Superviser trans 60 0D
Vered		25/03/04    FS18338 - Add new flag to oxoB for drawer accountability (FS18338)
Eranm		24/03/04	FS17494 Added ola info transaction for TransRef string.
ShaharK		12/03/04    FS18343 - New transactions:70x05 -parcel sell info,70x06 -charge info and new lags for dep_sale trs.
yonatan		04/03/04	1.FS20126 generate info transaction 0x70 function 0x04
						2.FS20126 added function generate_extra_plu_data_transaction decleration
ShaharK		04/03/04    FS18343 Added new flags to trs 60x11.
Helena		01/03/04    FS20572. Shoemart. New alert (151) for new Pos + new cold start.
Helena		01/03/04    FS20572. Shoemart. Use alert 38 for Fast cold start. New Alert 150 is for Fast cold start +download from FO.
Helena		29/02/04    FS20572_2; Shoemart. Add z_count to trans. 0x05.
Helena		26/02/04    FS20572_1; Shoemart, New cold start.Added new arerts 36,37,38.
DannyF		26/02/04	FS21409 Update 6001 unkoun item + 7003 same struct as 6001
ShaharK		19/02/04    FS18339 - New trs 70x02 - Sequence trs.
ShaharK		19/02/04    FS18339 - new field to 60xF0.
Tomer		22/02/04	Adding support on Extra Codes (FS20617)
ShaharK		18/02/04    FS18339 - added bit to trs 60/10 ecca info to indicate relation to customer center.
Helena		17/02/04    Added new flags to info transaction 1C , LayBys. FS19171_LayBysPoints.
Helena		11/02/04    Priceline. FS19171_LayBysTax. Added status of LayBys to info transaction 0x31.
Helena		10/02/04	Priceline; FS19171_LayBysTax. Added new transaction 0xC2.
ShaharK		09/02/04    #20687 Removed proggressive fields from 60/1a and added new staff fields instead.
Vered		03/02/04    New info transaction for drawer accountability (FS18338)
ChrisB		02/02/04	New info transaction for EFT decline (Publix)
AmyG		30/01/04	Issue #2711SL: Added new INFO trs for gift card ext data
ShaharK		29/01/04    Added field to 60xf0 FS18339.
DannyF		26/01/04	Add ( usa use )  TRANS_MEDIA_EXT4				(unsigned char) 0x19
Eranm		25/01/04	Add trs_s_card_cvm_list_ and trs_s_card_script_results_ new info transactions for ICC settlement and app_sequence_no to trs_s_card_issuer_.
Eranm		21/01/04	Add ICC data for settlement to 605C trs_s_card_issuer_
Eranm		20/01/04	Add PreTrack2 field to trans 6027 trs_extra_card_
Yulia		12/01/04    Use bit "opt_ctp" in trs 0x21 for lay by ticket indication (FS19171).
Vered		11/01/04    Changed field in transaction 0x0B (FS18338)
Yulia		06/01/04    Added defines for new info trs 60/FB and 60/FC (FS19171)
ShaharK		24/12/03    Added parameters to  to trs 60\x8A
ShaharK		24/12/03    Changed flag opt_saver to opt_replacement_to_unitm.(opt_saver was not used).
ShaharK		21/12/03    Added parameters to  to trs 60\x8A
AmyG		12/12/03	Enh #2385SL: Added new alert - ALERT_CHECK_SCANNER_ERROR
ChrisB		09/12/03	Updated infor transactions from USA
Vered		25/11/03    Added new info transaction 60/F8 (FS19041)
Vered		23/11/03    Added new info transaction 60/F6 (FS18285)
Vered		19/11/03    Added new field to cross transaction 60/40 (FS18285)
Helena		10/11/03    Added new transaction 0xC1 for CR19243.
ChrisB		30/10/03	Added new bit in trs_log for remote force logoff.
AmyG		29/10/03    Added new info transaction 60\F7 for storenext
ShaharK		05/10/03    Added flags to trs 60\xED
ChrisB		21/10/03	Added new byte for CC - Publix reporting level #SL1671
ShaharK		05/10/03    Added flags to trs 60\xED
ChrisB		16/10/03	SL1406 - NSC Coupon database
ShaharK		05/10/03    Added flag opt_reward_by_cashier to trs 60\x1A
ShaharK		22/09/03    added opt_weightToQtyItem to trs 0x01 (plu sale).
DannyF		18/09/03	FS1134 add bit bEmvPinHasRequierd to TRANS_INFO_OLA_PRINTING 60 28 06
DannyF		10/09/03	FS1134 WDM CR #18257 Add 60 5A offset 42 pos entry mode
Vered		10/09/03    Added new flag to customer info trans 60/11.
Yulia		10/07/03    Added new info transaction 0x60 0xF3,0x60 0x28 0x32, 0x60 0x28 0x33(FS15934)
ShaharK		03/09/03    Added new fields to info trs 0xF2 first data structure FS16831.
DannyF		27/08/03	FS1134 add field uchPanEntryMode to 60 28 06
DannyF		13/08/03	Build new trans 60 28 07 TRANS_INFO_OLA_REFFERAL_SAVE for FS1134
DannyF		12/08/03	Added field eft_tender_no to 60 28 06
ShaharK		06/08/03    Added new fields to trs_info_document_seq_ FS16831.
ShaharK		30/07/03    Added new fields to 60/F1 trans FS16831.
Eranm		28/07/03    FS1131 - Electronic sign on enhancement. Added type LOG_FUNC_ELECTRONIC_SIGN_ON to log transaction.
Vered		27/07/03    Change 60/E8 transaction - discounts_refunds changed to discounts (#16864)
ShaharK		23/07/03    Added new fields to 60/EC trans FS16831.
DannyF		27/07/03	Build new trans 60 28 06 TRANS_INFO_OLA_PRINTING for FS1134
Vered		21/07/03    Added new field to 60/1A trans "apportionment_type"
DannyF		09/07/03	Added new flag to 6032 "opt_manual_keyed" #16433
DannyF		08/07/03	Add cvv2 field to trans 6027 eft extra
DannyF		03/07/03	Add ICC transaction's struct ( copy from Tesco )
Shahark		21/05/03    FS1126 - added customer center address transaction - 60xF1
Vered		30/06/03    Change 60/E8 transaction - take out date and time
Shahark		21/05/03    FS1126 - added customer center transaction - 60xF0
Vered		18/06/03    Added new field "promotions" to 60/E8 (#16552)
ChrisB		04/06/03	Enh #65SL Q-Buster @ POS - Added new flag for 0x05 Ticket total Trans
Vered		02/06/03    Added new flag to 60/1A trans
Vered		29/05/03    Added new field (dep_no) to 60/6E trans
Vered		22/05/03    Added new field to 60/87 trans
Shahark		21/05/03    #15666 Added a flag to override trs indication of force price.
ChrisB		09/05/03	OW enh #15155 - Redeemable promotions
YuvalG		23/03/03    Add new info transaction: 0x60\0xEE (FS1117).
Shahark		12/03/03    Added 2 new flags in Dep sale trs 0x02.   FS1116
Vered		18/03/03    Add new field to 60/E6 (barcode coupon) FS5006
YuvalG		13/03/03    Add new transaction (60\ED) FS1115
Shahark		12/03/03    Added new info transaction.Invoice document sequence info trs 60xEC.   FS1088
Shahark		12/03/03    Added new info transaction.header info trs 60xEB.   FS1088
Vered		26/01/03    Added new flag "opt_electronic_reduced" to 60/14 (price override).
DannyF		22/01/03	add opt_vat_receipt to 0x60 , 0x18 reprint
DannyF		06/01/03    trans 0x60 0x18 add bit opt_during_ticket + start use in storeline
DannyF		02/01/03    CR #13504 add EftTypeNum to 60 C2
Vered		01/01/03    Added new fields to 60/E8 (FS1085)
Vered		01/01/03    Added new field "group_type" to 60/1A
Vered		30/12/02    Added new info transaction 60/E8 (FS1085)
DannyF		29/12/02    fix CR #13415 add provider error num to transaction 60 28 05
Vered		29/12/02    Added new field to 60/E6 (FS1100)
Vered		26/12/02    Added new field to 60/E6 (FS1100)
OfirZ		18/12/02	CR #13271 - new Info Trs for offline EFT transaction info.
Yulia		17/12/02    Added error_data to 60/E0 (Customer orders)
Vered		17/12/02    Added new info transaction 60/E6
Vered		17/12/02    Added a new flag to 0x15 (media_ext2) FS1094
Yulia		16/12/02    Trans 6011: added opcode for customer message
Yulia		15/12/02    Added order_status to 60/E0 (Customer orders)
YKL			12/12/02	Comments for 60/E0
Yulia		11/12/02    Added fields in the trans 0x22 (Customer orders)
Yulia		11/12/02    Added "ref_order_no" field to trans 60BC (Customer orders)
DannyF		10/12/02    2 scanners type acording scanner define number to alert 12 + 142
Shahar		09/12/02    FS1081 new trs 0xE5 for account tendering.0xDF changed to account id trs.
Yulia		14/12/02    CC&C: Updated trans 60E0 (Customer orders) 
Yulia		26/11/02    CC&C: Updated trans 60BC: added field "inv_option" for RRP indication
Vered		24/11/02    Add new flag "AcceptedInSaleMode" in media ext2 transaction
ChrisB		22/11/02	Updated new info transactions from US version
Yulia		21/11/02    CC&C: Updated trans 60BC: the field "tax_id" increased to 16 digits and moved from inf2 to inf3 structure for V8.7.4.0.
Rabi		17/11/02	Added new trx (0x25) same as ticket total trx (dummy). Cambpell's specific.
Vered		07/11/02    Add new flags to info service desk (60/DB)
YuvalG		05/11/02    Add new transaction (60\dd) for price list.
Vered		04/11/02    Add new flags to info points ext (60/D7)
Vered		23/10/02    Add new flag to ticket points transaction (60/DA)
Shahark		22/10/02    FS1081- Created strcuture for trs 60xDF and added it to TRANS_ - cust account info.
Shahark		08/10/02    FS1080 - opt_qty_sale available for repos as well as ROW
Yulia		08/10/02    CR#0010 - Customer Order Number Entry ( added info trans 0xDD )
AmyG		09/30/02	Enh #10812 Added signature capture to trs
OfirZ		29/09/02	New info Transaction 0xDC for Signature capture
ShaharK		29/09/02    Added field to trs_coupon_redemption //11599
ShaharK		23/09/02    Added new new transaction struct trs trs_info_service_desk_vchr_         (unsigned char) 0xDB //11722
ShaharK		04/09/02    new alert function:ALERT_PACKAGE_ABORT           0xFC //(252) FS1053
DannyF		04/09/02    update 0x17 V7 EFT for phillipines. ( only for document )
DannyF		03/09/02    update 0x63 89 ALERT_FILE_REFRESH
Vered		03/09/02	Add new transaction struct  trs_info_ticket_points_  0x60/0xDA
DannyF		27/08/02    new alert transaction ALERT_TRANSACTION_QDX_PROBLEM	116
DannyF		26/08/02    new trans TRANS_NEW_SEQ_NUM opcode 0xB0
Yulia		29/07/02    Added field "supervisor_name" and flags into trans 600D
YuvalG		21/07/02    New info Transaction: TRANS_INFO_BARCODE_DETAILS (60\D9) will be sent each time barcode scanned\key entered & found on barcode programming maintanance.
OfirZ		12/07/02	New Alert #20 for Enh #10490 SHORT_EOD AmyG
Vered		08/07/02    Add new flag 'opt_price_embedded_coupon' to 60/43.
Shahark		07/07/02    Add fiels cardStoreNum to trc 60 c4.
YKL			02/07/02	1. Detailed documentation of 0x02
						2. opt_ff_drags_modifier -> add_plu_calc
Vered		01/07/02    Added new fields to 60/5E (customer survey)
Rabi		27/06/02	Added new transaction TRANS_INFO_EFT_NOMAD_TRX_KEY to hold Authorization Key
						for each successful EFT Tender.  Will be used if POST Void needs to be supported.
YKL			20/06/02	1. Changed old ff (fast food) TRS fields to more meaningfull
						   names: opt_ff_drags_modifier -> add_plu_calc, opt_ff_modifier -> opt_grid_price_calc
						2. Started putting comments in a format which wile be easier to document
Yulia		18/06/02    Add flag "opt_credit_sale" to 0x04 trans (ROW).
ShaharK		22/05/02	Add new transaction struct  trs_info_points_ext_  0x60/0xd7
YuvalG		08/05/02    Add new flag: 'express_pos'  to 0x60\0x31 transaction
YuvalG		05/05/02    Add new flag 'opt_phone_card' into PLU transaction instead of existing ROA flags.
ShaharK		02/05/02    Add structure for trs 0x60/D4 - TRANS_INFO_BELGACOM.
YuvalG		01/05/02    Add structure for trs 0x88 - TRS_QDX_UPDATE (taken from TESCO sources).
Yulia		23/04/02    Added field "tender_date" to 0x14 (ROW_PRJ)
Vered		23/04/02    Added new info transaction 60/D3.
Yulia		18/04/02    Added flag "opt_frc_crd_return" to trans. 607E.
Vered		15/04/02    Added flag "origion_points" to transaction 60/1C.
Yulia		20/03/02    Added flag "opt_first_rcl_inv" to transaction 6011
HelenaT		18/03/02	Change request for Delivery charge: delivery charge after "Recall_invoice+sale".
						added opt "opt_recall_invoice_by_payment" in info trs. 0x7E.
ShaharK		17/03/02    Add new flag to : trs_media_ext3_ ,immediately_cashback.
YuvalG		17/03/02    Add new transaction : trs_media_ext3_ (0x18).
YuvalG		17/03/02    opt_deposit_from flg in media transaction replaced by media_ext3 flg.
YuvalG		17/03/02    Add new opcode for media transaction extra 3 (0x18)
DannyF		14/03/02    update 60 28 05 for Delhaize EFT
DannyF		13/03/02    update 60 02 ( EFT account  ) for Delhaize EFT
DannyF		12/03/02    update 60 28 01 + 60 C2 for Delhaize EFT
Yulia		10/03/02    Added flag "opt_ff_drags_modifier" to 0x02 transaction for ROW version
YuvalG		10/03/02    Add two flags into TRS (0x60-0xD0): opt_cancel & opt_current_ticket. 
OfirZ		05/03/02    Add new info transaction (0x60-0xD1). This transaction indicates that a secondary ID has been added to the member card (OEM -USA)
YuvalG		04/03/02    Add new info transaction (0x60-0xD0). This transaction will be used as invoice request for the FO
Yulia		04/03/02    Added flag 'opt_electronic_sale' to trans 0x21 ('Electronic sales' project) 
YuvalG		27/02/02    opt_extra_fee1 replaced by opt_points_reward in 0x03 transaction only on none ROW systems
Vered		27/02/02    New flag "barcode_points" in transaction 60/1C (points)
Vered		27/02/02    New info transaction 60/CF for barcode programming
Yulia		26/02/02    Added flags for total/prom discounts to transaction 60B3 
Vered		25/02/02    New info transaction 60/CE for barcode programming
Vered		24/02/22    New flag "opt_accounting_flag" in trans 02 (dept).
HelenaT		22/02/02	New flag "print price override as discount" in trans 03 (DISCOUNT).
YuvalG		17/12/02    Add new flag prom_internal_id to 60/40 TRS
YKL			17/02/02	Added foreign (export) customer flag to location TRS, 
						for easier TRS processing on B/O.
YKL			16/06/02	Added trs for non. merch. items (wholesale only).
YKL			11/02/02	Added negative flag to 60 B3, which will indicate that amounts
						in that transaction need to be reveresed.
HelenaT		03/02/02	Delivery Charges with new parameters: Added new info transaction 60 BC 04.
Rabi		03/02/02	Added unsigned char pmt_type_sot to trs_location_ 
						Payment type at SOT. 1: cash 2:credit
YKL			03/02/02	Added customer number to invoice payment TRS. Needed by B/O for
						transaction processing.
Yulia		31/01/02    Added struct inf3 to transaction 0x60 0xBC
YKL			29/01/02	Added 60/CA for V7 EFT (Prism)
YuvalG		22/01/02    Add trs_total_key_ structure with two new fields add bu Yosi Yakov.
YuvalG		22/01/02    Add SeqNo & time to trs_recall_trans_ transaction
Vered		22/01/02    Added field "discount_percent" to 60/B6
Yulia		21/01/02    Added flag to the 60/7E for indicate that payment was voided
Yulia		17/01/02    Added flag "opt_void_rcld_inv" to transaction 0x60 0xC7 for void recalled invoice.
YKL			08/01/02    The promotion/redc/offer flags in the 0x01 and 0x03TRS were put under #if compilation flag.
						they will not be used in ROW, but will remain available in other projects.
Vered		27/12/01    Added 60/C9 for Multi-Language
Yulia		20/12/01    Added force_crd_rtrn to 60/BC
YKL			20/12/01    Added pmt_type_sot to 60/7E
YKL			19/12/01    Added 60/9F: invoice re-print
YKL			18/12/01    Added new optino to the INVOICE_PAYMENT_TYPE: payment at another till
YKL			17/12/01    Added wet_tax_rate to 60/B3
YuvalG		17/12/001   Add new flags for trs_plu_nonfnd_ for unknown item request.
Yulia		10/12/01    Added flag "opt_recall_inv" to Media transaction for RECALL invoices
Yulia		06/12/01    Added new info on-line trans 0xC7 for RECALL invoices
Yulia		06/12/01    Added new fieds in the info trans 0x46 for Split trans. process
YKL			03/12/01    Added new PLU extension record, opcode 0x22
YKL			28/11/01    Added new wholesale TRS type: IBS sale and IBS return
YKL			22/11/01    Added few virtual states to the wholesale TRS type enum
YKL			13/11/01    Added invoice time to location TRS
Yulia		12/11/01	Added "Surcharge rate" field in the info trans 0xB3
HelenaT		05/11/01	Struct for info trans. 0xBC, TRANS_INFO_CUST_AT_SOT:
						Added type of return for "Return" at start of ticket
Yulia		01/11/01	Changed sundry item info transaction 0xB1( added Tax amount )
Yulia		01/11/01	Added delivery charges info trans 0x8D
Yulia		31/10/01	Changed transaction TRANS_INFO_GRID_PRICE
HelenaT		30/10/01	1. New in transaction 0x60, 0x7F TRANS_INFO_CHARGE_PAYM
						2. New parameters in struct  trs_cust_at_sot_
Yulia		29/10/01    Added "preliminary" and "credit" returns flags into ticket frame trans.
YKL			27/10/01    Added invoice date to 60/78 and 60/7E
YKL			26/10/01    Added issue date to invoice and location TRS 
YKL			25/10/01    1. Added inv_pmt to union
						2. Added invoice_no to location TRS
Yulia		21/10/01    added flag for Delivery charges to trans.0x03
Yulia		16/10/01    added more fields and sub-function to trs_cust_at_sot_
Yulia		10/10/01    added GST on Adm.fee for price calculation trans. ( 0x60 0xB2 )
Yulia		03/10/01    added voucher redemption tender fields
YKL			25/10/01	Fixed file after corruption in SourceSafe
YKL			19/09/01	1. Added handle type flags to 60/BE
						2. Added eft_handle to media extension 2
Yulia		12/09/01	fields "opt_ff_drags_modifier" and "opt_ff_modifier " will be used for ROW price calc.process
Yulia		11/09/01	1. Added transaction for sundry product
						2. Changed transaction trs_info_price_calc_ 
YKL			10/09/01	1. Added cust_acct to customer info record
						2. Added more fields and sub-function to trs_cust_at_sot_
HativA		16/12/08	FSD57203 - Add new transaction, TRANS_INFO2(0X70)  TRANS_LOYALTY_CARD_EXCHANGE(0XF1) and the struct "trs_info2_loyalty_card_exchange_"
DrorA	    26/10/10  FSD#159233 - Print pos description on receipt 0x70-0xCB.
       
*/

#ifndef POSTRANS_H 
#define POSTRANS_H 

#ifdef _LPOS_PACK_
	#pragma pack(1)
#endif


#define  TRANS_LEN                      64
#define  TAIL_LEN                       20
#define  MAX_SEND_TRANS   (1024/TRANS_LEN)
#define  MAX_TRANS_SEQ_NO         0x10000L

#define  DONT_SEND_TRANS  0
#define  SEND_TRANS       1
#define  WRITE_FLUSH_TRANS			2
#define  WRITE_DONT_FLUSH_TRANS		4

#define  TRANS_OPT_PC_MUST_ACCEPT         0x01
#define  TRANS_OPT_WRONG_RETRANSMITE_REQ  0x02
#define  TRANS_OPT_SWICTH_IHSS_LINE       0x04

#define TRS_CLN_ID (BYTE) ((G.TWO_PERSON_CHECKER)? RTTRSMNG_CHECKER_CLIENT_ID : RTTRSMNG_POS_CLIENT_ID)


/**************************************************/
/*** TRANSACTION TYPES                          ***/
/**************************************************/
#define  TRANS_PLU_SALE         (unsigned char) 0x01
#define  TRANS_DEP_SALE         (unsigned char) 0x02
#define  TRANS_DISCOUNT         (unsigned char) 0x03
#define  TRANS_MEDIA            (unsigned char) 0x04
#define  TRANS_TICKET_TOTAL     (unsigned char) 0x05
#define  TRANS_TICKET_TAX       (unsigned char) 0x06
#define  TRANS_FLOAT            (unsigned char) 0x07
#define  TRANS_COUPON           (unsigned char) 0x08
#define  TRANS_CASH_LIFT        (unsigned char) 0x09
#define  TRANS_POS_TIMES        (unsigned char) 0x0A
#define  TRANS_DECLARE          (unsigned char) 0x0B
#define  TRANS_INVENTORY        (unsigned char) 0x0C 
#define  TRANS_TICKET_TAX_RBT	(unsigned char) 0x0D //FSD16204 RewardByTender (RBT)
#define  TRANS_DEP_NON_SCANNED  (unsigned char) 0x10
#define  TRANS_PLU_SALE_EXT     (unsigned char) 0x11
#define  TRANS_DEP_SALE_EXT     (unsigned char) 0x12
#define  TRANS_DISCOUNT_EXT     (unsigned char) 0x13
#define  TRANS_MEDIA_EXT        (unsigned char) 0x14
#define  TRANS_MEDIA_EXT2       (unsigned char) 0x15
#define  TRANS_PAIDOUT_RECEIPT  (unsigned char) 0x16
#define	 TRANS_INFO_T7E			(unsigned char) 0x17
#define  TRANS_MEDIA_EXT3       (unsigned char) 0x18 
#define  TRANS_MEDIA_EXT4		(unsigned char) 0x19  // usa use
#define  TRANS_LOG_FUNC         (unsigned char) 0x20
#define  TRANS_TICKET_FRAME     (unsigned char) 0x21
#define  TRANS_PLU_SALE_EXT2    (unsigned char) 0x22
#define  TRANS_MEDIA_UK_EXT     (unsigned char) 0x24 // TESCO
#define	 TRANS_DUMMY_TICKET_TOT (unsigned char) 0x25 // Cambpell's specific
#define  TRANS_MEDIA_EXT5		(unsigned char) 0x26 // Issue #5215SL Albs
#define  TRANS_DISCOUNT_EXT2	(unsigned char) 0x27 //FSD44261: offer code
#define  TRANS_POS_LOCK_REQUEST	(unsigned char) 0x46
#define  TRANS_INFO_TICKET_FRAME (unsigned char) 0x50 // Start/End info ticket transaction, #15302
#define  TRANS_CASH_OFFICE      (unsigned char) 0x56 // BO usage only
#define  TRANS_STOCK            (unsigned char) 0x57 // taken by B/O (Clicks)
#define  TRANS_ZIP_PRINTOUT     (unsigned char) 0x68 // TESCO
#define  TRANS_ZIP_PRINTOUT_W   (unsigned char) 0x69 // wide prinout zip (invoices)
#define  TRANS_SCANPOS			(unsigned char) 0x76 // TESCO
#define  TRANS_QDX_UPDATE       (unsigned char) 0x88 // TESCO
#define  TRANS_PLU_STOCK_COUNT  (unsigned char) 0x91
#define  TRANS_PLU_WASTE_MODE   (unsigned char) 0x92 //Waste Mode plu transaction FSD277889
#define  TRANS_DEP_WASTE_MODE   (unsigned char) 0x93 //Waste Mode dep transaction FSD277889
#define  TRANS_CR_REENTRY_MEDIA (unsigned char) 0x94 // TESCO
#define  TRANS_EXT_DATA			(unsigned char) 0x95 // External messages to send via T-LOG
#define  TRANS_PLU_SALE_EXT5	(unsigned char) 0x96 //FSD 61034
#define  TRANS_TANK_NOZZLE_PUMP (unsigned char) 0x97 //FSD 61034
#define  TRANS_DEP_SALE_EXT2	(unsigned char) 0x98 //FSD 61034
#define  TRANS_NEW_SEQ_NUM		(unsigned char) 0xB0 // TRC
#define	 TRANS_EMPTY_OPCODE		(unsigned char) 0xC0 // QDX FILE EMPTY (TRC)
#define  TRANS_STAMPS_DUTY      (unsigned char) 0xC1 // CR19243
#define  TRANS_DEP_LAY_BY       (unsigned char) 0xC2 // FS19171_LayBysTax
#define  TRANS_TRACE			(unsigned char) 0xC3 // TRACE OPCODE
#define  TRANS_GNRL_CUST_INFO	(unsigned char) 0xC4 // FS6248
#define  TRANS_MEDIA_EXT6       (unsigned char) 0xC5 // FSD7148
#define  TRANS_MEDIA_EXT7       (unsigned char) 0xC6 // FSD7148  
#define  TRANS_MEDIA_EXT8       (unsigned char) 0xC7 // FSD7148
#define  TRANS_TRANSACTION_DESCRIPTION (unsigned char) 0xC8 // Fortress+iBS
#define	 TRANS_GENERAL_LONG_DATA	   (unsigned char) 0xC9	//FSD42325
#define  TRANS_MEDIA_EXT9				(unsigned char) 0xCA
#define  TRANS_ENHANCED_COUPON_DETAILS	(unsigned char) 0xCB //FSD64199 
#define  TRANS_SEGMENT_SALES			(unsigned char) 0xCE //KobiM - FSD121574
#define  TRANS_FISCAL_SIG_DATA			(unsigned char) 0xCF //OferK - FSD217889
#define  TRANS_PLU_SALE_EXT6			(unsigned char) 0xD0 //FSD 251772
#define  TRANS_PLU_SALE_EXTEN_PRICE		(unsigned char) 0xD1 //TD#317757 - exten price in case del/PnP charges; write it into a separate trs
#define  TRANS_MEDIA_EXT10				(unsigned char) 0xD2 //CR378184
#define  TRANS_MEDIA_EXT11				(unsigned char) 0xD3 //#425633



//List of actions for the ticket info frame transaction TRANS_INFO_TICKET_FRAME, #15302
#define NO_ACTION					0   //CR53695 - new changes
#define SIGN_ON_ACTION				1
#define SIGN_OFF_ACTION				2
#define X_REPORT_ACTION				3
#define END_OF_DAY_ACTION			4
#define DOC_SETTING_ACTION			5	// FSD18554
#define GIFT_RECEIPT_ACTION			6   // FSD10334
#define GIFT_CARD_ENQ_ACTION		7	// SuperDrug TD#17286
#define REORG_RCPT_FINISH_MEDIA		8	// FSD14741
#define DOC_LOCAL_PRINT_ACTION		9   // #26886
#define ADD_FLOAT_ACTION			10  // Shift_Management in Remote Office
#define PICK_UP_ACTION				11  // Shift_Management in Remote Office
#define DECLARATION_ACTION			12  // Shift_Management in Remote Office
#define PAIDOUT_ACTION				13  // Shift_Management in Remote Office
#define RECEIPT_ACTION				14  // Shift_Management in Remote Office 
#define POS_SHIFT_ACTION			15  // Shift_Management in Remote Office 
#define PRICE_UPDATE_ACTION			16  // #35357 (FSD16243)
#define SPOT_CHECK_ACTION			17  // FSD42257
#define ITEM_PRICE_INQUERY_ACTION 	18  // #46596
#define ONLINE_PURCHASE_REPRINT_ACTION 19 //FSD45606
#define CC_REFUSAL_ACTION			20 //#55823
#define FUNCTION_TRIGGERING_ACTION  21  // FSD62343  
#define ITEM_PROMOTION_INQUIRY_ACTION			22	//FSD53695
#define SWITCH_TWOPO_ACTION						23	//FSD53695
#define EXIT_POS_ACTION							24  //FSD53695
#define POS_SHUT_DOWN_ACTION					25  //FSD53695
#define CHANGE_PASSWORD_ACTION					26  //FSD53695
#define SUSPEND_PRINTER_ACTION					27  //FSD53695
#define RESUME_PRINTER_ACTION					28  //FSD53695
#define EMPTY_CASH_DISPENSER_ACTION				29  //FSD53695
#define SUSPEND_RESUME_COIN_DISPENSER_ACTION	30  //FSD53695
#define AUTOMATIC_ACTIONS						31  //FSD53695
#define EMERGENCY_DRAWER_OPEN_ACTION	  		32  //FSD57905
#define NO_SALE_TICKET							33
#define TAX_VOUCHER_ACTION	  					34  //Bug 69908
#define SECURE_ACTION							35  //CR53695 - new changes
#define UNSECURE_ACTION							36  //CR53695 - new changes
#define ENTER_TRAINING_ACTION					37  //CR53695 - new changes
#define EXIT_TRAINING_ACTION					38  //CR53695 - new changes
#define WRONG_PASSWORD_ACTION					39  //CR53695 - new changes
#define REBOOT_POS_ACTION						40  //CR53695 - new changes
#define CHIP_CARD_MESSAGE						41  // TD#52053
#define MANUAL_EOD_ACTION						42  //CR53695 - new changes
#define TICKET_BARCODE_PRINTING					43 // FSD#68095
#define UNKNOWN_ITEM_ACTION						44
#define CASH_CHANGE_CALCULATION_ACTION	  		50
#define FAIL_TICKET								51 // FSD70780
#define CASH_OFFICE_LOCKING_ACTION              52 // FSD58650 - start
#define CASH_OFFICE_TRANSFER_ACTION             53
#define CASH_OFFICE_BANK_DEPOSIT_ACTION         54
#define CASH_OFFICE_BANK_RECEIPT_ACTION         55
#define CASH_OFFICE_SAFE_TRANSFER_ACTION        56
#define CASH_OFFICE_SAFE_LOCKING_ACTION         57
#define CASH_OFFICE_SAFE_DECLARATION_ACTION     58 // FSD58650 - end
#define START_INFO_FOREIGN_CURRENCY				59	//Bug#99936
#define MM_INQUIRY_ACTION						60	//FSD61181 - Morrisons Miles Inquiry function
#define MM_TRANSFER_ACTION						61	//FSD61182 - Morrisons Miles Transfer function
#define MM_RECLAIM_ACTION						62	//FSD61183 - Morrisons Miles Reclaim function
#define REPRINT_TRANSACTION_ACTION				63	//Bug's fixing 109681, 112594
#define REMOTE_MONEY_REQUEST_FROM_POS_ACTION	64  //FSD90244
#define REMOTE_MONEY_REQUEST_APPROVED_AT_POS_ACTION	65  //FSD90244
#define EFT_ADMIN_MENU_AT_POS_ACTION	66  //FSD113464
#define CENTRAL_MESSAGE_DISPLAY_ACTION		67 
#define DEPOSIT_MONEY_INTO_DISPENSER_ACTION		68 
#define EXTERNAL_LOYALTY_ERRORS					69 
#define LOCAL_DISPENSE_ACTION					70  //Zen note dispenser.
#define CASH_EXCHANGE_ACTION					71 // FSD#218589
#define EFT_ADMIN_MENU_ACTION                   72 //FSD239084
#define SEAL_BAG                                73 //FSD#159229
#define TENDER_COUNTING_ACTION					74 //F1146___TD#331867
#define BARCODE_COUPON_PRINTING_ACTION		    75 //ASW-FSD324541
#define CONTENT_RECEIPT							76
#define INVOICE_PRINT_ACTION					77 // FSD350935
#define SECURITY_NUMBER							78 // FSD#366569
#define POS_REPORTS_BEFORE_EOD					79 // FSD#366569
#define LINK_POINTS_ENQUIRY_ACTION				80 //FSD#391853
#define GSE_EOD_RESPONSE						81
#define TAX_DETAILS_ACTION                      82 //FSD447653		

//Bug#99936: cash_office_type in transaction trs_info_denomination_  (  0x60, 0xFF)
//Exist: 1=declare,2=float,3=cash lift,4=paidout,5=receipt,6=roa,7=deposit , 8 = Safe Declaration,9= SCO ATM deposit (Acceptor),  10 = SCO ATM dispenser 
#define INFO_TRS_FOREGN_CURRENCY				11


#define  TRANS_INFO            		   (unsigned char) 0x60
#define  TRANS_INFO_NONFND     		   (unsigned char) 0x01
#define  TRANS_INFO_EFT        		   (unsigned char) 0x02
#define  TRANS_INFO_BIRTHDAY   		   (unsigned char) 0x03
#define  TRANS_INFO_TAX_EXEMPT 		   (unsigned char) 0x04
#define  TRANS_INFO_CAR        		   (unsigned char) 0x05
#define  TRANS_INFO_CHKSUM     		   (unsigned char) 0x06
#define  TRANS_INFO_BKGD_LOAD  		   (unsigned char) 0x07
#define  TRANS_INFO_ACCOUNT    		   (unsigned char) 0x08
#define  TRANS_INFO_BAGGER     		   (unsigned char) 0x09
#define  TRANS_INFO_CHARGE     		   (unsigned char) 0x0A
#define  TRANS_INFO_EXPENSE    		   (unsigned char) 0x0B //NU	by SuperStore
#define  TRANS_INFO_COST_PRCNT 		   (unsigned char) 0x0C
#define  TRANS_INFO_SUPERVISOR 		   (unsigned char) 0x0D
#define  TRANS_INFO_BUYAID     		   (unsigned char) 0x0E
#define  TRANS_INFO_STAFF      		   (unsigned char) 0x0F
#define  TRANS_INFO_ECCA       		   (unsigned char) 0x10
#define  TRANS_INFO_CUST_INFO  		   (unsigned char) 0x11
#define  TRANS_INFO_BATCH_UPD  		   (unsigned char) 0x12 //Futrue
#define  TRANS_INFO_SKU_ITEM		      (unsigned char) 0x13
#define  TRANS_INFO_PRICE_OVERRIDE     (unsigned char) 0x14
#define  TRANS_INFO_CHEQUE_GRNTY       (unsigned char) 0x15
#define  TRANS_INFO_DRIVE_OFF          (unsigned char) 0x16
#define  TRANS_INFO_BAD_ACCOUNT        (unsigned char) 0x17
#define  TRANS_INFO_TRANS_COPY         (unsigned char) 0x18 
#define  TRANS_INFO_ASSISTANT          (unsigned char) 0x19
#define  TRANS_INFO_PROMOTION          (unsigned char) 0x1A
#define  TRANS_INFO_CLUBCARD           (unsigned char) 0x1B
#define  TRANS_INFO_POINTS  	         (unsigned char) 0x1C
#define  TRANS_INFO_TRACK  	         (unsigned char) 0x1D
#define  TRANS_INFO_CASH_IN_DRAW       (unsigned char) 0x1E
#define  TRANS_INFO_WRONG_PASSWORD     (unsigned char) 0x1F
#define  TRANS_INFO_FREQ_SHOPPER       (unsigned char) 0x20
#define  TRANS_INFO_UNLOCK_UPDATE 	   (unsigned char) 0x21
#define  TRANS_INFO_REDEMPTION         (unsigned char) 0x22
#define  TRANS_INFO_APAC               (unsigned char) 0x23
#define  TRANS_INFO_TRANS_ALERT        (unsigned char) 0x24 //NU	by SuperStore
#define  TRANS_INFO_PC_UTILITY         (unsigned char) 0x25 //NU by SuperStore
#define  TRANS_INFO_TOTAL_KEY          (unsigned char) 0x26
#define  TRANS_INFO_EXTRA_CARD_INFO    (unsigned char) 0x27
#define  TRANS_INFO_OLA                (unsigned char) 0x28
#define  TRANS_INFO_AUTH_PRICE_DIFF    (unsigned char) 0x29
#define  TRANS_INFO_HOST_BATCH         (unsigned char) 0x2A
#define  TRANS_INFO_CHECK_FEE          (unsigned char) 0x2B
#define  TRANS_INFO_NEW_ECCA    	      (unsigned char) 0x2C
#define  TRANS_INFO_PRICE_EMBEDED	   (unsigned char) 0x2D 
#define  TRANS_INFO_EFT_MEDIA  		   (unsigned char) 0x2E 
#define  TRANS_INFO_EFT_PRINT_REJECT   (unsigned char) 0x2F
#define  TRANS_INFO_TRANS_INDEX        (unsigned char) 0x30
#define  TRANS_INFO_LOCATION           (unsigned char) 0x31
#define  TRANS_INFO_TNDR_COUPON        (unsigned char) 0x32
#define  TRANS_INFO_TRAINING_CP_ACCT   (unsigned char) 0x33
#define  TRANS_INFO_TICKET_TRAILER     (unsigned char) 0x34
#define  TRANS_INFO_FINISH_MEDIA       (unsigned char) 0x35
#define  TRANS_INFO_BAD_EXT_TRS        (unsigned char) 0x36
#define  TRANS_INFO_Q_LENGTH           (unsigned char) 0x37
#define  TRANS_INFO_EFT_PRINT_DATA     (unsigned char) 0x38
#define  TRANS_INFO_ALCOHOL_RESTRICT   (unsigned char) 0x39 //MC-2.4
#define  TRANS_INFO_MSG_MIN_AGE        (unsigned char) 0x3A
#define  TRANS_INFO_CLUBCARD_EXT       (unsigned char) 0x3B
#define  TRANS_INFO_SERVICE_FEE 	   	(unsigned char) 0x3C
#define  TRANS_INFO_LOYALTY_FLY_BUY    (unsigned char) 0x3D 
#define  TRANS_INFO_CHARGE_RVRSE_BAL   (unsigned char) 0x3E 
#define  TRANS_INFO_REENTRY      	   (unsigned char) 0x3F //Tesco: Clubcard re-entry
#define  TRANS_INFO_PROM_CROSS   	   (unsigned char) 0x40
#define  TRANS_INFO_DEPOSIT      	   (unsigned char) 0x41 //Tesco
#define  TRANS_INFO_TRADING_STAMPS 	   (unsigned char) 0x42 //Bashas
#define  TRANS_INFO_COUPON         	   (unsigned char) 0x43         
#define  TRANS_INFO_MEMBER_FREQ_SHOP   (unsigned char) 0x44 //progressive         
#define  TRANS_INFO_STAFF_DISCOUNT     (unsigned char) 0x45 //TESCO         
#define  TRANS_INFO_RECALL_TRANS       (unsigned char) 0x46
#define  TRANS_INFO_EFT_SETTLE         (unsigned char) 0x47
#define  TRANS_INFO_EFT_WYNID          (unsigned char) 0x48 //TESCO
#define  TRANS_INFO_NO_RESPOND 	      (unsigned char) 0x49 //TESCO 
#define  TRANS_INFO_CHEQUE_SORT_CODE   (unsigned char) 0x4A //TESCO
#define  TRANS_INFO_VOID_RPRT		   	(unsigned char) 0x4B //void report
#define  TRANS_INFO_REORG_PRINT		   (unsigned char) 0x4C 
#define  TRANS_INFO_FAMILY_FAVORITE    (unsigned char) 0x4D //TESCO
#define  TRANS_INFO_CUSTOMER_SELECT    (unsigned char) 0x4E //TESCO
#define  TRANS_INFO_FAMILY_PROMOTION   (unsigned char) 0x4F //TESCO
#define  TRANS_INFO_ADV_FREQ_SHOP      (unsigned char) 0x50 // Frys freq shop
#define  TRANS_INFO_FREQ_SHOP_CARD     (unsigned char) 0x51 // Frys freq shop
#define  TRANS_INFO_CUST_ACCNT         (unsigned char) 0x52 //FS1081
#define  TRANS_INFO_CUST_ACCNT_ORDER   (unsigned char) 0x53 //ALFA_KOOP
#define  TRANS_INFO_RETRANSMIT	      (unsigned char) 0x54
#define  TRANS_INFO_VOUCHERS  	      (unsigned char) 0x55 //computers_for_school 
#define  TRANS_INFO_STORE_COUNT		   (unsigned char) 0x56 //store_count
#define  TRANS_INFO_CRED_REENTRY	   	(unsigned char) 0x57 //TESCO
#define  TRANS_INFO_SAVING_TOTAL	   	(unsigned char) 0x58
#define  TRANS_INFO_SAVINGS_PLUS       (unsigned char) 0x59 //Albertson's
#define  TRANS_INFO_SC_ICC				(unsigned char) 0x5A 
#define  TRANS_INFO_SC_TILL				(unsigned char) 0x5B 
#define  TRANS_INFO_SC_ISSUER			(unsigned char) 0x5C 
#define  TRANS_INFO_SALES_ON_ACCOUNT   (unsigned char) 0x5D //Finland
#define  TRANS_INFO_CUST_SRV_QUESTION  (unsigned char) 0x5E //Albertson's 
#define  TRANS_INFO_VOUCHER			   (unsigned char) 0x5F //Albertson's fuel reward 
#define  TRANS_INFO_SC_ICC_DATA		   (unsigned char) 0x60 //TESCO
#define  TRANS_INFO_PRE_PAYMENT		   (unsigned char) 0x61 //TESCO
#define  TRANS_INFO_CHARGE_FNB		   (unsigned char) 0x62
#define  TRANS_INFO_PROMO_TTL_STUB	   (unsigned char) 0x63
#define  TRANS_INFO_ES_RESTRICTED_ITEM (unsigned char) 0x64 //TESCO
#define  TRANS_INFO_COMMUNITY_PARTNER  (unsigned char) 0x65 //Albertson's
#define  TRANS_INFO_AUTO_REFUND        (unsigned char) 0x66 //TESCO
#define  TRANS_INFO_CCMS			   	(unsigned char) 0x67 //Fry's VIP
#define  TRANS_INFO_BONUS_BUY          (unsigned char) 0x68 //Albertson's 
#define  TRANS_INFO_BONUS_POINTS       (unsigned char) 0x69 //Fry's VIP
#define  TRANS_INFO_BLACK_BOX  		   (unsigned char) 0x6A //BlackBox
#define  TRANS_INFO_BALANCE_INQUIRY	   (unsigned char) 0x6B //MicroTrax EFT 
#define  TRANS_INFO_BLACK_BOX_DATA     (unsigned char) 0x6C //BlackBox
#define  TRANS_INFO_PAY_AT_PUMP        (unsigned char) 0x6D // Pay At Pump Info
#define  TRANS_INFO_FUEL_REWARD			(unsigned char) 0x6E //gas reward albertson's
#define  TRANS_INFO_REWARD_TENDER      (unsigned char) 0x6F //gas reward redemption albertson's
#define  TRANS_INFO_EFT_NOMAD_MEDIA    (unsigned char) 0x70 //EFT_NOMAD
#define  TRANS_INFO_EFT_NOMAD_PRN_SLP1 (unsigned char) 0x71 //EFT_NOMAD  ----> CLICKS_EFT= SLIP1
#define  TRANS_INFO_EFT_NOMAD_OWN_NM   (unsigned char) 0x72 //EFT_NOMAD
#define  TRANS_INFO_REDEMP_POINTS	   (unsigned char) 0x73 //Fry's VIP
#define  TRANS_INFO_EFT_NOMAD_BUDGET   (unsigned char) 0x74 //EFT_NOMAD
#define  TRANS_INFO_EFT_NOMAD_CHEQUE   (unsigned char) 0x75 //EFT_NOMAD
#define  TRANS_INFO_EFT_NOMAD_TRX_KEY (unsigned char) 0x76 //EFT_NOMAD
#define  TRANS_INFO_SCANPOS_SAVE_RPRT  (unsigned char) 0x77 //SCANPOINT 
#define  TRANS_INFO_SAVED_TICKET			(unsigned char) 0x78 
#define  TRANS_INFO_SMART_CARD_COUPON  (unsigned char) 0x79 //Electronic Smart Card coupon
#define  TRANS_INFO_SMART_TV_CARD_DATA (unsigned char) 0x7A	//SmartTV card 
#define  TRANS_INFO_GIFT_CARD_ACTIVATION (unsigned char) 0x7B //activation of gift card
#define TRANS_INFO_SMART_CARD_COUPON_EXT (unsigned char) 0x7C //Electronic 
#define  TRANS_INFO_RTN_VOUCHER		   (unsigned char) 0x7D //ROW return voucher
#define  TRANS_INFO_INV_PMT            (unsigned char) 0x7E //ROW invoice payment
#define  TRANS_INFO_CHARGE_PAYM		   (unsigned char) 0x7F //ROW:SALE_PROC: ACCT_PAYM_ALL_TENDER
#define  TRANS_INFO_EFT_FIN_REQ1       (unsigned char) 0x80 //EFT_FIN; Finland
#define  TRANS_INFO_EFT_FIN_REQ2       (unsigned char) 0x81 //EFT_FIN; Finland
#define  TRANS_INFO_EFT_FIN_RESP1      (unsigned char) 0x82 //EFT_FIN; Finland
#define  TRANS_INFO_EFT_FIN_RESP2      (unsigned char) 0x83 //EFT_FIN; Finland
#define  TRANS_INFO_MATTHEW_TRIGGER	   (unsigned char) 0x84	//TESCO
#define  TRANS_INFO_CC_OLA_MSG         (unsigned char) 0x85	//TESCO
#define  TRANS_INFO_FURNITURE_ITEM     (unsigned char) 0x86	
#define  TRANS_INFO_PROM_COUPON_REQ    (unsigned char) 0x87 //PROM_CPN_REQ
#define  TRANS_INFO_OLA_DAY_TOTALS     (unsigned char) 0x88 //TESCO
#define  TRANS_INFO_PUMP_TOTALS        (unsigned char) 0x89 //TESCO
#define  TRANS_INFO_MSG5_PLU           (unsigned char) 0x8A //CR8_BIGY
#define  TRANS_INFO_CLUBCARD_OLA	   (unsigned char) 0x8B	//UKII 
#define  TRANS_INFO_CASH_WITHDRAW_EFT  (unsigned char) 0x8C //EFT_FIN_CASH_DRAW
#define  TRANS_INFO_DELIVERY_CHARGES   (unsigned char) 0x8D //ROW: Delivery charges
#define  TRANS_INFO_SEGMENT			   (unsigned char) 0x8E //Segment update trs
#define	 TRANS_INFO_CHIP_CARD_INFO	   (unsigned char) 0x8F //Chip card info trs
#define  TRANS_INFO_CHECKSUM           (unsigned char) 0x90 //TESCO
#define	 TRANS_INFO_ROA	               (unsigned char) 0x91 
#define  TRANS_INFO_CARD_DEPOSIT       (unsigned char) 0x92 //TESCO
#define  TRANS_INFO_TICKET_TIMES       (unsigned char) 0x93 //Cssc 
#define  TRANS_INFO_TICKET_EXCEPTIONS  (unsigned char) 0x94 //Cssc 
#define  TRANS_INFO_EFT_NOMAD_PRN_SLP2 (unsigned char) 0x95 //CLICKS_EFT_SLIP
#define  TRANS_INFO_EFT_NOMAD_PRN_SLP3 (unsigned char) 0x96 //CLICKS_EFT_SLIP
#define  TRANS_INFO_PUMP_POST_DEC	   (unsigned char) 0x97
#define  TRANS_INFO_PUMP_PRICE_ID      (unsigned char) 0x98
#define	 TRANS_INFO_CHIP_CARD_MSG_HANDLE  (unsigned char) 0x99 //Chip card trs after msg handle
#define  TRANS_INFO_SC_CVM_LIST        (unsigned char) 0x9A // EFT CVM_LIST from Smart Switch, Cardholder Verification Method (CVM) List (ICC tag '8E').
#define  TRANS_INFO_SC_SCRIPT_RESULTS  (unsigned char) 0x9B // EFT SCRIPT_RESULTS from Smart Switch, Issuer Script Results.
#define  TRANS_INFO_SC_ICC_EXT		   (unsigned char) 0x9C // EFT Extra ICC data of the application.
#define  TRANS_INFO_AUTH_VIA_AUTH_GATEWAY (unsigned char) 0x9D //KarenP @cr1256 appendix c2, Authorize Via Auth Gateway
#define  TRANS_INFO_SMART_VOUCH_CPN_REC	 (unsigned char) 0x9E //KarenP @cr1256 appendix c3, SmartVoucher Coupon Record
#define  TRANS_INFO_INV_REPRINT        (unsigned char) 0x9F // Invoice re-print 
#define  TRANS_INFO_EJ_BAD_ACCOUNT     (unsigned char) 0xA0 // EJ Info transaction
#define  TRANS_INFO_EJ_PRICE_INQUERY   (unsigned char) 0xA1 // EJ Info transaction  
#define  TRANS_INFO_EJ_CONTROL_CHECK   (unsigned char) 0xA2 // EJ Info transaction 
#define  TRANS_INFO_EJ_AGE_ID          (unsigned char) 0xA3 // EJ Info transaction  
#define  TRANS_INFO_ITEM_ON_SALE       (unsigned char) 0xA4 // AddLoss report
#define  TRANS_INFO_TANK_READ_HEADER   (unsigned char) 0xA5 //WINPOS GARAGE NT
#define  TRANS_INFO_TANK_READING	   (unsigned char) 0xA6 //WINPOS GARAGE NT
#define  TRANS_INFO_PUMP_READ_HEADER   (unsigned char) 0xA7 //WINPOS GARAGE NT
#define  TRANS_INFO_PUMP_READING	   (unsigned char) 0xA8 //WINPOS GARAGE NT
#define  TRANS_INFO_DELIVER_READ_HEADER (unsigned char) 0xA9 //WINPOS GARAGE NT
#define  TRANS_INFO_DELIVER_READING	   (unsigned char) 0xAA //WINPOS GARAGE NT
#define  TRANS_INFO_ALARM_READ_HEADER  (unsigned char) 0xAB //WINPOS GARAGE NT
#define  TRANS_INFO_ALARM_READING	   (unsigned char) 0xAC //WINPOS GARAGE NT
#define  TRANS_INFO_TANK_CONFIG_HEADER (unsigned char) 0xAD //WINPOS GARAGE NT
#define  TRANS_INFO_TANK_CONFIG_READING (unsigned char) 0xAE //WINPOS GARAGE NT
#define  TRANS_INFO_PUMP_CONFIG_HEADER (unsigned char) 0xAF //WINPOS GARAGE NT
#define  TRANS_INFO_PUMP_CONFIG_READING (unsigned char) 0xB0 //WINPOS GARAGE NT
#define  TRANS_INFO_SUNDRY_PRICE			  (unsigned char) 0xB1 //ROW
#define  TRANS_INFO_GRID_PRICE			  (unsigned char) 0xB2 //ROW
#define  TRANS_INFO_CALC_PRICE			  (unsigned char) 0xB3 //ROW
#define  TRANS_INFO_ITEM_DATA_CAPTURE    (unsigned char) 0xB4 //TESCO 
#define  TRANS_INFO_PRICELINE_ABN        (unsigned char) 0xB5 //PrLn_CRQ3 - Australia
#define  TRANS_INFO_STAFF_CARD           (unsigned char) 0xB6 // SWAN 
#define  TRANS_INFO_ITEM_DATA_RECALL     (unsigned char) 0xB7 //TESCO
#define  TRANS_INFO_MANUAL_CASH_OFF      (unsigned char) 0xB8 //Used by Front Office
#define  TRANS_INFO_OEM_POINTS		     (unsigned char) 0xB9 //USA Developmet - OEM points information.
#define  TRANS_INFO_ITEM_SALESMAN        (unsigned char) 0xBA // ROW
#define  TRANS_INFO_TRS_SALESMAN        (unsigned char) 0xBB // ROW
#define  TRANS_INFO_CUST_AT_SOT  		  (unsigned char) 0xBC //ROW
#define  TRANS_INFO_GIFT_BASKET			  (unsigned char) 0xBD //ROW
#define  TRANS_INFO_HANDLE_NMD		     (unsigned char) 0xBE //EFT_NMD_CLICKS
#define  TRANS_INFO_PRN_NMD				  (unsigned char) 0xBF //EFT_NMD_CLICKS
#define	 TRANS_INFO_LOYALTY_MSG			  (unsigned char) 0xC0
#define	 TRANS_INFO_LOYALTY_CUSTOMER	  (unsigned char) 0xC1
#define  TRANS_INFO_EFT_DATA			(unsigned char) 0xC2  // include sessionid & track2
#define	 TRANS_INFO_ADD_CRED_LIM_CUST   (unsigned char) 0xC3 //ROW:Metro:additional credit/check limit amount added by Superv.(for example)
#define  TRANS_INFO_CLUBCARD_DETAILS	(unsigned char) 0xC4
#define  TRANS_INFO_EXTERNAL_CHARGE_PAYMENT (unsigned char) 0xC5
#define	 TRANS_INFO_SELF_SCANNING			(unsigned char) 0xC6
#define	 TRANS_INFO_INVOICE_RECALL			(unsigned char) 0xC7
#define  TRANS_INFO_PRN_NMD_CLCKS		    (unsigned char) 0xC8 //V7:EFT printout_CLICKS
#define  TRANS_INFO_LANG_SELECT 		    (unsigned char) 0xC9 //Multi-Language
#define  TRANS_INFO_EFT_SVR					(unsigned char) 0xCA //v7: EFT supervisor menu 
#define  TRANS_INFO_NON_MRC					(unsigned char) 0xCB // Informormation about a non-merchendise item
#define	 TRANS_INFO_LOYALTY_MAIL			(unsigned char) 0xCC // Loyaly promotional mail 
#define  TRANS_INFO_EXCL_PRICE              (unsigned char) 0xCD // Exclude pricing 
#define  TRANS_INFO_SUPPLEMENTAL_DATA       (unsigned char) 0xCE // Barcode programming
#define  TRANS_INFO_BARCODE_PROG            (unsigned char) 0xCF // Barcode programming
#define  TRANS_INFO_INVOICE_REQUEST         (unsigned char) 0xD0 // Invoice Printing Request
#define  TRANS_INFO_OEM_SEC_ID_OPT_IN		(unsigned char) 0xD1 // OEM SECONDARY OPT-IN
#define  TRANS_INFO_CREATE_CLUBCARD			(unsigned char) 0xD2 // Create loyalty clubcard trs
#define  TRANS_INFO_COUPON_REDEMPTION		(unsigned char) 0xD3
#define  TRANS_INFO_BELGACOM         		(unsigned char) 0xD4 //Belgacom
#define  TRANS_INFO_ONL_SCRIPT_SALE         (unsigned char) 0xD5 //ROW
#define  TRANS_INFO_SCRIPT_PAYMENT          (unsigned char) 0xD6 //ROW  
#define  TRANS_INFO_POINTS_EXT              (unsigned char) 0xD7 //Points Tx extention
#define  TRANS_INFO_PHONE_CARD_ACTIVATION	(unsigned char) 0xD8 //Enh #9749 PHONE_CARD Hannaford AmyG
#define  TRANS_INFO_BARCODE_DETAILS     	(unsigned char) 0xD9 //Barcode Programming Transaction
#define  TRANS_INFO_TICKET_POINTS           (unsigned char) 0xDA //Ticket Points
#define  TRANS_INFO_SERVICE_DESK_VCHRS      (unsigned char) 0xDB //cust request points voucher.(bon avior).
#define  TRANS_INFO_SIGCAP				    (unsigned char) 0xDC //HF #10812 Signature Capture AmyG
#define  TRANS_INFO_ORDER_NUMBER            (unsigned char) 0xDD
#define  TRANS_INFO_PRICE_LIST              (unsigned char) 0xDE
#define  TRANS_INFO_CUST_ACCT_ID            (unsigned char) 0xDF  //FS1081
#define  TRANS_INFO_CUST_ORDER_STATUS       (unsigned char) 0xE0 //Customer orders CR#00014
#define  TRANS_INFO_FUEL_DISC_CPN			(unsigned char) 0xE1 //Ver.734 & 736(DOS)
#define  TRANS_INFO_CAR_WASH				(unsigned char) 0xE2 // CR #12797 - Car Wash
#define  TRANS_INFO_STOCK_MODE              (unsigned char) 0xE3 //TESCO 
#define  TRANS_INFO_RECONCILE_MODE          (unsigned char) 0xE4 //TESCO
#define  TRANS_INFO_CUST_ACCT_TENDERING     (unsigned char) 0xE5 ////FS1081 customer account - charge/payment/reversal.
#define  TRANS_INFO_BARCODE_COUPON		    (unsigned char) 0xE6 ////FS1094
#define  TRANS_INFO_OFFLINE_EFT				(unsigned char) 0xE7 //CR #13271 - used for the USA EFT. 
#define  TRANS_INFO_POS_REPORT				(unsigned char) 0xE8 //FS1085
#define  TRANS_INFO_SUNDRY_EXT2 		    (unsigned char) 0xE9 //ROW 
#define  TRANS_INFO_ROLLTAINER_ITEM         (unsigned char) 0xEA //ROW 
#define  TRANS_INFO_INV_HEADER				(unsigned char) 0xEB //FS1088
#define  TRANS_INFO_DOCUMENT_SEQ		    (unsigned char) 0xEC //FS1088
#define  TRANS_INFO_REASON_CODE             (unsigned char) 0xED //FS1115
#ifdef PRJ_ROW
#define	 TRANS_INFO_TRADE_PROM_CALC			(unsigned char) 0xEE
#else
#define  TRANS_INFO_REDUCE_TAX_SCHEME       (unsigned char) 0xEE //FS1117
#endif
#define  TRANS_INFO_CONFIRMED_PROMOTION		(unsigned char) 0xEF //OW enh #15155 - Redeemable promotions
#define  TRANS_INFO_CUST_CENTER     		(unsigned char) 0xF0 //FS1126 - customer center info transaction.
#define  TRANS_INFO_CUST_ADDRESS     		(unsigned char) 0xF1 //FS1126 - customer address info transaction.
#define  TRANS_INFO_TNDR_DATA        		(unsigned char) 0xF2 //FS1081 - Tender additional data - for cheques.
#define  TRANS_INFO_ONLINE_PURCHASE_ITEM    (unsigned char) 0xF3 //FS15934
#define  TRANS_INFO_MEMBER_NAME			    (unsigned char) 0xF4 //CR16987
#define  TRANS_INFO_NSC_CPN_VALIDATION		(unsigned char) 0xF5 //SL1406
#define  TRANS_INFO_ORDER_PROM_APPORT       (unsigned char) 0xF6 //FS18285
#define  TRANS_INFO_STORENEXT				(unsigned char) 0xF7 //Issue #2478SL AmyG
#define  TRANS_INFO_FORM					(unsigned char) 0xF8 //FS19041
#define  TRANS_INFO_TARE					(unsigned char) 0xF9 //enh iss #1905

#define  TRANS_INFO_BILL_PAYMENT            (unsigned char) 0xFA //CR #22761 
#define  TRANS_INFO_SCANNED_IMAGES			(unsigned char)	0xFA //Issue #2385SL ROW

#define  TRANS_INFO_LAY_BY                  (unsigned char) 0xFB //FS19171

#define  TRANS_INFO_ONL_LAY_BY              (unsigned char) 0xFC //FS19171 
#define  TRANS_INFO_GIFT_CARD_ACTIVATION_EXT (unsigned char) 0xFD //Issue #2711SL
#define  TRANS_INFO_EFT_DECLINE				(unsigned char) 0xFE
#define  TRANS_INFO_DENOMINATION			(unsigned char) 0xFF //FS18338


// "Info OLA" transactions (0x60 0x28) "sub function" list :
#define  TRANS_INFO_OLA_RESULT			(unsigned char) 0x00
#define  TRANS_INFO_OLA_REQ				(unsigned char) 0x01
#define  TRANS_INFO_OLA_ACK				(unsigned char) 0x02
#define  TRANS_INFO_OLA_ANS				(unsigned char) 0x03
#define  TRANS_INFO_OLA_FREE			(unsigned char) 0x04
#define  TRANS_INFO_OLA_RESULT_EXT		(unsigned char) 0x05
#define  TRANS_INFO_OLA_PRINTING		(unsigned char) 0x06
#define	 TRANS_INFO_OLA_REFFERAL_SAVE	(unsigned char) 0x07
#define	 TRANS_INFO_OLA_TRANS_REF		(unsigned char) 0x08
#define  TRANS_INFO_OLA_CC_REQ			(unsigned char) 0x11
#define  TRANS_INFO_OLA_CC_ANS_STRT		(unsigned char) 0x12
#define  TRANS_INFO_OLA_CC_ANS_CONT		(unsigned char) 0x13
#define  TRANS_INFO_OLA_CC_EOT			(unsigned char) 0x14
#define  TRANS_INFO_OLA_HUNGARY_RESULT	(unsigned char) 0x30
#define  TRANS_INFO_OLA_HUNGARY_REQ		(unsigned char) 0x31
#define  TRANS_INFO_OLA_EPAY_ANS        (unsigned char) 0x32 
#define  TRANS_INFO_OLA_EPAY_ANS_EXT    (unsigned char) 0x33
#define  TRANS_INFO_OLA_GIFT_CARD_ANS   (unsigned char) 0x34
#define  TRANS_INFO_OLA_BILL_PAY_ANS	(unsigned char) 0x35
#define  TRANS_INFO_OLA_GUID			(unsigned char) 0x36 //CR#6387
#define  TRANS_INFO_OLA_GIFT_CARD_ADDINF (unsigned char) 0x37 //FSD29721: 0X60;0X28; 0X37
#define	 TRANS_INFO_OLA_TRANS_ID		(unsigned char) 0x38 //#2888
#define	 TRANS_INFO_OLA_ACTIVATION_CODE	(unsigned char) 0x39 //FSD61084
#define  TRANS_INFO_EXT_SERIAL			(unsigned char) 0x42 //N#6755
#define  TRANS_INFO_EXT_PINNUMBER		(unsigned char) 0x43 //N#6546, CR#3037
#define  TRANS_INFO_OLA_RESULT_EXT2		(unsigned char) 0x44 //FS5721
#define  TRANS_INFO_EXT_IDENTIFY_NUMBER	(unsigned char) 0x45 //FS3012
#define  TRANS_INFO_OLA_LOYALTY_ANS		(unsigned char) 0x46 //FSD11780
#define  TRANS_INFO_OLA_EPAY_ANS_EXT2   (unsigned char) 0x47 //FSD28793
#define  TRANS_INFO_EXT_UNIQ_ID			(unsigned char) 0x48 //FSD26804
#define  TRANS_INFO_OLA_PAYMENT_CARD_ANS (unsigned char) 0x49 //IC Card
#define  TRANS_INFO_OLA_PCIDSS_HASHED_PAN (unsigned char) 0x4A	//PCIDSS HashedPan FSD34954
#define  TRANS_INFO_OLA_EFT_DEVICES_PROBE (unsigned char) 0x4B//FSD 57796 - EFT devices probe transaction
#define  TRANS_INFO_OLA_CARD_DATA         (unsigned char)0x4C
#define  TRANS_INFO_OLA_GIFT_CARD_ANS_EXT   (unsigned char) 0x4D

#define  TRANS_INFO_OLA_ABORT			(unsigned char) 0x99
#define  TRANS_INFO_OLA_AIRTIME_EXT0    (unsigned char) 0xA0 //FSD7148  N#16820
#define  TRANS_INFO_OLA_AIRTIME_EXT1    (unsigned char) 0xA1 //FSD7148  N#16821
#define  TRANS_INFO_OLA_3D_CARD_AUTH    (unsigned char) 0xA2 //FSD23009
#define  TRANS_INFO_OLA_3D_SECURE_DATA  (unsigned char) 0xA3 //FSD23009
#define  TRANS_INFO_OLA_3D_CERT_DETAILS (unsigned char) 0xA4 //FSD23009
#define  TRANS_INFO_OLA_DEBT_DATA       (unsigned char) 0xA5 //FSD61185
#define  TRANS_INFO_OLA_DEBT_DATA_EXT   (unsigned char) 0xA6 //FSD61185
#define  TRANS_INFO_OLA_ERROR		    (unsigned char) 0xA7
#define  TRANS_INFO_OLA_DEBT_DATA_EXT2   (unsigned char) 0xA8 //BUG#247732

// Chipcard sub types
#define	 TRANS_INFO_CHIP_MSG			(unsigned char) 0x00
#define	 TRANS_INFO_CHIP_ERROR_REASON	(unsigned char) 0x01

//FSD 61034 - sub functions for fuel info
#define  TRANS_INFO_DELIVER_READING_EXT	   (unsigned char) 0x01 //WINPOS GARAGE NT  

/*FSD6814 Sub-functions for Extract details 0x43 info2 transaction */
#define TRANS_OPCODE_HEADER_DETAILS        0x00  
#define TRANS_OPCODE_TITLE_DETAILS         0x01   
#define TRANS_OPCODE_LINE_DETAILS          0x02
#define TRANS_OPCODE_TENDER_DETAILS        0x03
#define TRANS_OPCODE_TAX_DETAILS           0x04
#define TRANS_OPCODE_TOTAL_DETAILS         0x05
#define TRANS_OPCODE_CUST_DISCOUNT_DETAILS 0x06

//New Opcode for INFO transactions!
#define  TRANS_INFO2                    (unsigned char) 0x70

#define  TRANS_INFO_MANUALLY_SETTLEMENT		(unsigned char) 0x01 //Woolworths
#define  TRANS_INFO_POS_SEQ         		(unsigned char) 0x02 //FS18339
#define  TRANS_INFO_NONFND_DEP_SALE		    (unsigned char) 0x03 //FS21409 7003 same struct as 6001
#define  TRANS_INFO2_EXTRA_CODE				(unsigned char) 0x03 //FSD245239
#define  TRANS_INFO_EXTRA_PLU_DATA         	(unsigned char) 0x04 //FS20126
#define  TRANS_INFO_PARCEL         		    (unsigned char) 0x05 //FS18343
#define  TRANS_INFO_CHARGE_DATA    		    (unsigned char) 0x06 //FS18343 - data for parcel pickup and delivery charge.
#define  TRANS_INFO2_RSS_DATA1    		    (unsigned char) 0x07 //3122SL - RSS 14 Barcode data
#define  TRANS_INFO2_RSS_DATA2    		    (unsigned char) 0x08 //3122SL - RSS 14 Barcode data
#define  TRANS_INFO2_CASH_LIFT				(unsigned char) 0x09 //FS21416
#define  TRANS_INFO2_EOD_MEDIA_TOTALS		(unsigned char) 0x0A //Saved for Tesco Use
#define  TRANS_INFO2_EOD_TILL_TOTALS		(unsigned char) 0x0B //Saved for Tesco Use
#define  TRANS_INFO2_MOBILIME_DATA			(unsigned char) 0x0C //Issue #4293SN
#define  TRANS_INFO2_MOBILIME_COMMENTS		(unsigned char) 0x0D //Issue #4293SN
#define  TRANS_INFO2_VENSAFE_SALE_PARAMS	(unsigned char) 0x0E //FS22935
#define  TRANS_INFO2_ARCHIVE_INVOICE  		(unsigned char) 0x0F //FS1870
#define  TRANS_INFO2_ECCA			        (unsigned char) 0x10 //#955
#define	 TRANS_INFO2_FS_ELIGIBLE_CPN		(unsigned char) 0x11 //Enh #4632SL
#define	 TRANS_INFO2_ZIPPED_TEXT			(unsigned char) 0x12
#define	 TRANS_INFO2_FUND_RAISING			(unsigned char) 0x13 //Enh #5768SL
#define  TRANS_INFO2_RETRIEVE_INVOICE	    (unsigned char) 0x14 //FS1870
#define  TRANS_INFO2_MISC_TRS_STATUS	    (unsigned char) 0x15 //miscellanous TRS info (see 0xd1)
#define  TRANS_INFO2_DEL_LAYBY_CUST			(unsigned char) 0x16 // delete layby customer record 
#define	 TRANS_INFO2_FUEL_VOUCHER_ISSUED	(unsigned char) 0x17 //Enh #5413SN 
#define	 TRANS_INFO2_LAYBY_CALCTAX			(unsigned char) 0x17 //lay-by calculated tax (Priceline). Conflicts with TRANS_INFO2_FUEL_VOUCHER_ISSUED
#define	 TRANS_INFO2_QBUSTER				(unsigned char) 0x18 //ROW QBuster cr#2820
#define  TRANS_INFO2_E_PURSE_REQ		    (unsigned char) 0x19 //KarenP TESCO @cr1256 
#define  TRANS_INFO2_FISCAL_TOTALS_DIFF	    (unsigned char) 0x1A //Enh # 7503SL - Latin America Dev
#define  TRANS_INFO2_QSR				    (unsigned char) 0x1B // SL Issue #7737/Enh #7737 [RandyB]
#define  TRANS_INFO2_MICR_DATA			    (unsigned char) 0x1C // SL Issue #7934/Enh #7934 [ElinaN]
#define  TRANS_INFO2_CCMS_TIMESTAMP			(unsigned char) 0x1D // SL Issue #7962/Enh #7962 [FeliciaT]
#define  TRANS_INFO2_INIT_LOYALTY_CARD		(unsigned char) 0x1E //FSD6795
#define	 TRANS_INFO2_DELYAED_FISCAL_PROM_LINE (unsigned char) 0x1F //FSD8152
#define	 TRANS_INFO2_TAX_VOUCHER			(unsigned char) 0x20 //FS3345
#define  TRANS_INFO2_REDEEM_VOUCHER         (unsigned char) 0x21 //CR4005
#define	 TRANS_INFO2_UNIQUE_COUNTERS		(unsigned char) 0x22 //FS3345
#define  TRANS_INFO2_E_PURSE_REQ_RESLT	    (unsigned char) 0x23 //KarenP TESCO @cr1256
#define	 TRANS_INFO2_INTERIM_USE			(unsigned char) 0x24 //FS3352 
#define	 TRANS_INFO2_GROSS_SUBTOTAL			(unsigned char) 0x25 //FSD3583 
#define  TRANS_INFO2_BILL_PAYMENT           (unsigned char) 0x26 //FS4002
#define  TRANS_INFO_MANUALLY_SETTLEMENT_EXT (unsigned char) 0x27 //FSD1798
#define	 TRANS_INFO2_BULK_GIFTCARD_SALE		(unsigned char) 0x28 //FSD1798 GIFT CARD BULK SALE
#define	 TRANS_INFO2_GIFTCARD_ENQUIRY		(unsigned char) 0x29 //FSD1798 GIFT CARD BALANCE ENQUIRY
#define	 TRANS_INFO_MSG5_PLU_EXT2			(unsigned char) 0x2A //CR#6910
#define  TRANS_INFO2_PARKING_CARD           (unsigned char) 0x2B //FSD10526 Parking Card
#define  TRANS_INFO2_NON_EFT_POST_VOID      (unsigned char) 0x2C //FSD11456
#define	 TRANS_INFO2_GIFT_VOUCH_ACC_CONVERSION	(unsigned char) 0x2D //FSD7148_OfflineGiftVouch
#define	 TRANS_INFO2_LAYBY_MESSAGE			(unsigned char) 0x2E //FSD6248 LayBy
#define	 TRANS_INFO2_TWO_PO					(unsigned char) 0x2F //FSD10094 - 2 Person Operation
#define  TRANS_INFO2_FISCAL_EOD			    (unsigned char) 0x30 //FS3742
#define	 TRANS_INFO2_LOCAL_BARCODE_ISSUED	(unsigned char) 0x31 //FS3582
#define  TRANS_INFO2_MEMBER_ACCOUNT         (unsigned char) 0x32 //FS3649 
#define  TRANS_INFO2_TICKET_TYPE            (unsigned char) 0x33 //FS1333  Defines the type of the ticket .
#define  TRANS_INFO2_LAYBY_FINANCIAL        (unsigned char) 0x34 //FS1333  reports the amount of layby financial entities.
#define  TRANS_INFO2_GIFTCARD_ACTIVATE      (unsigned char) 0x35 //FSD1798  Gift card activation process.
#define  TRANS_INFO2_ZIPCODE				(unsigned char) 0x36 //FSD4930  Zip Code 
#define  TRANS_INFO2_HOST_CLUB_DATA			(unsigned char) 0x37 //Issue #7350SL
#define  TRANS_INFO2_SEPS_SNF_DATA			(unsigned char) 0x38 //Issue #6426SN
#define  TRANS_INFO2_EXT_CUST_INFO			(unsigned char) 0x39 //FSD6785 Customer data extended transaction 
#define  TRANS_INFO2_POST_VOID_INDEX        (unsigned char) 0x3A //FSD9306
#define  TRANS_INFO2_END_OF_TICKET_APPORTMNT   (unsigned char) 0x3B //Work around for version 8710 .
#define  TRANS_INFO2_RESELL_POST_VOID_INFO   (unsigned char) 0x3C //FSD9306  
#define  TRANS_INFO2_GEN_SEGMENT_INFO       (unsigned char) 0x3D //FSD8152  
#define  TRANS_INFO2_ISSUE_NUMBER_ALLOC_REQUEST (unsigned char) 0x3E //FSD12841 , Requesting ranges of unique issue nubmer. 
#define  TRANS_INFO2_TICKET_TAX				(unsigned char) 0x3F //20789, ticket tax information in the middle of the ticket
#define  TRANS_INFO2_CHEQUE_VERIF_DATA		(unsigned char) 0x40 //FSD6785 Cheque Verification data
#define  TRANS_INFO2_LOYALTY_TRANSMISSION_POINTER (unsigned char) 0x41 //FS3585 Informs the FO about the 9220 messages status .
#define  TRANS_INFO2_ADDITION_TRS_TICKET_TOTAL	(unsigned char) 0x42 //FSD2733
#define  TRANS_INFO2_EXTRACT_DETAILS        (unsigned char) 0x43  //FSD6814
#define  TRANS_INFO2_POS_REPORT_BN          (unsigned char)	0x44//FSD2733
#define  TRANS_INFO2_EXT_LOYALTY_REWARD     (unsigned char)	0x45//FSD3585	
#define  TRANS_INFO_MSG5_PLU_EXT			(unsigned char) 0x46 //CR#6910
#define  TRANS_INFO2_ITEM_ADDITIONAL_INFO	(unsigned char)	0x47//FSD6248	
#define  TRANS_INFO2_UNIQUE_SEQ_ID			(unsigned char)	0x48//FSD7345		
#define  TRANS_INFO2_PLU_EMB_PRICE			(unsigned char)	0x49 //CR#9244
#define  TRANS_INFO2_LAYBY_ACC_DETAIL		(unsigned char) 0x4A//FSD6248		
#define  TRANS_INFO2_PHONE_CARD_EXT			(unsigned char) 0x4B //Issue #8532SL
#define  TRANS_INFO2_PREPAID_WIRELESS		(unsigned char) 0x4C //Issue #8532SL
#define  TRANS_INFO2_PREPAID_WIRELESS_EXT	(unsigned char) 0x4D //Issue #8532SL
#define  TRANS_INFO2_PREPAID_WIRELESS_EXT2	(unsigned char) 0x4E //Issue #8532SL
#define  TRANS_INFO2_SCALE_CHECK			(unsigned char) 0x4F //FSD9032
#define  TRANS_INFO2_FISCAL_SUB_TTL			(unsigned char) 0x50 //DR#6625
#define  TRANS_INFO2_ADD_SEGMENT			(unsigned char) 0x51 //#10425
#define  TRANS_INFO2_DECLARTION_LINE		(unsigned char) 0x52 //FS10343
#define  TRANS_INFO2_EFT_SESSION			(unsigned char) 0x53 //(MorA FSD #7610) eft session info transaction (eft session id & type)
#define  TRANS_INFO2_END_TICKET_VOUCHERS	(unsigned char) 0x54 // FSD9034
#define  TRANS_INFO2_TAX_VOUCHER_PRINTED	(unsigned char) 0x55 //CR #11383
#define  TRANS_INFO2_GUID                   (unsigned char) 0x56  //FSD7315  
#define  TRANS_INFO2_PRINT_LINE             (unsigned char) 0x57  //FSD7315
#define  TRANS_INFO2_PRINT_CONFIRM          (unsigned char) 0x58  //FSD7315
#define  TRANS_INFO2_PRINT_FOOTER           (unsigned char) 0x59  //FSD7315
#define  TRANS_INFO2_CONFIRM_EXT_CARD_UPDATED  (unsigned char) 0x5A  //FSD 16852
#define  TRANS_INFO2_FISCAL_SALES			(unsigned char) 0x5B  //Issue #12593SL
#define  TRANS_INFO2_FREEDOM_LANE			(unsigned char) 0x5C  //Issue #13256SL
#define  TRANS_INFO2_BILL_PAYMENT_DATA	 	(unsigned char) 0x5D  //FSD26778 
#define  TRANS_INFO2_PCARD					(unsigned char)0x5E
#define	 TRANS_INFO2_REMAC_RESPONSE			(unsigned char) 0x5F //#50704
#define	 TRANS_INFO2_CANCEL_PROM_APPORTION	(unsigned char) 0x60  //#12818
#define	 TRANS_INFO2_TICKET_START_TIME		(unsigned char) 0x61  //#11256
#define  TRANS_INFO2_BILL_PAYMENT_EXT0		(unsigned char) 0x62   //FSD2615
#define  TRANS_INFO2_BILL_PAYMENT_EXT1		(unsigned char) 0x63  //FSD2615
#define  TRANS_INFO2_BILL_PAYMENT_EXT2      (unsigned char) 0x64  //FSD2615
#define  TRANS_INFO2_BILL_PAYMENT_EXT3      (unsigned char) 0x65  //FSD2615
#define  TRANS_INFO2_BILL_PAYMENT_BILLER_NAME_EXT (unsigned char)0x66 //FSD2615
#define  TRANS_INFO2_BILL_PAYMENT_ACCOUNT_NUMBER_EXT  (unsigned char)0x67 //FSD2615
#define  TRANS_INFO2_BILL_PAYMENT_BARCODE_EXT  (unsigned char)0x68 //FSD2615  
#define  TRANS_INFO2_PROMPT_CASHIER_RESPONSE  (unsigned char) 0x69 //FSD11022
#define  TRANS_INFO2_COMPLEMENTARY_GROUP			(unsigned char) 0x6A //FSD11803
#define  TRANS_INFO2_INDEPENDENT_PRINT_LINE  (unsigned char)0x6B    //FSD7315
#define  TRANS_INFO_CAR_WASH_EXT			(unsigned char)0x6C		//CR#8665
#define  TRANS_INFO2_STOCK_MNG_INFO			(unsigned char) 0x6D //FSD11252
#define	 TRANS_INFO2_PICKUP_BAG			(unsigned char) 0x6E	//FSD 14665
#define	 TRANS_INFO2_EMPLOYEE_CARD			(unsigned char) 0x6F	//FSD13421 - Employee Card
#define  TRANS_INFO2_ENCRYPTED_DATA			(unsigned char) 0x70	// US Enh #9806
#define  TRANS_INFO2_PRINT_ITEM_FOOTER      (unsigned char) 0x71   //FSD7315 
#define	 TRANS_INFO2_FORMS_COLLECTION		(unsigned char)	0x72	//#15639
#define  TRANS_INFO2_BILL_PAYMENT_ADVICE_GUID (unsigned char)0x73  //FSD2615
#define  TRANS_INFO2_BILL_PAYMENT_ADVICE_TENDER  (unsigned char)0x74  //FSD2615
#define  TRANS_INFO2_BILL_PAYMENT_ADVICE_BARCODE (unsigned char)0x75  //FSD2615 
#define	 TRANS_INFO2_LOCAL_BARCODE_ISSUED_EXT	(unsigned char) 0x76 //FSD13078
#define	 TRANS_INFO2_VOUCHER_REWARD_PROM	(unsigned char) 0x77 //FSD14348 
#define  TRANS_INFO2_PICK_UP_TENDER         (unsigned char) 0x78 //FSD3923
#define  TRANS_INFO2_GC_BATCH_HEADER        (unsigned char) 0x79 //Issue #9564SL: Gift Card Batch Activation
#define  TRANS_INFO2_PROMOTION_EXT			(unsigned char) 0x7A //FSD14741
#define  TRANS_INFO2_GC_BATCH_DETAILS		(unsigned char) 0x7B //Issue #9564SL: Gift Card Batch Activation - not used yet
#define  TRANS_INFO2_MMBR_PROM_SCHEMES		(unsigned char) 0x7C //#55079
#define  TRANS_INFO2_REDEEM_MA_ONLINE_QUERY (unsigned char) 0x7D	//FSD56623 - CR62119
#define  TRANS_INFO2_LOG_FUNCTION_TRIGGER   (unsigned char) 0x7E //FSD61079.
#define	 TRANS_INFO2_TICKET_REFERENCE_NUMBER (unsigned char) 0x7F //FSD62787
#define  TRANS_INFO2_CUST_SRV_QUESTION_EXT  (unsigned char) 0x80 // TD#64966
#define  TRANS_INFO2_SUB_RETURN				(unsigned char) 0x81 //Issue #3754SL: Sub-Return functionality - Hannaford
#define  TRANS_INFO2_FISCAL_END_TICKET		(unsigned char) 0x82 //FSD3923 		 
#define  TRANS_INFO2_BARCODE_TO_EJ_DETAILS	(unsigned char) 0x83 //FSD10789
#define  TRANS_INFO2_HEADER_TRIGGER_PROM	(unsigned char) 0x84 //FSD14348  
#define  TRANS_INFO2_CHEQUE_DETAILS			(unsigned char) 0x85 //FSD16187		 
#define  TRANS_INFO2_RX_SALE				(unsigned char) 0x86 //FSD9896SL		
#define  TRANS_INFO2_ITEM_TAX_ADJ			(unsigned char) 0x86 //cr#3376 Priceline. Conflicts with TRANS_INFO2_RX_SALE
#define  TRANS_INFO2_ONLINE_PURCHASE_EXT	(unsigned char) 0x87
#define  TRANS_INFO2_THIRD_PARTY_LOYALTY		(unsigned char)	0x88 //FS18712 Third Party loyalty
#define  TRANS_INFO2_DUMMY_POINTS	        (unsigned char)	0x89 
#define  TRANS_INFO2_THIRD_PARTY_REFUND_DATA	(unsigned char)	0x8A //FSD16060 
#define  TRANS_INFO2_REFUND_ITEM_DATA		(unsigned char)	0x8B //FSD16060
#define  TRANS_INFO2_MEMBER_ACCOUNT_UPDATE (unsigned char)	0x8C //FSD16201
#define  TRANS_INFO2_ATM_DATA              (unsigned char)  0x8D //FSD14667 
#define  TRANS_INFO2_SELF_SCAN_TEXT_LINE	(unsigned char)	0x8E //FSD19186
#define  TRANS_INFO2_SUBITEM				(unsigned char)	0x8F //FSD20957
#define	 TRANS_INFO2_PRICE_UPDATED_AT_POS	(unsigned char) 0x90 //FSD16243
#define	 TRANS_INFO2_PROM_COUPON_REQ_EXT	(unsigned char) 0x91 //FSD18888
#define	 TRANS_INFO2_SPECIAL_TOTALS			(unsigned char) 0x92 //FSD18559
#define	 TRANS_INFO2_PROMOTION_SECTION		(unsigned char) 0x93 //FSD14741
#define	 TRANS_INFO2_SECURITY_NUMBER		(unsigned char) 0x94 //
#define  TRANS_INFO2_TRIGGER_COUNT          (unsigned char) 0x95 //FSD18361
#define  TRANS_INFO2_CONFIRMED_PROMOTION    (unsigned char) 0x96 //FSD16207 #24348
#define  TRANS_INFO2_RSS_DATA3    		    (unsigned char) 0x97 //FSD216989
#define  TRANS_INFO2_RSS_DATA4				(unsigned char) 0x98 //FSD216989
#define  TRANS_INFO2_EBTWIC					(unsigned char) 0x99 //Issue #8897SN
#define	 TRANS_INFO2_DYNAMIC_ATTRIBUTE		(unsigned char) 0x9A //FSD14082
#define  TRANS_INFO2_BARCODE_DISPLAY		(unsigned char) 0x9B //
#define  TRANS_INFO2_GIFT_MULTIPLE_REDEM_RESERVATION 	(unsigned char) 0x9C //FSD16855
#define  TRANS_INFO2_OLA_EXT_3				(unsigned char) 0x9D //YaelB. Support Alpha-Numeric terminal id.
#define  TRANS_INFO2_ORC_PLU_SALES	              (unsigned char) 0x9E //FSD16361
#define  TRANS_INFO2_ORC_COMBINED_PROMO_NET_SALES (unsigned char) 0x9F //FSD16361
#define  TRANS_INFO2_PROMOTION_EXT2         (unsigned char) 0xA0  //FSD16361
#define  TRANS_INFO2_TABLE_NUMBER			(unsigned char) 0xA1 //FSD18936 #26236
#define  TRANS_INFO2_KMS_TRS_MSG			(unsigned char) 0xA2 //FSD18937 #27165
#define  TRANS_INFO2_INVOICE_TAX_CALC		(unsigned char) 0xA3 //MorA
#define  TRANS_INFO2_ORC_REWARD_SPLIT_BY_REDEMPTION_INFO (unsigned char) 0xA4  //FSD16361
#define  TRANS_INFO2_EJ_PROMO_INQUERY       (unsigned char) 0xA5 //FSD16242 EJ Info transaction  
#define  TRANS_INFO2_DATA					(unsigned char) 0xA6	//FSD25302 OR Scheme Enhancement
#define  TRANS_INFO2_CASH_CHANGE_CORRECTION (unsigned char) 0xA7	//FSD16283 Cash Change Calculation
#define  TRANS_INFO2_PHARMACY_ITEM			(unsigned char) 0xA8 //FSD26364
#define  TRANS_INFO2_PHARMACY_ITEM2			(unsigned char) 0xA9 //FSD26364
#define  TRANS_INFO2_POS_SHIFT       	    (unsigned char) 0xAA //Shift_Management in Remote Office
#define  TRANS_INFO2_INGE_VOUCHER			(unsigned char) 0xAB //FSD28462
#define  TRANS_INFO2_CASHIER_DISCOUNT		(unsigned char) 0xAC	//29725
#define  TRANS_INFO2_CUSTOMER_COUNT			(unsigned char) 0xAD	//Bug#29984
#define  TRANS_INFO2_IGNORE					(unsigned char) 0xAE	//FSD24344 - transaction to be ignored
#define  TRANS_INFO2_EXTRA_CARD_INFO		(unsigned char) 0xAF   // FSD#59744
#define  TRANS_INFO2_ORC_REWARD_SPLIT_BY_REDEMPTION_INFO_EXT (unsigned char) 0xB0 //FSD16361
#define  TRANS_INFO2_PPT_GIFT_CARD_EXTRA_DATA	(unsigned char) 0xB1	//FSD22770
#define  TRANS_INFO2_FSA					(unsigned char) 0xB2 //FSD13919SL - FSA
#define  TRANS_INFO2_ALTERNATIVE_PLU_SALE	(unsigned char) 0xB3	//FSD14086	
#define  TRANS_INFO2_EFT_INSERTED_IN_TENDER_MODE	(unsigned char) 0xB4	//FSD27622 
#define  TRANS_INFO2_GENERAL_CARD			(unsigned char) 0xB5	//FSD29692 
#define  TRANS_INFO2_MANUAL_EOD				(unsigned char) 0xB6	//FSD16273
#define  TRANS_INFO2_STATUS  				(unsigned char) 0xB7	//FSD29690 - General transaction to indicated a certain status.
#define  TRANS_INFO2_PARKING_VOUCHER		(unsigned char) 0xB8	//FSD30642

#define  TRANS_INFO2_FUEL					(unsigned char) 0xB9	//FSD26154 sec. 7.4-7.8 - has subfunctions
#define  TRANS_INFO2_FUEL_MODE_CHANGED		(unsigned char) 0x01	//FSD26154 sec. 7.4-7.8 - subfunction of TRANS_INFO2_FUEL

#define  TRANS_INFO2_EMPLOYEE_CORPORATE_NO	(unsigned char) 0xBA	// FSD6916 EmployeeCorporateNumber
#define  TRANS_INFO2_REDEMPTION_SUMMARY		(unsigned char) 0xBB	// #34702 - performance issue
#define  TRANS_INFO2_EFT_EXT_SESSION		(unsigned char) 0xBC	// FSD 29649
#define  TRANS_INFO2_ACCUMULATED_VAT_RETURN	(unsigned char) 0xBD	//FSD28669 Accumulated Vat Return.
#define  TRANS_INFO2_VAT_RETURN_MEDIA	    (unsigned char) 0xBE	//FSD28669 Accumulated Vat Return.

#define  TRANS_INFO2_T7E_EXT				(unsigned char) 0xBF	//Extension sub opcode for TRANS_INFO_T7E
#define  TRANS_INFO2_TAX_LOCATION			(unsigned char) 0xC0	//FSD30255
#define  TRANS_INFO2_SEND_PROM_RESPONSE		(unsigned char) 0xC1	//YaelB Belgium
#define  TRANS_INFO2_MTX_RECEIPTS			(unsigned char) 0xC2	//FSD9797SN
#define  TRANS_INFO2_TICKET_SCHEME          (unsigned char) 0xC3    //FSD36846 
#define  TRANS_INFO2_ONLINE_PURCHASE_EXT2   (unsigned char) 0xC4    //FSD21868 
#define	 TRANS_INFO2_DYNAMIC_ATT_VALUE      (unsigned char) 0xC5    //FSD41496 
//RSCL_BLOCK:START 
#define  TRANS_INFO2_RSCL_LOG_IN			(unsigned char) 0xC6
//RSCL_BLOCK:END
#define  TRANS_INFO2_ONLINE_PURCHASE_EXT3   (unsigned char) 0xC7    //FSD40047

#define	 TRANS_INFO2_ELECTRONIC_VOUCHER		(unsigned char) 0xC8	//FSD42115 Everyday reward card redemption

#define  TRANS_INFO2_SWAP_PAYMENT			(unsigned char) 0xC9	//FSD36846 Swap Payment

#define  TRANS_INFO2_FUEL_DATA				(unsigned char) 0xCA	//FSD36846 Pump data
#define  TRANS_INFO2_LOCATION				(unsigned char) 0xCB	//FSD39882: 
#define  TRANS_INFO2_COPIENT				(unsigned char) 0xCC	// SL US #15253 [RandyB]

// FSD28467 GinatB
#define  TRANS_INFO2_SELF_SCAN_RESCAN_DIFF	(unsigned char) 0xCD

#define  TRANS_INFO2_ETOPUP_ITEM_DATA		(unsigned char) 0xCE	// FSD45606 C4 Wynid ETopUp
#define  TRANS_INFO2_ETOPUP_ITEM_DATA_EXT1 	(unsigned char) 0xCF	// FSD45606 C4 Wynid ETopUp

#define	 TRANS_INFO2_EXTENSION_POS_FORM		(unsigned char) 0xD0	// FSD46343
#define	 TRANS_INFO2_EFT_CASHOUT_ROUNDING	(unsigned char) 0xD1	// FSD42120
#define	 TRANS_INFO2_PLU_DATA				(unsigned char)	0xD2	// FSD42113

//FSD30639
#define	 TRANS_INFO2_RETURN_EXTRA_INFORMATION		(unsigned char) 0xD3	// FSD30639
#define	 TRANS_INFO2_RETURN_VOUCHER_SEQUENCE_NUMBER	(unsigned char)	0xD4	// FSD30639

#define	 TRANS_INFO2_RPC_CC_DEPOSIT					(unsigned char)	0xD5	// FSD48165,FSD28354
#define	 TRANS_INFO2_GIFTCARD_EXTRA_DATA			(unsigned char)	0xD6	//FSD45975
#define  TRANS_INFO2_EMV_ISS_AUTHENTIC_DATA			(unsigned char) 0xD7	//FSD45186 
#define  TRANS_INFO2_PHONE_CARD_EXT2		(unsigned char) 0xD8	//Issue #15446SL
#define  TRANS_INFO2_BALANCE_INQ_EXT		(unsigned char) 0xD9	//Issue #15446SL
#define  TRANS_INFO2_SUPERVISOR_MODE		(unsigned char) 0xDA	// US SL Issue #16303/Enh #16303 [RandyB]
#define  TRANS_INFO2_PICKUP_COUNTER			(unsigned char) 0xDB	//FSD50476
#define	 TRANS_INFO2_MARK_FISCAL_UNSECURED_TRS	   (unsigned char) 0xDC	// FSD40832
#define  TRANS_INFO2_HOME_SHOPPING_DETAILS	(unsigned char) 0xDD	// #50118
#define	 TRANS_INFO2_GIFTCARD_EXT2			(unsigned char) 0xDE	//#16122SL
#define	 TRANS_INFO2_UPDATE_TRANS			(unsigned char) 0xDF
#define  TRANS_INFO2_PLU_SALE_EXT4			(unsigned char) 0xE0    // FSD57241 FSD52741 Ticket Saving Enhancements For Drive-Offs
#define  TRANS_INFO2_OLA_SESSION			(unsigned char) 0xE1	//Generic Services
#define  TRANS_INFO2_HASH_PAN_US			(unsigned char) 0xE2	//Issue #17534SL
#define  TRANS_INFO2_OLA_SUMMARY			(unsigned char) 0xE3    //FSD51561 - esocket for spar  
#define  TRANS_INFO2_OLA_IDENTIFIER_KEY		(unsigned char) 0xE4    //Generic Services
#define  TRANS_INFO2_RECOVERY				(unsigned char) 0xE5	// US SL Generic [RandyB]
#define  TRANS_INFO2_ITEM_RESTRICTED		(unsigned char) 0xE6	//FSD55819 
#define  TRANS_INFO_SELF_SCANNING_EXT		(unsigned char) 0xE7	//FSD52276
#define  TRANS_INFO2_GIFT_RECEIPT			(unsigned char) 0xE8	//FSD55832
#define  TRANS_INFO2_PARENT_RETURN_TYPE		(unsigned char) 0xE9	//FSD52912
#define  TRANS_INFO2_POS_FORM_EXT			(unsigned char) 0xEA	//FSD52912
#define  TRANS_INFO2_CUSTOMER_DETAILS		(unsigned char) 0xEB //FSD54877
#define  TRANS_INFO2_CUSTOMER_DETAILS_EXT	(unsigned char) 0xEC //FSD54877
#define  TRANS_INFO2_FUEL_DELIVERY			(unsigned char) 0XED   //FSD52741
#define  TRANS_INFO2_CLEAN_TRS_CACHE		(unsigned char) 0XEE   //#67438
#define  TRANS_INFO2_FOREIGN_CURRENCY		(unsigned char) 0XEF   //FSD55806
#define  TRANS_INFO2_DATABAR_COUPON			(unsigned char) 0XF0   //Issue #10996SN
#define	 TRANS_LOYALTY_CARD_EXCHANGE		(unsigned char) 0xF1 // FSD57203
#define  TRANS_INFO2_POINTS_EXT				(unsigned char) 0XF2	//FSD44261
#define  TRANS_INFO2_INIT_LOYALTY_CARD_EXT	(unsigned char) 0XF3	//FSD53587
#define  TRANS_INFO2_CASH_VOUCHER			(unsigned char) 0XF4	//FSD58540
#define  TRANS_INFO2_GIFTCARD_EXT3			(unsigned char)	0xF5	//FSD55425
#define  TRANS_INFO2_RX_SALE_EXT			(unsigned char)	0xF6	//SL_US Issue #18249 - PDX Pharmacy [EL1G+TammyE]
#define  TRANS_INFO2_RX_SALE_EXT2			(unsigned char)	0xF7	//SL_US Issue #18249 - PDX Pharmacy [EL1G+TammyE]
#define  TRANS_INFO2_ZREPORT_TOTALS			(unsigned char)	0xF8	//SL_LA Issue #18981 - [BrianStafford]
#define  TRANS_INFO2_DPS_ENCRYPTED_DATA		(unsigned char) 0xF9	// SL US Issue #18272 [RandyB]
#define  TRANS_INFO2_LANEHAWK_CLEAR_ITEM	(unsigned char) 0XFA	//SL_US Issue #17615 [ShlomitG]
#define  TRANS_INFO2_PROMOTION_TAX_INFO		(unsigned char) 0xFB	// SL US Issue #19094 [RandyB]
#define  TRANS_INFO2_INGE_VOUCHER_EXT		(unsigned char) 0xFC	// FSD#59750	
#define	 TRANS_INFO2_OLA_EXTRA_DATA_HEADER	(unsigned char)	0xFD	//Global Transaction
#define	 TRANS_INFO2_OLA_EXTRA_DATA			(unsigned char)	0xFE	//Global Transaction 
#define	 TRANS_INFO2_EMV_CHIP_CARDS			(unsigned char) 0xFF	//FSD52846: Supporting EMV Chip Cards 
// please use free sub opcodes 0x98 for 0x70 

//New Opcode 0x80 for INFO transactions! 
#define  TRANS_INFO3						(unsigned char) 0x80

// -------------------------------------------------------------
// INFO3 transactions
// -------------------------------------------------------------
#define  TRANS_INFO3            			 (unsigned char) 0x80
#define	 TRANS_INFO3_VENDING_SESSION		 (unsigned char) 0x01
#define	 TRANS_INFO3_FUEL_FUNCTION_TRIGGER	 (unsigned char) 0x02 // FSD58646 Manual mode changing
#define	 TRANS_INFO3_ONLINE_PURCHASE_EXT	 (unsigned char) 0x03 // FSD61084 
#define  TRANS_INFO3_PURCHASE_ORDER_NUM		 (unsigned char) 0x04
#define  TRANS_INFO3_FISCAL_ITEM_SALE_ERROR  (unsigned char) 0x05 // FSD67680
#define  TRANS_INFO3_CLUBCARD_DETAILS_EXT    (unsigned char) 0x06 // TD#53437
#define  TRANS_INFO3_LOAD_BARCODE_TO_DB		 (unsigned char) 0x07 // FSD67534
#define  TRANS_INFO3_ANPR_DATA				 (unsigned char) 0x08 // FSD58656
#define  TRANS_INFO3_CHANGED_WORKING_DATE	 (unsigned char) 0x09
#define  TRANS_INFO3_BARCODE_DETAILS_EXT	 (unsigned char) 0x0A // FSD64199
#define  TRANS_INFO3_DATABAR				 (unsigned char) 0x0B // FSD28013
#define  TRANS_INFO3_VOUCHER_DETAILS_EXT	 (unsigned char) 0x0C // FSD66628
#define  TRANS_INFO3_OCTOPUS_DETAILS		 (unsigned char) 0x0D // FSD55426
#define  TRANS_INFO3_ONLINE_PURCH_ITEM_EXT	 (unsigned char) 0x0E // FSD67194
#define  TRANS_INFO3_DOCUMENT				 (unsigned char) 0x0F // FSD70780
#define  TRANS_INFO3_SCOT_FORCE_WEIGHT					(unsigned char) 0x10
#define  TRANS_INFO3_SCOT_SECURITY_WEIGHT_VIOLATION		(unsigned char) 0x11
#define  TRANS_INFO3_SCOT_SECURITY_WEIGHT_LEARNING		(unsigned char) 0x12
#define  TRANS_INFO3_RSCL_INTERVENTION_REPORT			(unsigned char) 0x13
#define  TRANS_INFO3_ONLINE_REWARD_MESSAGE_ID		(unsigned char) 0x14 // FSD#85881
#define  TRANS_INFO3_ONLINE_REWARD_PROMOTION_DATA	(unsigned char) 0x15 // FSD#85881
#define  TRANS_INFO3_ONLINE_REWARD_REDEMPTION_DATA	(unsigned char) 0x16 // FSD#85881
#define  TRANS_INFO3_ONLINE_REWARD_GUID				(unsigned char) 0x17 // FSD#85881
#define  TRANS_INFO3_ONLINE_REWARD_PRINT_LINE		(unsigned char) 0x18 // FSD#85881
#define  TRANS_INFO3_NON_PAYMENT_TRANSACTION        (unsigned char) 0x19 // FSD61185
#define  TRANS_INFO3_OLA_SESSION_EXT				(unsigned char) 0x1A 
#define  TRANS_INFO3_SELF_SCAN_SUMMARY				(unsigned char) 0x1B  //FSD95450
#define  TRANS_INFO3_GENERIC_CARD 			        (unsigned char) 0x1C // FSD61180 
#define  TRANS_INFO3_EXTERNAL_VOUCHER 			    (unsigned char) 0x1D // FSD61180
#define  TRANS_INFO3_ONLINE_REWARD_IMAGE			(unsigned char) 0x1E // FSD#85881
#define  TRANS_INFO3_PRINT_POINT_PROMO				(unsigned char) 0x1F // CR#97195
#define  TRANS_INFO3_PROM_TOTALS					(unsigned char) 0x20 // #107813
#define  TRANS_INFO3_SESSION_PRINT_DATA             (unsigned char) 0x21 // FSD61180
#define	 TRANS_INFO3_INGE_VOUCHER_EXT2				(unsigned char) 0x22 // TD#116482
#define	 TRANS_INFO3_EFT_STATUS						(unsigned char) 0x23 // FSD93620: PCI Interface Change
#define  TRANS_INFO3_REMOTE_REQUEST_HDR				(unsigned char) 0x24 // FSD90244: New Money Request from POS
#define  TRANS_INFO3_REMOTE_REQUEST_DETAIL			(unsigned char) 0x25 // FSD90244: New Money Request from POS
#define  TRANS_INFO3_WIDE_TEXT						(unsigned char) 0x26 // FSD101945 StoreLine Displaying Long Item Description on POS
#define  TRANS_INFO3_QUERY_TNDR_PROMO				(unsigned char) 0x27 //FSD121064 - MorA 4.8.2010
#define  TRANS_INFO3_PRISM_EMV_DATA					(unsigned char) 0x28 //TD108436: Prism Emv Data
#define	 TRANS_INFO3_TICKET_TOTAL					(unsigned char) 0x29 //TD134730: Rimi external loyalty
#define	 TRANS_INFO3_ATTRIBUTE_TRANSACTION			(unsigned char) 0x2A //FSD121160: Attribute Transaction
#define  TRANS_INFO3_SCOT_ITEM_RESTRICTION			(unsigned char) 0x30 //bug #146006
#define  TRANS_INFO3_EXT_LOYALTY_ERR_KEY			(unsigned char) 0x31 //bug #146006
#define  TRANS_INFO3_EXT_LOYALTY_ERR_DATA			(unsigned char) 0x32 //bug #146006
#define  TRANS_INFO3_ONLINE_PURCHASE_EXT4			(unsigned char) 0x33 //FSD153313
#define  TRANS_INFO3_ONLINE_PURCHASE_EXT5			(unsigned char) 0x34 //FSD153315
#define  TRANS_INFO3_REQUEST_TIME			        (unsigned char) 0x36 
#define  TRANS_INFO3_BASKET_ITEMS					(unsigned char) 0x37 // FSD106540		
#define	 TRANS_INFO3_LOYALTY_MASKED_ACCOUNT			(unsigned char) 0x38
#define	 TRANS_INFO3_MASKED_ACCOUNT					(unsigned char) 0x39
#define  TRANS_INFO3_ONLINE_PURCHASE_CONFIRMATION_FAILED		(unsigned char) 0x3A //OmerR FSD157230
#define	 TRANS_INFO3_VOIDED_ONLINE_ITEMS_IN_SAVED_TRS			(unsigned char) 0x3B //OmerR FSD157230
#define	 TRANS_INFO3_COUPON_CONDITIONAL_OVERRIDE				(unsigned char) 0x3C //FSD#139444
#define  TRANS_INFO3_BREAKDOWN_DATA                 (unsigned char)	0x3D // FSD221427     
#define  TRANS_INFO3_SUMMARY_DATA                   (unsigned char)	0x3E // FSD221427
#define  TRANS_INFO3_REQUEST_TIME2			        (unsigned char) 0x3F 
#define  TRANS_INFO3_REQUEST_TIME3			        (unsigned char) 0x40
#define  TRANS_INFO3_FISCAL_SIG_DATA_PRINT			(unsigned char)	0x41 // FSD217889
#define  TRANS_INFO3_CHANGE_POS_STATUS				(unsigned char)	0x42 // #222023
#define  TRANS_INFO3_INVOICE_INFO					(unsigned char)	0x43 // #222023
#define  TRANS_INFO3_APPORTIONMENT_INFO_VARIOUS_REWARDS	(unsigned char) 0x44	//FSD#139444_ApportTrs
#define  TRANS_INFO3_PROMO_TRIGER_ITEMS             (unsigned char)	0x45 //FSD75153
#define	 TRANS_INFO3_UNIQUE_SERIAL_ISSUANCE			(unsigned char) 0x46 //FSD234817
#define  TRANS_INFO3_EXTRA_LONG_BARCODE				(unsigned char) 0x47 //FSD#222936
#define  TRANS_INFO3_REFUND_INVOICE_NO				(unsigned char) 0x48 //FSD217889
#define  TRANS_INFO3_TICKET_FRAME_EXT				(unsigned char) 0x49 //TD261267
#define	 TRANS_INF03_EXT_CUSTOMER_ACCOUNT			(unsigned char) 0x4A //FSD#253338
#define	 TRANS_INF03_SAVER_SUMMARY					(unsigned char) 0x4B //FSD#260167
#define	 TRANS_INFO3_APPORTIONMENT_ITEMS			(unsigned char) 0x4C //Receipt Layout
#define	 TRANS_INFO3_REFUND_INVOICE					(unsigned char) 0x4D //FSD265316 Refunds enhancement
#define  TRANS_INFO3_TAX_REASON						(unsigned char) 0x4E //FSD217889
#define  TRANS_INFO3_NON_FISCAL_SALE_CROSS_REF      (unsigned char) 0x4F //FSD259732 
#define  TRANS_INFO3_Z_REPORT_DATA					(unsigned char) 0x50 // FSD#250726
#define  TRANS_INFO3_POS_TEST						(unsigned char) 0x51 // FSD#277645 LeonidO
#define  TRANS_INFO3_TRS_SEND_CONTROL				(unsigned char) 0x52 // FSD#268329
#define  TRANS_INFO3_EXTERNAL_ITEM_INFO				(unsigned char) 0x53 //TSC - PayPoint - CR #235029
#define  TRANS_INFO3_SEALED_BAG     				(unsigned char) 0x54 //FSD#159229
#define  TRANS_INFO3_STD_FINAL_CONFIRMATION			(unsigned char) 0x55 //FSD259707
#define  TRANS_INFO3_SELF_SCANNING_EXT2				(unsigned char) 0x56 //#271222
#define  TRANS_INFO3_DISCOUNT_EXT					(unsigned char) 0x57 //FSD257939
#define  TRANS_INFO3_WIWALLET_SKU					(unsigned char) 0x58 //FSD294724
#define  TRANS_INFO3_MANUAL_DISCOUNT_INFO			(unsigned char) 0x59
#define  TRANS_INFO3_EXT_LOYALTY_REWARD				(unsigned char) 0x5A // FSD316298
#define  TRANS_INFO3_EXT_MEDIA6						(unsigned char) 0x5B //FSD34249_V4
#define  TRANS_INFO3_E_COMMERCE_ORDER				(unsigned char) 0x5C //FSD#426710
#define  TRANS_INFO3_CUSTOMER_ACCNT_CHARGE          (unsigned char) 0x60  // FSD 230254
#define  TRANS_INFO3_PURCHASE_CHARGE                (unsigned char) 0x61  // FSD 230254
#define  TRANS_INFO3_CUSTOMER_NAME_CHARGE           (unsigned char) 0x62  // FSD 230254
#define  TRANS_INFO3_OLA_CARD_DENIAL_DATA			(unsigned char) 0x63  // FSD 296959
#define  TRANS_INFO3_FISCAL_EOD_TAX					(unsigned char) 0x65 //FSD298942
#define  TRANS_INFO3_FISCAL_EOD_TAX2_SERIAL			(unsigned char) 0x66 //FSD298942
#define  TRANS_INFO3_FUEL_VOUCHER_USED				(unsigned char) 0x67 //#306903 FSW fuel vouchers integration
#define  TRANS_INFO3_PROMOTION_EXT3					(unsigned char) 0x68 // //TD#316773 //FSD#258806
#define	 TRANS_INFO3_POS_REPORT_TOTALS				(unsigned char) 0x69	//FSD305075
#define  TRANS_INFO3_ONLINE_PURCHASE_DATA_TO_PRINT	(unsigned char) 0x6A //FSD#298969
#define  TRANS_INFO3_ONLINE_PURCHASE_DATA			(unsigned char) 0x6B //FSD#298969 //TD#384162
#define  TRANS_INFO3_ONLINE_COUPON_RWRD_PROMO		(unsigned char) 0x6C //CR334690
#define  TRANS_INFO3_ONLINE_COUPON_RWRD_DISP_LINE	(unsigned char) 0x6D //CR334690
#define  TRANS_INFO3_ONLINE_COUPON_RWRD_RSP			(unsigned char) 0x6E //CR334690
#define	 TRANS_INFO3_CUST_SRV_QUESTION_EXT2			(unsigned char) 0x6F //FSD#321725
#define  TRANS_INFO3_CLUBCARD_DETAILS_MSR_INFO      (unsigned char) 0x70 // TD#340518
#define  TRANS_INFO3_ONLINE_ORDER				    (unsigned char) 0x71 // FSD334265 FSW (TFXTrans use by ext pos)
#define  TRANS_INFO3_MM_REF_NUM						(unsigned char) 0x72 // CR337587
#define  TRANS_INFO3_TAX_SECTION					(unsigned char) 0x73 //TD347902
#define  TRANS_INFO3_PLU_END_SECTION				(unsigned char) 0x74 //CC&C
#define  TRANS_INFO3_DATABAR_ELEMENTS				(unsigned char) 0x75 //FSD309681
#define  TRANS_INFO3_ENVIRONNEMENTAL_TAX			(unsigned char) 0x76 //FSD350935
#define	 TRANS_INFO3_POS_REPORT_TOTALS_EXT			(unsigned char) 0x77 //CR#357297
#define  TRANS_INFO3_ONLINE_PURCHASE_NZL_ID         (unsigned char) 0x78 //Epic350305 - stores NZ Lotteries trx ID for "dip" and "IK"
#define  TRANS_INFO3_ONLINE_PURCHASE_NZL_IK         (unsigned char) 0x79 //Epic350305 - stores game/book/ticket numbers for "IK"
#define  TRANS_INFO3_TARGET_MESSAGE_PROMOTION       (unsigned char) 0x80 // target message
#define  TRANS_INFO3_INVOICE_PRINTING_REQUEST		(unsigned char) 0x81 //FSD350935
#define  TRANS_INFO3_NIF							(unsigned char) 0x82 //#380596
#define  TRANS_INFO3_MANUAL_PROMOTION				(unsigned char) 0x83 //TD#362727
#define  TRANS_INFO3_RESET_CUST_INFO				(unsigned char) 0x84
#define  TRANS_INFO3_DATABAR_RECOVER				(unsigned char) 0x85 //FSD#365331
#define  TRANS_INFO3_ONLINE_SERVICE_SESSION_DATA	(unsigned char)	0x86 //	//FSD370728
#define  TRANS_INFO3_ONLINE_SERVICE_SESSION_DATA_EXT	(unsigned char)	0x87 //	//FSD370728
#define  TRANS_INFO3_MOBILE_PAYMENT_DATA			(unsigned char)	0x88 //FSD396380
#define  TRANS_INFO3_QR_CODE_PROCESS				(unsigned char)	0x89 //FSD#397567
#define  TRANS_INFO3_LONG_USER_ID					(unsigned char) 0x90 //FSD#394140
#define  TRANS_INFO3_ITEM_MSG_EXT3					(unsigned char) 0x91 //CRL413907
#define	 TRANS_INFO3_FORTRESS						(unsigned char)	0x92 //FSD414790
#define	 TRANS_INFO3_TOKEN_INFORMATION				(unsigned char)	0x93 //FSD#414169
#define  TRANS_INFO3_ONLINE_IDENTIFIER				(unsigned char) 0x94 //FSD407160
#define  TRANS_INFO3_END_OF_PRINTING				(unsigned char) 0x95 //TD#423706,TD#423702
#define	 TRANS_INFO3_ALPHA_NUMERIC_CUST_SURVEY		(unsigned char) 0x96 //FSD433317

#define  TRANS_INFO3_SS_INFO_PLU_DEP_EXT			(unsigned char) 0xEE //FSD#159243
#define  TRANS_INFO3_DISCOUNT_EXT1					(unsigned char) 0xEF // TD#332305
#define  TRANS_INFO3_MEMBER_ACCOUNT					(unsigned char) 0xF0 // PE 2 LPE
#define  TRANS_INFO3_CHARGE							(unsigned char) 0xF1 //FSD347594 GSE Balance enquiry
#define  TRANS_INFO3_PLU_SALE_EXT7					(unsigned char) 0xF2 //FSD#358503
#define  TRANS_INFO3_DOCUMENT_NUM_FISCAL_FORMAT		(unsigned char) 0xF3 //FSD???ReceiptNonFiscal
#define  TRANS_INFO3_PROMOTION_INFO					(unsigned char) 0xF4 //FSD367024 ASW - Add Promotion info to Tlog
#define  TRANS_INFO3_CUSTOMER_EXT					(unsigned char) 0xF5 //FSD367024 ASW - Add Promotion info to Tlog
#define  TRANS_INFO3_CAPTURE_CUSTOMER_PHONE_NUMBER	(unsigned char) 0xF6 //FSD387834 Clicks - Cupture customer phone number	
#define  TRANS_INFO3_SECURITY_NUMBER				(unsigned char) 0xF7 //FSD#366569
#define  TRANS_INFO3_SECURITY_NUMBER_SALE			(unsigned char) 0xF8 //FSD#366569
#define  TRANS_INFO3_POS_TOTALS_PER_VAT				(unsigned char) 0xF9 //FSD#366569

#define  TRANS_INFO3_BARCODE_GENERATION             (unsigned char) 0xFA //FSD368305 PickUp Barcode
#define  TRANS_INFO3_LINK_POINTS					(unsigned char) 0xFB //FSD#391853
#define  TRANS_INFO3_ALLOWABLE_TENDERS              (unsigned char) 0xFC //FSD392122_AllTndrs
#define  TRANS_INFO3_CIF							(unsigned char) 0xFD //FSD#397828
#define  TRANS_INFO3_LINK_POINTS_EXT				(unsigned char) 0xFE //FSD#391853
#define  TRANS_INFO3_NRIC							(unsigned char) 0xFF //FSD#394167

// -------------------------------------------------------------
// end of info3
// -------------------------------------------------------------


//Opcode 0x90 for INFO4 transactions
// -------------------------------------------------------------
// INFO4 transactions
// -------------------------------------------------------------
#define  TRANS_INFO4            			 (unsigned char) 0x90	//FSD#391853_V7
#define	 TRANS_INFO4_LINK_POINTS_EXT2		 (unsigned char) 0x01	//FSD#391853_V7
#define	 TRANS_INFO4_SLIP_TYPE				 (unsigned char) 0x02	//Foodstuffs Wellington 418554: this tranasction is used to identify what type of slip is to come. it is used for reprint last tranaction from compressed text
#define	 TRANS_INFO4_GIFT_CARD				 (unsigned char) 0x03	//CRD413428. Shoprite Giftcard
#define  TRANS_INFO4_DDT_DETAILS			 (unsigned char) 0x04   //FSD418766 - C&C - PA document and customer enhancement
#define  TRANS_INFO4_SELF_SCAN_EXT3          (unsigned char) 0x05   //FSD420610
#define  TRANS_INFO4_RESCAN_DETAILS          (unsigned char) 0x06   //FSD420610
#define  TRANS_INFO4_FIRST_LAST_TICKETS_DATA_REPORT (unsigned char) 0x07	//FSD#411629
#define  TRANS_INFO4_EXT_LOYALTY_MESSAGES	 (unsigned char) 0x08	//#422014
#define  TRANS_INFO4_POS_ITEM_MESSAGE   	 (unsigned char) 0x09	//FSD403679 - PIM Enhancement
#define  TRANS_INFO4_COMBINE_MULTIPLE_DOCUMENTS	(unsigned char) 0x0A	//FSD#421963
#define  TRANS_INFO4_TRIGGER_PROMOTION       (unsigned char) 0x0B   //FSD406085
#define  TRANS_INFO4_LOG_DIFF_TRS			 (unsigned char) 0x0C	//TD#432674
#define  TRANS_INFO4_PARKING_EXIT_CODE		 (unsigned char) 0x0D	//FSD#226065_Ver5_020615D
#define  TRANS_INFO4_LOCAL_BARCODE_ISSUED_EXT2 (unsigned char) 0x0E	//FSD432753
#define  TRANS_INFO4_AXIA_CUSTOMER_DETAILS   (unsigned char) 0x0F	//FSD432753
#define  TRANS_INFO4_POINTS_APPORTIONMENT    (unsigned char) 0x10   // Epic 435446 US 1
#define  TRANS_INFO4_INVOICE_REFERENCE_DOCUMENT (unsigned char) 0x11	// FSD416124
//FSD438581
#define  TRANS_INFO4_EXT_BARCODE_PRG_TENDER_TYPE			(unsigned char)0x12 
#define  TRANS_INFO4_EXT_TENDER_TRS_BARCODE_LINKED_TENDER	(unsigned char)0x13
#define  TRANS_INFO4_PLU_SALE_EXT8							(unsigned char)0x14 //FSD#439874
#define  TRANS_INFO4_CHIP_CARD_INFO							(unsigned char)0x15	//FSD437272	
#define  TRANS_INFO4_COUPON_INFO							(unsigned char)0x16	//FSD437272	
#define  TRANS_INFO4_TAX_DETAILS						    (unsigned char)0x17	//FSD447653	
#define  TRANS_INFO4_MM_CONFIRM_DECLINE_REASON1				(unsigned char)0x18	//CR448058	
#define  TRANS_INFO4_MM_CONFIRM_DECLINE_REASON2		    	(unsigned char)0x19	//CR448058	
#define  TRANS_INFO4_DOCUMENT_DETAILS					    (unsigned char)0x1A	//FSD451172

#define TRANS_INFO4_UNIQUE_RCPT_NUMBER					    (unsigned char)0x1B	//FSD450176

#define TRANS_INFO4_NEW_INGE_VOUCHER     			        (unsigned char)0x1D //FSD448663
#define TRANS_INFO4_EWALLET_IDENTIFICATION 			        (unsigned char)0x1E //FSD450172
#define TRANS_INFO4_EWALLET_PAYMENT					        (unsigned char)0x1F //FSD450172

#define TRANS_INFO_DOCUMENT_SEQ_EXT					        (unsigned char)0x20 //FSD450172
#define TRANS_INFO4_PERFORMANCE_TEST_START				    (unsigned char)0x21
#define TRANS_INFO4_PERFORMANCE_TEST_END				    (unsigned char)0x22

// -------------------------------------------------------------
// end of info4
// -------------------------------------------------------------



#define  TRANS_CUSTOM_LINK                 (unsigned char) 0x61
#define  TRANS_CUSTOM_LINK_FUEL_ACCEPTED   (unsigned char) 0x01
#define  TRANS_CUSTOM_LINK_FUEL_RELEASE    (unsigned char) 0x02
#define  TRANS_CUSTOM_LINK_FUEL_PAID       (unsigned char) 0x03
#define  TRANS_CUSTOM_LINK_FUEL_RELEASE_NF (unsigned char) 0x04
#define  TRANS_CUSTOM_LINK_FUEL_PAID_NF    (unsigned char) 0x05

#define  TRANS_HOOK             (unsigned char) 0x62
#define  TRANS_ALERTS           (unsigned char) 0x63
#define  TRANS_PRINTOUT         (unsigned char) 0x64
#define  TRANS_SYSTEM_DEBUG     (unsigned char) 0x65	 //NU by SuperStore

#define  TRANS_FUEL_RECONCIL    (unsigned char) 0x66   // Moti 03/06/96
#define  TRANS_HOST_ALERTS      (unsigned char) 0x67   // Andy 12/06/96

#define  TRANS_APL1             (unsigned char) 0x77
#define  TRANS_APL2             (unsigned char) 0x78

#define  TRANS_MANAGER          (unsigned char) 0x99
#define  TRANS_EVENT            (unsigned char) 0x99

#define  TRANS_MISC_FRAME       (unsigned char) 0xD1 // misc. transaction start !yaron!
#define  TRANS_MISC_END         (unsigned char) 0xD5 // misc. transaction end !yaron!


#define  TRANS_PC_SYSTEM        (unsigned char) 0xF0	 //NU by SuperStore



/**************************************************/
/*** LOG FUNCTION TYPES                         ***/
/**************************************************/
#define  LOG_FUNC_POWER_UP                   1
#define  LOG_FUNC_STORE_OPEN                 2
#define  LOG_FUNC_STORE_CLOSE                3
#define  LOG_FUNC_AUTO_RECOVER_TICKET        4
#define  LOG_FUNC_MANU_RECOVER_TICKET        5
#define  LOG_FUNC_SIGN_ON                   11
#define  LOG_FUNC_SIGN_OFF                  12
#define  LOG_FUNC_ENTER_SECURE_MODE         13
#define  LOG_FUNC_EXIT_SECURE_MODE          14
#define  LOG_FUNC_ENTER_WAIT_MODE           15
#define  LOG_FUNC_EXIT_WAIT_MODE            16
#define  LOG_FUNC_ENTER_TRAINING_MODE       17
#define  LOG_FUNC_EXIT_TRAINING_MODE        18
#define  LOG_FUNC_PASSWORD_CHANGE           19
#define  LOG_FUNC_Z_CASHIER                 20
#define  LOG_FUNC_Z_SHIFT_CASHIER           21
#define  LOG_FUNC_X_READ                    22
#define  LOG_FUNC_POS_REPORT                23
#define  LOG_FUNC_MOVE_POS_TTL_2_PRV_ZERO   24 //PC
#define  LOG_FUNC_RESERVED_FOR_PC_USAGE     25 //PC
#define  LOG_FUNC_START_SPECIAL_PRINTOUT    26
#define  LOG_FUNC_END_SPECIAL_PRINTOUT      27
#define  LOG_FUNC_STORE_BOARD_MSG           28 //storeboard
#define  LOG_FUNC_X_ITEMIZED_CHECK_REPORT   31
#define  LOG_FUNC_Z_ITEMIZED_CHECK_REPORT   32
#define  LOG_FUNC_DEPART_REPORT             33
#define  LOG_FUNC_TAX_REPORT                34
#define  LOG_FUNC_DECLARATION               35 
#define  LOG_FUNC_PRINT_DUPL_GIFT			36	//Stuttafords
#define  LOG_FUNC_CUST_ORD_ERROR_REPORT     37
#define  LOG_FUNC_ELECTRONIC_SIGN_ON		38	// FS1131
#define  LOG_FUNC_MANUAL_ENTER_SECURE_MODE	39	// FSD4906
#define  LOG_FUNC_LAYBY_OLD_TICKET_START	40	// FSD6248 LayBy
#define  LOG_FUNC_LAYBY_OLD_TICKET_END		41	// FSD6248 LayBy
#define  LOG_FUNC_CASH_DENOMINATION         42
#define  LOG_FUNC_DETAILED_TENDER_REPORT    43
#define  LOG_FUNC_LONG_PASSWORD_CHANGE		44 //FSD 13459
#define  LOG_FUNC_EMERGENCY_DRAWER_OPENING  45	//FSD26800
#define  LOG_FUNC_INFO_LONG_USER			46
#define  LOG_FUNC_ASK_PROM_WHAT_TRIGGERED	47	//#40427
#define  LOG_FUNC_LOCK_CASHIER_POS_AFTER_SIGN_OFF      48 //Lock pos after sign off
#define  LOG_FUNC_PC_START_OF_DAY           99

/**************************************************/
/*** TRANS_GENERAL_LONG_DATA types	            ***/
/**************************************************/
#define  GENERAL_DATA_ENCRYPTED_PASSWORD	1	//FSD42325.
#define  GENERAL_DATA_ENCRYPTED_PASSWORD2	2	//FSD90637.
#define  GENERAL_DATA_GSE_PROVIDER_TRANSACTION_ID	3	//FSD428027.


/************************************************************************/


/**************************************************/
/*** START OF TICKET TYPES                      ***/
/**************************************************/
#define  TICKET_NONE						0x00
#define  TICKET_START						0x01
#define  TICKET_NO_SALE						0x02
#define  TICKET_NEGATIVE					0x04
#define  TICKET_CASH_OFFICE					0x08	//ShlomitG - 02/09/07 - Defect #36487 - Prevent similar define for two different types.
#define  TICKET_BALANCING					0x10
#define  TICKET_START_NO_CLEAR_TRS_CACHE	0x20
#define  RECALL_PACK						0x40  //For Backary packed transaction
#define  TICKET_TENDER_PURCHASE				0x80
			
#define  FLOAT_OPENING        1
#define  FLOAT_ADD_ON         2
#define  FLOAT_POST_ADD_ON    3

#define  TAIL_FLUSH						0x00		
#define  TAIL_NO_FLUSH					0x01
#define  TAIL_RETURN					0x02  //FSD8951 - Used in case of returned barcode
#define  TAIL_MASTER_TRANS				0x04  //FSD14741
#define  TAIL_VOID_TICKET				0x10
#define  TAIL_BAD_RECORD				0x20
#define  TAIL_NO_SEQ_CHECK				0x40  // TRC
#define	 TAIL_ALERT_POWER_UP			0x80  // FIXHALL
#define	 TAIL_OFFLINE_POS				0x100 // TD#52600
#define  TAIL_DONT_PARSE_TO_FO_DB		0x200 // Bug#101812 - New Tail option - don't parse to DB will be sent in some "bad record" scenarios.

#define  ALERT_PRINTER_ERROR  		     10
#define  ALERT_DRAWER_ERROR              11      
#define  ALERT_SCANNER_ERROR			 12
#define  ALERT_CUST_DISP_ERROR		     13
#define  ALERT_MCR_KBD_ERROR			 14
#define  ALERT_SCALE_ERROR               15
#define  ALERT_PAYMENT_TERM_ERROR        16
#define  ALERT_WRONG_TV_ERROR            17
#define  ALERT_DEAR_MANAGER_PERFOMED     18
#define  ALERT_FINISH_SND_TRS_EOD		 20 //Enh. #10490 SHORT_EOD AmyG
#define  ALERT_START_EOD				 21
#define  ALERT_EOD_TILL_IN_TRANS	     22 /* new short eod */
//#define  ALERT_END_EOD				   22 /* new short eod */
#define  ALERT_POWER_UP					 30
#define  ALERT_STORE_OPEN				 31
#define  ALERT_LINE_STAUS_CHANGE		 32
#define  ALERT_FORGROUND_PLU_LOAD	     33
#define  ALERT_BACKGROUND_PLU_LOAD	     34
#define  ALERT_COLD_START				 35
#define  ALERT_COLD_START_NRT			 36 //FS20572_1: NRT cold start
#define  ALERT_COLD_START_DOWN_MFS       37 //FS20572_1: cold start, download data from FO.
//#define  ALERT_COLD_START_NRT_DOWN       38 //FS20572_1: now we not use
#define  ALERT_FAST_COLD_START			 38 //FS20572_010304D:Fast cold start
#define  ALERT_FLASHING_DOLLAR   		 39
#define  ALERT_ASSISTANCE				 40
#define  ALERT_TOPUP					 41
#define  ALERT_Q_LENGTH  				 42
#define  ALERT_PASSWORD_VIOLATION	 	 45
#define  ALERT_OLA_OFFLINE       	     50
#define  ALERT_CATERING_SWITCH_FORMS     60 //TESCO
#define  ALERT_SOFTWARE_VERSION		     80
#define  ALERT_RELEASE_VERSION_NO_MATCH  81 //#11245
#define  ALERT_POS_UNBALANCED_TICKET	 82 //#11245
#define  ALERT_FILE_LOAD   			     88 //TESCO
#define  ALERT_FILE_REFRESH			     89
#define  ALERT_HOST_BATCH				 90
#define  ALERT_PROGRAM_CORRUPT		     91
#define  ALERT_QUICK_TERMINAL_CALL       92 //Quick
#define  ALERT_QUICK_BATTERY_LOW     	 93 //Quick
#define  ALERT_QUICK_ABANDON         	 94 //Quick
#define  ALERT_QUICK_FAIL_POSITION   	 95 //Quick
#define  ALERT_QUICK_CHARGE_TIMEOUT  	 96 //Quick
#define  ALERT_DOCK_PAPER_LOW        	 97 //Docking
#define  ALERT_DOCK_PRINTER_OFFLINE  	 98 //Docking
#define  ALERT_CCMS_OFFLINE  			 99 //COREMA
#define  ALERT_TOSCA_BAD_COM        	100 //TESCO
#define  ALERT_FISCAL_ERROR         	102 //TESCO
#define  ALERT_START_FISCAL_EOD			103 //TESCO  
#define  ALERT_BAUD_RATE				104 //TESCO
#define  ALERT_FISCAL_EOD_OK			106 //TESCO
#define  ALERT_FISCAL_EOD_FAILED		107 //FSD#225578
#define  ALERT_BOARD_MSG            	110 //storeboard
#define  ALERT_LOAD_HYBRID_READER       111 //SmartCard
#define  ALERT_CCMS_QDX_FULL            112 //COREMA
#define  ALERT_POST_MAIL                113 //POST_MAIL
#define  ALERT_POS_NOT_SIGN_AS_ACTIVE   114 //POS not sign as Active in "pos configuration"
#define  ALERT_POS_DISK_LIMIT           115 //Disk size limit
#define	 ALERT_TRANSACTION_QDX_PROBLEM	116 //FS1079 transaction qdx problem / see type list down
#define	 ALERT_REMOTE_SIGN_OFF_PROBLEM	117 //FSD10094 - 2 Person Operation
#define  ALERT_UNKNOWN_CASHIER_ID		119 //FSD56626


// OLA ALERTS use by CheckCrd dll 191201
#define  ALERT_SWITCH_OLAMainProvidertoSubProvider	120  
#define  ALERT_SWITCH_OLASubProvidertoMainProvider	121
#define  ALERT_SWITCH_OLASubProvider1toSubProvider2	122
#define  ALERT_SWITCH_OLAMainProvidertoOffLine		123 
#define  ALERT_SWITCH_OLASubProvidertoOffLine		124
#define  ALERT_SWITCH_OLAOffLinetoMainProvider		125
#define  ALERT_SWITCH_OLAOffLinetoSubProvider		126

#define  ALERT_SMART_SWITCH_OLAConnectionOffline	127
#define  ALERT_OLAConnectionOffline					127	//FSD153310

#define  ALERT_PLU_FILE_REFRESH						128 //#61699

#define  ALERT_GRADE_PRICE_CHANGE_FAILED            130 
#define  ALERT_PARKING_SERVER_OFFLINE               131 //FSD10526 No Response from Parking Server

#define  ALERT_PINPAD_REPLACEMENT					132 //FSD 57796 - alert for PIN-Pad replacement
#define  ALERT_SWIPE_AND_PARK_REPLACEMENT			133 //FSD 57796 - alert for PIN-Pad replacement
#define  ALERT_EFT_DEVICE_PROBE_FAILED				134 //FSD 57796 - alert for failing to get a response for the EFT devices probe request

#define  ALERT_SETTLED_MEDIA_CANCELLATION			135
		
#define	 ALERT_DSS_ERROR_RETURNED		136 //FSD34954
#define	 ALERT_DSS_INIT_FAILED			137 //FSD34954
#define	 ALERT_DSS_EFT_IP_EDITED		138 //FSD34954

#define  ALERT_PRINTER_OKAY            140
#define  ALERT_DRAWER_OKAY             141
#define  ALERT_SCANNER_OKAY            142
#define  ALERT_SCALE_OKAY              143
#define  ALERT_PAYMENT_TERM_OKAY       144
#define  ALERT_TV_NUMBER_OKAY          145
#define	 ALERT_WRONG_DLL_VERSION	   146 // New alert for wrong pos dll version
#define  ALERT_CHECK_SCANNER_ERROR     147	//Enh #2385SL
#define  ALERT_FAST_COLD_START_DOWN	   150 //FS20572_010304D: Fast cold start+ download
#define  ALERT_NEW_POS_TERMINAL 	   151 //FS20572_010304D: New Pos
#define  ALERT_QDX_USAGE_OVERFLOW	   152  //FSD19271 
#define  ALERT_POS_CRASH			   153
#define  ALERT_WRONG_DOCUMENT_SUMMARY  154
#define  ALERT_PROCESS_USAGE_OVERFLOW  155
#define  ALERT_QDX_MAX_RECORDS_SIZE_DIFFERENT  156
#define  ALERT_QDX_RECORDS_SIZE_DIFFERENT      157
//Alerts for Automatic Home Shoppings 
#define	 ALERT_INVALID_FILE				  161
#define  ALERT_EFT_DECLINED_TICKET_SAVED  162
#define  ALERT_SHARED_DIR_CANNOT_BE_SAVED 163
#define  ALERT_UNKNOWN_ITEM_HOST_LOOKUP   165 //(xA5)#23688 (FS22361)
#define  ALERT_TRANS_MANAGER_STUCK		  166 
#define  ALERT_GIFT_CARD_ENQUIRY		  167 //(xA7) FSD1798 - Gift Card
#define  ALERT_OFFLINE_MGR_OVERRIDE		  170 // Enh# 6531SL
#define  ALERT_FISCAL_TOTALS_DIFF		  171 // Enh# 7503SL - Latin America Dev
#define  ALERT_MAINTENANCE_PROBLEM		  172 // Enh# 6864SL - SYSTEM Dev
#define  ALERT_TRS_RECOVER_PROBLEM		  173 // Enh# 6864SL - SYSTEM Dev
#define  ALERT_CHECK_TENDER				  174 //Issue #8270SL
//Alerts for Enhanced home shopping
#define  ALERT_HOME_SHOPPING			  175 //FSD23594
#define  ALERT_AUTO_FUEL_MNGT			  176 //FSD30537
#define	 ALERT_FILE_SIZE				  177 //FSD10279
#define	 ALERT_EFT_END_OF_DAY			  178 //FSD24393
#define	 ALERT_SELF_SERVICE_LOYALTY_ERROR 179 //FSD52276


#define  ALERT_RTAPS_STARTUP			180
#define	 ALERT_RTAPS_SHUTDOWN			181
#define	 ALERT_RTAPS_STORE_NO_MISMATCH  182
#define	 ALERT_RTAPS_PROVIDER_OFFLINE	183
#define	 ALERT_RTAPS_REMA_COMM			184
#define	 ALERT_RTAPS_PROTOCOL_ERROR		185
#define  ALERT_RTAPS_FATAL_ERROR		188
#define  ALERT_RTAPS_COMMPOINT			189

//CR#7496
#define  ALERT_TAXEYES_TIMEOUT			190 
#define  ALERT_PROM_ENGINE_COM_FAIL		191

#define  ALERT_INNER_PAN_RETRIEVE_FAIL	193	//FSD47073
#define  ALERT_FAILED_TO_COPY_RECEIPT_PDF_FILE	194 //FSD414790 - Receipt
//FSD16259 - Tomer
#define ALERT_COIN_DISPENSER_SUSPENDED  194		//#58308 - numbers changed
#define ALERT_COIN_DISPENSER_RESUMED    195		//#58308 - numbers changed
#define ALERT_COIN_DISPENSER_ERROR		196		//CR53695 - new changes (automatic actions)

//FSD64199 - alerts for coupon file processing
#define	 ALERT_COUPON_PROCESSING_FAILED	194
#define  ALERT_COUPON_PROCESSING_COMPLETED_WITH_ERRORS	195
#define  ALERT_QDX_LOAD_REQUIRED_AFTER_SHORT_EOD		199
#define  ALERT_PACKAGE              	222 //0xDE code distribution sun opcode 
//CR1048
#define  ALERT_PACKAGE_UPGRD_FAILED    	223 //0xDF code distribution package upgrade failed. 
#define  ALERT_PACKAGE_UPGRD_ENDED      224 //0xE0 code distribution package upgrade Ended.

//FSD27939	KireetG
#define ALERT_FILE_OPERATION_SUCCESS	230
#define ALERT_FILE_OPERATION_FAILURE	231

//FSD16055 MarcellaR
#define ALERT_FISCAL_EJ_NEAR_END		240

//vivek FSD#16852
#define ALERT_SDD_CARD_INITIALIZATION   241


// FSD16852 Kireet
#define ALERT_SDD_CONFIG_NOT_EXIST		242
#define ALERT_SDD_CONFIG_CORRUPT	    243

// FSD 16852 Albertoa
#define ALERT_SDD_CHIP_CARD_READ_ERROR	244

//FSD14667
#define ALERT_SAFEPAY_CASH_PROBLEM      246
#define ALERT_COPY_EJ_BACKUP_TO_MFS		247
//FSD 27795
#define ALERT_FISCAL_DATE_DIFFER_POS_DATE		248	

//FSD 27835: Solo EFT Latvia
#define ALERT_EFT_BLOCKED				249	
#define ALERT_GLOBAL_SERVICES			250

#define ALERT_ONLINE_PURCHASE_VOID_DECLINE	251	//KobiM - FSD51133
#define ALERT_MERCH_TAG_DEVICE_ERROR		252  //CR327669

#define  ALERT_PACKAGE_START           0x01 
#define  ALERT_PACKAGE_ERROR           0xEE
#define  ALERT_PACKAGE_ABORT           0xFC //(252) FS1053
#define  ALERT_PACKAGE_NOT_SUPPORT	   0xFD // (253) FS1051
#define  ALERT_PACKAGE_END             0xFF

#define ALERT_SELF_SCANNING_FILE_NOT_FOUND					256	//FSD39274
#define ALERT_PARKING_SERVER_2_RESPONSE_CHECKSUM_ERROR		257	//FSD39175
#define ALERT_PARKING_SERVER_2_RESPONSE_ERROR_CODE			258	//FSD39175
#define ALERT_DATABAR_DLL_FAILURE							259	//FSD28013

#define ALERT_PRICE_CHECKER_ERROR							260 // TD#131317
#define ALERT_TAX_QDX_CHECKSUM_DIFFERENCE				    261 // FSD361521 ASW Fiscal Hungary 
#define ALERT_TAX_QDX_UPDATE_BY_FISCAL					    262 // FSD361521 ASW Fiscal Hungary 
 


//#144180
#define ALERT_FATAL_ERROR						270

#define ALERT_EOD_EFT_SETTLEMENT                315 // (0x13B) FSD69928


#define ALERT_POS_VERSION_OLDER_THEN_MFS		661				//FSD58886
#define ALERT_THIRDPARTY_PACKAGE_FAILED		    662				//FSD58886
#define ALERT_AUTOMATIC_UPGRADE_FAILED			663				//FSD58886
#define ALERT_THIRDPARTY_RCOPY_FAILED			664				//FSD58886
#define ALERT_CANNOT_LOGOFF_SUSPEND_UPGRADE		666				//FSD58886

#define ALERT_CANNOT_ISSUE_GIFT_VOUCHER 		667				//FSD407166
#define ALERT_POS_FATAL_ERROR					668 
#define ALERT_OLP_DECLINE						 669			//FSD437281  Storeline Conexflow E-Topup
#define ALERT_OLP_SUCCEEDED_BUT_POST_VOID_FAILED 670			//FSD437281  Storeline Conexflow E-Topup
#define ALERT_HOME_DELIVERY_CANCELLATION		 671			//FSD437596  StoreLine Home Delivery
#define ALERT_TIMEOUT_WITH_GENERIC_SERVICES		 673			//FSD437272	 StoreLine Loyalty Chip Card

#define ALERT_NO_RESPONSE_VENDING_MECHINE		700	//76594


//FSD31008
#define ALERT_ALARM_SRV							800 // 0x320	
#define ALERT_MANUAL_DECLARATION_NEEDED			801 // FSD#218589

#define ALERT_DPS_FAILURE_ERROR					1002			//FSD217889

#define ALERT_COMPLETE_HS_FILE_ERROR			1009 // FSD350524
#define ALERT_COMPLETE_HS_PARAM_ERROR			1010 // FSD350524
#define ALERT_INV_PDF_FAILURE        			1012 // FSD395537

#define	 ALERT_SELF_SCAN_ERROR							16010 // FSD28467 GinatB
#define	 ALERT_DRAWER_MANIPULATION						16011 //FSD403366
#define	 ALERT_OLA_ITEM_PURCHASE_CONFIRMATION_FAILED	16013 //OmerR FSD157230


//New US range for alerts
#define  ALERT_GC_BATCH_ERR_BAD			17006 //Issue #9564SL: Gift Card Batch Activation
#define  ALERT_GC_BATCH_ERR_DUPL		17007 //Issue #9564SL: Gift Card Batch Activation

#define  ALERT_TYPE_NONE      		 0
#define  ALERT_TYPE_START				 1
#define  ALERT_TYPE_END					 2

//FSD395537Invoice PDF Creation failure  reason codes
#define INV_PDF_FAILURE_REASON_NONE              0
#define INV_PDF_FAILURE_REASON_RTF_CREATION      1
#define INV_PDF_FAILURE_REASON_SERVER_DIR        2
#define INV_PDF_FAILURE_REASON_RCOPY_NOK         3
#define INV_PDF_FAILURE_REASON_PDF_NOT_CREATED   4



// TD#131317 - Sub types for 260 ALERT_PRICE_CHECKER_ERROR
#define ALERT_PRICE_CHECKER_EMTY_ITEM_DESCRIPTION   1
#define ALERT_PRICE_CHECKER_INVALID_LANGUAGE		2

// 2 scanners type acording scanner define number
#define  ALERT_TYPE_SCANNER1			11
#define  ALERT_TYPE_SCANNER2			12

// FS1079 sub type of alert 116 ALERT_TRANSACTION_QDX_PROBLEM
#define  ALERT_TRANSACTION_WRITE_FAILED		1
#define  ALERT_TRANSACTION_SEQ_ERROR		2
#define  ALERT_TRANSACTION_EMPTY_REC_C0		3 // not use
#define  ALERT_TRANSACTION_BACKUP_FAILED	4
#define  ALERT_TRANSACTION_EOD_EMPTY_FAILED	5 // not use
#define  ALERT_TRANSACTION_COUNTER_OVERFLOW	6
#define  ALERT_TRANSACTION_POINTERS_ERROR	7 // not use
#define	 ALERT_TRANSACTION_FIX_ON_START		8 // FIXHALL
#define	 ALERT_TRANSACTION_BAD_ON_START		9 // FIXHALL
#define	 ALERT_TRANSACTION_LOCAL_DELETE_FAILED 10 // FSD16261 - Quick Save function

/* ALERT FOR TAX EYES CR#7496 */
#define  ALERT_TAXEYES_INIT					1   //function init_tax
#define  ALERT_TAXEYES_TYPE_PRINT			2   //function print_invoice

/* ALERT FILE REFRESH (89) STATUS DEFINES #10593 */
#define FILE_REFRESH_CHECKSUM_FAILS			1	 //6 1-Start refresh checksum fails
#define FILE_REFRESH_TV_PROBLEM				2	 // 2-Start refresh TV problem
#define FILE_REFRESH_USER_ABORT				3	// 3-Suspend load  user abort
#define FILE_REFRESH_RESUME_LOAD			4	// 4-Resume  load  
#define FILE_REFRESH_FORCE_REQUEST			5  // 5-Start refresh force request
#define FILE_REFRESH_CFM_START				6	// 6-Start refresh CFM request
#define FILE_REFRESH_COMPLETED				7	// 7-File refreshing completed
#define FILE_REFRESH_POSMENU_FAILS			8	// 8-FSD11944, Posmenu.qdx file refreshing fails 
#define FILE_FORCE_REFRESH_CHECKSUM_FAILS	9 //FSD90654 //FSD90997
#define FILE_REFRESH_ADD_TO_START_LOAD		10  // mean 11 checksum
                                               // 12 TV
                                                // 14 RESUME  
#define FILE_REFRESH_NAK_FROM_MFS			16 
#define FILE_REFRESH_END_OF_COMBINATION		20  // The range of 11-19 is combination of 10 + 1...9. E.g.: 11 = FILE_REFRESH_CHECKSUM_FAILS(1) + FILE_REFRESH_ADD_TO_START_LOAD(10). 20 is the 1st value after this range.
#define FILE_CHECK_ONLY_CHECKSUM_FAILS		21 //FSD90654 //FSD90997


//ALERT STATUS FOR HOME SHOPPING
#define ALERT_HOME_SHOPPING_INVALID_FILE				1	//FSD23594
#define ALERT_HOME_SHOPPING_SHARED_DIR_CANNOT_BE_SAVED	2	//FSD23594
#define ALERT_HOME_SHOPPING_EFT_DECLINED_TICKET_SAVED	3	//FSD23594
#define ALERT_HOME_SHOPPING_OUTPUT_FILE_DIR				4	//FSD23594

/* ALERT FOR POS UNBALANCED TICKET */
#define  ALERT_GENERAL_UNBALANCED			1
#define  ALERT_APPORTIONMENT_UNBALANCED		2   


#define KEY_TICKET_COMPLETED				1  //CR6665 N#4731                                               
#define KEY_MEMBERCARD_NUMBER				2  //CR6665

// QSR Merge [RandyB]
#define QSR_INFO_TRANS_ITEM_SALE				0x01
#define QSR_INFO_TRANS_INGREDIENT				0x02
#define QSR_INFO_TRANS_SPECIAL_ORDER			0x03
#define QSR_INFO_TRANS_PRE_PACK					0x04
#define QSR_INFO_TRANS_ORDER_INSTRUCTIONS		0x05
#define QSR_INFO_TRANS_WASTE					0x06
#define QSR_INFO_TRANS_FUTURE_ORDER				0x07 //SL Enh #9219 QSR Future order
#define QSR_INFO_TRANS_DONT_RECORD_INVENTORY	0x08
#define QSR_INFO_TRANS_PACKAGE					0x09
#define QSR_INFO_TRANS_CUST_INFO_1				0x0A
#define QSR_INFO_TRANS_CUST_INFO_2				0x0B
#define QSR_INFO_TRANS_CUST_INFO_3				0x0C
#define QSR_INFO_TRANS_CUST_INFO_4				0x0D
#define QSR_INFO_TRANS_PICKUP_INFO				0x0E
#define QSR_INFO_TRANS_ITEM_INSTRUCTIONS		0x0F
#define QSR_INFO_TRANS_PAY_LATER				0x10
#define QSR_INFO_TRANS_REFERENCE_INFO			0x11 // SL Issue #10363/Enh #10363 [RandyB]

/*FSD 3582 Sub-functions for local barcode print info2 transaction */
#define TRS_LOCAL_BARCODE_SUB_FUNC_PRINTED  0   //barcode issued
#define TRS_LOCAL_BARCODE_SUB_FUNC_USED     1   //barcode used
#define TRS_LOCAL_BARCODE_SUB_FUNC_REJECTED 2   //barcode rejected //FSD314464
#define TRS_LOCAL_BARCODE_SUB_FUNC_VOID		3	//barcode Void //FSD314464
#define TRS_LOCAL_BARCODE_SUB_FUNC_GENERATED 4	//coupon barcode promotion triggered FSD324541

enum eLocalBarcodeRejectedReasons //FSD314464 TRS_LOCAL_BARCODE_SUB_FUNC_REJECTED values
{
	eBarcodeRejectNone = 0,
	eBarcodeRejectAlreadyScanned = 1,
	eBarcodeRejectNotFound =2,
	eBarcodeRejectExpired = 3, 
	eBarcodeRejectLocked = 4,
	eBarcodeRejectUsed = 5
}; 

//Stock management info types
#define STOCK_MNG_PSI						1
#define STOCK_MNG_OUTSTANDING_BALANCE		2

//FSD#28462: Action types for trs 0x70 0xAB
#define INGE_VOUCHER_ACTION_ACTIVATION		1  
#define INGE_VOUCHER_ACTION_CONFIRMATION	2 
#define INGE_VOUCHER_ACTION_CANCELLATION	3 
#define INGE_VOUCHER_ACTION_ERROR	        4 //FSD448663

//FSD36846: 0x70 0x33
#define NON_PAYMENT_TICKET_TYPE 16
#define DRIVE_OFF_TICKET_TYPE	17

//Issue #8897SN: EBTWIC INFO2 Sub Opcodes
#define EBTWIC_INFO_TRANS_TICKET_FRAME			0x01
#define EBTWIC_INFO_TRANS_ITEM_SALE				0x02
#define EBTWIC_INFO_TRANS_ERROR					0x06
#define EBTWIC_INFO_TRANS_TICKET_TOTAL			0x08
#define EBTWIC_INFO_TRANS_RX_DETAILS			0x09
#define EBTWIC_INFO_TRANS_TRANS_SIGN			0x0A
#define EBTWIC_INFO_TRANS_TICKET_TAX			0x0B
#define EBTWIC_INFO_TAX_DETAILS					0x0C
#define EBTWIC_INFO_BENEFITS_LIST				0x20
#define EBTWIC_INFO_TRANS_TICKET_END			0x99

//EBTWIC Benefits List Transaction SubTypes
#define EBTWIC_BENEFITS_LIST_HEADER				0x01
#define EBTWIC_BENEFITS_LIST_DETAILS			0x02


//TD#328259
#define TICKET_TYPE_LPE_DATA        12
//FSD58559
#define TICKET_TYPE_REPORT_SCHEMA	19
#define TICKET_TYPE_PRINTING_DATA	20
#define TICKET_TYPE_POS_ADDITIONAL_PRINTING_DATA		31		//FSD#373244_XmlCompressToEJ
#define TICKET_TYPE_POS_DYNAMIC_ATTRIBUTES_DATA		    32      //CR454762- Generic Enhancement for Online Services 


//FSD70780
#define DOCUMENT_DETAILS_TRS	0
#define DOCUMENT_TICKET_TRS		1
#define DOCUMENT_LINK_TRS		2
#define DOCUMENT_UPDATE_FIELD	3

// FSD350935
#define INV_TYPE_SALE_ORIGINAL						1
#define INV_TYPE_RETURN_ORIGINAL					2
#define INV_TYPE_TICKET_CHANGED_RETURN_ORIGINAL		3
#define INV_TYPE_TICKET_CHANGED_SALE_ORIGINAL		4
#define INV_TYPE_SALE_DUPLICATE						5
#define INV_TYPE_RETURN_DUPLICATE					6
#define INV_TYPE_REPRINT_ORIGINAL					7
#define INV_TYPE_REPRINT_DUPLICATE					8
#define INV_TYPE_RECIBO_ORIGINAL					9
#define INV_TYPE_RECIBO_DUPLICATE					10
#define INV_TYPE_RECIBO_REPLACE_SALE_ORIGINAL		11
#define INV_TYPE_RECIBO_REPLACE_RETURN_ORIGINAL		12


#ifndef _LPOS_LINUX_   // V.G. 070402
// whole sale TRS type
typedef enum wholesale_trs_type_
{
	whsttStandard=0,
	whsttCreditSale=1,
	whsttCashSale=2,
	whsttAcctPmt=11,
	whsttAcctPmtRev=12,
    whsttIBSSale=13,
    whsttIBSRet=14,
	whsttPrelRet=21,
	whsttCrdtRet=22,
	whsttVouchRedemp=23,
	whsttCntrlPayPnt=24,

    // types 101 and avove are virtual. they are not real state, but they define
    // a sub state: something was selected from the menu (e.g. sale), but the real
    // state still needs to be fined (e.g. credit sale or cash sale).
    whsttVSale=101,
    whsttVReturn=102,
    whsttVAcctPmt=103,
    whsttVAccRev=104,
	 whsttVFrcReturn=105,
	whsttVSaleCO=106,		//CR19916
    whsttVReturnCO=107		//CR19916
	 
} WHOLESALE_TRS_TYPE;

typedef enum invoice_payment_type_
{
    enInvPmtTypeNormal = 0,
    enInvPmtTypeAcctPmt = 1,    //  Paid through an account payment (offline)
    enInvPmtTypeSplitOfln = 2,  // Split TRS paid offline 
    enInvPmtTypeSplitOnln = 3,  // Split TRS paid online
    enInvPmtTypeFrcCrdReturn = 4,  // Force credit return
	 enInvPmtTypeAnotherTill = 5    // Payment on another till
} INVOICE_PAYMENT_TYPE;
#endif // _LPOS_LINUX_  V.G. 070402

#define  EXT_TRS_PAYMENT        1
#define  EXT_TRS_ALERT          2
#define  EXT_TRS_ONLINE_ALERT   3

#define  EXT_DEVICE_PFS         1
#define  EXT_DEVICE_DOS_PRGRAM  2
#define  EXT_DEVICE_SCOT_MODE   2
#define  EXT_DEVICE_E_TICKET_MODE 3

//Service desk trs types.
#define  SD_TENDER_ONLY         1
#define  SD_POINTS_ONLY         2
#define  SD_TENDER_AND_POINTS   3

//FSD25302 Sub Function type for 70xA6 transaction
#define	DISPLAY_TTL_DISCOUNT				1
#define	PRINT_PRM_BLK_HEADER				2
#define INFO2_DATA_DIA_TEXT					3    // dynamic item attribute text ( 40 char out of 50).
#define ASK_PROM_WHAT_TRIGGERED				4	//#41836
#define EDIT_TENDER_ECCA_NAME				5
#define EDIT_TENDER_ECCA_NUMBER				6
#define EDIT_TENDER_CUST_NUM				7
#define EDIT_TENDER_CUST_NAME				8
#define ORGRCPT_PLU_PRINT_DATA				9

//FSD58540 Cash voucher
#define CASH_VOUCHER_SERIAL_NUMBER_MAX_LEN	14
#define CASH_VOUCHER_SALE					1
#define CASH_VOUCHER_REDEMPTION				2

// #144180
#define CUST_DISP_ERROR_INIT				0
#define CUST_DISP_ERROR_DISPLAY				1

// #144180
#define PRINTER_ERROR_REGULAR				0
#define PRINTER_ERROR_RESUME				1



#define VCHR_TYPE_VOUCHER                   1
#define VCHR_TYPE_COUPON                    2
#define VCHR_TYPE_EXTERNAL                  3
#define VCHR_TYPE_FUEL_LOYALTY              4



// Misc. transaction start/end function (opcodes TRANS_MISC_FRAME, TRANS_MISC_END)
//!yaron!
typedef enum misc_trans_func_
{
	MISCTF_NOTDEF=0,
	MISCTF_ROA=1,
	MISCTF_PAYOUT=2,
	MISCTF_NOSALE=3,
	MISCTF_GTTL=4,
	MISCTF_VISIT=5,
	MISCTF_PRINT_LAST_TRS=6,
	MISCTF_GC_OFFLINE=7
} MISC_TRANS_FUNC;

//#334477: Log control-check reasons in TRS file
typedef enum CC_REASON_
{
	ccre_Undef=0 //undefined

	// Tender >=10, <40
	,ccre_TND_repeat //Tender repeat
	,ccre_TND_open_float //Tender opening float
	,ccre_TND_bypass_tender_template //Bypass tender template printing
	,ccre_TND_max_amount //Tender maximum amount
	,ccre_TND_max_purchase //Tender maximum purchase
	,ccre_TND_floor_limit //Tender floor limit
	,ccre_TND_min_amount //Tender minimum amount
	,ccre_TND_change //Tender change
	,ccre_TND_Min_cashback_amount //Tender minimum cashback amount
	,ccre_TND_Max_cashback_amount //Tender maximum cashback amount
	,ccre_TND_repeat_card  //Repeat card number
	,ccre_TND_max_ticket_count //Tender max ticket count
	,ccre_TND_max_ticket_amount  //Tender max ticket amount

	//Department >=40 <60
	,ccre_DEP_HALO=40 //Department HALO amount
	,ccre_DEP_LALO //Department LALO amount
	,ccre_DEP_cash_privilege //Cashier privilege for Department sale

	//Card range
	,ccre_CR_card_range=50 //Card range control check

	//Bad accounts
	,ccre_BA_bad_account=60 //Bad account authorization 

	// POS Config
	,ccre_LOC_min_amount=70 //POS config - minimum amount
	,ccre_LOC_max_amount //POS config - maximum amount
	

	//Discount
	,ccre_DIS_discount=80 //Discount 
	,ccre_ECCA_bad_account //ECCA bad account

	//ECCA
	,ccre_ECCA_limit_amount=90 //ECCA period amount limit 
	,ccre_ECCA_limit_cash_back //ECCA period cashback limit
	,ccre_ECCA_limit_count //ECCA period count limit

	//Menus
	,ccre_MNU_GenMenuCC=100 //CC set on menusys menu
	
	//Return
	,ccre_RTN_return=110 //Return item/transaction

	//POS/sys pararm >=1000
	,ccre_PP_item_cancel=1000 //Item void (cancel, subtract)
	,ccre_PP_trans_void //Void transaction
	,ccre_PP_price_override //Price override
	,ccre_PP_uchCCMaxPriceOverride //Price override exceeding maximum amount
	,ccre_PP_return_tran_post_act //Return transaction after media
	,ccre_PP_max_total_negative_in_order //Transaction negative value is over thereshold
	,ccre_PP_max_negative_percent_of_the_order //Transaction negative value percent is over threshold
	,ccre_PP_key_weight //Manual weight entry
	,ccre_PP_bypass_chq_print //Bypass cheque printing
	,ccre_PP_bypass_tender_template //Bypass tender template printing
	,ccre_PP_clubcard_dont_match //Clubcard does not amtch
	,ccre_PP_for_disc_min_purch  //Discount minimum purchase
	,ccre_PP_bypass_endorcment //Bypass cheque endorcment
	,ccre_PP_offline_ecca //Offline ECCA
	,ccre_PP_blocked_cust //Blocked customer account
	,ccre_PP_offline_charge_account //Charge account while the POS is offline
	,ccre_PP_not_on_file_charge_account //Customer account not on file
	,ccre_PP_cust_accnt_insufficient_funds //Customer account insufficient credit
	,ccre_PP_accnt_paym_cash_cust //Cash-only customer is paying on account
	,ccre_PP_cust_cheque_zero //Customer has zero cheque balance
	,ccre_PP_additional_check //Give customer additional cheque credit
	,ccre_PP_credit_sale //Credit sale
	,ccre_PP_account_payment //Account payment
	,ccre_PP_account_reversal  //Account payment reversal
	,ccre_PP_additional_credit //Give customer additional credit
	,ccre_PP_allow_coupon_first //A coupon was the 1st item in the sale
	,ccre_SP_more_cpn_than_items //More coupon than items
	,ccre_SP_cpns_subtotal_less_0 //Sale total minus coupons is less than zero
	,ccre_PP_bypass_wic_winz_amt //Bypass WIC/WINZ amount
	,ccre_PP_bypass_wic_date //Bypass WIC/WINZ expiry date
	,ccre_PP_bypass_freq_shop //Bypass non Frequent Shopper
	,ccre_PP_invoice_details //Force Credit Return amount not equal to original invoice
	,ccre_PP_for_saved_trs //Save (suspend) transaction
	,ccre_PP_offline_save_recall_save //Save transaction while POS offline
	,ccre_PP_offline_save_recall_recall //Recall transaction while POS offline
	,ccre_PP_save_tran_tend  //Save transaction with partial tender
	,ccre_PP_for_recalled_trs //Recall transaction
	,ccre_PP_offline_supervisor_request //Offline supervisor request
	,ccre_PP_min_purch_cpn_print //Coupon printing: Minimum purchase for coupon printing
	,ccre_CP_for_minimum_purchase //Coupon printing: Minimum purchase 
	,ccre_PP_invoice_offline_mode //Invoice payment: recall in offline mode
	,ccre_PP_invoice_amnt_not_found //Invoice payment: invoice amount not found
	,ccre_PP_bypass_cashier_not_found //Sign on: cashier not found
	,ccre_PP_save_trs_log_off //Log off while having saved transactions
	,ccre_PP_no_sale_out_trans //No sale open drawer out of a sale
	,ccre_PP_no_sale_in_trans //No sale open drawer during a sale
	,ccre_PP_print_voucher_on_duplicate_receipt  //Print voucher on duplicate receipt
	,ccre_PP_offline_bad_account //Bad account authorization in offline
	,ccre_PP_cust_accnt_transaction //Customer account transaction
	,ccre_PP_scanning_qty_limit //Quanity entered with scanning 
	,ccre_PP_Liquor_license //Liquor license
	,ccre_PP_dep_age_restrict //Department age restriction
	,ccre_PP_bypass_bday //Bypass age valiation
	,ccre_PP_exceed_wic_amt //Exceeding WIC/WINZ amount
	,ccre_PP_manual_name_entry //Manual name entry
	,ccre_PP_sell_qty //Sell quantity
	,ccre_PP_can_sub_limit //Subtract amount limit
	,ccre_PP_max_amount_in_negative_ticket //Maximum amount in negative ticket
	,ccre_PP_can_sub_limit_amt //Cancel/subtract amount greater than limit
	,ccre_PP_staff_disc_min_purchase //Staff discount minimum purchase
	,ccre_PP_freq_shop_min_purch //Frequent shopper minimum purchase
	,ccre_SP_coupon99_out_of_ticket  //EAN 99 coupon out of ticket
	,ccre_PP_GC_CC_Errors //Gift Card sale error
	,ccre_PP_CC_acct_payment //	CC to check account payment against credit limit
	,ccre_PP_LayByCC_ModifyConditions //Modifying lay by conditions
	,ccre_PP_LayByCC_CancellationFee // CC for over-riding cancellation fee
	,ccre_PP_ofln_client // Offline member/client
	,ccre_PP_DiscBigPrice  // Price override greater than price
} CC_REASON;

//!yaron!
typedef struct OnLineTrsData_
{
  unsigned char FC;
  unsigned char opcode;
  unsigned char subopcode;
  unsigned short  pos_no;
  unsigned char option;
  unsigned short  count;
  unsigned char trs[TRANS_LEN];
} ONLINE_TRS_DATA;

//#45246 Transaction Type 
#define TRANSACTION_MODE_SALE			0
#define TRANSACTION_MODE_REFUND			1

//FSD45766
#define EXPENSE_BASIC_TRANSACTION		1
#define EXPENSE_BASIC2_TRANSACTION		10
#define EXPENSE_COST_CENTER_TRANSACTION 13

//FSD168932 Enhanced Payout Receipt On POS Avivp
//TD#293482 DidiO 
#define EXPENSE_ADDITIONAL_REF_TRANSACTION				14
#define EXPENSE_MILEAGE_CLAIM_TRANSACTION				15
#define EXPENSE_AUTOMATIC_MACHINE_TRANSACTION			16
#define EXPENSE_COMMENTS_TRANSACTION					17
#define EXPENSE_ADDITIONAL_REF_COMMENTS_TRANSACTION		18



//FSD168932 Enhanced Payout Receipt On POS Avivp
// Extra data for the expense code being used (for example supervisor approved privileges)
#define EXPENSE_SPECIAL_EXTRA_DATA						99


// FSD316298 - Storeline to HQ Upload Transaction Enhancement
#define EXT_LOYALTY_DATA_TOTAL							1
#define EXT_LOYALTY_DATA_TOTAL_2						2
#define EXT_LOYALTY_DATA_ITEM							3
#define EXT_LOYALTY_DATA_DEP							4

#define EXT_LOYALTY_DATA_MESSAGE_TYPE_1					1
#define EXT_LOYALTY_DATA_MESSAGE_TYPE_2					2
#define EXT_LOYALTY_DATA_MESSAGE_TYPE_3					3
#define EXT_LOYALTY_DATA_MESSAGE_TYPE_4					4
#define EXT_LOYALTY_DATA_MESSAGE_TYPE_5					5
#define EXT_LOYALTY_DATA_MESSAGE_TYPE_6					6

//FSD414790
//Fortress subfunction start
#define	FORTRESS_EXTENDED_WARRANY						0x01
#define	FORTRESS_PRICE_CHANGE			            	0x02
#define	FORTRESS_TRADE_IN1								0x03
#define	FORTRESS_TRADE_IN2								0x04
#define	FORTRESS_TRADE_IN3								0x05
#define	FORTRESS_TRADE_IN4								0x06
#define	FORTRESS_TRADE_IN5								0x07
#define	FORTRESS_TRADE_IN6								0x08
#define	FORTRESS_SERIAL_NUMBER							0x09
#define FORTRESS_REMARK_LINES									0x0A
//Fortress subfunction end

/*----------------------------------------------------------------------
This structure describes the transaction record tail part. The sturcture
of the tail is the same for all transaction types.
-----------------------------------------------------------------------*/
struct trans_tail_							//OFS	Description
{
    unsigned char nu;						//44	Keep for high byte part offset

	unsigned char TwoPO_checker_sign	:1;	//45	For 2 person operation
	unsigned char opt_master_trans		:1;	//45	Master transaction of events (FSD14741)
	unsigned char opt_fuel_test         :1; //45    Pump Test ticket (FSD58636) /  Bug#101812
	unsigned char bInfo					:1; //45
	unsigned char bShouldBeBadRecord	:1;	//45	//TD#336203
	unsigned char nu_flags				:3;	//45	Not used

    unsigned char ext_pos_no;				//46	External POS number
   
    unsigned char ext_device             :4;//47	External device number
    unsigned char quick_till             :1;//47	QUICK POS (Tesco)
    unsigned char dock_till              :1;//47	QUICK docking (Tesco)
    unsigned char opt_scanpoint_item_till:1;//47	SCANPOINT
    unsigned char nu2					 :1;//47    
    
    unsigned short ticket_no;				//48	Ticket number
    unsigned char date[3];					//50	Date (YYMMDD in BCD)
    unsigned char time[3];					//53	Time (HHMMSS in BCD)

    unsigned char opt_return_ticket :1;		//56	Return ticket
    unsigned char opt_training_mode :1;		//56	Training mode ticket
    unsigned char opt_pc_generated  :1;		//56	Record generated by MFS/LFS
    unsigned char opt_pos_offline   :1;		//56	POS was offline
    unsigned char opt_void_ticket   :1;		//56	Ticket was voided
    unsigned char opt_bad_record    :1;		//56	Ignore record
    unsigned char opt_store_count   :1;		//56	Store stock count TRS (Tesco)
    unsigned char opt_wastage_mode  :1;		//56	Tesco

    unsigned short cashier;					//57	Cashier number
    unsigned char pos_no;					//59	POS number
    unsigned short seq_no;					//60	Record sequence number

    unsigned char pc_no         :4;			//62	PC number (1 or 2) receiving TRS from POS
    unsigned char trans_version :4;			//62	TV number
    unsigned char qdx;						//63	QuickDex flags
};											//64

/*----------------------------------------------------------------------
This structure describes the general layout of a transaction record
-----------------------------------------------------------------------*/
struct trs_general_							//OFS	Description
{
    unsigned char opcode;					//0		Transaction record opcode
    unsigned char sub_opcode;				//1		Optional sub opcode
    unsigned char data[TRANS_LEN - 2 - TAIL_LEN];//2
    struct   trans_tail_  tail;					//44
};


/*----------------------------------------------------------------------
Opcode: 0x21
Start of ticket
-----------------------------------------------------------------------*/
struct trs_ticket_frame_					//OFS	Description
{
    unsigned char opcode;					//0		0x21 <Opcode Value="0x21" />

    unsigned char opt_start             :1;	//1		1:Start of ticket 0:not part of a ticket
    unsigned char opt_no_sale           :1;	//1		No sale (drawer open)
    unsigned char opt_negative          :1;	//1		TESCO
    unsigned char opt_eod_progress      :1; //1		TESCO
    unsigned char opt_save_trans        :1;	//1		Ticket was saved for later recall
    unsigned char opt_recall_trans      :1;	//1		Ticket was recalled
    unsigned char opt_void_trans        :1;	//1		Post-void
    unsigned char opt_tender_purchase   :1;	//1		Tender purchase ticket

    unsigned char opt_factura_ticket    :1;	//2		Not used (Guatemalla)
    unsigned char opt_wic_ticket        :1;	//2		WIC transaction
    unsigned char opt_freq_shop         :1;	//2		Frequent shopper ticket
    unsigned char opt_charge_payment    :1;	//2		Account payment
    unsigned char opt_reverse_payment   :1;	//2		Account payment reversal
    unsigned char opt_confirm_price	   	:1;	//2
    unsigned char opt_give_cash_only	:1;	//2		Return TRS: give cash only
    unsigned char opt_multi_tender_allowed	:1;	//2		Return TRS: allow multi tender

    unsigned char return_type;				//3		Return type number
    unsigned short ticket_no;				//4		Ticket number, in case Post-void - voided ticket number
    unsigned short void_ticket_no;			//6		In case Post-void: current ticket number
    unsigned short recall_ticket_no;		//8		Recall: the original (saved) ticket no.

    unsigned short factura_no;				//10	Guatemalla invoices
    //Was: unsigned char  factura_id[15];	//12	Guatemalla invoice
	unsigned char  factura_id[14];			//12	Guatemalla invoice
	
	unsigned char  opt_info_ticket		:1; //26	Information ticket
	unsigned char  opt_trans_continue	:1; //26	There is continue for this transaction
	unsigned char  opt_tender_swap	:1; //26	FS9797
	unsigned char  opt_recovered_ticket	:1;	//26	cr#8389	
	unsigned char  bATMTicket           :1; //26    FSD14667 
	unsigned char  bPriceQuote			:1; //26	FSD14089
	unsigned char  opt_qsr_ticket		:1; //26	FSD23831 QSR Save / Recall  - Indication that this ticket contains qsr items
	unsigned char  opt_cash_office		:1; //26	to indicatie that a no_sale ticket shouldn't be calculated in the no_sale reports.

    unsigned char wic_day;					//27	WIC info: day
    unsigned char wic_month;				//28	WIC info: month
    unsigned short wic_year;				//29	WIC info: year
             long wic_amount;				//31	WIC: amount 

    unsigned char store_no[3];				//35	Store number
    unsigned char recall_pos_no;			//38	Recall: original POS number
    
    // Garage flags
    unsigned char opt_balancing        :1;  //39	Drive off balancing ticket

	unsigned char bLayByTicket         :1;  //39    Lay by ticket (FS19171)

    unsigned char opt_drive_off        :1;  //39	Drive off
    unsigned char opt_fuel_test        :1;  //39	Fuel test
    unsigned char opt_family_favourite :1;  //39	Family_Favourite_Choices	
    unsigned char opt_store_count      :1;  //39	store_count (not Garage flag)
//#ifdef PRJ_ROW
//   unsigned char bRecallPrepay        :1;	//39  N#3269
//    unsigned char opt_take_away        :1;	//39
//#else
    unsigned char opt_eat_in           :1;	//39
    unsigned char opt_take_away        :1;	//39
//#endif    
    // Stuttafords flag
    unsigned char opt_account_cheque_payment :1;//40 
    unsigned char opt_charge_enquiry         :1;//40	
    unsigned char opt_account_payment        :1;//40	
    unsigned char opt_account_fast_payment   :1;//40	
    unsigned char opt_cred_reentry           :1;//40	

    unsigned char opt_self_scanning          :1;//40	Self Scanning ticket
    unsigned char opt_cash_templates         :1;//40	Cash Deposit / Withdrawal
    unsigned char opt_express_order          :1;//40	express ticket
    
    unsigned char opt_wic_issue_date   :1;	//41	Use WIC issue date
    unsigned char opt_coupon_ticket    :1;	//41	First item is coupon
    unsigned char opt_home_shopping    :1;	//41
    unsigned char opt_tender_ticket    :1;	//41	First item is a tender
    unsigned char opt_IH_payment       :1;	//41	First item is IH payment
    unsigned char opt_IH_purchase      :1;	//41	First item is IH purchase
    unsigned char opt_cash_purchase    :1;	//41	Cash tender purchase
    unsigned char opt_deposit_ticket   :1;	//41
    
    unsigned char home_shopping_origin_no;	//42	TESCO
    
	unsigned char opt_archive_ticket    :1; //42    FS1870 ENA
	unsigned char opt_esep_ticket		:2; //43	EASYSHOP and ExpressPoint
#ifdef PRJ_ROW
	unsigned char opt_customer_order    :1; //43	Customer orders
#else
    unsigned char opt_ManEntryHomeShop  :1; //43	Self Scanning voided ticket
#endif
    unsigned char opt_barcoded_tender   :1; //43	COINSTAR
	unsigned char opt_SelfScanningRescan:1; //43	Self scanning Rescan ticket         
	unsigned char opt_SelfScanningForceRescan    :1;	//43	Self scanning with Force ReScan 
	unsigned char opt_HomeShopping_Scanning      :1;	//43	STY - Home Shopping

    struct   trans_tail_  tail;				//44	Transaction tail
};											//64

/*----------------------------------------------------------------------
Opcode: 0x01     TRANS_PLU_SALE
Item sale transaction
-----------------------------------------------------------------------*/
struct trs_plu_sale_						//OFS	Description
{
    unsigned char opcode;					//0		0x01 (or 0x91 for Stock Count, 0x92 for waste mode) <Opcode Value="0x01,0x91,0x92" />
																
    unsigned char code[7];					//1		Item number (BCD)

	unsigned char opt_ext_record		 :1;//8		Extension record 0x11 follows
    unsigned char opt_subtract           :1;//8		Item was subtracted	
    unsigned char opt_cancel             :1;//8		Item was canceled
    unsigned char opt_negative           :1;//8		Negative item
    unsigned char opt_was_cancelled      :1;//8		Fuel item sale canceled
    unsigned char opt_supplier_promotion :1;//8		Item flagged as being on suppler promotion
    unsigned char opt_staff_discountable :1;//8		The item department is flagged as staff discountable
    unsigned char opt_accept_price_override:1;//8		Price override done on this item

    unsigned char opt_item_on_sale       :1;//9		Item is on sale (via front office batch)
    unsigned char opt_price_override     :1;//9		Price override 
    unsigned char opt_manual_price       :1;//9		Price was keyed
    unsigned char opt_manual_price_alloewd :1;//9		Manual price allowed for item
    unsigned char opt_weight_from_scale  :1;//9		Weight read from scale (no manual weight entry)
    unsigned char opt_qty_is_weight      :1;//9		Weighted item sold
    unsigned char opt_qty_is_decimal_qty :1;//9		Decimal quantity item (e.g. meters)
    unsigned char opt_qty_is_fuel_gallons:1;//9		Fuel item sold in gallons

    unsigned char opt_chained_prv_item   :1;//10	Item was sold as a result of link to previous item
#ifdef PRJ_ROW
	unsigned char opt_ext_phone_card	 :1;//10	Next is TRS with the phone card handle #3365
    unsigned char opt_ext_6              :1;//10	PLU extension 6 record 0xD0 follows //FSD251772
	unsigned char opt_extra_code_sale    :1;//10	FSD245239 extra code sale transaction follows
#else // non ROW projects
    unsigned char opt_promotion          :1;//10	Item on promotion 
    unsigned char opt_reduction          :1;//10	Item on reduction
    unsigned char opt_offer              :1;//10	Item on offer
#endif
    unsigned char opt_non_merch          :1;//10	Non-merchandise item
    unsigned char opt_store_coupon       :1;//10	Store coupon item
    unsigned char opt_vendor_coupon      :1;//10	Vendor coupon item
    unsigned char opt_item_discount_flag :1;//10	Discounable item

    unsigned char opt_scanned_item       :1;//11	Item was scanned
    unsigned char opt_read_from_pc       :1;//11	Item read fron front office
    unsigned char opt_next_info			 :1;//11	Hooks: an informative record follows
#ifdef PRJ_USA
	unsigned char optNonRx				:1; //11	13919 - FSA Legal requirements for USA, bit for healthcare items
#else
    unsigned char opt_replacement_to_unitm :1;//11	Indication that this item was sold instead of an unknown item.
#endif
    unsigned char opt_ext_prom           :1;//11	Item on member promotion
    unsigned char opt_price_embeded      :1;//11	ROW: indicates that a tax exclusive price TRS follows
#ifdef PRJ_ROW    
	unsigned char opt_add_calc_price     :1;//11    Add calc price transaction
    unsigned char opt_grid_price_calc    :1;//11    Grid price calculation
#else
	unsigned char opt_phone_card         :1;//11	Phone card
	unsigned char opt_weightToQtyItem    :1;//11	Indicates this item is weight item and was sold as qty.
#endif

#ifdef PRJ_ROW
    unsigned char opt_trade_prom_disc    :1;//12    Confectionary 
	unsigned char opt_bill_payment       :1;//12    CR #22761
    unsigned char opt_bCustomerFee       :1;//12    FS3025 (Delivery and Pick&Pack fee item)
#else
    unsigned char opt_offer_discount     :1;//12	03 will follow
    unsigned char opt_offer_continue     :1;//12	continuation offer
    unsigned char opt_offer_first        :1;//12	01 & 03 will follow
#endif
     unsigned char opt_counter_dept       :1;//12	TESCO taken from dep struct
    unsigned char opt_return_2_stock     :1;//12	TESCO taken from return struct
    unsigned char opt_cost_plus          :1;//12	Cost plus item
    unsigned char opt_freq_shop_disc     :1;//12	Frequent shopper discount given
    unsigned char opt_FS_payment         :1;//12	Payment by food stamps allowed

    unsigned short dept;					//13	Department number
    unsigned char mult_sell_unit;			//15	MSU
    unsigned char return_type;				//16	Return type number
    unsigned char tax_ptr;					//17	Tax flags

    long          qty;						//18	Quantity sold
    long          price;					//22	Item price
    long          amount;					//26	Amount received for this item

    long          nt_price;					//30	ROW: Tax exclusive price
    long          nt_amount;				//34	ROW: Tax exclusive amount
    long          retn_surcharge_percent;	//38
    unsigned char product_code;			   	//42	TESCO: taken from department
    
    unsigned char opt_ext_2             :1; //43	PLU extension record 0x22 follows
    unsigned char opt_markdown          :1; //43	Markdown given on this item		FSD14741 - used this flag for different purpose.
    unsigned char opt_member_disc       :1; //43	Members as frequent shopper: discount given
    unsigned char opt_bottle_deposit    :1; //43	Bottle deposit/refund
    unsigned char opt_bottle_refund     :1; //43	Bottle deposit/refund
#ifdef PRJ_USA
	unsigned char optRx					:1; //43	13919 - FSA Legal requirements for USA, bit for prescription items
#else
    unsigned char opt_rep_code          :1; //43	Rep code captured (ROW)
#endif
    unsigned char opt_limit_qty_prom    :1; //43	A's	 Limited quantity promotion
	unsigned char opt_qty_case			:1; //43	Case Item Sales 

    struct   trans_tail_  tail;				//44	Transaction tail
};											//64


/*----------------------------------------------------------------------
Opcode: 0x02
Open department sale transaction
-----------------------------------------------------------------------*/
struct trs_dep_sale_						//OFS	Description
{
    unsigned char opcode;					//0		0x02 <Opcode Value="0x02,0x93" /> 0x93 - waste mode department trans

    unsigned short  dept;					//1		Department number

    unsigned char opt_ext_record		:1; //3		Trs 0x12 followed
    unsigned char opt_subtract          :1;	//3		Was subtracted
    unsigned char opt_cancel            :1;	//3		Was canceled
    unsigned char opt_negative          :1; //3		Negative item
    unsigned char opt_was_cancelled     :1;	//3		Fuel item sale canceled
    unsigned char opt_bottle_deposit    :1; //3		Bottle deposit/refund
    unsigned char opt_bottle_refund     :1; //3		Bottle deposit/refund
#ifdef PRJ_ROW								 
	unsigned char opt_scr_sls_flag      :1; //3		Pharmacy script 
#else
    unsigned char opt_accounting_flag   :1; //3		Barcode programming
#endif

    unsigned char opt_not_found_sell    :1;	//4		Sold after item was not found
    unsigned char opt_price_override    :1;	//4		Price override 
    unsigned char opt_manual_price      :1; //4		Price was keyed
    unsigned char opt_manual_price_alloewd:1; //4		Manual price allowed for item
    unsigned char opt_weight_from_scale :1; //4		No manual weight entry
    unsigned char opt_qty_is_weight     :1; //4		Weighted item sold
    unsigned char opt_qty_is_decimal_qty:1;	//4		Decimal quantity item
    unsigned char opt_qty_is_fuel_gallons:1;//4		Fuel item sold in gallons

    unsigned char opt_chained_prv_item  :1;	//5		Item was sold as a result of link to previous item
    unsigned char opt_as_cost_plus      :1;	//5		Cost plus
    unsigned char opt_promotion         :1; //5		Item promotion flag
    unsigned char opt_non_merch         :1;	//5		Non merchendise department
    unsigned char opt_store_coupon      :1;	//5		Store coupon department
    unsigned char opt_vendor_coupon     :1;	//5		Vendor coupon department
    unsigned char opt_dept_discount_flag:1;	//5		Discount allowed for this department
    unsigned char opt_FS_payment        :1;	//5		Payment by foodstamps allowed

    unsigned char opt_cost_plus         :1;	//6		Cost plus item
    unsigned char opt_ext_prom          :1;	//6		Item on member promotion
    unsigned char opt_staff_discountable:1;	//6		Staff discounts allowed
    unsigned char opt_counter_dept      :1;	//6		Counter department (TESCO)
    unsigned char dont_disp_weight_and_qty	:1;	//6		TESCO
    unsigned char opt_fee               :1;	//6		Service fee
    unsigned char opt_refund_dept       :1;	//6
#ifdef PRJ_ROW
	unsigned char opt_add_calc_price	:1;	//6		Add calc price transaction
#else
    unsigned char opt_dep_additional_data:1;//6
#endif
    unsigned char return_type;				//7		Return type number
    unsigned char tax_ptr;					//8		Tax flags
    unsigned char product_code;				//9		TESCO: taken from department
    unsigned char pre_pay_pump_no;			//10	PosPump : Pre-Pay		
    unsigned long cancelled_pre_pay_sync_no;//11	PosPump : Pre-Pay		

	unsigned char opt_surcharge         :1;	//15	Indicate surcharge department sale.
    unsigned char opt_deliveryCharge    :1;	//15	Indicate delivery charge department sale
    unsigned char opt_info              :1; //15	FS1866 DEP Sale apportionment (info flag)
	unsigned char opt_chargeAmountPerTaxCalculation:1; //15    Indicate dep sell apportionment trans (#10194)
	unsigned char opt_markdown			:1;	//15	FSD14741 - used this flag to indicate that this sale took part in promotion.
	unsigned char optRx					:1;	//15    13919 - FSA Legal requirements for USA, bit for prescription items
	unsigned char optNonRx				:1;	//15	13919 - FSA Legal requirements for USA, bit for healthcare items
	//unsigned char NU                  :1; //15	NU
	unsigned char opt_weightToQtyItem	:1; //15	TD#42705 GinatB - Indication of item is weight
    
    long          qty;						//16	Quantity sold
    long          price;					//20	Price
    long          amount;					//24	Amount received for this item

    long          nt_price;					//28	ROW: Tax exclusive price
    long          nt_amount;				//32	ROW: Tax exclusive amount

    long          at_qty;					//36
    long          retn_surcharge_percent;	//40

    struct   trans_tail_  tail;				//44	Transaction tail
};											//64

/*----------------------------------------------------------------------
Opcode: 0x03
Discount/promotion tranasaction
-----------------------------------------------------------------------*/
struct trs_discount_						//OFS	Description
{
    unsigned char opcode;					//0		0x03 <Opcode Value="0x03" />

    unsigned char plu_code[7];				//1		Item number (if discount given to an item)
    unsigned short  dept;					//8		Department number 

    unsigned char opt_info_trans       :1;	//10	Ignore this transaction
    unsigned char opt_non_merch        :1;	//10	None merchendise item/department
    unsigned char opt_subtract         :1;	//10	Item was subtracted
    unsigned char opt_cancel           :1;	//10	Item was canceled
    unsigned char opt_negative         :1;	//10	Negative item
    unsigned char opt_upcharge         :1;	//10	Negative discount
    unsigned char opt_additive         :1;	//10	Additive discount
    unsigned char opt_deliv_charges    :1;	//10	Delivery charges (was progressive)

    unsigned char opt_manual           :1;	//11	Manual discount
    unsigned char opt_percent          :1;	//11	Percentage discount
    unsigned char opt_cost_plus        :1;	//11	Cost plus item/department
    unsigned char opt_FS_payment       :1;	//11	Foodstambable item
    unsigned char opt_store_promotion  :1;	//11	Not used
    unsigned char opt_ttl_trans_disc   :1;	//11	Ticket discount
    unsigned char opt_plu_trans_disc   :1;	//11	Item discount	
    unsigned char opt_dep_trans_disc   :1;	//11	Department discount

#ifdef PRJ_ROW
#ifdef PRJ_ROW_NEW_PROM
    unsigned char opt_promotion         :1;	//12	Promotion given; CR#38963
    unsigned char opt_reduction         :1;	//12	Reduction given		
    unsigned char opt_offer             :1;	//12	Offer given
#else
	unsigned char price_over_as_disc	:1; //12	Price override treated as discount
	unsigned char bPickPackFee          :1; //12    FS3025 - Pick&Pack fee  #436096: Used by Foodtuffs Wellington to indicate that a promotion requires a member card
    unsigned char bMinDeliveryFee       :1;	//12	FS3025 - Minimum delivery fee
#endif
#else
    unsigned char opt_promotion         :1;	//12	Promotion given
    unsigned char opt_reduction         :1;	//12	Reduction given		
    unsigned char opt_offer             :1;	//12	Offer given
#endif
    unsigned char opt_multisaver        :1;	//12	
    unsigned char opt_ext_promotion     :1;	//12	Extended promotion
    unsigned char opt_not_net_prom      :1; //12	None-netted promotion
    unsigned char opt_member_disc       :1; //12	Frequent shopper discount
    unsigned char opt_discount_flag     :1; //12	Item/department "discount allowed" flag. Used in cases of promotions

    unsigned char discount_type;			//13	Discount number
    unsigned long percent;					//14	Discount percent
    unsigned char return_type;				//18	Return type number
    unsigned char tax_ptr;					//19	Tax flags of discountable item

    long          qty;						//20	Item quantity
    long          price;					//24	Item price
    long          amount;					//28	Discount amount


#ifdef PRJ_ROW
#ifdef PRJ_ROW_NEW_PROM
    unsigned char opt_points_reward    	:1;	//32	Points given as reward;  CR#38963
	unsigned char bCustAccntDiscount    :1; //32    FSD16729 Customer Account discount
	unsigned char bExtTrs               :1; //32    Extended trs (future use)
#else
	unsigned char opt_extra_fee1       	:1; //32	Extra fee 1
	unsigned char opt_extra_fee2       	:1; //32	Extra fee 2
	unsigned char opt_fin_fee         	:1; //32	Finance fee
#endif
#else
    unsigned char opt_points_reward    	:1;	//32	Points given as reward
	unsigned char bCustAccntDiscount    :1; //32    FSD16729 Customer Account discount
	unsigned char bExtTrs               :1; //32    Extended trs (future use)
#endif
	
    unsigned char opt_automatic        	:1; //32	Automatic discount 
	unsigned char opt_delayed_prom     	:1; //32	Delayed promotion (LUCKY)
	unsigned char opt_report_as_tender 	:1; //32	Report discount as tender (LUCKY)
    unsigned char opt_not_net_fs		:1; //32	Non-Netted promotions/frequent shopper
	unsigned char opt_staff_discount   	:1; //32	Staff discount (ROW)
    
    unsigned char mult_sell_unit;			//33	Item MSU
	unsigned short tender;					//34	Tender number (LUCKY)
    long          nt_amount;				//36
    long          retn_surcharge_percent;	//40

    struct   trans_tail_  tail;				//44	Transaction tail
};											//64

/*----------------------------------------------------------------------
Opcode: 0x04
Media transaction
-----------------------------------------------------------------------*/
struct trs_media_							//OFS	Description
{
    unsigned char opcode;					//0		0x04 <Opcode Value="0x04" />

    unsigned short  no;						//1		Tender number

    unsigned char opt_change           :1;	//3		Change given transaction
    unsigned char opt_rounding         :1;	//3		Rounding done
    unsigned char opt_subtract         :1;	//3		Tender subtracted
    unsigned char opt_cancel           :1;	//3		Tender canceled
    unsigned char opt_was_cancelled    :1;	//3		Fuel: tender canceled
    unsigned char opt_return           :1;	//3		Not used
    unsigned char opt_given_as_reward  :1;	//3     Redemption
    unsigned char opt_tender_purchase  :1;	//3		Tender purchase

    unsigned char opt_multi_part_rcpt  :1;	//4		Print multi-part receipt
    unsigned char opt_confirm_signature:1;	//4		Confirm signatue
    unsigned char opt_charge_posting   :1;	//4		Charge posting tender
    unsigned char opt_ecca             :1;	//4		Use ECCA with this tender
    unsigned char opt_ecca_defined     :1;	//4		ECCA record defined
    unsigned char opt_issue_no_used    :1;	//4
    unsigned char opt_accept_isu_date  :1;	//4
    unsigned char opt_accept_exp_date  :1;	//4		Expiry date accepted

    unsigned char opt_MCR_used         :1;	//5		Magnetic card reader used
    unsigned char opt_auth_checked     :1;	//5		Authrosization done
    unsigned char opt_not_auth         :1;	//5		Authorization not done
    unsigned char opt_account          :1;	//5		Account number field used
    unsigned char opt_eft_print_data   :1;  //5         
    unsigned char opt_account_auth_alfa:1;	//5		Account number TRS follows
    unsigned char media_ext            :1;	//5		Media extentios TRS follows
    unsigned char opt_accept_auth_no   :1;	//5		Account number entered manually

    unsigned char opt_next_car_info    :1;	//6		Car info TRS follows
    unsigned char opt_buyaid           :1;	//6		Tender is a buy-aid
    unsigned char opt_ecca_new         :1;	//6		New ECCA record
    unsigned char opt_eft_auth         :1;	//6		Authorized by EFT
    unsigned char opt_coupon_sale      :1;	//6		Coupon sale
    unsigned char opt_next_chq_grty    :1;	//6		Cheque guarantee TRS follows
    unsigned char opt_cashback         :1;	//6		Cashback
    unsigned char opt_reverse_balancing:1;	//6		Customer account purchase or payment

    unsigned char type;						//7		Tender type/class
    long          amount;					//8		Tender amount or cashback
    long          foreign_amount;			//12	Foreign currency amount
    long          foreign_rate;				//16	Foreign currency rate

    unsigned char isu_date[2];				//20	Issue date
    unsigned char account[10];				//22	Account number
    unsigned char state_code[2];			//32	USA state code
    unsigned char exp_date[2];				//34	Expiry date
    unsigned char auth_no[4];				//36	Authorization number
#ifdef PRJ_ROW
    unsigned char card_range_no			:4;	//40	Card range number
	unsigned char opt_media_ext4        :1; //40      Media extention 4 follows
	unsigned char media_ext3            :1;	//40	Media extention 3 follows
	unsigned char opt_media_ext5		:1;	//40	Media extention 5 follows
	unsigned char nu_bit	            :1;	//40	not used
#else	
    unsigned char card_range_no;			//40	Card range number
#endif
    
    unsigned char account_len           :5; //41	Account number length
#ifdef PRJ_ROW 	    
	unsigned char opt_recall_inv        :1; //41	Recall invoice indicator
    unsigned char opt_credit_sale       :1;  //41	Credit sale indicator (Split trans.)
#else
	unsigned char opt_media_ext4        :1; //41      Media extention 4 follows
	unsigned char media_ext3            :1;	//41	Media extention 3 follows
#endif
    unsigned char media_ext2            :1;	//41	Media extention 2 follows
    
    unsigned char issue_no;					//42	Issue number
    char 		   count;					//43	Tender count
    
    struct   trans_tail_  tail;				//44	Transaction tail
};											//64

/*----------------------------------------------------------------------
Opcode: 0x06
Ticket tax info
FSD16204: New transaction 0x0D reflecting Reward By Tender tax data has been added - 
the tax data struct will be the same for both 0x06 and 0x0D but tax calculations
will be based on different taxable amounts
-----------------------------------------------------------------------*/
struct trs_ticket_tax_						//OFS	Description
{
    unsigned char opcode;					//0		0x06 or 0x0D <Opcode Value="0x06,0x0D" />
    unsigned char tax_no;					//1		Tax rate number
    long 			taxable_amount;			//2		Taxable amount
    long 			tax_amount;				//6		Tax amount

    unsigned char exemptable   :1;			//10	Tax exempt given
    unsigned char tax_included :1;			//10	GST inclusive tax
    unsigned char uchZeroRated :1;			//10	KobiM - FSD121574 - Zero rated tax
    unsigned char opt_nu3      :1;			//10	Not used
    unsigned char opt_nu4      :1;			//10	Not used
    unsigned char opt_nu5      :1;			//10	Not used
    unsigned char opt_nu6      :1;			//10	Not used
    unsigned char opt_nu7      :1;			//10	Not used

    unsigned char exempt_no[10];			//11	BCD 19 digits right justify

    long 			FS_forgive_taxable;		//21	Food stamps forgiven taxable amount
    long 			FS_forgive_tax;			//25	Food stamps forgiven tax amount
//#ifndef TAX_REDUCTION_RULES
	long            tax_reduction;                 //FSD231586  
//#else
//	long 			nt_amount;				//29	Not used
//#endif
	
    long 			tax_refund_amount;		//33	refunded tax
	unsigned char   type;					//37    Tax type FS22354
	unsigned long   rate;					//38    Tax rate FS22354

	unsigned char uchTaxPrintChar;			//42	Tax print char
    unsigned char reserved;					//43	Not used
    struct   trans_tail_  tail;				//44	Transaction tail
};											//64

/*----------------------------------------------------------------------
Opcode: 0x05
Ticket total (end of ticket transaction)
-----------------------------------------------------------------------*/
struct trs_ticket_total_					//OFS	Description
{
    unsigned char opcode;					//0		0x05 <Opcode Value="0x05" />

    unsigned char opt_ticket_total       :1;//1		1:ticket total. 0:not a ticket total TRS
    unsigned char opt_void_ticket        :1;//1		Voided ticket
    unsigned char opt_save_ticket        :1;//1		Saved transaction
    unsigned char opt_recall_trans       :1;//1		Recalled transaction
    unsigned char opt_drive_off          :1;//1		Garage: drive off
    unsigned char opt_quick_store        :1;//1		TESCO: Quick terminal
    unsigned char opt_info               :1;//1		to update PC with POS grand ttl.
    unsigned char opt_tender_purchase    :1;//1		Tender purchase ticket

    unsigned char opt_coupon_ticket      :1;//2		First item was a coupon	
    unsigned char opt_tender_ticket      :1;//2		First item was a tender
    unsigned char opt_IH_payment         :1;//2		First item is IH payment
    unsigned char opt_IH_purchase        :1;//2		First item is IH purchase	
    unsigned char opt_send_to_email      :1;//2		Send ticket by email
    unsigned char opt_send_to_qbuster    :1;//2		Enh #65SL Q-Buster @ POS
    unsigned char TaxVoucherRequested    :1;//2		Not used
    unsigned char opt_ProhibitPostVoid   :1;//2		CR9266

    unsigned short  ticket_no;				//3		Ticket amount
    long          tax_value;				//5		Not used
    short           items;					//9		Number of items in ticket

    long          amount;					//11	Total ticket value
    long          discount;					//15	Not used
#ifdef C4_STYLE_REWARD_AS_TENDER
    long          amount_with_reward_by_tender;	//19 FSD16204 Ticket total including RewardByTender discount amt
#else
	long          nt_amount;				//19	Not used
#endif
    long          nt_discount;				//23	Not used

    unsigned char grand_ttl[6];				//27	POS grand total sales value
    unsigned char return_type;				//33	Return type number (if a return ticket)

	long		  food_stamp_real_payment;	//34	Not used
	long    amount_without_electronic_cpns;	//38	Total amount excluding elec. couponss
	unsigned short z_count;					//42	//FS20572_2
    
    struct   trans_tail_  tail;				//44	Transaction tail
};											//64


/*----------------------------------------------------------------------
Opcode: 0x64
Ticket printout, not compressed
-----------------------------------------------------------------------*/
struct trs_printout_						//OFS	Description
{
    unsigned char opcode;					//0		0x64	<Opcode Value="0x64" />

    unsigned char end               :1;		//1		End of ticket text
    unsigned char start             :1;		//1		Start of text
    unsigned char pre_blank_lines	:2;		//1		Inset blank lines above text ( up to 3 pre blank lines)
    unsigned char print_only_2_ej	:1;		//1		Print to EJ only, not on receipt
    unsigned char cut	           	:1;		//1		Cut paper
    unsigned char emph              :1;		//1		Print enphasised
    unsigned char enlarge           :1;		//1		Print enlarged

    unsigned char text[40];					//2		Text to print
    
	unsigned char enlarge_vertical  :1;		//42		Vertical enlarge
	unsigned char nu_7              :7;		//42
	
	unsigned char supported_line_chars;		//43	
    
    struct   trans_tail_  tail;				//44	Transaction tail
};

/*----------------------------------------------------------------------
Opcode: 0x0A
Cashier time/performance statistics
-----------------------------------------------------------------------*/
struct trs_times_							//OFS	Description
{
    unsigned char opcode;					//0		0x0A <Opcode Value="0x0A" />

    unsigned char pos_mode;					//1		Logs the mode the POS was in (sale, tender, idle etc.)

	// The following log the total times during the cashier shift
    unsigned short  item_reg_time;			//2		Total item registration time
    unsigned short  idle_time;				//4		Total idle time
    unsigned short  secure_time;			//6		Total secure time
    unsigned short  tender_time;			//8		Total tender time
    unsigned short  wait_time;				//10	Total wait time
    unsigned short  inq_time;				//12	Total inquiry time
    unsigned short  other_time;				//14	Total other time

    unsigned char quarter_hour  :1;			//16	TESCO
    unsigned char sign_off      :1;			//16	TESCO
    unsigned char nu3           :1;			//16	Not used
    unsigned char nu4           :1;			//16	Not used
    unsigned char nu5           :1;			//16	Not used
    unsigned char nu6           :1;			//16	Not used
    unsigned char nu7           :1;			//16	Not used
    unsigned char express_order :1;			//16	Express ticket (less than 10 items)
    
    // Delta time: time since last 0x0A TRS
    unsigned short  delta_item_reg_time;	//17	Item registration time
    unsigned short  delta_idle_time;		//19	Idle time
    unsigned short  delta_secure_time;		//21	Secure time
    unsigned short  delta_tender_time;		//23	Tender time
    unsigned short  delta_wait_time;		//25	Wait time
    unsigned short  delta_inq_time;			//27	Inquiry time
    unsigned short  delta_other_time;		//29	Other time

    unsigned short  sign_on_time;			//31	Total sign on time
    unsigned short  delta_sign_on_time;		//33	Delta sign one time

	unsigned long   maint1;					//35	Maint recieved statistics
 	unsigned long   maint2;					//39	Maint recieve statistics
    unsigned char   local_maint_Q;			//43	Pending maintenance records

    struct   trans_tail_  tail;				//44	Transaction tail
};											//64


/*----------------------------------------------------------------------
Opcode: 0x11
PLU sale extension record
-----------------------------------------------------------------------*/
struct trs_plu_sale_ext_					//OFS	Description
{
    unsigned char opcode;					//0		0x11 <Opcode Value="0x11" />

    unsigned char code[7];					//1		plu code					

    unsigned char opt_pump_test			:1;		//8		Fuel: pump test TRS
    unsigned char opt_fuel_trs			:1;		//8	    Fuel transaction
    unsigned char opt_recalled_trs		:1;		//8		Fuel recalled TRS
    unsigned char opt_drive_off 		:1;		//8		Fuel: drive off
    unsigned char opt_prepay_trs 		:1;		//8		Fue: pre-paid TRS
	unsigned char opt_postpay_accepted  :1;		//8		Index/Defect #13482SL/#13482SL
    unsigned char opt_postpay_paid    	:1;		//8		Index/Defect #13482SL/#13482SL
    unsigned char opt_manual_fuel 		:1;		//8		Issue #9270SN

    unsigned char opt_cs_tax_comb :1;		//9
    unsigned char opt_SelfScaningAditionalItem:1;		//9		Not used
#ifdef PRJ_ROW
    unsigned char opt_self_scan_notOK 		:1;		//9 SelfScan22304FS
#else
    unsigned char opt_vensafe_item	:1;		//9		Not used
#endif
    unsigned char opt_external_modify				:1;		//9		QSR Merge [RandyB]
    unsigned char opt_plu_void_at_end		:1;		//9		//FSD42826
    unsigned char uch_DEA_override_approved	:1;		//9		FSD54875
#ifdef PRJ_USA
    unsigned char opt_laneHawk_item			:1;		//9		SL_US Issue #17615 [ShlomitG]
#else
    unsigned char opt_BagReUsePLU			:1;		//9		FSD51799
#endif
    unsigned char opt_SaleForPumpTest		:1;		//9		FSD58093

    unsigned char pump;						//10	pump number
    unsigned char fuel_grade;				//11	grade number
	unsigned long pump_trans_no;			//12	synch no.					
    unsigned char nozzle;					//16	Pump nozzle number

    //Copy of values from PLU transaction - needed for SQL tables
    long           qty;						//17	Quantity sold
    long           price;					//21	Item price
    long           amount;					//25	Amount taken

    long fuel_disp_price;					//29	Grade price, 3 decimal digits
    
	long          nt_amount;				// 33   SL Issue #7826/Bug #7914 [RandyB] non-GST amount
	unsigned long	external_sale_handle;	// 37	SL Issue #7737/Enh #7737 [RandyB] QSR sale handle

	union
	{    
	    short			prepay_ticket_no;	// 41   Defect #14148 - Need to know original prepay ticket number in case of multiple prepay recalls
        unsigned char   tank_no;            // 41   #70523: Pump Test Enhancemnt not returning fuel to Tanks
    };

	//unsigned char	opt_vending_item 		:1;// 43
	//unsigned char	reserved				:7;// 43
	unsigned char uchPluLen;				//43	TD#87705
	
    struct   trans_tail_  tail;				//44	Transaction tail
};											//64

/*----------------------------------------------------------------------
Opcode: 0x12
Department sale extension record
-----------------------------------------------------------------------*/
struct trs_dep_sale_ext_					//OFS	Description
{
    unsigned char opcode;					//0		0x12 <Opcode Value="0x12" />

    unsigned short  dept;					//1		Department no.

    unsigned char opt_pump_test		:1;     //3		Fuel: pump test TRS
    unsigned char opt_fuel_trs		:1;		//3	    Fuel transaction
    unsigned char opt_recalled_trs	:1;		//3		Fuel recalled TRS
    unsigned char opt_current_trs	:1;		//3		TESCO Garage
    unsigned char opt_drive_off 	:1;		//3		Fuel: drive off (ALB)
	unsigned char opt_SelfScaningAditionalItem:1;		//3		used by self scanning systems
    unsigned char opt_parking_trs	:1;		//3		FSD39663 - parking transaction
    unsigned char opt_dep_void_at_end    	:1;		//3	FSD42826 - Cashier age Validation

    unsigned char bPrintOnReceipt	:1;			//4		Not used
    unsigned char opt_manual_fuel  	:1;			//4		FSD57577 Manual Fuel Flag
    unsigned char bItemAllreadyPrintedOnKitchenDoc :1; //4	//FSD62785 - StoreLine Kitchen printing support
    unsigned char bExtraFeeSale    	:1;			//4		//FSD307721
    unsigned char opt_nu14    	:1;			//4		Not used
    unsigned char opt_nu15    	:1;			//4		Not used
    unsigned char opt_nu16    	:1;			//4		Not used
    unsigned char opt_nu17    	:1;			//4		Not used

    unsigned char pump;						//5		Pump number
    unsigned char fuel_grade;				//6		Grade number
	unsigned long pump_trans_no;			//7		Synch no.
    unsigned char nozzle;					//11	Nozzle no.
    
    //Copy of values from DEP transaction - needed for SQL tables
    long           qty;						//12	Quantity sold
    long           price;					//16	Item price
    long           amount;					//20	Amount taken
    
    long fuel_disp_price;					//24	Grade price, 3 decimal digits			
    unsigned char  sSalesPersonTemplate[10];//28	Sales Person Template
	unsigned short sSalesPersonTillNo;		//38	Sales Person till number
    unsigned short ushGroupId;              //40
    unsigned char  reserved[2];             //42       Not used


    struct   trans_tail_  tail;				//44	TRS tail
};											//64


/*----------------------------------------------------------------------
Opcode: 0x22
PLU sale extention record 2
-----------------------------------------------------------------------*/
struct trs_plu_sale_ext2_					//OFS	Description
{
    unsigned char opcode;					//0     0x22 <Opcode Value="0x22" />
    unsigned char code[7];					//1     plu code					
    unsigned char liquor_type;				//8     Liquour/Tobacco type

	unsigned char opt_bonus_item			:1;   //9
	unsigned char opt_pick_qty_zero			:1;
#ifdef PRJ_ROW
	unsigned char opt_qty_is_weight			:1;//9		Weighted item sold
    unsigned char opt_qty_is_decimal_qty	:1;//9		Decimal quantity item (e.g. meters)
    unsigned char opt_qty_is_fuel_gallons	:1;//9		Fuel item sold in gallons
#else
	unsigned char opt_homeDeliveryCharge	:1;	//9	Indicate delivery charge plu sale
    unsigned char opt_parcelPickCharge		:1;	//9	Indicate delivery charge plu sale
	unsigned char opt_extraCode				:1;	//9 Indicate Extra code value is valid
#endif
	unsigned char opt_price_overr_calc		:1;//9     CC&C pricing
	unsigned char bOptOnlinePurchaseItem    :1;//9     FS3012						
	unsigned char bLaybyFeeSale				:1;//9	FSD3928

#ifdef PRJ_ROW
	long          qty;						//10	Quantity sold
    long          price;					//14	Item price
    long          amount;					//18	Amount taken
	unsigned char price_type;               //22    Price type
	unsigned short mult_sell_unit;			//23	MSU
#ifdef PRJ_PRICELINE
	unsigned char opt_scr_sls_flag  :1;		//25	Pharmacy script  cr#3040
	unsigned char opt_scr_sls_void  :1;		//25	script void cr#3040
	unsigned char bSaleInReturnTrs  :1;		//25	A sale of a script in a return transaction
	unsigned char opt_nu			:5;		//25	not used

    long  retn_surcharge_percent;   //26     cost-plus surcharge on refund item cr#3113
#else //#ifdef PRJ_PRICELINE
    unsigned char sOutOfStockCode[5];		//25 FSD14255
#endif
#else //#ifdef PRJ_ROW
	unsigned char strExtraCode[20];			//10     ExtraCode (FS20617)
#endif

#ifdef PRJ_ROW
	unsigned char sBCDInternalCode[7];      //30     BCD Internal Item code
#else
    unsigned char sBCDOrgItemCode[7];		//30     BCD original Item code	 (The item code of the drill down item)
#endif

	unsigned char bAdditionalReceiptItem		:1;	//37	//FSD3580
	unsigned char bProhibitDiscount				:1;	//37	//FSD3585
	unsigned char bGiftCardBalanceItemSale		:1;	//37	//#7405
	unsigned char bNotFoundSale					:1;	//37	// #8628
	unsigned char bItemSoldByBarcodeProgramming :1;	//37	//FS3585
	unsigned char bLaybyModifyRefundItem		:1; //37	//FSD6248
	unsigned char bDeliveryItem					:1;	//37	//FSD11254
	unsigned char bOptExternalPosItem   		:1;	//37    //FSD7315

	unsigned char ucExternalItemRef ;         //38     //FSD7315   
	unsigned char bDepositableItem				:1;			//39
	unsigned char bStockAllocationType			:1;			//39 FSD11254
	unsigned char ucStockMngBits				:5;			//39
	unsigned char bOptBillPayment            	:1;   		//39 FSD2615	

	//removed sBCDSubstractedQty for unsolved old bug #3051
	unsigned char bDoNotIncreaseItemCount	:1;			//40 FSD29687
	unsigned char bOnlinePurchaseItemIncludeCommission	:1; //FSD26777
	unsigned char bExtraFeeSale				:1;		//#40131 mark extra fee flag
	unsigned char bCancelledItem            :1;     //CR#43068
	unsigned char bLicenseValid				:1;		//FSD55249
	unsigned char bRepeat					:1;		//CR#53701
	unsigned char bParkingItem				:1;		//FSD59807
	unsigned char bDataBarItemSale			:1;		//FSD28013	 

    unsigned char  POSItemMessageID;	    //41 //FSD65262						//41
	unsigned short ushOriginalPluSeqNo;		//42     the sequence number  of the plu in original ticket (before save/recall)

    struct   trans_tail_  tail;				//44    TRS tail							
};											//64

/*----------------------------------------------------------------------
Opcode:		0x16
Payout / Receipt
-----------------------------------------------------------------------*/
struct trs_paidout_receipt_					//OFS	Description
{
    unsigned char opcode;					//0		0x16 <Opcode Value="0x16" />

    unsigned char expence_code;				//1		Expense code
    unsigned char expence_referance[10];	//2		Reference number

    long          amount;					//12	Amount
    unsigned char tender;					//16	Tender number

    unsigned char post_accntblty   :1;		//17	POS accountability
    unsigned char opt_reprocess    :1;		//17	Process this record only if re-process mode
    unsigned char opt_amount_int64 :1;		//17	Use the int64 amount 
    unsigned char opt_enhanced     :1;		//17	Enhanced payout/roa
    unsigned char auto_trans   	   :1;		//17	FSD#166552
    unsigned char opt_TenderByUnit :1;		//17	FSD#166552
    unsigned char paidout     	   :1;		//17	Not used
    unsigned char receipt     	   :1;		//17	Not used

    long          expn_code;				//18	Enhanced expense code number
    long          vat_amount;				//22	VAT amount
    
	unsigned char expense_code_1[4];		//26	4 more characters of reference no.
	unsigned short user;					//30	B/O user number
	unsigned short safe_no;					//32	Safe number
#ifdef PRJ_ROW
    unsigned char  qty;						//34	Tender quantity           
    struct
    {
		unsigned char seq_no   :3;			//35	This is record #xxx for this payout/payin trs
											//			0: main transaction
											//			1: rounding transaction
											//			2: tender transaction
											//			3: change transaction
		unsigned char change   :1;			//35	Change given to customer
		unsigned char rounding :1;			//35	Rounding applied at POS
		unsigned char notused  :3;			//35	Not used
    } flags2;
#else
    unsigned short  qty;                    //34	Tender quantity
#endif
	__int64       amount2;					//36	Amount (if opt_amount_int64 set)

    struct   trans_tail_  tail;				//44	TRS Tail
};											//64

/*----------------------------------------------------------------------
Opcode:		0x60 
Subopcode:	0x01 TRANS_INFO_NONFND
Item not found
-----------------------------------------------------------------------*/
struct trs_plu_nonfnd_						//OFS	Description
{
    unsigned char opcode;					//0		0x60 <Opcode Value="0x60" />
    unsigned char function;					//1		0x01 <Opcode Value="0x01" />

    unsigned char code[7];					//2		Item number

    unsigned char opt_scanned_item      :1;	//9		Item was scanned
    unsigned char opt_inquery           :1;	//9		Item was lookked up via inquiry
    unsigned char opt_info              :1;	//9		Informative record
    unsigned char opt_DepSaleUnknown    :1;	//9		FS21409
    unsigned char opt_ExtraCode         :1;	//9		Extra Code
    unsigned char opt_nonfnd_sold		:1;	//9		Not used
    unsigned char opt_WasteMode         :1;	//9		Waste Mode - FSD277889
    unsigned char opt_nu17              :1;	//9		Not used

	unsigned char pos_offline           :1; //10	Indicate if POS is offline
    unsigned char used_unknow_item_logic:1; //10	if using the unknown item logic (Sainsbury's)
    unsigned char unitmsrv_alive        :1; //10	if POS got ACK for the unknown item request
    unsigned char received_plu_info     :1; //10	if POS got ANS for the unknown item request
	unsigned char invalid_plu_details   :1; //10	Answer not valid
	unsigned char external_srv_allive   :1; //10	Cyber not alive
    unsigned char nu4	                :2;	//10	Not used

	unsigned char strExtraCode[20];			//11     ExtraCode (FS20617)

    unsigned char nu[13];					//31	Not used

    struct   trans_tail_  tail;				//44	TRS tail
};											//64

/*----------------------------------------------------------------------
Opcode:		0x60 
Subopcode:	0x02
EFT communication transaction. Used by V7 POS with SMT EFT
-----------------------------------------------------------------------*/
struct trs_eft_com_							//OFS	Description
{
    unsigned char opcode;					//0		0x60 <Opcode Value="0x60" />
    unsigned char function;					//1		0x02 <Opcode Value="0x02" />

    unsigned char status;					//2		1 - fail clear input
											//		2 - timeout on first ack
											//		3 - NAK on first req
											//		4 - not ACK on first req
											//		5 - Big timeout
											//		6 - timeout between msg chars
											//		7 - more than 1000 chars
											//		8 - got bad lrc
											//		9 - general
											//		9 - general
											//		10 - geot more than buffer can hold
											//		0  - end request

    unsigned char eft_rc;					//3		Return code
    long          amount;					//4		include CashBack in pay currency	
    unsigned short  tender_no;				//8		Tender number
    unsigned char account[10];				//10	Account number (BCD)
    unsigned char start_time[3];			//20	Start time
    unsigned char account_str[21];			//23	not pak account 

    struct   trans_tail_  tail;				//44	TRS tail
};											//64


/*----------------------------------------------------------------------
Opcode:		0x60 
Subopcode:	0x03
Customer birthday or age info
-----------------------------------------------------------------------*/
struct trs_birthday_						//OFS	Description
{
    unsigned char opcode;					//0		0x60 <Opcode Value="0x60" />
    unsigned char function;					//1		0x03 <Opcode Value="0x03" />

    unsigned char age;						//2		Age

    unsigned char day;						//3		Date of birth: day
    unsigned char month;					//4		Date of birth: month
    unsigned short  year;					//5		Date of birth: year
	unsigned char BioDOBFlg				:1;	//7		DOB obtained by PBT? Issue #7703SL
	unsigned char supervisor_verified   :1; //7     Age checked by mngr Enh #14437SL
	unsigned char auto_approve_ignore	:1; // FSD102391 StoreLine Product Restriction Enhancement
	unsigned char is_auto_approve		:1; // bug 119491
	unsigned char nu_bdate				:4;
 
    unsigned char restiction_message_id;	// 8 FSD102391 StoreLine Product Restriction Enhancement
 	unsigned short supervisor_id;			//9
	unsigned char nu[33];					//11
    
	struct   trans_tail_  tail;				//44	TRS tail
};											//64

/*----------------------------------------------------------------------
Opcode:		0x60 
Subopcode:	0x04
Tax exemption information
-----------------------------------------------------------------------*/
struct trs_tax_exempt_						//OFS	Description
{
    unsigned char opcode;					//0		0x60 <Opcode Value="0x60" />
    unsigned char function;					//1		0x04 <Opcode Value="0x04" />

    unsigned char option;					//2		1-start 0-stop
    unsigned char exempt_no[19];			//3		Exemption number
    		     
	unsigned char all_tax;					//22	Exempt from all taxes
    unsigned char tax[8];					//23	Flag for each examptable tax
    
    unsigned char wic_tax_exempt  :1;		//31	Albertson's
    unsigned char nu1             :7;		//31	Not used
    unsigned char tax_2[7];					//32	Flag for each examptable tax
    unsigned char nu[5];					//39	Not used

    struct   trans_tail_  tail;				//44	TRS tail
};											//64

/*----------------------------------------------------------------------
Opcode:		0x60 
Subopcode:	0x31
Location (POS information) transaction
-----------------------------------------------------------------------*/
struct trs_location_						//OFS	Description
{
	unsigned char opcode;					//0		Opcode - 0x60		<Opcode Value="0x60" />
	unsigned char function;					//1		Subopcode -  0x31	<Opcode Value="0x31" />

	unsigned char opt_tender_correction	:1;	//2		Tender correction
	unsigned char fuel_merged_recall_prepay_ticket:1;	//2		Fuel for ALB's
	unsigned char opt_invoice			:1;	//2		Use invoice number field
	unsigned char opt_frgn_cust			:1;	//2		Cutomer is an export customer
	unsigned char frc_crd_return		:1;	//2		Force credit return
	unsigned char express_pos    		:1;	//2		Express POS
#ifdef PRJ_ROW
	unsigned char rdh_sale				:1;	//2		Future use
#else
	unsigned char bDepositReqInPrvTicket:1;	//2		Deposit requested in previous ticket.
#endif
	unsigned char rdh_return			:1;	//2		Future use
   
	//CR55882 - changed from "unsigned char store_id[6];" to union to send long value
	union
	{
		unsigned char store_id[6];	 			//3		Store number (Alphanumeric)
		struct LongStoreNo
		{
			unsigned long ulLongStoreNumber;
			char filler[2];
		}LongStore;
	};

	unsigned char till_type;				//9		'O/I/S'
	unsigned char checkout_bank;			//10	Checkout bank number (0-99)
	unsigned char eft_location[5];			//11	EFT location as defined on POS configuration
	unsigned char till_profile;				//16	Till profile as defined on POS configuration

	unsigned char doc_type;					//17	El-Salvador tax report 
											//		1=ticket
											//		2=factura
											//		3=credito fiscal
   
	unsigned short till_no;					//18	
	unsigned short cashier_no;				//20

	unsigned char wholesale_trs_type;		//22	see enum WHOLESALE_TRS_TYPE
	unsigned char invoice_no[8];			//23	wholesale invoice number
	unsigned char inv_date[3];				//31	Invoice generation date	
	unsigned char inv_time[3];				//34	Invoice time
	unsigned char uchLayByStatus;			//37	//FS19171_LayBysTax: Status of LayBys (Priceline)

	unsigned char bBulkGiftCardSale		  :1; //38	//FSD1798 Bulk Gift Card Sale
	unsigned char bTicketOfReturns		  :1;
	unsigned char bCashChangeCalcul		  :1; // FSD#16283
	unsigned char bRedeemVoucher		  :1; // FSD#30639 
	unsigned char bManualAdjustmentTicket :1; // FSD#16270
	unsigned char bCashVoucherSaleTicket  :1; // FSD58540 Cash voucher
	unsigned char bRpoTicket			  :1; // CR 65207
	unsigned char bNonPaymentDriveOffTrs  :1; // FSD61185

	unsigned char   uchLocalWeekInYear;		//39    #10485 Week of year of local time (January 1-7 == 0)

	unsigned short shShiftId;				//40	Shift_Management in Remote Office
	short  shCurFunction;					//42    TD 41380 the ppm_entry.code function  reserved[2];				//42	Future use

	struct   trans_tail_  tail;				//44	Transaction tail
};											//64

/*----------------------------------------------------------------------
Opcode:		0x60 
Subopcode:	0x7E
Info transaction for recalled invoice
-----------------------------------------------------------------------*/
struct trs_info_inv_pmt_					//OFS	Description
{
	unsigned char opcode;					//0		0x60	<Opcode Value="0x60"/>
	unsigned char function;					//1		0x7E	<Opcode Value="0x7E"/>

    unsigned char invoice_no[8];			//2     invoice number (CCCCTTTNNNNN) (CASHIER,TILL,TICKET NUMBER)
    unsigned char payment_type;				//10    0 Normal payment
											//      1 Paid through an account payment (offline)
											//      2 Split TRS paid offline 
											//      3 Split TRS paid online
											//      See also INVOICE_PAYMENT_TYPE
    unsigned char inv_issue_dt[3];			//11    Invoice issue date
    unsigned char inv_issue_tm[3];			//14    Invoice issue date
    unsigned char pmt_type_sot;				//17    Payment type at SOT. 1: cash 2:credit
	
	unsigned char opt_void_payment:1;		//18    Flag for indication that payment was voided
	unsigned char opt_recall	  :1;		//18	The invoice was recalled
	unsigned char opt_recall_by_payment	:1; //18	recall_invoice+sale
	unsigned char opt_frc_crd_return    :1; //18	Force credit return
    unsigned char opt_not_crtd_rcl_inv	:1;	//18	Not created invoice
	unsigned char opt_nu				:3;	//18	Future use

	unsigned char cust_no[10];				//19	Customer number
	unsigned char sale_type;				//29    Sale type 
	long		  amount;					//30    invoice value
	unsigned char filler[10];				//34    Future use

	struct   trans_tail_  tail;				//44	TRS tail
};											//64

/*----------------------------------------------------------------------
Opcode:		0x60 
Subopcode:	0x9F
Invoice re-print
-----------------------------------------------------------------------*/
struct trs_info_inv_reprint_				//OFS	Description
{
	unsigned char opcode;					//0		0x60	<Opcode Value="0x60"/>
	unsigned char function;					//1		0x9F	<Opcode Value="0x9F"/>

    unsigned char invoice_no[8];			//2     invoice number 
    unsigned char inv_issue_dt[3];			//10    Invoice issue date
	long          lAmount;					//13	Invoice Value	FSD31954
	long		  lSupervisor;				//17	FSD31954_supervisor
	unsigned char filler[23];				//21    Future use

	struct   trans_tail_  tail;				//44	TRS tail
};


/*----------------------------------------------------------------------
Opcode:		0x08
Coupon transaction
-----------------------------------------------------------------------*/
struct trs_coupon_							//OFS	Description
{
    unsigned char opcode;					//0		0x08 <Opcode Value="0x08" />

    unsigned char opt_subtract           :1;//1		Coupon subtracted
    unsigned char opt_cancel             :1;//1		Coupon canceled
    unsigned char opt_supress_bonus_cpn  :1;//1		Supress bonus coupon
    unsigned char opt_ext_cpn_info_trs   :1;//1		Coupon info TRS follows
    unsigned char opt_dept_net           :1;//1		Department netted coupon
    unsigned char opt_bonus_cpn_followed :1;//1
    unsigned char opt_cost_plus          :1;//1		Cost plus
    unsigned char opt_chained_prv_item   :1;//1		As a result of previous item sale

    unsigned char opt_store_coupon       :1;//2		This is a store coupon item
    unsigned char opt_vendor_coupon      :1;//2		This is a vendor coupon item
    unsigned char opt_bonus_coupon       :1;//2		Bonus coupon
    unsigned char opt_UPC5_coupon        :1;//2		UPC5
    unsigned char opt_FS_payment         :1;//2		Payment by food stamps allowed
    unsigned char opt_discount_allowed   :1;//2		Discount allowed
    unsigned char opt_manual_entered_amount	 :1;//2		Amount entered manually
    unsigned char opt_manual_entered_dept		 :1;//2		Dept. no. entered manually

    long          qty;						//3		Quantity
    long          amount;					//7		Coupon amount

    unsigned short tender_no;				//11	Tender number
    unsigned char  tender_type;				//13	Tender type
    unsigned short coupon_dept;				//14	Department number
    unsigned char  coupon_code[7];			//16	Coupon number
    unsigned char  coupon_name[16];			//23	Coupon name

    unsigned char  tax_ptr;					//39	Tax flags
    unsigned short min_qty;					//40	Minimum quantity

	short plus_amount;						//42	Addad after the ceiling amt. limit
    								 
    struct   trans_tail_  tail;				//44	TRS tail
};											//64	

/*----------------------------------------------------------------------
Opcode:		0x60 
Subopcode:	0x43 TRANS_INFO_COUPON
Coupon info
-----------------------------------------------------------------------*/
struct trs_coupon_info_						//OFS	Description
{
    unsigned char opcode;					//0		0x60	<Opcode Value="0x60" />
    unsigned char function;					//1		0x43	<Opcode Value="0x43" />TRANS_INFO_COUPON

    unsigned char opt_weight_coupon      :1;//2	
	unsigned char opt_dep_store_coupon   :1;//2		A's department store coupon.
    unsigned char opt_dep_other_coupon   :1;//2		A's (other) bonus coupon.
	unsigned char opt_dep_vendor_coupon  :1;//2		A's department vendor coupon.
	unsigned char opt_plu_store_coupon   :1;//2		A's plu store coupon.
	unsigned char opt_plu_other_coupon   :1;//2		A's	plu "other" bonus coupon.
	unsigned char opt_plu_vendor_coupon  :1;//2		A's plu vendor coupon.
    unsigned char opt_freq_shop_coupon   :1;//2		Frequent shopper coupon

    long weight;							//3		Weight
    long price;								//7		Price
    long amount;							//11	Amount
    unsigned char return_type;				//15	Return type number
    unsigned char link_code[7];				//16	Linked item code
	

    unsigned char triple_coupon			:1; //23	TRIPLE COUPON
    unsigned char smart_card_coupon		:1; //23	Electronic smart card coupon
	unsigned char opt_price_embedded_coupon		:1; //23	HF #9259
    unsigned char nu					:5;	//23	Not used		 

    long          qty;						//24	For balancing back office reports
	unsigned short ushProjectId;			//28	FSD15885 - Sweet Mart Coupon
	unsigned short ushTemplateId;			//30	FSD15885 - Sweet Mart Coupon
    unsigned char plu_code[7];				//32	Issue #8897SN: EBTWIC plu code for item that UPC5 coupon is attached to
	unsigned short ushTicketType;			//39	Sweet Mart Coupon
	unsigned char uchExternalCouponProviderTenderTypeID;	//41	FSD34249_V4

    unsigned char reserved[2];				//42	Not used

    struct   trans_tail_  tail;				//44	TRS tail
};											//64

/*----------------------------------------------------------------------
Opcode:		0x60 
Subopcode:	0x08
account number information
-----------------------------------------------------------------------*/
struct trs_account_							//OFS	Description
{
    unsigned char opcode;					//0		0x60 <Opcode Value="0x60" />
    unsigned char function;					//1		0x08 <Opcode Value="0x08" />

    unsigned short tender_no;				//2		tender number
    unsigned char  type;					//4		tender type

    unsigned char account[21];				//5		account number (ascii)
    unsigned char auth_no[9];				//26	authorization number
    unsigned char print_auth_no[9];			//35	printed auth. number
    
    struct   trans_tail_  tail;				//44	TRS tail
};											//64

/*----------------------------------------------------------------------
Opcode:		0x60 
Subopcode:	0x09
bagger information
-----------------------------------------------------------------------*/
struct trs_bagger_							//OFS	Description
{
    unsigned char opcode;					//0		0x60 <Opcode Value="0x60" />
    unsigned char function;					//1		0x09 <Opcode Value="0x09" />

    unsigned char bagger_id[11];			//2		bagger number as captured at POS
    unsigned char resevd[31];				//13	reserved
    struct   trans_tail_  tail;				//44	TRS tail
};											//64

/*----------------------------------------------------------------------
Opcode:		0x60 
Subopcode:	0x0B TRANS_INFO_EXPENSE
FSD14423 Payout / Receipt Expense code transaction
-----------------------------------------------------------------------*/
struct trs_info_expense_						//OFS	Description
{
   unsigned char opcode;	               // 0 0x60					<Opcode Value="0x60"/>
   unsigned char function;                // 1 0x0b TRANS_INFO_EXPENSE	<Opcode Value="0x0B"/>
   unsigned char sub_func;                // 2 1 - basic
                                          //   2,3 - purchase
                                          //   4 - debtors
                                          //   5 - cristmas stamps
                                          //   6,7 - bad debts recovered
                                          //   8 - Basic + VAT
                                          //   9 - salary
										  //   11 - Non bankable
										  //   12- Basic + Transaction Description	
										  //   13- Cost Center
										  //   99 - ExtraData = Special related info to the expense FO uses union ExtraData

   unsigned char  opt_payout    :1;       // 3
   unsigned char  opt_receipt   :1;       //
   unsigned char  opt_salary    :1;       //       jmd, Shoprite CP-0012
   unsigned char  opt_reproc    :1;       // process TRS only in reprocess mode
   unsigned char  opt_last_id   :1;       // use last TRS id
   unsigned char  opt_nu        :3;       //

   union trs_expense_inf_                 // 4 40 bytes length
   {
      struct trs_expense_general_
      {
         unsigned char data[40];          // 4
      } general;

      struct trs_expense_basic_           // 4
      {
         unsigned char  reference[14];    // 4
         unsigned long  branch;           // 18   
         unsigned long  exp_code;         // 22    
         unsigned short tender_type;      // 26    
         __int64        amount;           // 28   
         unsigned short safe_no;          // 36
         unsigned short user_no;          // 38
         unsigned char  action;           // 40
         unsigned char  pc_no;            // 41
         unsigned char  template_type;    // 42
         unsigned char  filler[1];        // 43
      }basic;                             // 44

      struct trs_expense_basic2_          
      {
         long           qty;              // 4
		 unsigned char  date[3];          // 8       BCD: yymmdd
         unsigned char  filler[33];       // 11
      }basic2;                            // 44

      struct trs_expense_basic_vat__
      {
         __int64 vat_amount;              // 4
         double  vat_ref;                 // 12
         long    qty;                     // 20
         unsigned char filler[20];        // 24
      } basic_vat;

      struct trs_expense_purch1_          // 4
      {
         __int64        vat_amount;       // 4
         double         vat_invoice;      // 12
         unsigned long  grv_number;       // 20
         unsigned short re_dept;          // 24
         long           qty;              // 26
         unsigned char  filler[14];       // 30
      } purch1;                           // 44

      struct trs_expense_purch2_          // 4
      {
         unsigned char  desc[28];         // 4
         unsigned char  filler[12];       // 32
      } purch2;                           // 44

      struct trs_expense_debtor_
      {
         __int64        vat_amount;       // 4
         unsigned char  vat_invoice[7];   // 12
         unsigned char  filler[25];       // 19
      } debtor;                           // 44

      struct trs_expense_crst_               
      {
         unsigned long  agent;            // 4
         long           qty;              // 8
         unsigned char  filler[32];       // 12
      } xmas;                             // 44

      struct trs_expense_acct_
      {
         unsigned char  acct_num[22];     // 4
         long           qty;              // 26
         unsigned char   filler[14];      // 30
      } acct;                             // 44

      struct trs_expense_acct2_
      {
         unsigned char	name[30];			// 4
			unsigned char  initials[10];		// 34
      } acct2;                            // 44

      struct trs_expense_salary_
      {
         unsigned short  type;             // 4
         long			 qty;              // 6
		 unsigned char   batch_code[14];  // 10
         unsigned char   filler[20];      // 24
      } salary;                           // 44

	  struct trs_expense_NonBankable
      {
         unsigned char  RefDate[20];         // 4
         unsigned char  filler[20];       // 24
      } NonBankable;					  // 44

	  //FSD45766
	  struct trs_expense_CostCenter_ 
	  {
		  unsigned char sCostCenter[7];	  // 4
		  unsigned char filler[33];		  // 11
	  } CostCenter;						  // 44
		//FSD#55809
		struct trs_expense_AdditionalReference_
		{
			unsigned char Type;           //4 
			//0 -AddReference        
			//1 -Comment1 
			//2 -Comment2
			//3 -Comment3               
			unsigned char AddReference[30];//5
			
			unsigned char filler[9];                               //35 
		} AdditionalReference;                        //44
		
		
		struct trs_expense_MileageClaim_          
		{
			unsigned char DriveNo[3];                              //4 
			__int64 Mileage;                                       //7          long
			__int64 PricePerMile;                                  //15 
			unsigned char  EngineSize[10];							//23 
			unsigned char  filler[11];                            //33
		} MileageClaim;                                          //44
		
		struct trs_expense_AutoMachines_
		{
			unsigned short MachineID;      //4
			__int64 OpenRead;              //8          long
			unsigned char filler[28];      //16 
		} AutoMachines;						//44
		
		struct trs_extra_data_ 
		{
			unsigned char uchDataType;		//4
			unsigned char uchSubDataType;	//5
		
			union trs_extra_data_info_
			{
				struct trs_extra_data_approval_
				{
					short shSupervisorId;			//6
					unsigned char filler[36];		//8
				} ExtraDataApproval;				//44



			}ExtraDataInfo;
		} ExtraData;	//44
	  
   } inf;

   struct   trans_tail_  tail;
};											//64

// Electronic smart card coupon - coupon information + plu attached
struct trs_smart_card_coupon_
{
    unsigned char opcode;         //0x60 <Opcode Value="0x60" />
    unsigned char function;       //0x79 <Opcode Value="0x79" />

    unsigned char  coupon_code[7];	//2 BCD: Empty[3], ManufacturerCode[6], 
	                                //     FamilyCode[3], ValueCode[2].

	unsigned char  coupon_info[6];  //9 BCD: OfferCode[5], CouponCategoryCode[2]
									//     Medium[1], Vehicle[2], Placement[2]

	unsigned char ExpirationTime[3]; //15
	unsigned char StartTime[3];      //18 
	unsigned char CaputureTime[3];   //21

	unsigned char ReusedCounter;     //24 


	struct
	{
		unsigned char NU0					:1;
		unsigned char NU1					:1;
		unsigned char DisplayCapable		:1;
		unsigned char DBUnreadOrRead		:1;
		unsigned char Source				:1;
		unsigned char ActivOrCancel			:1;
		unsigned char ActiveOrOverageStatus	:1;
		unsigned char RedemptionStatus		:1; //25
	}Build_in_flag;

	unsigned char opt_subtract			:1;
    unsigned char opt_cancel			:1;
	unsigned char opt_ext_smart_cpn_trs	:1;
	unsigned char nu3					:1;
	unsigned char nu4					:1;
	unsigned char nu5					:1;
	unsigned char nu6					:1;
	unsigned char nu7					:1;  //26

    long           reward;                   //27

	struct
	{
		unsigned char  plu_code[7];			//31 BCD 
		short		   FamilyCode1;         //38
		short		   FamilyCode2;         //40
    }attached_plu1;


    unsigned char  reserved[2];             //42

	struct trans_tail_ tail;                //44
};

// Smart card coupon info transaction		// correct fix
// include information about plu's attached to coupon
struct trs_smart_card_coupon_ext_
{
	unsigned char opcode;         //0x60 <Opcode Value="0x60" />
    unsigned char function;       //0x7C <Opcode Value="0x7C" />

	struct
	{
		unsigned char  plu_code[7];			//BCD
		short		   FamilyCode1;
		short		   FamilyCode2;
    }attached_plu2;

	struct
	{
		unsigned char  plu_code[7];			//BCD
		short		   FamilyCode1;
		short		   FamilyCode2;
    }attached_plu3;

	struct
	{
		unsigned char  plu_code[7];			//BCD
		short		   FamilyCode1;
		short		   FamilyCode2;
    }attached_plu4;

	unsigned char reserved[9];

	struct trans_tail_ tail;
};



// SmartTV card information
struct trs_smart_TV_card_data_
{
    unsigned char opcode;				//0x60 <Opcode Value="0x60" />
    unsigned char function;				//0x7A <Opcode Value="0x7A" />

	unsigned char WalletID[4];			//2		BCD
	unsigned char CardHolderID[8];		//6		BCD
	unsigned char SerialNumber[8];		//14	BCD
	unsigned short CardUsageCount;		//22	
	unsigned short CouponRedeemed;		//24	
	unsigned long  SavingAccumulator;	//26

	struct Flag1_
	{
		unsigned char NU0	:1;
		unsigned char NU1	:1;
		unsigned char NU2	:1;
		unsigned char NU3	:1;
		unsigned char NU4	:1;
		unsigned char NU5	:1;
		unsigned char NU6	:1;
		unsigned char Dirty	:1;         //30
	}Build_in_flag;

	unsigned char read		:1;
	unsigned char write		:1;
	unsigned char nu2		:1;
	unsigned char nu3		:1;
	unsigned char nu4		:1;
	unsigned char nu5		:1;
	unsigned char nu6		:1;
	unsigned char nu7		:1;         //31

	unsigned char  reserved[12];        //32

	struct trans_tail_ tail;            //44
};



// Gift card transaction for Albertson 
// activation/recharge(re-activation) card 
struct trs_gift_card_act_
{
    unsigned char opcode;         //0x60 <Opcode Value="0x60" />
    unsigned char function;       //0x7B <Opcode Value="0x7B" />

	unsigned char ActionType;    //2
	unsigned char CardNo[11];	 //3 BCD
	unsigned char AuthNo[9];     //14
	unsigned char Reference[10]; //23

	long BegBalance;             //33
	long TrsAmount;              //37

    unsigned char Activation		:1; //Gift card activation
    unsigned char Recharge			:1; //Recharge gift card 
    unsigned char variable_card		:1; //card price was manual entered
    unsigned char ManualySwipe		:1; //card was swiped manualy
    unsigned char OptExtData		:1; //
	unsigned char bIsOffline		:1; //FSD55425
    unsigned char nu				:2; //41 

    short TenderNo;                     //42

    struct   trans_tail_  tail;         //44
};

//Issue #2711SL: Extended gift card data
struct trs_gift_card_act_ext_
{
    unsigned char opcode;			//0x60	<Opcode Value="0x60"/>
    unsigned char function;			//0xFD	<Opcode Value="0xFD"/>

	unsigned char Template[10];		//2
	unsigned char CardNo[11];		//12 BCD
	unsigned char AuthNo[9];		//23
	char plu_code[7];               //32 BCD     PLU number  
	long TrsAmount;					//39

	unsigned char Filler[1];		//43

    struct   trans_tail_  tail;		//44
};

//Index/Defect #16122SL/#16122SL
struct trs_gift_card_act_ext2_
{
    unsigned char opcode;						//0	0x70
    unsigned char function;						//1	0xDE
	unsigned char EFTTraceNo[6];				//2	pakd
	unsigned char szTrsDateAndTime[15];			//8		//FSD55425
	unsigned char szGiftExpiryDate[9];			//23	//FSD55425
	unsigned char RetrivalReferenceNumber[12];	//32	//FSD55425
    struct   trans_tail_  tail;					//44
};

struct trs_info2_gift_card_act_ext3_
{
    unsigned char opcode;						//0	0x70
    unsigned char function;						//1	0xF5
	unsigned char ECRReferenceNumber[16];		//2
	unsigned char BatchNumber[6];				//18			
	unsigned char BalanceAmount[12];			//24

	unsigned char nu[8];						//36
    struct   trans_tail_  tail;					//44
};

struct trs_media_ext_
{
	unsigned char opcode;      //0x14 <Opcode Value="0x14" />
	unsigned short  no;

	unsigned char fee_type;
	unsigned char table_no;

	unsigned char tender_req_add_fee :1;
	unsigned char fee_tender         :1;
	unsigned char payment_is_change  :1; 
	unsigned char MICR_used   		 :1; 
	unsigned char wic_tax_exempt	 :1;
	unsigned char tender_correction  :1; //TENDER CORRECTION
	unsigned char duplicate_receipt  :1;
	unsigned char barcoded_tender	 :1; //COINSTAR

	unsigned char ext_desc[21];
	unsigned char bank_account[9];
#ifdef PRJ_ROW 	
	unsigned char tender_date[3];        
	unsigned char date_issued[3];        //Split transaction
#else
	unsigned char check_number[6];
#endif

	unsigned char deposit            :1;
	unsigned char withdrawal         :1;
	unsigned char coupon_coin_sale	 :1; 
	unsigned char opt_bag_refund	 :1;
	unsigned char cashback_balance	 :1;  //  Cashback balance transaction
	unsigned char Eft_ext			 :1;
#ifdef PRJ_ROW 	
	unsigned char opt_not_created_inv:1;  // Indicator for Not creadted invoice (Split trans.) 
#else
	unsigned char ChangeConvert	   	 :1;
#endif
	unsigned char LoyaltyVoucher   	 :1;

	unsigned char SavingsDeposit	 :1;//43
	unsigned char bGnrlDeposit	     :1;//43 FS18341
	unsigned char bDepositCover	     :1;//43 FS18341
	unsigned char bCashPurchaseFirstStage :1;//43 //Cash purchase recovery
	unsigned char bCashPurchaseSecondStage :1;//43 //Cash purchase recovery
	unsigned char bCashbackRounding	 :1;
	unsigned char bGiftCardRedemption:1;  //FS3012 FSD22770
	unsigned char bRefundGiftCard	 :1;  //FS3012 FSD22770

	struct   trans_tail_  tail;
};


struct trs_media_ext2_
{
	unsigned char opcode;      //0x15 <Opcode Value="0x15" />

	unsigned char reference_no[11]; //1 Eft refference no

	unsigned char enhanced_MPR_voucher_print :1;
	unsigned char print_cash_balance	        :1;
	unsigned char print_foodstamps_balance 	:1;
	unsigned char VoidTenderNotAllowed  		:1;
	unsigned char voucher_tender   	        :1;	//Return Voucher redemption
	unsigned char opt_voucher			    :1; //Loyalty Voucher redemption
	unsigned char dispNegTenderAmtFlag		:1; //FS1046       BITS    Display tender negative amount flag  
   unsigned char media_ext3					:1;	// HF #10812

	unsigned short eft_tender_no;		//13 
	unsigned char	SettlementDate[8];	//15 Quest DDMMYYYY
	unsigned char  CardType;            //23 Quest
	short AccountType;                  //24 Quest 
	short TransactionType;				//26 Quest
	unsigned long eft_handle;			//28 Nomad EFT TRS handle
	unsigned char voucher_no[10];  		//32 Voucher redemption (BCD format)  
	unsigned char voucher_len ;         //42

	unsigned char AcceptedInSaleMode		:1; //43 FS1055
	unsigned char barcode_tender_cpn		:1; //   FS1094
	unsigned char bSettlementDone			:1; //   FS17494
	unsigned char bVATReturnDone            :1; //   FS4716
	unsigned char bLaybyBalancingTender     :1; //   FS1333
	unsigned char bTPCoverTender            :1; //   FS1333 - Tender purchase cover tender.
	unsigned char bInstantRedemption		:1;
	unsigned char bRefundedTender			:1; //   FSD10281 - Tender purchase in the sale/tender mode

	struct   trans_tail_  tail;          //44
};

struct trs_media_ext3_
{
	unsigned char opcode;      //0x18 <Opcode Value="0x18" />
	unsigned char CashBackType; //None, Prompt Operator, Smart
	long          CashBackValue;
	unsigned char immediately_cashback		 :1; //condition of open drawer
	unsigned char bNameTrsFollow			 :1;
	unsigned char bOctopusCard				 :1;	// EranL: flag for octopus card save transaction
	unsigned char bOctopusCardDeduct		 :1; // Octopus card payment
	unsigned char bRDRedemptionTender		 :1; // FS5721 R$ redemption tender
	unsigned char bVoidTenderIfEftNotConfirm :1; // FS5721 Void tender if Eft answer is not confirm.
	unsigned char bRefundDuplicateReceipt	 :1; //FS7000
	unsigned char bLineTempleateInUse		 :1; //FSD14741
	
	unsigned short	tender_no;
	unsigned char	sBankAccount[12];	// Chip Card payment account
	unsigned char	sDomiciliation[12]; // Chip Card domiciliation number

	unsigned char SignatureCaptureFailed			:1; // HF #10812
	unsigned char bSuppressAdditionCardInfoPrint	:1; //#955
	unsigned char bPreSwipeMedia					:1; //#FSD16142
	unsigned char bIsExternalCouponTrs				:1;	//#31651
	unsigned char bBalanceTransfer				    :1; //FSD22770 
	unsigned char bForceVoid                        :1; //FSD42824
	unsigned char bProvisionalPaymentTender			:1; //#50834
    unsigned char bHashedPanFound                   :1; //FSD34954    


	long lSavebackValue; // Bug #23538

	unsigned char	TrxIdentifyNumber[3];	// 38 BCD

	unsigned char	chNumberOfPayments;		// 41
	unsigned char	sSponsorID[2];			// 42

	struct   trans_tail_  tail;
};

//FSD3582
struct trs_media_ext4_
{
	unsigned char opcode;								//0x19 <Opcode Value="0x19" />
	unsigned char expiry_date[3];						// 1 BCD format yymmdd
	unsigned long ulRewardTenderPromo;					// 4 FSD11575 - The reward tender trigger promotion.
	unsigned char bCouponGeneratedTender			:1;	// 8 Indicate tender ( ususally a rewarding tender) is a result of a coupon.
	unsigned char bATMTender						:1; // 8 FSD14667 ATM (SafePay) tender type
	unsigned char bTenderHasExtraFee				:1; // 8 FSD29811 - Indicate a tender has fee.
	unsigned char bExtraFeeIncludedInTenderAmount	:1; // 8 FSD29811 - Indicates the fee amount is part of the tender paymeny.
	unsigned char bTndrHasRestrictedAmount			:1; // 8 FSD29811 - Indicates a tender has resriction amount due to included items.
	unsigned char opt_long_coupon_number			:1;	// 8 FSD26780 - if the BCDTriggeringCoupon length longer than 7 
														//		the BCDTriggeringCoupon will be writen in the following 0x70,0x91 trs.
	unsigned char bDetailedTender					:1;	// 8 FSD61175 - Mrs V8716 ,FSD32316 - Indicates this tender is detailed.
	unsigned char bVoucherApproved					:1; // 8 FSD55061: 0 - Approved externally, 1 - Approved locally
	unsigned char sBCDTriggeringCoupon[7];				// 9 The coupon that generated the tender
														
	unsigned char referenceNumber[10];					// 16 BCD - FSD13078 - Reference number associated to the issued voucher
	union
	{
		long	  lEftRetuenCardType;					// 26 For Delhaize smash eft
		long	  lTenderCount;							// 26 For Woolworths - stores tender count when trs_media_::count overflows [signed char] (14813)
	};
	unsigned char uchReferenceNumberLen;				// 30 Reference number length
	unsigned char uchExternalValidationAgainst;			// 31 FSD 19134: 0 == None, 1 == LPE.
	unsigned char uchEOTEndrFileSeq;					// 32 FSD29690 - End of ticket endorsement file sequence.
	long		  lNewAmountBalance;					// 33
	short		  shPaymentOption;						// 37
	unsigned char bcdAuthorizationDate[2];				// 39 BCD mmdd
	unsigned char bcdAuthorizationTime[3];				// 41 BCD hhmmss
														
	struct   trans_tail_  tail;							// 44
};

//FSD13919
struct trs_media_ext5_
{
	unsigned char opcode;				// 0	0x26

	unsigned char PONumber[6];			// 1	BCD
	unsigned char PONumberLen;			// 7

	long RxTenderAmount;					//8
	long NonRxTenderAmount;					//12
	short shEftProviderRespCode;			//16
	unsigned long GiftCardTraceID;			//18 authorization code for gift card redemption authorization #67417
	short shOrgTenderNumber;				//22 //TD#77209
	unsigned char uchFuelCardPaymentType;	//24 FSD126489_Storeline_Postilion_EFT_Enhancement_for_Bunker_Card_Commercial_Fuel
	long lBankID;							//25
	long lNumberOfPayments;					//29
	long lbankInstallments;					//33
	long lResponseFlags;					//37
	
	unsigned char bLinkedToDataBar			:1;//41
	unsigned char bProhibitReturnToSaleMode :1;//41  FSD392122 - Partial Tendering
	unsigned char bIsCatalinaCoupon			:1;//41 TD#437457
	unsigned char bNU						:5;//41
	unsigned char NU[1];					//42
	
	unsigned char media_ext6				:1;	//43
	unsigned char OptFsaTender				:1;	//43
	unsigned char bTenderNotEffectBalanceDue:1; //FSD56623
	unsigned char bDisallowLoyalty			:1; //FSD112346_Storeline_Revoke_MMiles_For_Certain_EFT_Payment_Methods
	unsigned char bRoundingTender           :1; 
	unsigned char bPromotionCoupon			:1; //43 FSD#... - GS1
	unsigned char bLocalIssuedBarcode		:1;	//43 FSD314464
	unsigned char bRecalculateTender		:1;	//43

	struct   trans_tail_  tail;				//44
};

struct trs_charge_posting_
{
    unsigned char opcode;         //0x60 <Opcode Value="0x60" />
    unsigned char function;       //0x0A <Opcode Value="0x0A" />

    unsigned char cp_name[16];
    unsigned char cp_account_num[12];
    unsigned char cp_status;
    long cp_amount;
    long cp_balance;
    long cp_limit;
    unsigned char cp_upcharge;
    
    struct   trans_tail_  tail;
};


struct trs_external_charge_payment
{
    unsigned char opcode;        //0 0x60	<Opcode Value="0x60"/>
    unsigned char function;      //1 0xC5	<Opcode Value="0xC5"/>
    unsigned char account[10]; //bcd of account, without check  digit, with leading zeros.
    unsigned char is_reversal_charge_payment  :1; //is it reversal charge payment.
    unsigned char nu_2  :1;
    unsigned char nu_3  :1;
    unsigned char nu_4  :1;
    unsigned char nu_5  :1;
    unsigned char nu_6  :1;
    unsigned char nu_7  :1;
    unsigned char nu_8  :1;
    long amount; //always positive.
    unsigned char reseved[27];
    struct   trans_tail_  tail;
};

struct trs_charge_reverse_bal_
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60" />
    unsigned char function;       //0x3E	<Opcode Value="0x3E" />

    unsigned char payment  :1;
    unsigned char purchase :1;
    unsigned char nu2      :1;
    unsigned char nu3      :1;
    unsigned char nu4      :1;
    unsigned char nu5      :1;
    unsigned char nu6      :1;
    unsigned char nu7      :1;
    
    unsigned char cp_name[16];
    long cp_limit;
    unsigned char cp_account_num[13];
    long cp_amount;
    long cp_balance;
    
    struct   trans_tail_  tail;
};


struct trs_cost_percent_
{
    unsigned char opcode;         //0x60 <Opcode Value="0x60" />
    unsigned char function;       //0x0C <Opcode Value="0x0C" />

    unsigned char start    :1;
    unsigned char nu01     :1;
    unsigned char nu02     :1;
    unsigned char nu03     :1;
    unsigned char nu04     :1;
    unsigned char nu05     :1;
    unsigned char nu06     :1;
    unsigned char nu07     :1;

    unsigned long new_percent;
    unsigned long old_percent;

    unsigned char reserved[33];
    struct   trans_tail_  tail;
};


struct trs_supervisor_
{
    unsigned char opcode;         //0x60 <Opcode Value="0x60" />
    unsigned char function;       //0x0D <Opcode Value="0x0D" />

    unsigned char scan_card  :1;
    unsigned char prelim_rtrn:1;
    unsigned char credit_rtrn:1;
    unsigned char credit_sale:1;
    unsigned char auth_voids :1;
    unsigned char mngr_disc  :1;
    unsigned char bResend    :1; // #22084
    unsigned char approved_by_rpo	:1;  //enh #1591 - Bit to determine if approved at POS or by RPO

    unsigned long supervisor;
    unsigned char prvlg;
	unsigned char keylock;

	unsigned char sprvr_name[20];
    
	unsigned char plu_action;          //enh iss #3456SL
	unsigned char transaction_action;  //enh iss #3456SL
    
	unsigned short ushFuncUsed;			 //31 N#3831
    unsigned short ushPosFuncOrCCNumber; //33 FSD26801

    unsigned char  bPosFuncIndicator  :1;	//35	//FSD26801
	unsigned char  bTicketIndicator	  :1;			// FSD#50018
	unsigned char  bPrintSupervisorAuthorization	:1;		//FSD367295
    unsigned char  nu				  :5;

	unsigned short ulCashierId;			//36	//ShlomitG - 13/06/07 - FSD26801 enhancement

    unsigned char reserved[6];			//38 

    struct   trans_tail_  tail;
};

struct trs_buyaid_
{
    unsigned char opcode;         //0x60 <Opcode Value="0x60" />
    unsigned char function;       //0x0E <Opcode Value="0x0E" />

    unsigned char nu00     :1;
    unsigned char nu01     :1;
    unsigned char nu02     :1;
    unsigned char nu03     :1;
    unsigned char nu04     :1;
    unsigned char nu05     :1;
    unsigned char nu06     :1;
    unsigned char nu07     :1;

    unsigned short buyaid_no;

    long          amount;
    long          voucher_no;
    unsigned char account[20];

    unsigned char reserved[11];
    struct   trans_tail_  tail;
};


struct trs_staff_
{
    unsigned char opcode;	  	  //0x60	<Opcode Value="0x60" />
    unsigned char function;	  //0x0F		<Opcode Value="0x0F" />

    unsigned char nu00		            :1;
    unsigned char nu01		            :1;
    unsigned char nu02		            :1;
    unsigned char nu03		            :1;
    unsigned char nu04		            :1;
    unsigned char nu05		            :1;
    unsigned char nu06		            :1;
    unsigned char nu07		            :1;

    unsigned char staff[11];  //Ascii null terminated
    long	  		   discount_amount;
    unsigned short  discount_no;
    long	  			discount_percent;
    unsigned short  tender_no;

    unsigned char reserved[18];
    struct   trans_tail_  tail;
};

struct trs_ecca_
{
    unsigned char opcode;			  //Offset 0	//0x60	<Opcode Value="0x60" />
    unsigned char function;			  //Offset 1	//0x10	<Opcode Value="0x10" />
    unsigned char sub_function;		  //Offset 2	//Values:
														//1-name[20]
														//2-addres[30]
														//3- phone[10]

    unsigned char account[10];		  //Offset 3

    unsigned char new_ec	          :1;			//Offset 13
	unsigned char bLinked2CustCntr	  :1;			//Offset 13
    unsigned char bEccaExt			  :1; //#955	//Offset 13
    unsigned char nu02                :1;			//Offset 13
    unsigned char nu03                :1;			//Offset 13
    unsigned char nu04                :1;			//Offset 13
    unsigned char nu05                :1;			//Offset 13
    unsigned char nu06                :1;			//Offset 13


	
    union											//Offset 14
    {

       unsigned char name[20];						//Offset 14


       unsigned char address[30];					//Offset 14


       unsigned char phone[10];						//Offset 14



	   struct										//Offset 14
	   {
		   long lDiscountPercent;					//Offset 14
		   unsigned char uchDiscountLevelIndex;		//Offset 18		//FSD240909 Multi Level Staff Discount Avivp
		   long lDiscountable;                      //Offset 19     // WDM 309911
		   unsigned char DiscountInfo_NU[21];		//Offset 23
	   }DiscountInfo;
    }info;

    struct   trans_tail_  tail;
};

/*************************************/
//Customer at Start of Ticket - Metro
//Add sub_function type 0 - number[20]
//Andre		17/07/01
/*************************************/
struct trs_cust_info_
{
    unsigned char opcode;         //0x60 <Opcode Value="0x60" />
    unsigned char function;       //0x11 <Opcode Value="0x11" />
    unsigned char sub_function;   // 0 - number[20]
    							  // 1 - name  [40]
                                  // 2 - addres[40]
                                  // 3 - addres[40]
                                  // 4 - addres[40]
                                  // 5 - phone [20]
								  // 6 - date[12]
								  // 7 - time[10]
	                              // 8 - customer message[40] 
		                          // 9 - name and vat id (customer account).
                                  //10 - Profession (customer account).
	                              //11 - Fiscal office(customer account).
	                              //12 - New/Updated address.
	                              //14 - address4
                                  //15 - address5
								  //19 - Surname
								  //28 - company VAT
								  //29 - company registration
								  //30 - Bank Account number
								  //31 - Detailed Tender
								  //34 - TIN number
								  //35 - Suburb
								  //36 - State
								  //37 - Postcode
								  //38 - Manual Name
							   	  //39 - Manual Address
								  //40 - Additional Customer Name
	                              //41 - Additional Customer Address1
	                              //42 - Additional Customer Address2
								  //43 - Country ISO code.
	                                 

    unsigned char first       :1; // bug # 15979
    unsigned char last        :1; // bug # 15979
    unsigned char cust_acct   :1; // these are details for a customer
#ifdef PRJ_ROW	
    unsigned char bLayByCust  :1; // Lay Bys FS19171
#else
    unsigned char fiscal      :1; // simplified receipt
#endif
#ifdef PRJ_ROW
	unsigned char bMember:1;		//3		Member details
#else
    unsigned char bHomeDelivery   :1;//FS18343
#endif
    
    unsigned char bParcelPickup   :1;//FS18343
    unsigned char bIgnore         :1;
#ifdef PRJ_ROW
    unsigned char bLayByWriteNow :1; // lay by out of ticket: write now !yaron!
#else
	unsigned char bVoidCustAccnt :1; // FSD16729 Void Customer Account
#endif

    union
	{
		//TD#389640
		struct 
		{
			unsigned char sName[35];
			unsigned long ulVatID;
			unsigned char uchFiller;
		}CustNameAndVatID;

		unsigned char data[40];
		
		//FSD221427
		struct
		{
			unsigned char bcdLSTNumber[6];
			unsigned char bcdLSTDate[3];
			unsigned char bcdCSTNumber[6];
			unsigned char bcdCSTDate[3];

			unsigned char filler[22]; 
		}CustTIN;
	};

    struct   trans_tail_  tail;
};


struct trs_sku_
{
    unsigned char opcode;         //0x60 <Opcode Value="0x60" />
    unsigned char function;       //0x13 <Opcode Value="0x13" />

    unsigned char nu00        :1;
    unsigned char nu01        :1;
    unsigned char nu02        :1;
    unsigned char nu03        :1;
    unsigned char nu04        :1;
    unsigned char nu05        :1;
    unsigned char nu06        :1;
    unsigned char nu07        :1;

    unsigned char sku[11];
	unsigned char code_plu[11];  

	long price_old;
	long price_new;    
    
    unsigned char reserved[11];

    struct   trans_tail_  tail;
};


struct trs_price_override_
{
    unsigned char opcode;						//0x60	<Opcode Value="0x60" />
    unsigned char function;						//1 0x14	<Opcode Value="0x14" />

    unsigned char opt_markdown				:1; //progressive
    unsigned char opt_electronic_reduced	:1; //Electronic reduction
    unsigned char opt_forcePrice			:1; //Indication that the org price is a force price.#15666
    unsigned char opt_refundPriceOverride	:1; //#2166 - Indicate the transaction was generated due to refund confirm price.
    unsigned char opt_nu14					:1;
    unsigned char opt_qty_is_fuel_gallons	:1; //enh iss #3456SL
    unsigned char opt_qty_is_weight			:1; //enh iss #3456SL
    unsigned char opt_qty_is_decimal_qty	:1; //2 enh iss #3456SL

    long 	 org_price;							//3
    long 	 reduced_price;						//7
    
    long		 qty;							//11
    long	    diff_amount;					//15
    
    unsigned char code[7];						//19
    
    unsigned char type;							//26
    
	char reason_no;						        //27 progressive

	char rtc_cycle;								//28 FSD242819
	char rtc_cycle_counter;						//29 FSD242819
	char filler[2];								//30 

	long org_amount;					        //32 progressive
	unsigned char percentage				:1;	//36 FSD26795
	unsigned char bPriceModification		:1;	//36 FSD24344,#30389
	unsigned char bSpecialCancel			:1;	//#30389,02/06/09 MosheBe - renamed from bPriceModificationCancelItem
	unsigned char bTotalPriceOverride			:1; //36 FSD54403
	unsigned char bRainCheck				:1; //36 Epic 370524 StoreLine Extend Raincheck on POS
	unsigned char nu						:3;	//36 
 
	unsigned short percEntry;					//37	FSD26795
	long lFirstOrgPrice;							//39	#47327
	unsigned char reseved;						//43

	struct   trans_tail_  tail;
};

struct trs_car_
{
    unsigned char opcode;      //0x60 <Opcode Value="0x60" />
    unsigned char function;    //0x05 <Opcode Value="0x05" />

    unsigned char opt_reg_no  :1;
    unsigned char opt_milage  :1;
    unsigned char opt_cvd     :1;
    unsigned char opt_range   :1;
    unsigned char opt_nu14    :1;
    unsigned char opt_nu15    :1;
    unsigned char opt_nu16    :1;
    unsigned char opt_nu17    :1;

    unsigned char reg_no[11];
    unsigned char milage[11];
    unsigned char cvd[1];
    unsigned char range[5];

    unsigned char reseved[13];

    struct   trans_tail_  tail;
};

struct trs_chq_grty_
{
    unsigned char opcode;      //0x60 <Opcode Value="0x60" />
    unsigned char function;    //0x15 <Opcode Value="0x15" />

    unsigned char opt_issue_no_used    :1;
    unsigned char opt_accept_isu_date  :1;
    unsigned char opt_accept_exp_date  :1;
    unsigned char opt_MCR_used         :1;
    unsigned char opt_nu14 			   :1;
    unsigned char opt_nu15 			   :1;
    unsigned char opt_nu16 			   :1;
    unsigned char opt_nu17 			   :1;

    unsigned char cheque_grty_card[10];
    unsigned char grty_card_len;
    
    unsigned char isu_date[2];
    unsigned char exp_date[2];
    unsigned char card_range_no;
    unsigned char issue_no;
    unsigned char auth_card_range_no;
    
    unsigned char reseved[23];

    struct   trans_tail_  tail;
};

struct trs_drive_off_
{
    unsigned char opcode;      //0x60	<Opcode Value="0x60" />
    unsigned char function;    //0x16	<Opcode Value="0x16" />

    unsigned char opt_ctp       :1;
    unsigned char bOutstandingPayment :1; //FSD102401		
    unsigned char opt_nu12      :1;
    unsigned char opt_nu13      :1;
    unsigned char opt_nu14      :1;
    unsigned char opt_nu15      :1;
    unsigned char opt_nu16      :1;
    unsigned char opt_nu17      :1;

    unsigned char reg[11];
    unsigned char surname[20];

    unsigned char car_make[5];
    unsigned char car_year[2];
    unsigned char car_color[3];

    struct   trans_tail_  tail;
};


struct trs_bad_account_
{
    unsigned char opcode;      //0x60 <Opcode Value="0x60" />
    unsigned char function;    //0x17 <Opcode Value="0x17" />

    unsigned char type; //0-bad_account, 1-enhanced 3-ecca

    unsigned char account[10];
    unsigned char account_len;

    unsigned char reseved[30];

    struct   trans_tail_  tail;
};

struct trs_assistant_
{
    unsigned char opcode;         //0x60 <Opcode Value="0x60" />
    unsigned char function;       //0x19 <Opcode Value="0x19" />

    unsigned char nu00        :1;
    unsigned char nu01        :1;
    unsigned char nu02        :1;
    unsigned char nu03        :1;
    unsigned char nu04        :1;
    unsigned char nu05        :1;
    unsigned char nu06        :1;
    unsigned char nu07        :1;

    unsigned char no[16];	//in ascii null terminated
    unsigned char bcd[6];	//in BCD up to 12 digits
    
    unsigned char name[19];

    struct   trans_tail_  tail;
};

struct trs_prom_info_
{
    unsigned char opcode;         //0x60 <Opcode Value="0x60" />
    unsigned char function;       //0x1A <Opcode Value="0x1A" />

    unsigned char opt_long_prom :1; //PROM_CHNG
    unsigned char opt_info_trans:1; //MBA
    unsigned char opt_was_cancel:1; //FS17238 VOID MANUAL PROMOTION 
    unsigned char opt_reward_by_cashier   :1; //Indicates reward entered by cashier.
    unsigned char bStaffDisc_Promotion    :1;
	unsigned char bRefundDiscount		  :1;
    unsigned char bClientDiscount		  :1;//FSD8900 - true if use discount instead of promotion
    unsigned char bTriggeredByManSegmentFunc :1; // FSD 8152 

    unsigned char promotion_type;	// 3
    unsigned char ext_promotion_type;	// 4
    unsigned char dep_ext_promotion_type;	// 5
    
    unsigned char code[7];			// 6
    unsigned short  promotion_no;	// 13
    unsigned char bucket_no;		// 15
    unsigned short  ext_promotion_no; // 16
    unsigned char ext_bucket_no;	  // 18
    unsigned short  dep_ext_promotion_no;	// 19
    unsigned char dep_ext_bucket_no;		// 21
    
    unsigned char reward_type;				// 22
    unsigned char ext_reward_type;			// 23
    unsigned char dep_ext_reward_type;		// 24

#ifdef PRJ_ROW
#ifdef PRJ_ROW_NEW_PROM
	long          lQualifySpent;		   //  25 #20687 for recover;  CR#38963
	unsigned char uchTriggerScheme;        //  29 #20687 for recover
	long lPromEngineAllocatedPromNo;	   //  30 for 'discounts' , N# 11007
    
	unsigned char uchPromFiscalReportingMethod :2; //34 - "item" == 0, "package" == 1, "total" == 2.
	unsigned char bCollectedPromotion   	   :1; //34 //FSD12648 Indicate this promotion is part of a promotion collector.
	unsigned char bTrigBySegments       	   :1; //34 //FSD12648 Indicate this promotion was triggered by segments.
	unsigned char bDelayedPromo				   :1; //34 - delayed promotion flag
	unsigned char bLaybyItemPromo				:1;	//34 - this is a promotion on layby item level
	unsigned char bLaybyTicketPromo				:1;	//34 - this is a promotion on layby ticket level
	unsigned char bInjectRewardFromDynamicAttr  :1; //34
#else
	//ykl 29/04/10: i needed the lQualifySpent and uchTriggerScheme for porting PE
	//to Foodstuffs. From what I checked, qty_attached_ttl and qty_attached_bucket 
	//are not in use.
	//long          qty_attached_ttl;		   //  25 progressive
    //short 	      qty_attached_bucket[3];  //  29 progressive
	long          lQualifySpent;		   //  25 #20687 for recover
	unsigned char uchTriggerScheme;        //  29 #20687 for recover
	unsigned char notused[4];			   //  30

	unsigned char uchPromFiscalReportingMethod :2; //34 - "item" == 0, "package" == 1, "total" == 2.
	unsigned char bCollectedPromotion   	   :1; //34 //FSD12648 Indicate this promotion is part of a promotion collector.
	unsigned char bTrigBySegments       	   :1; //34 //FSD12648 Indicate this promotion was triggered by segments.
	unsigned char bDelayedPromo				   :1; //34 - delayed promotion flag
	unsigned char bLaybyItemPromo				:1;	//34 - this is a promotion on layby item level
	unsigned char bLaybyTicketPromo				:1;	//34 - this is a promotion on layby ticket level
	unsigned char bInjectRewardFromDynamicAttr  :1; //34
	
#endif
#else
	long          lQualifySpent;		   //  25 #20687 for recover
	unsigned char uchTriggerScheme;        //  29 #20687 for recover
	long lPromEngineAllocatedPromNo;	   //  30 for 'discounts' , N# 11007
    
	unsigned char uchPromFiscalReportingMethod :2; //34 - "item" == 0, "package" == 1, "total" == 2.
	unsigned char bCollectedPromotion   	   :1; //34 //FSD12648 Indicate this promotion is part of a promotion collector.
	unsigned char bTrigBySegments       	   :1; //34 //FSD12648 Indicate this promotion was triggered by segments.
	unsigned char bDelayedPromo				   :1; //34 - delayed promotion flag
	unsigned char bLaybyItemPromo				:1;	//34 - this is a promotion on layby item level
	unsigned char bLaybyTicketPromo				:1;	//34 - this is a promotion on layby ticket level
	unsigned char bInjectRewardFromDynamicAttr  :1; //34
#endif
    long          long_promotion_no;       //  35 PROM_CHNG
	unsigned char group_type;              //  39
	unsigned char apportionment_type;      //  40
    
    unsigned char manualDiscountAmount[3];  // 41 bcd

    struct   trans_tail_  tail;      // 44
};
//TD#316773 //FSD#258806 - Start
/*----------------------------------------------------------------------
Opcode:		0x80 
Subopcode:	0x68
//TRANS_INFO3_PROMOTION_EXT3
-----------------------------------------------------------------------*/
struct trs_prom_info_ext
{
	unsigned char opcode;					//0			//0x80 <Opcode Value="0x80" />
    unsigned char function;					//1			//0x68 <Opcode Value="0x68" />

	unsigned char bTriggeredByCoupon	:1;	//2
	unsigned char notUsed				:7;

	unsigned char notused[41];				//3
	struct   trans_tail_  tail;				// 44
};
//TD#316773 //FSD#258806 - End

/*----------------------------------------------------------------------
TRANS_INFO3_ONLINE_PURCHASE_DATA_TO_PRINT
-----------------------------------------------------------------------*/
struct trs_info3OnlinePurchaseDataToPrint_
{
	unsigned char opcode;			//0x80										//0
	unsigned char function;			//0x6A										//1

	unsigned char szSaleDocumentNumber[9];	//in BCD							//2	
	unsigned char szRechargeCode[9];	//in BCD								//11
	unsigned short shRechargeCodeLength; //TD#383013							//20
	unsigned long lTelephoneNumber;												//22
	unsigned char nu[18];														//26			
	struct   trans_tail_  tail;													//44
};

//TD#384162
/*----------------------------------------------------------------------
TRANS_INFO3_ONLINE_PURCHASE_DATA
-----------------------------------------------------------------------*/
struct trs_info3OnlinePurchaseData_
{
	unsigned char opcode;			//0x80										//0
	unsigned char function;			//0x6B										//1

	char olaIdentifierKey[35];													//2
	unsigned char nu[7];														//37
	struct   trans_tail_  tail;													//44
};

struct trs_clubcard_
{
	unsigned char opcode;           //0x60 <Opcode Value="0x60" />				//0
	unsigned char function;         //0x1B <Opcode Value="0x1B" />				//1

	unsigned char accepted  			:1; // Card was accepted				//2
	unsigned char voided 	   			:1; // Card was voided
	unsigned char MCR_used  			:1; // Card was swiped else keyd in.
	unsigned char staff_disc_card		:1; // Clubcard is a staff disc card
	unsigned char qualify_spent_info	:1;
	unsigned char re_entry       		:1; // Clubcard re-entry
	unsigned char freq_shop_accepted	:1; // progressive (1) ayal
	unsigned char freq_shop_rejected	:1; // progressive (1) ayal

	unsigned char scheme_no;			  // 1 to 9								//3
	unsigned char card_no[20];			  // card no in ascii null terminated	//4
#ifdef PRJ_PRICELINE
	unsigned char  tender_no;				// Card is credit/debit to tender n
	
	unsigned char client_id	:1;				// this is a client record
	unsigned char bMemberDetailsPrompt :1;
	unsigned char bMemberNew	:1; //#408085
	unsigned char bMemberUpdated:1; //#408085
	unsigned char bEOT			:1;
	unsigned char opt_nu	:3;
#else
   unsigned short  tender_no;			  // Card is credit/debit to tender n
#endif

   unsigned char cust_type;			  // panel flag								//26
   long          cust_points;			  // Points up to date					//27
   long          cust_redempt_value;  // redemption value						//31
   unsigned char cust_upd_date[3];	  // Up to date								//35

	unsigned char cust_msg;														//38
   long          qualify_spent;													//39												
	unsigned char CRNG_No;														//43
   
	struct   trans_tail_  tail;													//44
};

//Issue #7703SL
struct trs_clubcard_ext
{
	unsigned char opcode;           //0x60 <Opcode Value="0x60" />
	unsigned char function;         //0x3B <Opcode Value="0x3B" />

	unsigned char BioFreqShopFlg	:1;
	unsigned char bIsHomeGroup		:1;
	unsigned char bIsHomeStore		:1;
	unsigned char bThirdPartyLoyaltyAtBeginOfTicket		:1; //FSD55061&55659
	unsigned char bWasApprovedByEFT						:1; //FSD55061&55659: after QuerySession(); 0 - Approved externally; 1 - Approved locally

	unsigned char bNewSignup		:1; //#387582
	unsigned char bFlyBuyAsSegmentBCP	:1; //FSD#450005: Fly Buy according to configuration Barcode Programming with type Segment
	unsigned char bDisplayCardIndicatorSegmentBCP		:1; //FSD#450005

	short LoyaltyState;
	long  lSessionID;		//FSD55061&55659	
	unsigned char CardNo[10];	// MAX_LEN_LOYALTY_CARD_NO = 20 ==> size is MAX_LEN_LOYALTY_CARD_NO/2 = 10
	long			lResultCode;

	unsigned char TypeNWCC;		//FSD#444616: see TypeLoyaltyScheme_FB, TypeLoyaltyScheme_DiffNWCC,....

	//FSD#450005
	unsigned long	FixedSegment;

	unsigned char nu[16]; //FSD55061&55659: was 39

	struct   trans_tail_  tail;
};

//FSD56623 - CR62119
struct trs_reddem_MA_online_query_
{
	unsigned char opcode;           //0x70 
	unsigned char function;         //0x7D 

	unsigned char uchRedeemMAState;	//2
	long lVoucherCount;				//3
	unsigned long ulPromotionNumber;//7
	unsigned char uchPostalCode[3];	//11
	unsigned char uchBirthDate[4];	//14
	unsigned char uchCardId[10];	//18
	unsigned char nu[16];			//28

	struct   trans_tail_  tail;
};

struct trs_clubcard_info_
{
	unsigned char opcode;           //0x60 <Opcode Value="0x60" />
	unsigned char function;         //0xC4 <Opcode Value="0xC4" />

	unsigned char	sCardNo[10];	//2 card no in BCD
    unsigned short	shExpYear;      //12
	unsigned char	chExpMonth;     //14

    unsigned char	chIssueNo;      //15

	unsigned char	sMasterAccountNo[10]; //16

	unsigned char	bChipCard_used				:1;	//26
	unsigned char   bOctopusLoyaltyCard			:1; //FS5721
	unsigned char	bLoyaltyIssueOnly			:1; //FS5721
	unsigned char   bRocksLoyaltyCard			:1; //FSD6795
	unsigned char	bMasterCardFromBarcode		:1; //FSD18888
	unsigned char	bVoidBarcodeWhenSchemeVoided:1; //FSD18888
	unsigned char	bBadAcctValidated			:1;	//FSD30871
	unsigned char	bBadAcct					:1; // FSD30871

	unsigned short  cardStoreNum;        //27 Member card store number #10555
	unsigned char	uchLoyaltyType;	     //29
	unsigned short  ushTenderNo;		 //30
	unsigned short  ushMasterAccountLen; //32	//YaelB 13/05/08
	unsigned char	uchRedemptionStatus; //34	//FSD56623 - CR62119
	unsigned long   ulCardLongStoreNum;  //35 FSD63030
	
	unsigned char	bOnlineLoyaltyCard				:1; //36 // FSD62522
	unsigned char	bThirdPartyLoyalty				:1;	//#70725,#72200
	unsigned char	bOfflineSegments				:1; // 24 //FSD#231491
	unsigned char	bWineCardType					:1;	// FSD#394174	
	unsigned char	bRMWIdentification				:1;	// FSD450172
	unsigned char   bNotAllowGuardiolaRedemption	:1;	//FSD442705 AlessandroS
	unsigned char	bNU					:2;
	
	
	unsigned char	reserved[4];         //39


	struct   trans_tail_  tail;      // 44
};


//FSD7148

struct trs_media_ext6_
{
	unsigned char opcode;		  //0xC5 TRANS_MEDIA_EXT6	<Opcode Value="0xC5"/>
	
	unsigned char ucTemplatetype;
	unsigned char sAccountDescription[15];
    unsigned char sTrsCertificate[17];
	unsigned long lAuditNumber;
	unsigned char ucNumberOfPayments;
    unsigned char  sRefNo2[4];
    unsigned char ucProviderAccountType;
	struct   trans_tail_  tail;
};

struct trs_media_ext7_
{
	unsigned char opcode;		  //0xC6 TRANS_MEDIA_EXT7	<Opcode Value="0xC6"/>
	
	unsigned char sCardName[33];
    unsigned char sRefNo1[10];  //9+3 from ext6
		

	struct   trans_tail_  tail;
};

struct trs_media_ext8_
{
	unsigned char opcode;		  //0xC7 TRANS_MEDIA_EXT8	<Opcode Value="0xC7"/>
	
	unsigned char sMechantID[16];
    unsigned short shServiceRestrictionCode;
	unsigned char sEmvCryptogram[16];
	unsigned char sWiCodeProduct[2];	//	FSD#294724

	unsigned short ushVoidedTenderSeqNo; //TD#352124
	long lConvertedAmount;				 //FSD#399162
    unsigned char NU[1]; 
		

	struct   trans_tail_  tail;
};

struct trs_media_ext9_
{
	
	unsigned char opcode;      //0 //0xCA TRANS_MEDIA_EXT9	<Opcode Value="0xCA"/>

	char  szHashedPANValue[38];	//1 The Hashed PAN Text
	unsigned short ushTenderReferenceNumber; //39
	unsigned char NU[3]; //41
	
	struct   trans_tail_  tail; //44
};

//CR378184
struct trs_media_ext10_
{	
	unsigned char opcode;		//0 //0xD2 TRANS_MEDIA_EXT10	<Opcode Value="0xD2"/>

	char  sVoucherNumber[14];	//1 Payment voucher number
	char  sVoucherName[29];		//15 Payment voucher name
	
	struct   trans_tail_  tail; //44
};

struct trs_media_ext11_
{
	unsigned char opcode;		//0 //0xD3 TRANS_MEDIA_EXT11	<Opcode Value="0xD3"/>

	long lATMChangeAmount;		//1 // #425633

	//TD#434067-start
	unsigned char bFromPromotion:1;
	unsigned char bnu           :7;
	unsigned short ushMessageOnItemId; 
	unsigned char uchRewardType;        
    //TD#434067-end
	unsigned long lPromotionId;//5   BUG #451799
	unsigned char NU[31];		//9

	struct   trans_tail_  tail; //44
};

//FSD414790 - EW
struct trs_extended_warranty_
{
	unsigned char	opcode;						//0		0x80	TRANS_INFO3
	unsigned char	function;					//1		0x92	TRANS_INFO3_FORTRESS
	unsigned char	subfunction;				//2		0x01	FORTRESS_EXTENDED_WARRANY
	unsigned char	bVoid :1;					//3
	unsigned char	nNU	  :7;			
	char	sMainItemIDInBCD[7];				//4
	long	lSequanceID;						//11
	long	lOriginalTransactionNumber;			//15
	short	shOriginalStoreNumber;				//19
	char	sSerialNumberOfTheMainItemID[15];	//21
	char	sPurchaseDate[4];					//36
	long	lActualPrice;						//40

	struct   trans_tail_  tail; //44
};

//FSD414790 - GreenSection - Start
struct trs_trade_in1_
{
	unsigned char	opcode;						//0		0x80	TRANS_INFO3
	unsigned char	function;					//1		0x92	TRANS_INFO3_FORTRESS
	unsigned char	subfunction;				//2		0x03	TRADE_IN1
	long			lTradeInValue;				//3
	char			sIMEI[15];					//7
	char			sModelNumber[20];			//22
	char			NU[2];						//42
	struct   trans_tail_  tail; //44

};

struct trs_trade_in2_
{
	unsigned char	opcode;						//0		0x80	TRANS_INFO3
	unsigned char	function;					//1		0x92	TRANS_INFO3_FORTRESS
	unsigned char	subfunction;				//2		0x04	TRADE_IN2
	char			sCustomerName[25];			//3
	char			sReasonCode[3];				//28
	char			sOverrideReference[5];		//31
	unsigned char   uchPluCodenum[7];			//36
	char			NU[1];						//43
	struct   trans_tail_  tail; //44

};

struct trs_trade_in3_
{
	unsigned char	opcode;							//0		0x80	TRANS_INFO3
	unsigned char	function;						//1		0x92	TRANS_INFO3_FORTRESS
	unsigned char	subfunction;					//2		0x05	TRADE_IN3
	char			sCustomerDetailsLine1[25];		//3
	char			NU[16];							//28
	struct   trans_tail_  tail; //44

};

struct trs_trade_in4_
{
	unsigned char	opcode;							//0		0x80	TRANS_INFO3
	unsigned char	function;						//1		0x92	TRANS_INFO3_FORTRESS
	unsigned char	subfunction;					//2		0x06	TRADE_IN4
	char			sCustomerDetailsLine2[30];		//3
	char			NU[11];							//33
	struct   trans_tail_  tail; //44

};

struct trs_trade_in5_
{
	unsigned char	opcode;							//0		0x80	TRANS_INFO3
	unsigned char	function;						//1		0x92	TRANS_INFO3_FORTRESS
	unsigned char	subfunction;					//2		0x07	TRADE_IN5
	char			sCustomerDetailsLine3[30];		//3
	char			NU[11];							//33
	struct   trans_tail_  tail; //44

};

struct trs_trade_in6_
{
	unsigned char	opcode;							//0		0x80	TRANS_INFO3
	unsigned char	function;						//1		0x92	TRANS_INFO3_FORTRESS
	unsigned char	subfunction;					//2		0x08	TRADE_IN6
	char			sCustomerDetailsLine4[30];		//3
	char			NU[11];							//33
	struct   trans_tail_  tail; //44

};

struct trs_serial_number_
{
	unsigned char	opcode;							//0		0x80	TRANS_INFO3
	unsigned char	function;						//1		0x92	TRANS_INFO3_FORTRESS
	unsigned char	subfunction;					//2		0x09	FORTRESS_SERIAL_NUMBER
	unsigned char	uchItemCodeInBCD[7];			//3
	char			sSerialNumber1[16];				//10
	char			sSerialNumber2[16];				//26
	char			NU[2];							//42
	struct   trans_tail_  tail; //44
	
};

//FSD414790 - Remark line text
struct trs_remark_line_
{
	unsigned char	opcode;						//0		0x80	TRANS_INFO3
	unsigned char	function;					//1		0x92	TRANS_INFO3_FORTRESS
	unsigned char	subfunction;				//2		0x0A	TRADE_IN1
	unsigned char	uchTransactionSeqNumber;	//3		0 , 1  , 2  , 3
	char			sTextRemark[30];			//4
	char			NU[10];						//34
	struct   trans_tail_  tail;					//44

};

//FSD414790-GreenSection - End

struct trs_request_time_
{
	
	unsigned char opcode;					//0		0x80	TRANS_INFO3
	unsigned char subOpcode;  				//1		0x36	TRANS_INFO3_REQUEST_TIME

	unsigned char  AuthorizationSessionBeginsTimeBCD[9];		//2  
	unsigned char  OnlineAuthorizationStartedTimeBCD[9];		//11
	unsigned char  AuthorizationSessionCompletedTimeBCD[9];		//20

	unsigned long lTotalNetworkTime;							//29
	
	unsigned char NU[11]; //33
	
	struct   trans_tail_  tail; //44
};

struct trs_request_time2_
{
	
	unsigned char opcode;					//0		0x80	TRANS_INFO3
	unsigned char subOpcode;  				//1		0x3F	TRANS_INFO3_REQUEST_TIME2

	unsigned char  ApplicationSelectionTimingTimeBCD[9];	// 2
	unsigned char  CardProcessingBeginsTimeBCD[9];			// 11
	unsigned char  CashbackProcessingStartTimeBCD[9];		// 20
	unsigned char  CashbackProcessingEndedTimeBCD[9];		// 29

	unsigned char NU[6]; //38

	struct   trans_tail_  tail; //44
};

struct trs_request_time3_
{
	
	unsigned char opcode;					//0		0x80	TRANS_INFO3
	unsigned char subOpcode;  				//1		0x40	TRANS_INFO3_REQUEST_TIME3

	unsigned char  PinEntryStartedTimeBCD[9]; //2
	unsigned char  PinEntryCompetedTimeBCD[9]; //11

	unsigned char  NU[24]; //20

	struct   trans_tail_  tail; //44
};

//FSD64199 - definition for enhanced coupon details transaction
struct trs_enhanced_coupon_details_
{
	unsigned char uchOpcode;					//0	0xCB TRANS_ENHANCED_COUPON_DETAILS

	unsigned char sCouponNumberBCD[10];			//1

	unsigned char sTrigerredPromNumberBCD[5];	//11
	unsigned char uchGroupType;					//16
	unsigned long ulFirstThreshold;			    //17
	unsigned long ulSecondThreshold;			//21
	unsigned long ulMinQualifyingBalance;		//25

	unsigned char uchRewardType;				//29
	unsigned long ulRewardMemberAccount;		//30
	long lRewardAmount;							//34
	unsigned char uchRewardingTender;			//38
	unsigned char uchPromMaxNumOfRewards;	    //39

	unsigned char bIsBlocked						:1;	//40
	unsigned char bDeductMarkedTendersFromQualSpend :1; 
	unsigned char bMemberCardRequired				:1;
	unsigned char bIsCatalinaCoupon					:1;
	unsigned char bCouponCancelled					:1; //#88668
	unsigned char bCouponKeyed						:1; //#114581
	unsigned char bPromotionCoupon				    :1; // FSD#... - GS1 NEEDED???
	unsigned char NotUsed							:1;

	unsigned short ushQty;						//41 // FSD#... - GS1

	unsigned char uchReserved[1];				//43

	struct   trans_tail_  tail;					//44
};


//FSD7148

// save customer points status from server
struct trs_loyalty_cust_
{
	unsigned char opcode;					// 0	//0x60									<Opcode Value="0x60" />
	unsigned char function;					// 1	//0xC1 - TRANS_INFO_LOYALTY_CUSTOMER	<Opcode Value="0xC1" />

	unsigned char CardNo[10];				// 2	// loyalty card no in BCD

	long          lCustPoints;				// 12	// Points up to date
	long          lTodayEarnedPoints;		// 16	// Points earned during the day - From SERVER
	long          lTodayRedeemedPoints;		// 20	// Points redeemed during the day - From SERVER

	unsigned char RecordInServer		:1;	// 24	// Customer in server cust.qdx file
	
	unsigned char uchRewardAllowed		:1; // 24	// Bug #12769 Saving if Redemption is allowed
	unsigned char bBalanceQuery			:1;  // 24   //#61768 - indication that 60-C1 was written as a result of choosing the 'Points Balance' function.
	unsigned char notFirstLoyalInTicket	:1; // TD54927; SplitUpdateV8551
	unsigned char nu_5					:4; // 24
   
	unsigned short segment_id1;				// 25
	unsigned short segment_id2;				// 27
	unsigned short segment_id3;				// 29
	unsigned short segment_id4;				// 31
	unsigned short segment_id5;				// 33

	unsigned short ushStatusRelatedMsg;		// 35	// TD#52737
	
	short shCardNumberLen;					// 37   // TD#70383

	unsigned char nu_19[5];					// 39
	
	struct   trans_tail_  tail;				// 44
};

struct trs_eft_info_data_ 
{
	unsigned char opcode;				//0x60	<Opcode Value="0x60" />
	unsigned char function;				//0xC2	<Opcode Value="0xC2" />	- TRANS_INFO_EFT_DATA

	unsigned short SessionID;			//2 
	unsigned char CustomerWaitTime;     // 4
	unsigned char TotalNetworkTime;     // 5

	unsigned char CommunicationTimeOut :1;	// 6
	unsigned char OfflineAuthorization :1;
	unsigned char OutPrintMsg		   :1;
	unsigned char CancelLastReq		   :1;
	unsigned char RepeatInfoReq		   :1;	
	unsigned char bOffline			   :1;		// FSD#30638
	unsigned char bCanceled            :1;      // FSD63194 - transaction was canceled
	unsigned char bTimedOut            :1;		// FSD63194 - transaction was canceled due to
	                                            //            Time-Out

	unsigned char card_type; //7 //CARD_TYPE_CHEQUE_CARD    0   // 080801  0 - undefined ( includes cheque cards )
								 //CARD_TYPE_DEBIT_CARD     1   // 080801  1 - debit card ...
								 //CARD_TYPE_CREDIT_CARD    2   // 080801  2 - credit card
								 //CARD_TYPE_CHARGE_CARD    3   // 080801 3 - charge card
								 //CARD_TYPE_FUEL_CARD      4   // 080801 4 - fuel card
								 //CARD_TYPE_SECURITY       6   // 080801  6 - security card
								 //CARD_TYPE_LOYALTY        7   // 080801  7 - Loyalty
								 //CARD_TYPE_STAFF_DISCOUNT 8   // 080801  8 - staff discount
								 //CARD_TYPE_CONSUMER_PANEL 9   // 080801  9 - consumer panel
	                             // Delhaize other defines
	unsigned short CardRangeNum; // 8
	unsigned char  XAuthCode[9]; // 10  // 221101 auth code from EFT provider 
										// BASE24 "0000" -if online authorization
										// BASE24 "IHCF" -if only check in bad account list
	unsigned char chAuthorizSrc; // 19
								 /*
										#define BankAuthorization     1
										#define MainProviderAuthorization   2
										#define SubProviderAuthorization    3
										#define OfflineAuthorization  4
										#define ManuelAuthorization   5
								  */
	long	TerminalID;          //20  for Smash Delhaize
	long	TransactionNumber;   //24  for Smash Delhaize
	unsigned short EftTypeNum;   //28  for Smash Delhaize CR #13504

	unsigned char OfflineTrs	            :1;//30 FS21345
	unsigned char bAdditionalPaymentExist	:1;//30 FSD26155
        							           //   FSD26155 - If flag is TRUE it means the followed
										       //   media transaction (0x04) is the result of
										       //   additional payment application (Wynid - Cetelem)
	unsigned char bDoNotPrintExpiryDate		:1;//30 FSD64200
	unsigned char bNewVoucherEntry  		:1;//30 FSD93620: Voucher Entry Function
	unsigned char bProcessingType  			:1;//30 FSD93620: Voucher Entry Function                              
                                               //   1-Online 0-Offline
	unsigned char bManualVoucherEntered		:1;//30 FSD93620: Voucher Entry Function    
	unsigned char NU_Bits					:2;

	unsigned short ushTenderNumber;	//31 Tender number
	
	unsigned char sPinPadId[8];	//33 FSD1332 (Interfaces) Pinpad id 

	unsigned char chAuthorizationReason;	//41
											/*
											AUTHORIZATION_REASON_UNKNOWN			= 0, 
											AUTHORIZATION_REASON_ISSUER				= 1, 
											AUTHORIZATION_REASON_CARD_LIMIT			= 2, 
											AUTHORIZATION_REASON_MERCHANT_LIMIT		= 3,
											AUTHORIZATION_REASON_CARD_BALANCE		= 4,
											AUTHORIZATION_REASON_VELOCITY_BALANCE	= 5
											*/
	unsigned char chFallbackType;			//42
											/*
											NO_FALLBACK								= 0, 
											FALLBACK_TYPE_ICC_2_SWIPE				= 1,
											FALLBACK_TYPE_SWIPE_2_PAN_ENTRY			= 2
											*/

	unsigned char ucTemplateId;				// 43


	struct   trans_tail_  tail;  //44
};


struct trs_msg_min_age_
{
	unsigned char opcode;           //0x60	<Opcode Value="0x60" />
	unsigned char function;         //0x3A	<Opcode Value="0x3A" />

	unsigned char min_age;
   
	unsigned char reserved[41];
   
	struct   trans_tail_  tail;
};

struct trs_staff_card_
{
	unsigned char opcode;           //0x60
	unsigned char function;         //0xB6

	unsigned char MCR_used  	   	   :1; // Card was swiped/keyd
	unsigned char not_used  		   :7; 
	unsigned char scheme_no;			  // 1 to 9
	unsigned char card_no[20];			  // card no in ascii null terminated
    unsigned short  tender_no;			  // Card is credit/debit to tender n
	unsigned char crng_no;                // Card Range number
	long	  	  discount_percent;       // Staff discount percent
	long		staff_qualify_amount;	//31 

	unsigned char exp_date[4];			//35
	unsigned char issue_no;             //39 
	unsigned char  not_used1[4];		//40

	struct   trans_tail_  tail;         //44
};

struct trs_info_tpf_recall_
{
	unsigned char opcode;    //0x60	<Opcode Value="0x60"/>
	unsigned char function;  //0xB7	<Opcode Value="0xB7"/>		item data for recall

    unsigned char plu_code[7];	 //2 plu number

	struct
	{
		unsigned char type;	 //2-date, 3-integer, 4-decimal, 5-alpha requests
		unsigned char number; 
	}field[10];					//9


	unsigned char refund_tpf_item  :1;
	unsigned char price_curreny	   :1;  // 0 - defualt, 1 - euro.
	unsigned char RTC              :1;	// 0 - Normal, 1 - RTC item.
	unsigned char void_item        :1;  // 0 - scnanned , 1 - voided
	unsigned char nu04             :1;
	unsigned char nu05             :1;
	unsigned char nu06             :1;
	unsigned char nu07             :1;		// 29
									  //msg number that was used from e-topup variant 
	unsigned char	Qty[6];					// 30
	unsigned char   Amount[5];				// 36

	unsigned char reserved[3];				// 41

	struct  trans_tail_  tail;				// 44
};

struct trs_points_
{
	unsigned char opcode;         	//0x60 <Opcode Value="0x60" />
	unsigned char function;       	//0x1C <Opcode Value="0x1C" />

	unsigned char info_only			:1;
	unsigned char cc_re_entry		:1;
	unsigned char opt_long_prom		:1; //PROM_CHNG
	unsigned char HomeStore			:1;
	unsigned char AccountUpdate		:1;
	unsigned char ChangeConversion	:1;
	unsigned char MessageUpdate		:1;
	unsigned char barcode_points	:1;  // 2

	unsigned char  scheme_no;		//3 1 to 9
	unsigned short promotion_no;	//4 2 lowest bytes (right)
	unsigned char  card_no[20];		//6 card no in ascii null terminated
	long		   qualify_spent;	//26 QS
	unsigned char  promotion_type;  //30

	unsigned char  Count;			//31 number of times reward was accepted //31

	unsigned char  origion_points			:1;
	unsigned char  PointsUpdatedInChipCard	:1;
	unsigned char  opt_cancel   			:1;
	unsigned char  opt_was_cancel			:1;
	unsigned char  opt_info_LBSale			:1; //FS19171_LayBysPoints
	unsigned char  opt_LBSale				:1; //FS19171_LayBysPoints
	unsigned char  active_kids_points		:1; //FSD9034
	unsigned char  total_reward_points		:1; //FSD71759 this trs just stores change in reward points (info only)

	unsigned char  decimalPlaces;   //33 FSD71759 for REWARD_POINTS transaction we need to store decimal points

	long		   points;			// 34	
	long		   bonus_points;    // 38
	unsigned short long_promotion_no; //42 PROM_CHNG - 2 highest bytes (left)

	struct   trans_tail_  tail;       //44
};

struct trs_points_ext_
{//TRANS_INFO2_POINTS_EXT
	unsigned char opcode;         	//0x70 <Opcode Value="0x70" />
	unsigned char function;       	//0xF2 <Opcode Value="0xF2" />

	unsigned char sOfferCode[10];		  //2
	long	lBonusPoints;				  //12
	unsigned char NU[28];		   		  //16

	struct trans_tail_ tail;    	      //44
};

//Albertson's fuel reward
struct trs_fuel_reward_
{
	unsigned char opcode;         	//0x60 <Opcode Value="0x60" />
	unsigned char function;       	//0x6E <Opcode Value="0x6E" />

	unsigned long program_no;		
	unsigned long promotion_no;
	unsigned char plu_code[7]; //BCD
	unsigned char price[7];
	long		  points;
	short		  count; // counts the total numbers of promotions given 
	short		  dep_no;

	unsigned char reserved[12];

   struct   trans_tail_  tail;
};

//Albertson's fuel reward
struct trs_voucher_
{
   unsigned char opcode;         	//0x60 <Opcode Value="0x60" />
   unsigned char function;       	//0x5F <Opcode Value="0x5F" />

   unsigned long program_no;		
   unsigned char voucher_no[10];
   unsigned char key_code[4];
   long			 points;		
   short template_type;		

   unsigned char reserved[18];

   struct   trans_tail_  tail;
};

// trs_track_ stores PAN "track" data.  Originally this was for tracks 1,2,3
// read from the card.  For PCI compliance (FSD93620) this now includes replacement
// data as we no longer process unencrypted (track 2) card numbers etc.

enum TrackType { trackType1=1, trackType2, trackType3, // original 3 track types
                 trackTypeEPAN=20,            // encrypted PAN (of form 123456X12345678901234 where X=A-F)
                 trackTypeToken,              // token used instead of PAN (20 digit number)
                 trackTypeTruncPAN,           // truncated PAN (something like 123456 ... 1234)
				 trackTypeEPANNoClean,        // EPAN but clean not required
                 trackTypeClearPAN,           // Clear PAN
};
struct trs_track_
{
	unsigned char opcode;         //0x60 <Opcode Value="0x60" />
	unsigned char function;       //0x1D <Opcode Value="0x1D" />

	unsigned char first		   :1;
	unsigned char last         :1;
	unsigned char bPCIPAN      :1;		//PCIDSS
	unsigned char bCCDeposit   :1;		//#53845
	unsigned char nu04         :1;
	unsigned char nu05         :1;
	unsigned char nu06         :1;
	unsigned char continuation :1;

	unsigned char track_no;   // see enum above
	unsigned char data[40];

	struct   trans_tail_  tail;
};


struct trs_cash_in_draw_
{
	unsigned char opcode;         //0x60 <Opcode Value="0x60" />
	unsigned char function;       //0x1E <Opcode Value="0x1E" />

	unsigned char too_much    :1; //Assistance
	unsigned char not_enough  :1;	//Topup
	unsigned char nu02		  :1;
	unsigned char nu03		  :1;
	unsigned char nu04		  :1;
	unsigned char nu05		  :1;
	unsigned char nu06		  :1;
	unsigned char nu07		  :1;
   
	long CashInDrawer;				//FSD15007
	unsigned long SupervisorNo;		//FSD15007_040606D
	long		  DrawerLimit;		//FSD15007
	unsigned char data[29];

	struct   trans_tail_  tail;
};


struct trs_wrong_password_
{
	unsigned char opcode;         //0x60 <Opcode Value="0x60" />
	unsigned char function;       //0x1F <Opcode Value="0x1F" />

	unsigned char mode;	// 1-at sign on 2-at secure
   
	unsigned short  cashier;
	unsigned short  password;
   
	unsigned char data[37];


	struct   trans_tail_  tail;
};



struct trs_freq_shopper_
{
    unsigned char opcode;	  	//0x60 <Opcode Value="0x60" />
    unsigned char function;	    //0x20 <Opcode Value="0x20" />

    unsigned char code[7];


    unsigned char reward_check_used  :1;
    unsigned char opt_not_net_fs     :1; 
    unsigned char nu02	             :1;
    unsigned char nu03	             :1;
    unsigned char nu04	             :1;
    unsigned char nu05	             :1;
    unsigned char nu06	             :1;
    unsigned char nu07	             :1;

    long  old_price;
    long  new_price;
    long  qty;
    long  save_amount;
	unsigned short dept;

    unsigned char reserved[16];
    struct   trans_tail_  tail;
};


struct trs_unlock_upd_
{
	unsigned char opcode;         //0x60 <Opcode Value="0x60" />
	unsigned char function;       //0x21 <Opcode Value="0x21" />

	unsigned char add_value   :1;
	unsigned char write_value :1;
	unsigned char unlock      :1;
	unsigned char nu03        :1;
	unsigned char nu04        :1;
	unsigned char nu05        :1;
	unsigned char nu06        :1;
	unsigned char nu07        :1;

	unsigned char qdx_file;
	unsigned char index[12];
   unsigned short  value_offset;
   long			  value;
   unsigned short  unlock_offset;
   
	unsigned char reserved[20];

	struct   trans_tail_  tail;
};

struct trs_redemption_
{
	unsigned char opcode;         //0x60 <Opcode Value="0x60" />
	unsigned char function;       //0x22 <Opcode Value="0x22" />

	unsigned char InstantRedemption			:1;
	unsigned char PointsUpdatedInChipCard	:1;
	unsigned char PromotionRedemption		:1; // #11205
	unsigned char bMemberAccountRedemption	:1; //FSD11780
	unsigned char bHomeStore				:1; // TD#55980 
	unsigned char bOriginPoints				:1;	//TD#126009
	unsigned char nu06						:1;
	unsigned char nu07						:1;

	unsigned char scheme_no;			  // 1 to 9
	unsigned char card_no[20];			  // card no in ascii null terminated
	unsigned char cust_type;			  // panel flag
	long          cust_redempt_value;  // redemption value
	long          cust_redempt_used;   // redemption used
	unsigned long ulMemberAccountId;   // Member account used for the redemption (FSD11780)
	
	unsigned char reserved[7];
	struct   trans_tail_  tail;
};


struct trs_apac_
{
	unsigned char opcode;         //0x60	<Opcode Value="0x60"/>
	unsigned char function;       //0x23	<Opcode Value="0x23"/>

	unsigned char first       :1;
	unsigned char all_depts   :1;
	unsigned char nu02        :1;
	unsigned char nu03        :1;
	unsigned char nu04        :1;
	unsigned char nu05        :1;
	unsigned char nu06        :1;
	unsigned char nu07        :1;

	unsigned short  dept_used[20];
	unsigned char reserved;

	struct   trans_tail_  tail;
};


struct trs_tndr_cpn_
{
	unsigned char opcode;         //0x60 <Opcode Value="0x60" />
	unsigned char function;       //0x32 <Opcode Value="0x32" />

	unsigned char opt_coupon_ticket        :1;
	unsigned char master_coupon_use        :1;
	unsigned char opt_cancel_coupon        :1;
	unsigned char opt_coupone_was_canceled :1;
	unsigned char opt_manual_keyed         :1; // #16433
	unsigned char nu05                     :1;
	unsigned char nu06                     :1;
	unsigned char nu07                     :1;

	unsigned char code[7];
    long		  value;
    short		  threshold_qty;
    long 		  min_purchase;
	unsigned char type;
    long 		  qty;
    long		  ttl_value;
   
	unsigned char code_master_cpn[7];
    unsigned char option;        

    unsigned char reserved[7];   

	struct   trans_tail_  tail;
};



struct trs_train_acct_
{
    unsigned char opcode;      //0x60	<Opcode Value="0x60"/>
    unsigned char function;    //0x33	<Opcode Value="0x33"/>

    unsigned short  media_no;

    unsigned char opt_charge_payment   :1;
    unsigned char opt_charge_reverse   :1;
    unsigned char opt_nu13             :1;
    unsigned char opt_nu14             :1;
    unsigned char opt_nu15             :1;
    unsigned char opt_nu16             :1;
    unsigned char opt_nu17             :1;
    unsigned char opt_nu18             :1;

    unsigned char cp_account_num[12];
    unsigned char cp_status;

    long cp_amount;
    long cp_balance;
    long cp_limit;

    unsigned char resevd[14];
    struct   trans_tail_  tail;
};


struct trs_ticket_trailer_
{
	unsigned char opcode;         //0x60	<Opcode Value="0x60" />
	unsigned char function;       //0x34	<Opcode Value="0x34" />

	unsigned char nu00        :1;
	unsigned char nu01        :1;
	unsigned char nu02        :1;
	unsigned char nu03        :1;
	unsigned char nu04        :1;
	unsigned char nu05        :1;
	unsigned char nu06        :1;
	unsigned char nu07        :1;

	unsigned char date[3]; // BCD yymmdd
	unsigned char time[3]; // BCD hhmmss
   unsigned long ticket_no;
   unsigned short cashier_no;	// #9547
   unsigned short pos_no;		// #9547
   
	unsigned char reserved[27];

	struct   trans_tail_  tail;
};



struct trs_finish_media_
{
	unsigned char opcode;         //0x60	<Opcode Value="0x60" />
	unsigned char function;       //0x35	<Opcode Value="0x35" />

	unsigned long fuel_prepay_sync_no;		// PosPump : Pre-Pay		// Offset 2
	unsigned long security_number;          // Offset 6
   
	unsigned char bFastFinishMedia	:1;		// Offset 10
	unsigned char NU7				:7;

	short shPromCount;						// Offset 11		// #103665
	unsigned char reserved[31];				// Offset 13		

	struct   trans_tail_  tail;				// Offset 44	
};


struct trs_q_length_
{
	unsigned char opcode;         //0x60	<Opcode Value="0x60" />
	unsigned char function;       //0x37	<Opcode Value="0x37" />

	unsigned char nu00        :1;
	unsigned char nu01        :1;
	unsigned char nu02        :1;
	unsigned char nu03        :1;
	unsigned char nu04        :1;
	unsigned char nu05        :1;
	unsigned char nu06        :1;
	unsigned char nu07        :1;

	unsigned short  q_length;
	unsigned short  alert_q_length;
   
	unsigned char reserved[37];

	struct   trans_tail_  tail;
};


struct trs_eft_print_data_
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60" />
    unsigned char function;       //0x38	<Opcode Value="0x38" />

    unsigned char line_no    :6;
    unsigned char first_line :1;
    unsigned char last_line  :1;
    
    unsigned char data[41];
    
    struct   trans_tail_  tail;
};

struct trs_alcohol_restricted_
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60" />
    unsigned char function;       //0x39	<Opcode Value="0x39" />

    unsigned char restricted         :1;
    unsigned char future_restricted  :1;
    unsigned char sale_restriction   :1;
    unsigned char void_restriction   :1;
    unsigned char refund_restriction :1;
    unsigned char nu14 :1;
    unsigned char nu15 :1;
    unsigned char nu16 :1;
    
    unsigned char code[7];
    unsigned short  dept;
    unsigned short  hour;
    unsigned short  minute;
    
    long amount;
    
    unsigned char nu[24];
    
    struct   trans_tail_  tail;
};

struct trs_extra_card_
{
	unsigned char opcode;         //0x60	<Opcode Value="0x60" />
	unsigned char function;       //0x27	<Opcode Value="0x27" />

	unsigned char guarantee         :1; //Funds guarantee 
	unsigned char home_shopping     :1;
	unsigned char credit_card       :1;
	unsigned char debit_card        :1;
	unsigned char smart_card        :1;
	unsigned char smart_card_track2 :1;
	unsigned char t7_eft			:1;      //EFT
	unsigned char media_ext3        :1;	//Media extention 3 follows - flag used by ROW

	unsigned char voucher_time[3];		//3
	unsigned char tender_eft_group;		//6
	unsigned char merchant_no[15];		//7
	unsigned char sponcer_no;			//22
    long		  cash_back;			//23
   
	unsigned char branch[6];			//27 branch no, null terminated
   
    short cred_reentry_receipt;			//33
    short cred_reentry_seq_no;			//35
	unsigned char pos_entry_mode;		//37
	unsigned char auth_resp_code[2];	//38
   
	unsigned char pak_cvv2[2];			//40 fill with 'A' FS1134 pak move to

	unsigned char sPreTrack2[2];		//42	FS17494 any chars before track2.

	struct   trans_tail_  tail;
};

struct trs_extra_card2_ // FSD#59744
{
	unsigned char opcode;              // 0	0x70	TRANS_INFO2
    unsigned char subopcode;		   // 1	0xAF	TRANS_INFO2_EXTRA_CARD_INFO

	unsigned char szEftModuleName[35]; // 2

	unsigned short ushPosNumber;	   // 37

	unsigned char NU[5];			   // 39

	struct trans_tail_ tail;		   // 44
};

struct CardTypeFlag_   // 191201 for 6028.. transaction
{
	char	ChequeGarenteeCard_Type	:1; 
	char	DebitCard_Type			:1;
	char	CreditCard_Type			:1;
	char	FuelCard_Type			:1;
	char	SecurityCard_Type		:1;
	char	LoyaltyCard_Type		:1;
	char	StaffDiscountCard_Type	:1;
	char	ConsumerPanelCard_Type	:1;
};

struct trs_ola_result_
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60" />
	unsigned char function;    //0x28	<Opcode Value="0x28" />
	unsigned char sub_func; 	//0-Ola results	<Opcode Value="0x00" />

	unsigned char card_accepted    :1;  // 3
	unsigned char hot_card         :1;
	unsigned char garanteed        :1;
	unsigned char not_garanteed    :1;
	unsigned char referral         :1;
	unsigned char extra_id         :1;
	unsigned char extra_trs        :1;
	unsigned char offline_auth     :1;	// 041201

	unsigned long msg_no;	// 4

	unsigned char card_type; // 8
	unsigned char trans_type;	// 9
	unsigned char auth_type;	// 10
	unsigned char auth_reason;	// 11
   
	short         ans_rtc;  //12     0    - Ok
									// 1-10 - Host answer
									// -1   - BAD
									// -6   - Timeout  
   
	unsigned char auth_code[10]; // 14
	unsigned char confirm_code;	 // 24	
   
	unsigned char account[10]; // 25 BCD up to 19 digits
	unsigned char account_len; // 35
			long amount;		// 36
    char          RefuesdType;   // 40 291101  

	struct CardTypeFlag_ CardTypeFlag;		// 41

											// 42
	unsigned char cheque_garantee			:1; // 181201 move
	unsigned char bProviderNotAvailable		:1; //FSD63194
	unsigned char nu_bit					:6; // 42
   
	unsigned char pump;     // 43

	struct   trans_tail_  tail;
};

struct trs_ola_error_
{
	unsigned char opcode;				//0x60
	unsigned char function;				//0x28
	unsigned char sub_func;				//0xA7 TRANS_INFO_OLA_ERROR

	char error[41];						//3

	struct   trans_tail_  tail;
};

//FSD34954
struct trs_ola_PCIDSS_HashedPAN_	//PCIDSS
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60" />
	unsigned char function;    //0x28	<Opcode Value="0x28" />
	unsigned char sub_func; 	//0-Ola results	<Opcode Value="0x4A" />
	
	unsigned char uchSeqNum;	//3 Transaction sequence number
	unsigned char bLastSeqTrs	:1;	//4
	unsigned char bDssFaild		:1; //is DSS failed
	unsigned char bNotUsed		:6;
	unsigned char uchHashedPANValueLen;		//5	The length-text HashedPAN value
	/*short shSeqNum;				//3 Transaction sequence number
	short shLastSeqNum;			//5 The last sequence number will be send
	short shHashedPANValueLen;	//7 The length-text HashedPAN value (max 34)*/
	char  szHashedPANValue[38];	//6 The Hashed PAN Text

	struct   trans_tail_  tail;
};

//FSD 57796 - EFT devices probe transaction
struct trs_ola_EFT_Devices_Probe_
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60" />
	unsigned char function;    //0x28	<Opcode Value="0x28" />
	unsigned char sub_func; 	//Ola results <Opcode Value="0x4B" />
	
	unsigned char ucNotUsed; //3

	unsigned char sSwipeAndParkID[10];   //4
	unsigned char sSwipeAndParkFirmwareVersion[4]; //14
	unsigned char sSwipeAndParkApplicationVersion[6]; //18

	unsigned char szPinPadID[10];	//24
	unsigned char szPinPadFirmwareVersion[4]; //34
	unsigned char szPinPadApplicationVersion[6]; //38
	
	struct   trans_tail_  tail; //44

};




struct trs_ola_req_
{
	unsigned char opcode;    //0x60	<Opcode Value="0x60" />
	unsigned char function;  //0x28	<Opcode Value="0x28" />
	unsigned char sub_func;	 //0x01	<Opcode Value="0x01" />

	unsigned char open_comm_failed		:1;
	unsigned char tx_failed				:1;
	unsigned char CancelLastReq			:1; // for Delhaize Smash
	unsigned char RepeatInfoReq			:1; // for Delhaize Smash	
	unsigned char bRequestWasCanceled   :1; //FSD63194
	unsigned char bSettlementRequiredAfterAuth	:1; //#131589
	unsigned char nu06					:1;
	unsigned char nu07					:1;  // 3

	unsigned long msg_no;  // 4
   
	unsigned char card_data[24]; // 8 nul terminated
	unsigned char card_type;     // 32

	unsigned char trans_type;	// 33
	unsigned char auth_type;	// 34
	unsigned char auth_reason;	// 35
   
	long			  req_amount; //36 amount + cashback

	struct CardTypeFlag_ CardTypeFlag; // 40	

	unsigned char	tender_no;  //41 120302 for Delhaize	
	unsigned char	reserved;   //42 
   
	unsigned char pump;			//43

	struct   trans_tail_  tail;	// 44
};


struct trs_ola_ack_
{
	unsigned char opcode;    //0x60	<Opcode Value="0x60" />
	unsigned char function;  //0x28	<Opcode Value="0x28" />
	unsigned char sub_func;	 //0x02	<Opcode Value="0x02" />

	unsigned char timeout          :1;
	unsigned char msg_rejected     :1;                   
	unsigned char ack_rejected     :1;
	unsigned char nu03             :1;
	unsigned char nu04             :1;
	unsigned char nu05             :1;
	unsigned char nu06             :1;
	unsigned char nu07             :1;

	unsigned long ack_msg_no;
   
	unsigned long timeout_value;
			   short  ack_rtc;
   
	unsigned char reserved[29];
   
	unsigned char pump;

	struct   trans_tail_  tail;
};


struct trs_ola_ans_
{
	unsigned char opcode;    //0x60	<Opcode Value="0x60" />
	unsigned char function;  //0x28	<Opcode Value="0x28" />
	unsigned char sub_func;	 //0x03	<Opcode Value="0x03" />

	unsigned char timeout          :1;
	unsigned char msg_rejected     :1;                   
	unsigned char nu02             :1;
	unsigned char nu03             :1;
	unsigned char nu04             :1;
	unsigned char nu05             :1;
	unsigned char nu06             :1;
	unsigned char nu07             :1;

	unsigned long ans_msg_no;
   
	unsigned long timeout_value;
	unsigned char msg_type;	//hold
	unsigned char confirm_code;
	         short  ans_rtc;
   unsigned char auth_code[10];
	unsigned short  delay;
   
   //PROJECT_ORANGE
   unsigned long club_plus_bal;     
   unsigned char club_plus_date[6]; 
   
	unsigned char reserved[5];

	unsigned char pump;
   
	struct   trans_tail_  tail;

};


struct trs_ola_free_
{
	unsigned char opcode;    //0x60	<Opcode Value="0x60" />
	unsigned char function;  //0x28	<Opcode Value="0x28" />
	unsigned char sub_func;	 //0x04	<Opcode Value="0x04" />

	unsigned char with_confirm     :1;
	unsigned char nu01             :1;
	unsigned char nu02             :1;
	unsigned char nu03             :1;
	unsigned char nu04             :1;
	unsigned char nu05             :1;
	unsigned char nu06             :1;
	unsigned char nu07             :1;

	unsigned long conf_msg_no;
	unsigned char confirm_code;
	unsigned char auth_code[10];
   
	unsigned char reserved[24];
   
	unsigned char pump;

	struct   trans_tail_  tail;
};


// Ext.trs of trs_ola_result_
struct trs_ola_result_ext_
{
	unsigned char opcode;		//0 0x60	<Opcode Value="0x60" />
	unsigned char function;		//1 0x28	<Opcode Value="0x28" />
	unsigned char sub_func; 	//2 0x05	<Opcode Value="0x05" />	Ola results extra SUB_FUNC_OLA_PROVIDER_MESSAGE

	unsigned char ResultMsg[20];// 3 Message from authorizer

	unsigned char exp_date[2]; //  23


	unsigned char hot_card					:1;
	unsigned char opt_MCR_used				:1;
	unsigned char ReasonPrinterProblem_flag	:1;
	unsigned char ReasonWrongSignature_flag	:1; 
	unsigned char ReasonFrozenCard_flag		:1; 
	unsigned char nu						:3; /*25*/

	struct CardTypeFlag_ CardTypeFlag; //26

	unsigned char account[10];	// 27 BCD up to 19 digits 
	unsigned char account_len; // 37
	unsigned char issue_no;		// 38
	long ProviderErrorNum;      // 39 
	char nu_1;					// 43 
	struct   trans_tail_  tail; // 44
};

struct trs_info_eft_declined_
{
	unsigned char opcode;					// 0	0x60
	unsigned char function; 				// 1	0xFE

	unsigned char reasonCode;				// 2
	unsigned char tenderNum;				// 3
	long declineAmount;						// 4
	unsigned char cardNum[10];				// 8 - BCD
	unsigned short segment;					// 18
	unsigned char exp_year[2];				// 20 FSD47073
	unsigned char exp_month[2];				// 22 FSD47073
	unsigned char issue_no;					// 24 FSD47073
	unsigned short ushEFTProviderErrorCode;	// 25 FSD#30638
	unsigned char nu[17];					// 27

	struct   trans_tail_  tail;				// 44
};

//TRANS_INFO_OLA_PRINTING
// Paramters for print eft slip ( card name + masking + lay out )
struct trs_ola_printing_
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60" />
	unsigned char function;    //0x28	<Opcode Value="0x28" />
	unsigned char sub_func;    //0x06	<Opcode Value="0x06" />	TRANS_INFO_OLA_PRINTING

	unsigned char sCardName[20]; // 3 Message from authorizer

	unsigned char sPanLayOut[5]; // 23
	char chMaskStart;			 // 28
	char chMaskEnd;				 // 29
	char chMaskChar;			 // 30  // default '*'
	unsigned short eft_tender_no;		//31
	unsigned char  uchPanEntryMode;		//33

	unsigned char bEmvPinHasRequierd			:1;  //FS1134
	unsigned char variable_pan_length			:1;  // Bug #22923
	unsigned char bEmvSigHasRequired			:1;  // Bug N#3034
	unsigned char bNeedSignatureVerify			:1;  // Bug #13307
	unsigned char bNU							:4;  //34

	unsigned char uchPANlength;	// 35 VPL (varable PAN len) Bug #22923

	unsigned char uchCardMaskingType;		//	36	FSD23593
	unsigned char uchNoUnmaskCharAtStart;	//	37	FSD23593
	unsigned char uchNoUnmaskCharAtEnd;		//	38	FSD23593

	char nu[5];				// 39
	struct   trans_tail_  tail; /*44*/
};

//	 TRANS_INFO_OLA_REFFERAL_SAVE	(unsigned char) 0x07
// Paramters for save transaction when need refferal 

struct trs_ola_refferal_
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60" />
	unsigned char function;    //0x28	<Opcode Value="0x28" />
	unsigned char sub_func;    //0x07	<Opcode Value="0x07" />	TRANS_INFO_OLA_REFFERAL_SAVE

	unsigned char bEftSaveRefferal	:1;
	unsigned char bEftVoid			:1;  // Do cancel after restore transaction
	unsigned char bEftGetAuth		:1;	 // After Get manual auth.
	unsigned char bManualSwipeRequired:1; // Required manual swipe of card
	unsigned char bTrsProcessed     :1; // #1935 Indication trs was already process (in case of several recalls)

	unsigned char bnu				:3;	// 3
	unsigned char stMerchantTelephone[15]; // 4 

	unsigned short eft_tender_no;		//19
	long	lAmount;					//21
	long	lCashBackAmount;			//25
	unsigned short	usSessionId;		//29
	unsigned short	usSavePosNum;		//31
	unsigned short	usSaveTicketNum;	//33
	unsigned char   uchCardSessionOrgTndr; //35
	unsigned char   sSponsorID[2];		//36

	long 	lSessionId;					//38
	char nu[2];							//42 
	struct   trans_tail_  tail; /*44*/
};

// TRANS_INFO_OLA_TRANS_REF	(unsigned char) 0x08
// TransRef Paramter for settlement.
struct trs_ola_transref_
{
	unsigned char opcode;		//0x60	<Opcode Value="0x60" />
	unsigned char function;		//0x28	<Opcode Value="0x28" />
	unsigned char sub_func;		//0x08	<Opcode Value="0x08" />	TRANS_INFO_OLA_TRANS_REF

	unsigned char sTransRef[40];		// 3
	unsigned char uchTransRefLength;	// 43

	struct   trans_tail_  tail;			// 44
};

//CR131
struct trs_cc_req_
{
	unsigned char opcode;    //0x60	<Opcode Value="0x60"/>
	unsigned char function;  //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;	 //0x11	<Opcode Value="0x11"/>

	unsigned char open_comm_failed :1;
	unsigned char tx_failed		    :1;
	unsigned char nu02             :1;
	unsigned char nu03             :1;
	unsigned char nu04             :1;
	unsigned char nu05             :1;
	unsigned char nu06             :1;
	unsigned char nu07             :1;

	unsigned long msg_no;
   
	unsigned char card_data[10]; //BCD up to 19 digits
   unsigned char card_data_len;
   unsigned char trs_type;
   
	unsigned char reserved[24];

	struct   trans_tail_  tail;
};


//CR131
struct trs_cc_ans_strt_
{
	unsigned char opcode;    //0x60	<Opcode Value="0x60"/>
	unsigned char function;  //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;	 //0x12	<Opcode Value="0x12"/>

	unsigned char timeout          :1;
	unsigned char msg_rejected     :1;                   
	unsigned char er_avail_flag	 :1;	 //CR131 yulia
	unsigned char nu03             :1;
	unsigned char nu04             :1;
	unsigned char nu05             :1;
	unsigned char nu06             :1;
	unsigned char nu07             :1; // 3

	unsigned int  req_msg_no;      // 4
	unsigned int  ans_msg_no;      // 8

	unsigned short family_favourite_choice[10];  // 12
	unsigned char  cust_type;			 // 22

	long           acc_points; // 23
	long           redem_value;     // 27
	short int      operator_msg_no;  // 31        

	unsigned char cust_upd_date[3];	  //35 DR2612
	unsigned char reserved[2];        //38 

	struct   trans_tail_  tail;       // 40
};


//CR131
struct trs_cc_ans_cont_
{
	unsigned char opcode;    //0x60	<Opcode Value="0x60"/>
	unsigned char function;  //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;	 //0x13	<Opcode Value="0x13"/>

   unsigned char prom_msg[5];
   long          prom_points[5];
   
	long 			  redem_thresh;
	long			  redem_step;

	long          scnd_curr_bal; //DR2612
	unsigned char reserved[4];
   
	struct   trans_tail_  tail;
};


//CR131
struct trs_cc_eot_
{
	unsigned char opcode;    //0x60	<Opcode Value="0x60"/>
	unsigned char function;  //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;	 //0x14	<Opcode Value="0x14"/>

	unsigned char open_comm_failed :1;
	unsigned char tx_failed		    :1;
	unsigned char nu02             :1;
	unsigned char nu03             :1;
	unsigned char nu04             :1;
	unsigned char nu05             :1;
	unsigned char nu06             :1;
	unsigned char nu07             :1;

	unsigned long msg_no;
   
	unsigned char reserved[36];
   
	struct   trans_tail_  tail;
};


// Hungary_EFT result
struct trs_hungary_ola_result_
{	
	unsigned char opcode;      //0x60	<Opcode Value="0x06"/>
	unsigned char function;    //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func; 	//0x30	<Opcode Value="0x30"/> hungary Ola results

	unsigned char card_accepted    :1;
	unsigned char nu01             :1;
	unsigned char nu02             :1;
	unsigned char nu03             :1;
	unsigned char nu04             :1;
	unsigned char nu05             :1;
	unsigned char nu06             :1;
	unsigned char nu07             :1;

	unsigned long msg_no;
	unsigned char nu1;
	unsigned char trans_type;
	unsigned char auth_type;
	unsigned char nu2;
   
            int  ans_rtc;  // 0    - Ok
									// 1-10 - Host answer
									// -1   - BAD
									// -6   - Timeout  
   
	unsigned char auth_code[10];
	unsigned char nu3;
	unsigned char account[10]; //BCD up to 19 digits
	unsigned char account_len;
   			long amount;
	unsigned char response_code[3];
	unsigned char nu4;

	struct   trans_tail_  tail;
};


// Hungary_EFT  request
struct trs_hungary_ola_req_
{
	unsigned char opcode;    //0x60	<Opcode Value="0x60"/>
	unsigned char function;  //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;	 //0x31	<Opcode Value="0x31"/>

	unsigned char nu00             :1;
	unsigned char tx_failed		    :1;
	unsigned char nu02             :1;
	unsigned char nu03             :1;
	unsigned char nu04             :1;
	unsigned char nu05             :1;
	unsigned char nu06             :1;
	unsigned char nu07             :1;

	unsigned long msg_no;
   
	unsigned char card_data[24]; //nul terminated
	unsigned char trans_type;
	unsigned char auth_type;
   
	long			  req_amount; // amount + cashback
   
	unsigned char reserved[6];
   
	struct   trans_tail_  tail;
};

struct trs_ola_e_pay_result_
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60"/>
	unsigned char function;    //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;    //0x32	<Opcode Value="0x32"/>

	unsigned short SessionId;   //3
	unsigned char ola_date[4];  //5
	unsigned char ola_time[2];  //9

	unsigned char PinSerialNumber[15];     //11 // Pin Serial Number
	unsigned char AuthorisationCode[9];    //26 // Authorisation code from OLA response 

	short ResponseCode;                    //35 // Response code
	unsigned char  ReversalAuthorisation;  //37

	unsigned long SeqNo;                    //38
	unsigned char bSecondExtensionTransExists :1; //42		//FSD 28793
	unsigned char bVoidAfterAuth			  :1;
	unsigned char filler			    :6; //42
	unsigned char not_used[1];              //43


	struct   trans_tail_  tail;            //44 
};

struct trs_ola_e_pay_result_ext_
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60"/>
	unsigned char function;    //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;    //0x33	<Opcode Value="0x33"/>

	unsigned short SessionId;   //3
	unsigned char  ApplOption;  //5 // 1-Card or 2-Voucher

    union                       //6
	{
		struct                  // Card information
		{
			unsigned char MobileNumber[15];
			unsigned char nu[12];
		}inf1;                  
		struct                  // Voucher information  
		{
			unsigned char PinNumber[24];
			unsigned char PINExpDate[3];
		}inf2;                   
	};

	unsigned char PinNumber_ext[8];		//33, N#6546 if pin number len is bigger then 24 get the right size
	unsigned char pak_IdentifyNum[3];   //41

	struct   trans_tail_  tail;         //44 
};


//FSD 28793
struct trs_ola_e_pay_result_ext2_ 
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60"/>
	unsigned char function;    //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;    //0x47	<Opcode Value="0x47"/>
	
	unsigned char sPinSerialNumber[28];   //3
	unsigned char sAuthNumber[13];			  //31 - FSD32829

	struct   trans_tail_  tail;			  //44 
};


//FSD153313
struct trs_ola_gift_card_result_ext_
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60"/>	
	unsigned char function;    //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;    //0x34	<Opcode Value="0x4D"/>

	char sMaskedCardNumber[30]; //3

	char NotUsed[11];			//33

	struct   trans_tail_  tail;         //44 
};
struct trs_ola_gift_card_result_       //FS3012
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60"/>	
	unsigned char function;    //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;    //0x34	<Opcode Value="0x34"/>
 
	unsigned short ushSessionId;      //3
	unsigned char bcdExpiryDate[2];   //5  //MMYY
	
	unsigned char sAcountNumber[10];	//7 BCD up to 19 digits
	unsigned char sMerchantID[5];		//17 YohayB - used to be size [15]
	long lOldAmountBalance;				//22 
	long lNewAmountBalance;				//36 
	
	short shResponseCode;             //30 
	struct flag_				      //32	
	{
		unsigned char  bReversalAuthorisation  :1; //32
		unsigned char  bPanMasking		       :1; //32
		unsigned char  bWasCanceled            :1; //FSD2270 - For PPt Gift Cards Printing		
		unsigned char  bExecutedAtNoSaleMode   :1; //FSD2270 - For PPt Gift Cards Printing		  
		unsigned char  bExecutedFromBalanceTransfer   :1; //FSD2270 - For PPt Gift Cards Printing		  
		unsigned char  bExecutedFromRefundOrRedemption   :1; //FSD2270 - For PPt Gift Cards Printing		  
		unsigned char  nu_bits                 :2;   
	}Flags;

	unsigned long ulSeqNo;              //33
	
	unsigned char chMaskChar;		//37
	unsigned char chMaskEnd;		//38
	unsigned char chMaskStart;		//39
	unsigned char sPanLayOut[3];	//40
	unsigned char uchActionType;	//43 FSD22770

	struct   trans_tail_  tail;         //44 
};

struct trs_ola_bill_payment_result_       //FS4002
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60"/>
	unsigned char function;    //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;    //0x35	<Opcode Value="0x35"/>
 
	unsigned short ushSessionId;			//3
	unsigned char bcdTransactionDate[2];   //5  //MMYY
	unsigned char bcdTransactionTime[2];   //7  //MMYY

	unsigned char sMerchantID[15];    //9 

	short shResponseCode;             //24 
	struct BillFlag_				      //26	
	{
		unsigned char  bReversalAuthorisation  :1;
		unsigned char  nu_bits                 :7;   
	}Flags;

	unsigned long ulSeqNo;              //27
	unsigned char bcdBillNumber[10];    //31
	unsigned char uchBillType;			//41
	unsigned char uchBillNumberLength;  //42

	char	nu;							//43

	struct   trans_tail_  tail;         //44 
};

struct trs_ola_auth_guid_				//CR#6387
{
	unsigned char opcode;				//0x60	<Opcode Value="0x60"/>
	unsigned char function;				//0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;				//0x36	<Opcode Value="0x36"/>
	
	unsigned char request_session	:1;	// 03
	unsigned char auth_session		:1;	
	unsigned char reversal_session	:1;	
	unsigned char nu0				:1;	
	unsigned char nu1				:1;	
	unsigned char nu2				:1;	
	unsigned char nu3				:1;	
	unsigned char nu4				:1;	
	
	unsigned char nu[8];				// 04
	unsigned char uchguid[32];			// 12 

	struct   trans_tail_  tail;			// 44
};

//FSD29721
struct trs_ola_gift_card_addInf_ 
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60"/>	
	unsigned char function;    //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;    //0x37	<Opcode Value="0x37"/>
 
	unsigned short ushSessionId;      //3
	unsigned char sAcountNumber[10];	//5 BCD up to 19 digits

	struct flagAddInf_				      //15	
	{
		unsigned char  bReversalAuthorisation  :1; //15
		unsigned char  bWasCanceled            :1;
		unsigned char  bBalanceAmountAvail     :1;   //TD276983
		unsigned char  bNewBalanceAmountAvail  :1;   //TD276983
		unsigned char  nu_bits                 :4;   
	}Flags;

	unsigned long ulSeqNo;              //16 
	long lBalanceAmount;				//20
	long lNewAmountBalance;				//24 //FSD29721_150807D

	unsigned char nuAddInf[16];			//28
	
	struct   trans_tail_  tail;         //44 
};

/*----------------------------------------------------------------------
Opcode:		0x60
Subopcode:	0x28
Subfunction:0x38
EFT transaction ID. This transaction logs the tranaction ID received from
the EFT provider at the beginning of the EFT transaction. Started with
Syncro implementation.
-----------------------------------------------------------------------*/
struct trs_ola_trans_id_			//OFS	Description
{
	unsigned char opcode;			//0		0x60 <Opcode Value="0x60"/>	
	unsigned char function;			//1		0x28 <Opcode Value="0x28"/>	
	unsigned char sub_func;			//2		0x38 <Opcode Value="0x38"/>	

	unsigned char uchSyncroEvent;	//3		Syncro EFT event type (see WPEftWyncro.dll)
	unsigned long ulTransID;		//4		Transaction ID
	unsigned char tender_id;		//8
	long		  amount;			//9
	long		  cashout;			//13

	unsigned char uchFiller[27];	//17		not used

	struct   trans_tail_  tail;		//44	Transaction tail
};									//64

/*----------------------------------------------------------------------
Opcode:		0x60
Subopcode:	0x28
Subfunction:0x39
-----------------------------------------------------------------------*/
struct trs_ola_activation_code_ext_			//FSD61084
{
	unsigned char opcode;			//0		0x60 <Opcode Value="0x60"/>	
	unsigned char function;			//1		0x28 <Opcode Value="0x28"/>	
	unsigned char sub_func;			//2		0x39 <Opcode Value="0x39"/>	

	unsigned char ActivationCode[10]; //3	
	unsigned char bTemplatePrintingSucceeded	: 1; //13
	unsigned char bNU							:7;

	unsigned long ulSeqNo;			//14
	unsigned char uchFiller[26];	//18		not used

	struct   trans_tail_  tail;		//44	Transaction tail
};			

struct trs_ola_serialnumber_ext_	//N#6755
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60"/>
	unsigned char function;    //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;    //0x42	<Opcode Value="0x42"/>

	unsigned char PinSerialNumber_ext[15]; //3
	unsigned char uchOnlinePurchaseProvider; //18 FSD17863  Provider ID ( Using trs as ext to trs_info_online_purchase_item_ which was suppose to be its real purpose).
	unsigned char not_used[25];   //19

	struct   trans_tail_  tail;         //44 
};

struct trs_ola_pinnumber_ext_2_			//N#6546, CR#3037
{
	unsigned char opcode;      //0x60
	unsigned char function;    //0x28
	unsigned char sub_func;    //0x43

	unsigned char Ext2_PinNumber[28];   // 3
	unsigned char notused[13];				//31
	
	struct   trans_tail_  tail;         //44 
};

struct trs_ola_IdentifyNumber_ext_			//N#6546, CR#3037
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60"/>
	unsigned char function;    //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;    //0x45	<Opcode Value="0x45"/>

	unsigned char IdentifyNumber[7];   // 3
	unsigned char bcdTransSeqNumber[30];	//10 BCD FSD14337
	unsigned char uchTransSeqNumberLength;	//40 FSD14337

	unsigned char bConfirmationRequestRequired		:1;	//41 FSD32111
	unsigned char bSlipTextReceivedUponConfirmation	:1; //42 FSD32111
	unsigned char nu								:6;	//41 FSD32111
	
	unsigned char notused[2];						//42
	
	struct   trans_tail_  tail;         //44 
};

struct trs_ola_UniqID_ext_			//FSD26804
{
	unsigned char opcode;					//0x60	<Opcode Value="0x60"/>
	unsigned char function;					//0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;					//0x48	<Opcode Value="0x48"/>
											
	unsigned char UniqID[32];				//3	
	unsigned char uchUniqIDLength;			//35
	unsigned char notused_uniq[8];			//36
											
	struct   trans_tail_  tail;				//44 
};

struct trs_ola_loyalty_update_result_			//FSD11780
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60"/>
	unsigned char function;    //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;    //0x46	<Opcode Value="0x46"/>

    unsigned char	sAccountNumber[10];			//3		
	long			lProviderResponseCode;		//13				 
	unsigned char	notused[27];				//17
	
	struct   trans_tail_  tail;			        //44 
};

/*----------------------------------------------------------------------
Opcode: 0x60 function:0x28 sub_func: 0x44
FS5721: Added information to ola result extension 2.
-----------------------------------------------------------------------*/
//!EranL!
struct trs_ola_result_ext2_             //OFS		Description
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60"/>
	unsigned char function;    //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;    //0x44	<Opcode Value="0x44"/>

	long lDeviceNumber;			//3
	long lAmount;				//7		amount added/deducted
	long lRemainingValue;		//11

	long lRewardRedeemed;		//15
	long lActualRewardRedeemValue;			//19	
	long lRewardBalance;		//23
	long lExtraRewardEarned;	//27
	short shStandardRewardEarned;	//31

	char bcdAccountNumber[10];	//33 BCD

   unsigned char filler[1];     //43 Not used      

   struct   trans_tail_  tail;               //44     TRS tail
};

/*----------------------------------------------------------------------
Opcode: 0x60 function:0x28 sub_func: 0x4C
EFTPOS card data: masked card number as received from OLA plus few other bits of info
-----------------------------------------------------------------------*/
struct trs_ola_card_data_             //OFS		Description
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60"/>
	unsigned char function;    //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;    //0x4C	<Opcode Value="0x4C"/>

   unsigned char szCardPAN[17]; //3   Maked card# as received from EFTPOS
   unsigned char szCardType[16];//20  Card type as read from card range table
   unsigned char szOLAResponseCodeForDenial[4];		//36  //FSD296959
   short shTenderNumberReturned;						//40

   unsigned char uchAccountType;//42  1:cheque 2:credit 3:savings 

   unsigned char bEOVOffline :1;	//43 the EFTPOS transaction was done offline and required signature #3919
   unsigned char bSignPIN    :1;    //43 0: customer keyed PIN 1: customer signed
   unsigned char bNotUsed    :6;	//43


   struct   trans_tail_  tail; //44     TRS tail
};

struct trs_ola_abort_
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60" />
	unsigned char function;    //0x28	<Opcode Value="0x28" />
	unsigned char sub_func; 	//0x99	<Opcode Value="0x99" />aborted by user

	unsigned long msg_no;    // 03

	struct CardTypeFlag_ CardTypeFlag; /*07*/	

	unsigned char account[10]; //BCD up to 19 digits /*08*/
	unsigned char account_len; // 18
	
	unsigned char reserved[24];  // 19

	unsigned char pump;          // 43
   
	struct   trans_tail_  tail;  // 44
};


struct trs_auth_price_diff_
{
    unsigned char opcode;	  	//0x60	<Opcode Value="0x60" />
    unsigned char function;	//0x29		<Opcode Value="0x29" />

    unsigned char code[7];

    unsigned char nu00	   :1;
    unsigned char nu01	   :1;
    unsigned char nu02	   :1;
    unsigned char nu03	   :1;
    unsigned char nu04	   :1;
    unsigned char nu05	   :1;
    unsigned char nu06	   :1;
    unsigned char nu07	   :1;

    long	    authorized_price;
    long	    sold_price;
    
    long		 qty;
    long	    diff_amount;

    unsigned char reserved[18];
    struct   trans_tail_  tail;
};


struct trs_host_batch_
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60" />
	unsigned char function;    //0x2A	<Opcode Value="0x2A" />
   
	unsigned char option;      //0-Start 1-End
   									//2-Start rejected

   unsigned char host_batch_number[6];
   unsigned long host_records;
   unsigned long accepted_records;
    
	unsigned char post_batches;
	unsigned char post_batch1[6];
	unsigned char post_batch2[6];
	unsigned char post_batch3[6];
	unsigned char reserved[8];

	struct   trans_tail_  tail;
};


struct trs_check_fee_
{
    unsigned char opcode;	  	//0x60	<Opcode Value="0x60" />
    unsigned char function;	//0x2B		<Opcode Value="0x2B" />

    unsigned char fee_code[7];
    
    unsigned char uchServiceFeeType	:2;	//#23033
    unsigned char nu02	   :1;
    unsigned char nu03	   :1;
    unsigned char nu04	   :1;
    unsigned char nu05	   :1;
    unsigned char nu06	   :1;
    unsigned char nu07	   :1;
    
    long	         fee_price;
    long	         cashback;
    unsigned char table_no;
    unsigned short dep_no;
    unsigned short tender_no;
    unsigned char fee_type;

    unsigned char reserved[20];
    struct   trans_tail_  tail;
};

struct trs_commission_
{
	unsigned char opcode;	  	//0x60 <Opcode Value="0x60" />
	unsigned char function;	   //0x3C <Opcode Value="0x3C" />
   
	long commision_amount;      
	long tender_amount;    
	long percent;
	unsigned char tnder_name[16];
   
   unsigned char cancel   :1;
   unsigned char subtract :1;
   unsigned char nu02     :1;
   unsigned char nu03     :1;
   unsigned char nu04     :1;
   unsigned char nu05     :1;
   unsigned char nu06     :1;
   unsigned char nu07     :1;

   unsigned long sPluOrDepTrsSequence;//FSD307721
   
	unsigned char reserved[9];
	struct   trans_tail_  tail;
};


struct trs_fly_buy_
{
	unsigned char opcode;           //0x60	<Opcode Value="0x60" />
	unsigned char function;         //0x3D	<Opcode Value="0x3D" />

	unsigned char final     :1;
	unsigned char voided    :1;
	unsigned char nu02      :1;
	unsigned char nu03      :1;
	unsigned char nu04      :1;
	unsigned char bClubCardIndicator      :1; //FSD#444616
	unsigned char MCR_used  :1;
	unsigned char scanned   :1;

	unsigned char card_no[20];
	long		  amount;

	char clubcard[16];
	unsigned char reserved[1];
   
	struct   trans_tail_  tail;
};


struct trs_new_ecca_
{
    unsigned char opcode;         //0x60 <Opcode Value="0x60" />
    unsigned char function;       //0x2C <Opcode Value="0x2C" />

    unsigned char templates;   // 2
    unsigned char account[20]; // 3   //ascci null terminated

    unsigned char second_ecca : 1; 
    unsigned char nu          : 7; // 23
    unsigned char reserved[20];	   // 24 

    struct   trans_tail_  tail;    // 44
};


struct trs_eft_media_
{
    unsigned char opcode;         //0x60 <Opcode Value="0x60" />
    unsigned char function;       //0x2E <Opcode Value="0x2E" />

    unsigned short  cashier;
    unsigned short  media_no;
    unsigned long   amount;
	unsigned char	uchPaymentOption;
    unsigned char	referanceNumber[12]; //FSD266668
   unsigned char	referanceId[6]; //NTUC PILOT
    unsigned char	reserved[15];

    struct   trans_tail_  tail;
};


struct trs_eft_print_reject_
{
    unsigned char opcode;         //0x60 <Opcode Value="0x60" />
    unsigned char function;       //0x2F <Opcode Value="0x2F" />

    unsigned char tender_no[2];
    unsigned short  error_code;
    unsigned char account_no[20];
    long balance1;
    long balance2;

	unsigned short SessionID;		//FSD3598 - add sessionID for retrieval of extra information 

	unsigned char eft_print_data_indication		:1;           
	unsigned char nu							:7;

	unsigned char multi_part_option;

    unsigned char reserved[6];

    struct   trans_tail_  tail;
};


struct trs_trans_index_
{
	unsigned char opcode;           //0x60	<Opcode Value="0x60" />
	unsigned char function;         //0x30	<Opcode Value="0x30" />

	unsigned char opt_ticket_total  :1;
	unsigned char opt_void_ticket   :1;
	unsigned char opt_save_ticket   :1;
	unsigned char opt_nu13          :1;
	unsigned char opt_nu14          :1;
	unsigned char opt_nu15          :1;
	unsigned char opt_nu16          :1;
	unsigned char opt_info          :1;
   
   unsigned char opt_nu20          :1;
   unsigned char opt_nu21          :1;
   unsigned char opt_nu22          :1;
   unsigned char opt_nu23          :1;
   unsigned char opt_nu24          :1;
   unsigned char opt_nu25          :1;
   unsigned char opt_nu26          :1;
   unsigned char opt_nu27          :1;
   
   unsigned char index_clubcard    :1;
   unsigned char index_01          :1;
   unsigned char index_02          :1;
   unsigned char index_03          :1;
   unsigned char index_04          :1;
   unsigned char index_05          :1;
   unsigned char index_06          :1;
   unsigned char index_07          :1;
   
	unsigned char index_len;
	unsigned char index[30];	
    
	unsigned char reserved[8];

	struct   trans_tail_  tail;
};




struct trs_chksum_
{
    unsigned char opcode;      //0x60 <Opcode Value="0x60" />
    unsigned char function;    //0x06 <Opcode Value="0x06" />

    unsigned char no_chksum_perform    :1;
    unsigned char ignored_plu_mnt      :1;
    unsigned char ignored_brom_mnt     :1;
    unsigned char plu_chksum_fail      :1;
    unsigned char brom_chksum_fail     :1;
    unsigned char opt_nu15             :1;
    unsigned char opt_nu16             :1;
    unsigned char opt_nu17             :1;

    unsigned long pos_plu_count;
    unsigned long pos_plu_chksum;
    unsigned long pos_brom_count;
    unsigned long pos_brom_chksum;

    unsigned long pc_plu_count;
    unsigned long pc_plu_chksum;
    unsigned long pc_brom_count;
    unsigned long pc_brom_chksum;

    unsigned char reseved[9];

    struct   trans_tail_  tail;
};


struct trs_bkgd_load_
{
    unsigned char opcode;      //0x60 <Opcode Value="0x60" />
    unsigned char function;    //0x07 <Opcode Value="0x07" />

    unsigned char start_plu_file_load  :1;
    unsigned char stop_plu_file_load   :1;
    unsigned char start_brom_file_load :1;
    unsigned char stop_brom_file_load  :1;
    unsigned char opt_nu14             :1;
    unsigned char opt_nu15             :1;
    unsigned char opt_nu16             :1;
    unsigned char opt_nu17             :1;

    unsigned short  new_items;
    unsigned short  upd_items;
    unsigned short  del_items;
    unsigned short  errors;

    unsigned char reseved[33];

    struct   trans_tail_  tail;
};


struct trs_retrans_
{
    unsigned char opcode;	  	//0x60	<Opcode Value="0x60" />
    unsigned char function;	//0x54		<Opcode Value="0x54" />
    
    unsigned char fail     :1;
    unsigned char ignore   :1;
    unsigned char nu02     :1;
    unsigned char nu03     :1;
    unsigned char nu04     :1;
    unsigned char nu05     :1;
    unsigned char nu06     :1;
    unsigned char nu07     :1;

	 unsigned short  retrans_req;
    
    unsigned short  trans_fifo_size;
    unsigned short  trans_first;
    unsigned long trans_pointer;
    unsigned short  trans_count;
    unsigned short  future_trans_count;
    unsigned short  trans_seq_no;
    
    // Ignore loging
	 unsigned short  seq_range_start;
	 unsigned short  seq_range_end;

	 // Fail logging
	 unsigned short  read_ptr;
	 unsigned short  alt_read_ptr;
    
    unsigned char reserved[17];
    struct   trans_tail_  tail;
};


struct trs_fuel_pay_at_pump_info_
{
   unsigned char opcode;      //0x60	<Opcode Value="0x60" />
	unsigned char function;    //0x6D	<Opcode Value="0x6D" />
	unsigned char sub_func;    //0x01	<Opcode Value="0x01" />

   unsigned char trs_date[3];   //BCD YMD
   unsigned char trs_time[3];   //BCD HMS
	
	unsigned long InvoiceNumber;
	unsigned char ReferenceNumber[12];
	unsigned char sCardName[19];

	struct   trans_tail_  tail;
};






struct trs_log_func_
{
    unsigned char opcode;//0         //0x20 <Opcode Value="0x20" />

    unsigned char function;//1    // 01 - power up
                                  // 02 - store open
                                  // 03 - store close (EOD)
                                  // 04 - automatic recover ticket
                                  // 11 - sign on
                                  // 12 - sign off
                                  // 13 - enter secure mode
                                  // 14 - exit secure mode
                                  // 15 - enter wait mode
                                  // 16 - exit wait mode
                                  // 17 - enter training mode
                                  // 18 - exit training mode
                                  // 19 - password change
                                  // 20 - Zero cashier totals
                                  // 21 - Move totals to prev, Zero current
                                  // 22 -	X_READ                 
                                  // 23 -	POS_REPORT             
                                  // 24 -	MOVE_POS_TTL_2_PRV_ZERO
                                  // 25 -	RESERVED FOR PC USAGE  
                                  // 26 -	START_SPECIAL_PRINTOUT
                                  // 27 -	END_SPECIAL_PRINTOUT  
                                  // 28 -	Store Board message
                                  // 29 -	START Reorg print
                                  // 30 -	END Reorg print
                                  // 31 - X ITEMIZED check report
                                  // 32 - Z ITEMIZED check report
                                  // 33 - Depart report          
                                  // 34 - Tax report             
                                  // 35 - Declaration
                                  // 36 - Print dupl gift			
                                  // 37 - Cust ord error report	
                                  // 38 - Electronic sign on
                                  // 39 - Manual Enter Secure Mode (FSD4906)
								  // 40 - LayBy old ticket start section, LOG_FUNC_LAYBY_OLD_TICKET_START, FSD6248 LayBy
								  // 41 - Layby old ticket end section, LOG_FUNC_LAYBY_OLD_TICKET_END, FSD6248 LayBy
								  // 44 - Long password password change, uses struct trs_log_func_long_password_
								  // 45 - EMERGENCY_DRAWER_OPENING, //FSD26800
								  // 46 - sign on with long user
								  // 47 - Ask Promotion what was triggered, LOG_FUNC_ASK_PROM_WHAT_TRIGGERED, #40427
								  // 48 - Perform POS Locking At Pos EOD (Manual EOD) //FSD53694
									// 99 - PC start of day



    unsigned short  cashier_no;	//2
    unsigned short  secret_no;	//4

    struct	//6
    {
       unsigned char offline_exe        :1;
       unsigned char remote_cmd         :1;
	   unsigned char opt_reprocess      :1; // B/O use
       unsigned char force_cmd          :1; // Enh #1962SL
	   unsigned char forceSuperVisor    :1; // FSD7786 
       unsigned char bTemporarySignOff	:1;	// FSD39662 - turn on for temporarySignOff when using 2 drawers on same pos
       unsigned char bPermanentlyForcedSignOffBySupervisor :1;// FSD39662 - turn on for PermanentlySignOff from drawersAssignment()
       unsigned char end_of_period      :1;
    }opt;


    unsigned char pos_staus;//7   // COLD_STAND_BY  0x00
                                  // STAND_BY       0x01
                                  // IDLE           0x02
                                  // NO_SALE        0x04
                                  // SALE           0x08
                                  // TENDER         0x10
                                  // IDLE_STAND_BY1 0x20
                                  // IDLE_STAND_BY2 0x40

    unsigned short ticket_no;//8

    unsigned short old_password;//10
    unsigned short new_password;//12

    unsigned char  pos_no;		//14
    
	unsigned short used_drawer1;//15
	unsigned short used_drawer2;//17
    unsigned char  text[21];	//19
    
    unsigned char cashier_msg_no; 

    unsigned char reset_msg		:1; 
    unsigned char set_msg		:1;
    unsigned char immediate_msg :1; //#1585
    unsigned char alfa_numeric_password	:1;
    unsigned char bPerformPosLockingAtPosEod:1;//FSD53694 - after FSD Updates.
    unsigned char nu5			:1;
    unsigned char nu6			:1;
    unsigned char nu7			:1;

    unsigned short  code;
    
    struct   trans_tail_  tail;
};

//FSD 13459. trs_log_func updated to allow long cashier password
struct trs_log_func_long_password_
{
    unsigned char opcode;         //0x20	<Opcode Value="0x20"/>

    unsigned char function;       // 44 - long password password change



    unsigned short  cashier_no;
    unsigned short  secret_no;

    struct
    {
       unsigned char offline_exe        :1;
       unsigned char remote_cmd         :1;
	   unsigned char opt_reprocess      :1; // B/O use
       unsigned char force_cmd          :1; // Enh #1962SL
	   unsigned char forceSuperVisor    :1; // FSD7786 
       unsigned char bTemporarySignOff	:1;	// FSD39662 - turn on for temporarySignOff when using 2 drawers on same pos
       unsigned char bPermanentlyForcedSignOffBySupervisor :1;// FSD39662 - turn on for PermanentlySignOff from drawersAssignment()
       unsigned char end_of_period      :1;
    }opt;


    unsigned char pos_staus;      // COLD_STAND_BY  0x00
                                  // STAND_BY       0x01
                                  // IDLE           0x02
                                  // NO_SALE        0x04
                                  // SALE           0x08
                                  // TENDER         0x10
                                  // IDLE_STAND_BY1 0x20
                                  // IDLE_STAND_BY2 0x40

    unsigned short ticket_no;

    unsigned short old_password;
    unsigned short new_password;

    unsigned char  pos_no;
    
	unsigned short used_drawer1;
	unsigned short used_drawer2;

	unsigned char szOldLongPassword[10]; //FSD 13459
	unsigned char szNewLongPassword[10]; //FSD 13459

	unsigned char nu; 
    
    unsigned char cashier_msg_no; 

    unsigned char reset_msg					:1; 
    unsigned char set_msg						:1;
    unsigned char immediate_msg				:1; //#1585
    unsigned char alfa_numeric_password	:1;
    unsigned char nu4			:1;
    unsigned char nu5			:1;
    unsigned char nu6			:1;
    unsigned char nu7			:1;

    unsigned short  code;
    
    struct   trans_tail_  tail;
};


struct trs_float_
{
	unsigned char opcode;         //0x07 <Opcode Value="0x07" />

	unsigned char function;       // 01 - opening float
								  // 02 - add on float
								  // 03 - POST add on float

	long          amount;  // 2
	short           count; // 6
	unsigned char tender;  // 8

	long          total;   // 9

	 // PC generated options
	unsigned char previous_period   :1;
	unsigned char no_empl_update    :1;
	unsigned char opt_reprocess     :1; // B/O use
	unsigned char opt_remote        :1; // B/O use
	unsigned char opt_amount_int64  :1; // B/O use
	unsigned char bLoanType         :1;	//FSD56621	0=normal loan , 1=ATM loan
	unsigned char bPOSAccontability :1;
	unsigned char bReportPrintingRequired :1; // 13 //FSD365329 - changed in FSD450223 - added indication for 'Report Printing'

	unsigned char pc_no;              // 14
	unsigned char pos_no;			  // 15
	unsigned long supervisor_no;     // 16 SAL54

	long          safe_no;       // 20 ; B/O use
	__int64       amount2;       // 24 ; B/O use

	long		  carry_over_amount; //32 carry_over (amount kept)
	short         carry_over_count;  //36 carry_over (amount kept)

	unsigned char loan_type;         //38 0=default, 1=transfer funds (Epic316907)
	unsigned char other_pos_no;      //39 pos_no from transfer pair transaction

	unsigned char nu[4];             // 41
	struct   trans_tail_  tail;      // 44
};


struct trs_cash_lift_
{
    unsigned char opcode;         //0x09 <Opcode Value="C" />

    unsigned char function;       // 01 - Regular
    										 // 02 - POST pickup

    long          amount;			//2
    short         count;			//6
    unsigned char tender;			//8

    long          reserved;			//9

	 // PC generated options
    unsigned char previous_period :1;	//13
    unsigned char no_empl_update  :1;
    unsigned char opt_reprocess   :1; // B/O use
    unsigned char opt_remote      :1;
    unsigned char opt_int64       :1; //FSD2733
    unsigned char opt_nu05        :1; //used by the FO
    unsigned char opt_void        :1; //#51300
    unsigned char bPickupType     :1;	//FSD56621	0=normal pickup , 1=ATM pickup
    
    unsigned char pos_no;				//14
    unsigned char pc_no;				//15
	unsigned long supervisor_no;		//16 SAL54
	unsigned short cashier_no;			//20
									
	//FSD2733
    long			safe_no;			// 22  FO use
   __int64			amount2;			// 26  

    //#55356 Send Foreign currency amount and exchange rate. vincentb
	long          foreign_amount;			//34	Foreign currency amount
    long          foreign_rate;				//38	Foreign currency rate

	unsigned char pickup_type;              //42 FO use: 0=default, 1=borrowed funds (Epic316907)	

	unsigned char bReportPrintingRequired :1;//43 FSD450223 - added indication for 'Report Printing' 
    unsigned char bNU_BITS                :7;//43
	                                        
    struct   trans_tail_  tail;
};


/*----------------------------------------------------------------------
Opcode: 0x0b
Cashier/safe declaration
-----------------------------------------------------------------------*/
struct trs_declare_                 //OFS	Description
{
    unsigned char opcode;           //0   0x0B  <Opcode Value="0x0B" />

    unsigned char function;         //1   Function  <Opcode Value="1,2,10" />
                                    //    01 - Cashier 
                                    //    02 - POS
                                    //    10 - Safe

    long          amount;           //2   Total amount declared in period (DOS systems)
    short         count;            //6   Total quantity declared for this tender (DOS systems)
    unsigned char tender;           //8   Tender number
#ifdef PRJ_ROW
    long          total;            //9
#else
	unsigned short manager_no;      //9   Manager number
	unsigned char  not_used[2];     //11  Not used
#endif
	                                 //13  PC generated options
    unsigned char previous_period:1;//13  Declaration for previous period
    unsigned char no_empl_update :1;//13  Do not update EMPL record
    unsigned char opt_reprocess  :1;//13  Process only if in reprocess mode
    unsigned char opt_additive   :1;//13  additive declaration: add "this time" to existing values
    unsigned char opt_remote     :1;//13  remote declaration                                       
    unsigned char opt_amount_int64:1;//13 Amount is stored in int64 field
    unsigned char opt_first       :1;//13 FS18338
    unsigned char opt_info        :1;//13 informative only. ignore this record.
    
    long          amount_this_time; //14  Amount declared this time 
    short         count_this_time;  //18  Quantity declared this time
    unsigned char  pos_no;          //20  POS number (POS accountability)
    unsigned short cashier_no;      //21  Cashier number
    unsigned short safe_no;         //23  Safe number
   __int64       amount2;           //25  Total amount declared in period 
   __int64       amount_this_time2; //33  Amount declared in this session        
   
    unsigned char work_date[3];     //41  working date for which declaration to be applied
    struct   trans_tail_  tail;
};


// DannyF 06/01/03 add bit opt_during_ticket to 0x60 , 0x18
// DannyF 22/01/03 add opt_vat_receipt to 0x60 , 0x18 reprint
// DavidHu 04/01/10 FSD70677: add opt_duplicate_receipt to 0x60,0x18 by Duplicate Receipt for FrontOffice
struct trs_reprint_
{
    unsigned char opcode;      //0x60	<Opcode Value="0x60"/>
    unsigned char function;    //0x18	<Opcode Value="0x18"/>

    unsigned char opt_during_ticket	:1;
    unsigned char opt_vat_receipt	:1;
    unsigned char opt_buffer_print	:1; //FSD14741
    unsigned char opt_duplicate_receipt	:1; //FSD70677
    unsigned char opt_nu14			:1;
    unsigned char opt_nu15			:1;
    unsigned char opt_nu16			:1;
    unsigned char opt_nu17			:1;		//2

    unsigned char pos;						//3
    unsigned short  receipt_no;				//4

	unsigned short ushDocType;				//6

    unsigned char reseved[36];				//8

    struct   trans_tail_  tail;				//44
};

struct trs_info_inv_req_
{
	unsigned char opcode;				//0		0x60	<Opcode Value="0x60"/>
	unsigned char function;				//1		0xD0	<Opcode Value="0xD0"/>

	//2 BIT
	unsigned char opt_immediate       :1; // immediate=1 Delayed=0
	unsigned char opt_cancel          :1; // If set - F\O should ignore this request
	unsigned char opt_current_ticket  :1; // Will be set if the invoice is from the current ticket.
	unsigned char bTenderDependency   :1; //FSD123007
	unsigned char bInvoicePrinting	  :1; //TD#435542ErrorMsg
	unsigned char bCreditAllowedInv	  :1; //FSD#442000
	unsigned char nu                  :2; // 

	unsigned char inv_type;          //3  NUM  1-Belgium VAT
	//        2-Phone number
	//        3-Foreign VAT  
	//		  4 - Loyalty number FSD#357330

	unsigned char invnum[10]; 		   //4  BCD	 Belgium VAT/Phone number/Foreign VAT 

	unsigned short ticket_no;        //14 NUM	  
	unsigned char  pos_no;	         //16 NUM

	unsigned char bdcOrgTicketDate[3];	//17	FSD#90612 Date (YYMMDD in BCD)


	unsigned char bcdTransactionNumber[11];		//20	FSD#365331
	unsigned char uchInvNumLen;					//31	FSD427277
	unsigned char bdcOrgTicketTime[2];			//32	FSD427277
	unsigned char filler[10];					//34	Future use


	struct   trans_tail_  tail;		//44	tail
};

//OEM 
struct trs_info_oem_sec_opt_in_
{
	unsigned char opcode;         //0x60	<Opcode Value="0x60"/>
    unsigned char function;       //0xD1	<Opcode Value="0xD1"/>

	unsigned char member_card_no[15];
	unsigned char alternate_id[10];
	unsigned char prev_alternate_id[10];
	short rc;
	unsigned char reserv[5];

    struct   trans_tail_  tail;
};


struct trs_info_oem_club_data_
{
	unsigned char opcode;				//0x60	<Opcode Value="0x60"/>
	unsigned char function;				//0xD3	<Opcode Value="0xD3"/>

	unsigned char card_no[20];			// card no in ascii null terminated
	long          lPromotionNumber;		
	unsigned char ucClubNumber;			
	long          lPoints;				// Points earned
	unsigned char ucOptInFlag;			// 0 - no change, 1 - opt-in, 2 - opt-out		
	long		  lRedeemed; 
	short		  lAward;
	unsigned char date[3];				//Enh #11720 - yymmdd
	unsigned char time[3];				//Enh #11720 - hhmmss
   
	struct   trans_tail_  tail;
};


// B/O transaction
struct trs_non_scanned_dept_
{
  unsigned char  		opcode; // 0x10	<Opcode Value="0x10"/>
  unsigned short   		dept;
  unsigned char  		option;
  unsigned char  		option1;
  unsigned char  		till_no;
  unsigned char  		product_code;
  long           		amount;

  unsigned char  		reserved[33];

  struct trans_tail_ tail;
};


struct trs_alert_
{
    unsigned char opcode;         //0x63	<Opcode Value="0x63" />
    
    unsigned short  subopcode;	  // 1		<Opcode Value="0x01" />
    unsigned char function;		  // 3	

    unsigned char disp_message     :1;
    unsigned char drvfile_popup    :1;
    unsigned char ignore_alert     :1;
    unsigned char use_org_pos_no   :1;
    unsigned char get_text_msg     :1;
    unsigned char opt_nu15         :1;
    unsigned char opt_nu16         :1;
    unsigned char opt_nu17         :1;  // 4

    unsigned char data[37];				// 5
    unsigned char org_pos_no;			// 42
    unsigned char org_pc_no;			// 43

    struct   trans_tail_  tail;			// 44
};

struct trs_alert_pos_unbalanced_general_
{
    unsigned char  opcode;        // 0
    unsigned short subopcode;	  // 1
    unsigned char  type;          // 3
	long lSalesAmount;			  // 4
	long lPromontionsAmount;      // 8
	long lTendersAmount;          // 12
	long lTaxAmount;	          // 16

	unsigned char filler[24];	  // 20

    struct   trans_tail_  tail;	  // 44
};

struct trs_alert_pos_unbalanced_apportionment_
{
    unsigned char opcode;         // 0
    unsigned short  subopcode;	  // 1
    unsigned char  type;          // 3
	long lPromontionsAmount;      // 4
	long lApportionmentAmount;    // 8

	unsigned char filler[32];	  // 12

    struct   trans_tail_  tail;	  // 44
};

//FSD27939.. KireetG
struct trs_alert_file_distribution_
{
    unsigned char	opcode;					//0x63	<Opcode Value="0x63" />
    
    unsigned short  subopcode;				// 1	// (230 / 231)
    unsigned char	function;				// 3	
	
	unsigned char	uchFileID;				// 4
	unsigned char	uchFileOperationType;	// 5

    unsigned char	data[36];				// 6
    unsigned char	org_pos_no;			// 42
    unsigned char	org_pc_no;			// 43

    struct   trans_tail_  tail;			// 44
};


//FSD27795	AlbertoA
struct trs_alert_FiscDateVsOSDate_
{
    unsigned char	opcode;					//0x63	<Opcode Value="0x63" />
    
    unsigned short  subopcode;				// 1	248 ALERT_FISCAL_DATE_DIFFER_POS_DATE	<Opcode Value="248" />
    unsigned char	function;				// 3	
	
	unsigned char	Dates[40];				// 4
	

    struct   trans_tail_  tail;			// 44
};

struct trs_alert_fiscal_problem_
{
    unsigned char opcode;         //0x63	<Opcode Value="0x63" />
    
    unsigned short  subopcode;		//102 ALERT_FISCAL_ERROR	<Opcode Value="102" />
    unsigned char function;

    unsigned char disp_message     :1;
    unsigned char drvfile_popup    :1;
    unsigned char ignore_alert     :1;
    unsigned char use_org_pos_no   :1;
    unsigned char get_text_msg     :1;
    unsigned char opt_nu15         :1;
    unsigned char opt_nu16         :1;
    unsigned char opt_nu17         :1;  // 4

	long	lErrorCode;					// 5
	long	lExtendedErrCode;			// 9			
	
    unsigned char data[29];				// 13
    unsigned char org_pos_no;			// 42
    unsigned char org_pc_no;			// 43

    struct   trans_tail_  tail;
};

struct trs_alert_trans_send_
{
    unsigned char opcode;         //0x63	<Opcode Value="0x63" />
    
    unsigned short  subopcode;		//166 ALERT_TRANS_MANAGER_STUCK	<Opcode Value="166" />
    unsigned char function;

    unsigned char disp_message     :1;
    unsigned char drvfile_popup    :1;
    unsigned char ignore_alert     :1;
    unsigned char use_org_pos_no   :1;
    unsigned char get_text_msg     :1;
    unsigned char opt_nu15         :1;
    unsigned char opt_nu16         :1;
    unsigned char opt_nu17         :1;  // 4

	long	ClnSendPointer;				// 5
	long	ClnWritePointer;			// 9			
	
    unsigned char data[29];				// 13
    unsigned char org_pos_no;			// 42
    unsigned char org_pc_no;			// 43

    struct   trans_tail_  tail;
};


//INDYME
struct trs_alert_indyme_
{
    unsigned char  opcode;         //0x63	<Opcode Value="0x63" />
    
    unsigned short subopcode;		 //		<Opcode Value="0x00-0x50"/>
    unsigned char  function;		

	unsigned char disp_message     :1;
    unsigned char drvfile_popup    :1;
    unsigned char ignore_alert     :1;
    unsigned char use_org_pos_no   :1;
    unsigned char get_text_msg     :1;
    unsigned char opt_nu15         :1;
    unsigned char opt_nu16         :1;
    unsigned char opt_nu17         :1;  // 4

    unsigned long  virtual_key; 
    unsigned short indyme_rtc;	 
    
    unsigned char  data[31];
    unsigned char  org_pos_no;
    unsigned char  org_pc_no;

    struct   trans_tail_  tail;
};

struct trs_alert_batch_
{
   unsigned char opcode;         //0x63	<Opcode Value="0x63" />
   
   unsigned short  subopcode;      // 90	<Opcode Value="90" />
   unsigned char function;	   	//  0

   unsigned char disp_message     :1;
   unsigned char drvfile_popup    :1;
   unsigned char ignore_alert     :1;
   unsigned char use_org_pos_no   :1;
   unsigned char get_text_msg     :1;
   unsigned char bPLURecord       :1;		//54743 - Batch acknowledge from POS
   unsigned char opt_nu16         :1;
   unsigned char opt_nu17         :1;  // 4

   unsigned char host_batch_number[6];
   unsigned long host_records;
   unsigned long accepted_records;

   unsigned short ushBatchType;				//54743 - Batch acknowledge from POS
   unsigned char data[21];
   unsigned char org_pos_no;
   unsigned char org_pc_no;

	struct   trans_tail_  tail;
};

struct trs_alert_board_msg_
{
   unsigned char opcode;         //0x63	<Opcode Value="0x63" />
   
   unsigned short  subopcode;      // 110	<Opcode Value="110" />
   unsigned char function;	   			//  3

   unsigned char disp_message     :1;
   unsigned char drvfile_popup    :1;
   unsigned char ignore_alert     :1;
   unsigned char use_org_pos_no   :1;
   unsigned char get_text_msg     :1;
   unsigned char bCashierType     :1;
   unsigned char bPOSType         :1;
   unsigned char opt_nu17         :1;	// 4

   unsigned char msg_number;			//5
   unsigned char cashier_answer;		//6	//0 - cancel  //FSD219364
											//1 - no
											//2 - yes
											//3 - timeout //FSD219364
   unsigned char msg_text[35];			//7 //first 35 bytes of text
   
   unsigned char org_pos_no;			//42
   unsigned char org_pc_no;				//43

   struct   trans_tail_  tail;
};

struct trs_file_refresh_
{
	unsigned char opcode;         //0x63 <Opcode Value="0x63" />

	unsigned short  subopcode;      // 89 ALERT_FILE_REFRESH	<Opcode Value="89" />
	unsigned char function;	   	// 3 0

    unsigned char disp_message     :1;
    unsigned char drvfile_popup    :1;
    unsigned char ignore_alert     :1;
    unsigned char use_org_pos_no   :1;
    unsigned char get_text_msg     :1;
    unsigned char zip_failed       :1; //FSD11944
    unsigned char unzip_failed     :1; //FSD11944
    unsigned char opt_nu17         :1;  // 4

	unsigned char qdx_file;	 //5 File number. 0 represent all files
	unsigned char status;	 //6 1-Start refresh checksum fails
   								 // 2-Start refresh TV problem
							// 3-Suspend load  user abort
							// 4-Resume  load  
   								 // 5-Start refresh force request
							// 6-Start refresh CFM request
							// 7-File refreshing completed
							// 8- pos menu QDX file refreshing fails //FSD11944

	unsigned long  number_of_records; //7  #10593
	unsigned short pos_checksum;      //11
	unsigned long  FO_number_of_records; //13  #10593
	unsigned short FO_checksum;       //17
   
	unsigned char data[23];  // 19

	unsigned char org_pos_no; //42
	unsigned char org_pc_no;  //43

	struct   trans_tail_  tail; //44
};

struct trs_alert_transact_err_ 
{
	unsigned char opcode;    // 0x63 <Opcode Value="0x63"/>

	unsigned short  subopcode; // ALERT_TRANSACTION_QDX_PROBLEM	116	<Opcode Value="116"/>
	unsigned char function;    // 3

    unsigned char disp_message     :1;
    unsigned char drvfile_popup    :1;
    unsigned char ignore_alert     :1;
    unsigned char use_org_pos_no   :1;
    unsigned char get_text_msg     :1;
    unsigned char opt_nu15         :1;
    unsigned char opt_nu16         :1;
    unsigned char opt_nu17         :1;  // 4

    unsigned short  trans_fifo_size;    // 5
    unsigned short  trans_first;		// 7
    unsigned long	trans_pointer;		// 9
    unsigned short  trans_count;		// 13
    unsigned short  future_trans_count; // 15
    unsigned short  trans_seq_no;		// 17

	unsigned char data[23];             // 19
	unsigned char org_pos_no;			// 42
	unsigned char org_pc_no;			// 43
   								  
	struct trans_tail_ tail;			// 44
};

struct trs_alert_post_version_ 
{
	unsigned char opcode;    // 0x63 <Opcode Value="0x63" />
	
	unsigned short  subopcode; // 80 - POST version	<Opcode Value="80" />
	unsigned char function;
	
	unsigned char disp_message     :1;
	unsigned char drvfile_popup    :1;
	unsigned char ignore_alert     :1;
	unsigned char use_org_pos_no   :1;
	unsigned char get_text_msg     :1;
	unsigned char opt_nu15         :1;
	unsigned char opt_nu16         :1;
	unsigned char opt_nu17         :1;	// 4
	
	unsigned char program_name[12];		//5
	unsigned char compile_date[3];		//17
	unsigned char compile_time[3];		//20
	unsigned char version[12];			//23
	
	unsigned char data[6];				//35
	unsigned char TaxSystemType;		//41 // CR #9351
	
	unsigned char org_pos_no;			//42
	unsigned char org_pc_no;				//43
	
	struct trans_tail_ tail;				//44
};

struct trs_alert_post_mail_  
{
   unsigned char  opcode;      // 0x63   <Opcode Value="0x63" />

   unsigned short subopcode;   // 113 - POST_MAIL	<Opcode Value="113" />
   unsigned char  function;	   //0

   short 		  FromAddr;
   char  		  MailMsgNum[4]; //BCD
   unsigned char  SendToAll;

   unsigned char  data[31];
   unsigned char  org_pos_no;
   unsigned char  org_pc_no;

   struct   trans_tail_  tail;
};

// Code Distribution
struct trs_alert_pkg_
{
   unsigned char opcode;   // 0x63		//0	<Opcode Value="0x63" />
   unsigned short subopcode;// 0xde     //1	<Opcode Value="0xDE" />
   unsigned char function;				//3

   unsigned char disp_message    :1;	//4
   unsigned char drvfile_popup   :1;
   unsigned char ignore_alert    :1;
   unsigned char use_org_pos_no  :1;
   unsigned char get_text_msg    :1;
   unsigned char manual_pkg      :1;
   unsigned char nu06            :1;
   unsigned char nu07            :1;

   unsigned char pkg_name[12];			//5
   unsigned char data[14];				//17
   unsigned char opener_result;			//31
   unsigned short prev_rel_a;			//32	
   unsigned short prev_rel_b;			//34
   unsigned short prev_rel_c;			//36
   unsigned short prev_rel_d;			//38
   unsigned short error;				//40
   unsigned char pos_no;				//42
   unsigned char pc_no;					//43

   struct   trans_tail_  tail;			//44
};

struct trs_ola_alert_ // 200102 use by CheckCrd.dll 
{
    unsigned char	opcode;         //0x63	<Opcode Value="0x63"/>
    
    unsigned short	subopcode;		//		<Opcode Value="0x51"/>
    unsigned char	function;

    unsigned char disp_message     :1;
    unsigned char drvfile_popup    :1;
    unsigned char ignore_alert     :1;
    unsigned char use_org_pos_no   :1;
    unsigned char get_text_msg     :1;
    unsigned char opt_nu15         :1;
    unsigned char opt_nu16         :1;
    unsigned char opt_nu17         :1;  // 4

	char			new_ola_provider1; // 0 - mean offline , 1- 10 mfs1 - lfs10
	char			old_ola_provider1; // 0 - mean offline , 1- 10 mfs1 - lfs10 170102

    unsigned char	data[35];
    unsigned char	org_pos_no;
    unsigned char	org_pc_no;

    struct   trans_tail_  tail;
};

//FSD31008 - AlaramSrv alerts txn, written only from
//ExtTrs32 and not from POS.
struct trs_alert_alarm_srv_         
{
 unsigned char  opcode;               //0 0x63
 unsigned short subopcode;            //1 800(0x320)
 unsigned char  function;             //3
    
 unsigned short category;             //4
 unsigned short sub_category;         //6
 unsigned short alarm_id;             //8
 unsigned short device_no;            //10
 
 unsigned char  nu[32];               //12         

 struct   trans_tail_  tail;          //44
};


struct trs_alert_auto_fuel_mngt_		//FSD30537
{
    unsigned char opcode;				// 0 - 0x63	<Opcode Value="0x63" />
    
    unsigned short  subopcode;			// 1 - 176 ALERT_AUTO_FUEL_MNGT	<Opcode Value="176" />
    unsigned char function;				// 3 - alert number

    unsigned char disp_message     :1;	// 4
    unsigned char drvfile_popup    :1;	// 4
    unsigned char ignore_alert     :1;	// 4
    unsigned char use_org_pos_no   :1;	// 4
    unsigned char get_text_msg     :1;	// 4
    unsigned char opt_nu15         :1;	// 4
    unsigned char opt_nu16         :1;	// 4
    unsigned char opt_nu17         :1;  // 4

	long	lBatchNo;					// 5
	long	lStoreId;					// 9			
    unsigned char uchPriceChangeType;	// 13
	
    unsigned char data[28];				// 14
    unsigned char org_pos_no;			// 42
    unsigned char org_pc_no;			// 43

    struct   trans_tail_  tail;
};

//FSD56626
struct trs_alert_CombinedUserSecurity_
{
    unsigned char	opcode;					//0x63	<Opcode Value="0x63" />
    unsigned short  subopcode;				// 1	
    unsigned char	function;				// 3	
	
	unsigned char disp_message		  :1;	// 4
    unsigned char drvfile_popup		  :1;	// 4
    unsigned char ignore_alert		  :1;	// 4
    unsigned char use_org_pos_no	  :1;	// 4
    unsigned char get_text_msg		  :1;	// 4
    unsigned char opt_nu15			  :1;	// 4
    unsigned char opt_nu16			  :1;	// 4
    unsigned char opt_nu17			  :1;   // 4
	
	unsigned short	ushCashierNo;			// 5
	unsigned short	ushPosNo;				// 7
	unsigned char	NU[35];					// 9
	

    struct   trans_tail_  tail;			// 44
};

struct trs_alert_scale_error_ // #144180
{
    unsigned char	opcode;					//0x63	<Opcode Value="0x63" />
    unsigned short  subopcode;				// 1	
    unsigned char	function;				// 3	
	
	unsigned char disp_message		  :1;	// 4
    unsigned char drvfile_popup		  :1;	// 4
    unsigned char ignore_alert		  :1;	// 4
    unsigned char use_org_pos_no	  :1;	// 4
    unsigned char get_text_msg		  :1;	// 4
    unsigned char opt_nu15			  :1;	// 4
    unsigned char opt_nu16			  :1;	// 4
    unsigned char opt_nu17			  :1;   // 4
	
	short shScaleError;						// 5
	unsigned char NU[35];					// 7
    unsigned char org_pos_no;				// 42
    unsigned char org_pc_no;				// 43
	
    struct   trans_tail_  tail;				// 44
};

struct trs_alert_fatal_error_ // #144180
{
    unsigned char	opcode;					//0x63	<Opcode Value="0x63" />
    unsigned short  subopcode;				// 1	
    unsigned char	function;				// 3	
	
	unsigned char disp_message		  :1;	// 4
    unsigned char drvfile_popup		  :1;	// 4
    unsigned char ignore_alert		  :1;	// 4
    unsigned char use_org_pos_no	  :1;	// 4
    unsigned char get_text_msg		  :1;	// 4
    unsigned char opt_nu15			  :1;	// 4
    unsigned char opt_nu16			  :1;	// 4
    unsigned char opt_nu17			  :1;   // 4
	
	short shFatalError;						// 5
	unsigned char NU[35];					// 7
    unsigned char org_pos_no;				// 42
    unsigned char org_pc_no;				// 43
	
    struct   trans_tail_  tail;				// 44
};

struct trs_alert_printer_error_ // #144180
{
    unsigned char	opcode;					//0x63	<Opcode Value="0x63" />
    unsigned short  subopcode;				// 1	
    unsigned char	function;				// 3	
	
	unsigned char disp_message		  :1;	// 4
    unsigned char drvfile_popup		  :1;	// 4
    unsigned char ignore_alert		  :1;	// 4
    unsigned char use_org_pos_no	  :1;	// 4
    unsigned char get_text_msg		  :1;	// 4
    unsigned char opt_nu15			  :1;	// 4
    unsigned char opt_nu16			  :1;	// 4
    unsigned char opt_nu17			  :1;   // 4
	
	short shPrinterError;					// 5

	unsigned char NU[35];					// 7
    unsigned char org_pos_no;				// 42
    unsigned char org_pc_no;				// 43
	
    struct   trans_tail_  tail;				// 44
};

struct trs_alert_cust_disp_error_ // #144180
{
    unsigned char	opcode;					//0x63	<Opcode Value="0x63" />
    unsigned short  subopcode;				// 1	
    unsigned char	function;				// 3	0 - INIT
											// 		1 - DISPLAY
	
	unsigned char disp_message		  :1;	// 4
    unsigned char drvfile_popup		  :1;	// 4
    unsigned char ignore_alert		  :1;	// 4
    unsigned char use_org_pos_no	  :1;	// 4
    unsigned char get_text_msg		  :1;	// 4
    unsigned char opt_nu15			  :1;	// 4
    unsigned char opt_nu16			  :1;	// 4
    unsigned char opt_nu17			  :1;   // 4
	
	short shCustDispError;					// 5

	unsigned char NU[35];					// 7
    unsigned char org_pos_no;				// 42
    unsigned char org_pc_no;				// 43
	
    struct   trans_tail_  tail;				// 44
};

struct trs_alert_failed_to_copy_receipt_pdf_file_
{
	unsigned char	opcode;		//0		 TRANS_ALERTS
	unsigned short	subopcode;	//1		 ALERT_FAILED_TO_COPY_RECEIPT_PDF_FILE

	char	szPDFName[34];		//3
	
	unsigned char NU[7];			//37
	
	struct   trans_tail_  tail;				// 44
};

struct trs_prom_cross_
{
    unsigned char opcode;         //0x60    //0	<Opcode Value="0x60" />
    unsigned char function;       //0x40    //1	<Opcode Value="0x40" />

    unsigned char prom_plu        :1;       //2
    unsigned char prom_dep        :1;
    unsigned char prom_sub        :1;
    unsigned char prom_mmg        :1;
    unsigned char prom_manfacture :1;
    unsigned char prom_group      :1;
    unsigned char opt_long_prom   :1; //PROM_CHNG
    unsigned char prom_internal_id :1;

    unsigned short  promotion_no;           //3
    unsigned char bucket_no;                //5
    unsigned char promotion_type;           //6
    
    unsigned short  dept;                   //7
    unsigned char code[7];                  //9
    
    unsigned char reward_type;              //16
    long          long_promotion_no;	//PROM_CHNG    //17
	long          apportionment_amount; //FS18285      //21

	unsigned short ushCrossType;                       //25
	union                                              //27
	{
		unsigned long ulSegment;
    
		unsigned char reserved[10];
	}Entity;
	unsigned char reserved[7];                        //37


    struct   trans_tail_  tail;                       //44
};
struct trs_info_deposit_                 //FS18341
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60"/>
    unsigned char function;       //0x41	<Opcode Value="0x41"/>

    unsigned char bRequest        :1; //2
    unsigned char bIgnoreRcvr     :1; //2
    unsigned char nu        :6;
    
    unsigned short  ushTender;        //3
    unsigned long ulAmount;           //5
    
    unsigned char reserved[35];      //9

    struct   trans_tail_  tail;
};


// Bashas
struct trs_trading_stamps_
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60" />
    unsigned char function;       //0x42	<Opcode Value="0x42" />

    long qualify_trading_stamps;
    short  trading_stamps_no;
    
    unsigned char reserved[36];

    struct   trans_tail_  tail;
};


// progressive    
struct trs_member_freq_shopper_
{
    unsigned char opcode;	  	//0x60	<Opcode Value="0x60" />
    unsigned char function;	//0x44		<Opcode Value="0x44" />

    unsigned char code[7];

    unsigned char nu00	   :1;
    unsigned char nu01	   :1;
    unsigned char nu02	   :1;
    unsigned char nu03	   :1;
    unsigned char nu04	   :1;
    unsigned char nu05	   :1;
    unsigned char nu06	   :1;
    unsigned char nu07	   :1;

    long	    old_price;
    long	    new_price;
    long		 qty;
    long	    save_amount;

    unsigned char reserved[18];
    struct   trans_tail_  tail;
};

struct trs_recall_trans_
{
	unsigned char opcode;	  	//0x60	<Opcode Value="0x60" />
	unsigned char function;		//0x46	<Opcode Value="0x46" />

	unsigned short recall_ticket_no;   // offset 2
	unsigned char  recall_pos_no;	   // offset 4
	unsigned short recall_cashier;	   // offset 5

	unsigned char start        :1;	   // offset 7
	unsigned char offline_mode :1;	   //   till offline
	unsigned char manual_entry :1;	   //   manual entry values
	unsigned char inv_not_fond :1;	   //   invoice not found
	unsigned char recall_saved_bakery	:1; // FSD9033
	unsigned char recall_drive_off		:1; // FSD9033
	unsigned char quick_recall_flag		:1; //FSD16261	
	unsigned char extended_recall		:1; // 9849SL - Miltiple Recalls Publix

	unsigned short  branch;			   // offset 8 
	unsigned short  checkout_bank;	   // offset 10

	long          inv_amount;          // offset 12 ( Invoice amount )
	unsigned char invoice_no[8];       // offset 16 ( Invoice number )
	unsigned char invoice_dt[3];	   // offset 24 ( Invoice date or used for date of saved transaction )

    unsigned short seq_no;             // offset 27
    unsigned char  time[3];            // offset 29

	unsigned char uchSavedTillType;    // offset 32 // FSD9033
	unsigned char uchSavedTillProfile; // offset 33 // FSD9033
	unsigned char uchRecallMode;       // offset 34 // FSD9033

	unsigned char saved_pos_no; // offset 35 // FSD9849
	unsigned short saved_cashier; // offset 36 //FSD9849

	unsigned long ulLongStoreNumber;   // offset 38

	unsigned char bEmbManualSave     :1;	   // offset 42
	unsigned char NU			     :7;	   // offset 42

	unsigned char reserved[1];         // offset 43

	struct   trans_tail_  tail;        // offset 44
};

#ifdef PRJ_ROW
struct trs_eft_settle_
{
    unsigned char opcode;         //0x60	<Opcode Value="0x"60/>
    unsigned char function;       //0x47	<Opcode Value="0x47"/>
    unsigned char sub_function;   //0-Header 1/2-Data	<Opcode Value="0x00-0x02"/>


    unsigned char cut_over  :1;
    unsigned char in_window :1;
    unsigned char nu02      :1;
    unsigned char nu03      :1;
    unsigned char nu04      :1;
    unsigned char nu05      :1;
    unsigned char nu06      :1;
    unsigned char failed    :1;



	 union
    {
    	struct 
      {
    		unsigned char no;
    		unsigned short  count;
    		unsigned long amount;
      }ttl[5];
      
      struct 
      {
	      unsigned char terminal_ID[8];
	      unsigned char merchant_ID[15];
	      unsigned char date[4]; //ddmm
	      unsigned char time[6]; //hhmmss
	      unsigned char nu[2];
      }hdr;
    }x;

    unsigned char reserved[5];

    struct   trans_tail_  tail;
};
#else
struct trs_eft_settle_
{
    unsigned char	opcode;				//0x60	<Opcode Value="0x60"/>
    unsigned char	function;			//0x47	<Opcode Value="0x47"/>
	unsigned char	sub_func;			//2		<Opcode Value="0x03-0xFF"/>
	

	short			shTenderID;			//3
	unsigned char	chCardType;			//5
	unsigned char	chSettlementType;	//6
	unsigned char	chAccountType;		//7
	long			lAmount;			//8
	unsigned short	ushTrxCount;		//12
   	unsigned char	bUpdatePrvDay   :1;	//14
   	unsigned char	bUpdateSameDay  :1;	//14
   	unsigned char	bNU             :6;	//14


	unsigned char	sBIN[2];			//15
	unsigned char	sBCDSettlementDate[3]; // 17 //DDMMYY // FSD46688 Added PAP Settlement Date
	unsigned char	reserved[24];		//20

    struct   trans_tail_  tail;
};
#endif

struct trs_reorg_print_
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60" />
    unsigned char function;       //0x4C	<Opcode Value="0x4C" />

    unsigned char start       :1;
    unsigned char end         :1;
    unsigned char nu02        :1;
    unsigned char nu03        :1;
    unsigned char nu04        :1;
    unsigned char nu05        :1;
    unsigned char nu06        :1;
    unsigned char nu07        :1;

    unsigned char reserved[41];

    struct   trans_tail_  tail;
};

// Frys freq shop
struct trs_adv_freq_shop_
{
    unsigned char opcode;	  	//0x60	<Opcode Value="0x60" />
    unsigned char function;		//0x50	<Opcode Value="0x50" />

    unsigned char code[7];

    unsigned char exceed_limit 		:1;
    unsigned char opt_not_net_fs	:1; 
    unsigned char nu02	       		:1;
    unsigned char nu03	       		:1;
    unsigned char nu04	       		:1;
    unsigned char nu05	       		:1;
    unsigned char nu06	       		:1;
    unsigned char nu07	       		:1;

    long	    old_price;
    long	    new_price;
    long		 qty;
    long	    save_amount;

    unsigned char reserved[18];
    struct   trans_tail_  tail;
};

// Frys freq shop
struct trs_freq_shop_card_
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60" />
    unsigned char function;       //0x51	<Opcode Value="0x51" />

    unsigned char code[14];

    unsigned char reserved[28];

    struct   trans_tail_  tail;
};
struct trs_zip_printout_
{
    unsigned char opcode;	  //0x68	<Opcode Value="0x68" />

	 unsigned char bites;
    
    unsigned char data[42];

    struct   trans_tail_  tail;
};

struct trs_zip_printout_wide_
{
	unsigned char opcode;	//0 0x69	<Opcode Value="0x69" />

	unsigned char bytes;	//1
    unsigned char data[42];	//2

    struct   trans_tail_  tail;	//44
};

struct trs_zipped_text_
{
    unsigned char opcode;         //0x70	<Opcode Value="0x70"/>
    unsigned char function;       //0x12	<Opcode Value="0x12"/>

	unsigned char	DataType;			// 2
	unsigned char	FilledBytes;		// 3

	unsigned char	CompressedText[38]; // 4

	unsigned char	nu[2];				// 42

	struct   trans_tail_  tail;	// 44
};

//#134117 - 40 Char to be reflecated in EJ
struct trs_zipped_wide_text_
{
    unsigned char opcode;         //0	<Opcode Value="0x80"/>
    unsigned char function;       //1	<Opcode Value="0x26"/>
	
	unsigned char	DataType;			// 2
	unsigned char	FilledBytes;		// 3
	
	unsigned char	CompressedText[38]; // 4
	
	unsigned char	nu[2];				// 42
	
	struct   trans_tail_  tail;	// 44
};

//RDS13
struct trs_freq_shop_saving_
{
	unsigned char opcode;         	//0x60	<Opcode Value="0x60" />
	unsigned char function;       	//0x58	<Opcode Value="0x58" />

	unsigned char card_no[20];			// card no in ascii null terminated
   long			  saving_total;		// freq shopper savings
   
	unsigned char reserved[18];

	struct   trans_tail_  tail;
};

struct trs_savings_plus_
{
	unsigned char opcode;         	//0x60	<Opcode Value="0x60" />
	unsigned char function;       	//0x59	<Opcode Value="0x59" />

	unsigned char voided;	 
   
	unsigned char reserved[41];

	struct   trans_tail_  tail;
};

//SmartCard
struct trs_s_card_icc_
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60" />
	unsigned char function;    //0x5A	<Opcode Value="0x5A" />

	unsigned char AID[16];					//2  BCD
	unsigned char AIP[2];					//18 BCD
	unsigned char ATC[2];					//20 BCD
	unsigned char app_usage_control[2];		//22 BCD
	unsigned char app_version_no[2];		//24 BCD
	unsigned char issuer_codes_denial[5];	//26 Use By Tesco Only
	unsigned char issuer_codes_online[5];	//31 Use By Tesco Only
	unsigned char issuer_codes_default[5];	//36 Use By Tesco Only
	unsigned char conf_not_req;				//41 Use By Tesco Only
	
	unsigned char stPOSEntryMode[2];		//42 Not BCD 2 bytes pan entry mode
	// byte 1 entry mode 1
	// byte 2 entry mode 2
	struct   trans_tail_  tail;				//44
};

//SmartCard
struct trs_s_card_till_	 
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60" />
	unsigned char function;    //0x5B	<Opcode Value="0x5B" />

	unsigned char cryptogram_type;				//2 BCD
	unsigned char currency_code[2];				//3 BCD
	unsigned char country_code[2];				//5 BCD
	unsigned char unpredictable_no[4];			//7 BCD
	unsigned char TVR[5];						//11 BCD
	unsigned char cardholder_verification[3];	//16 BCD
	unsigned char TSI[2];						//19 BCD
	unsigned char EMV_Terminal_Type;			//21 BCD
	unsigned char terminal_capabilities[3];		//22 BCD
	unsigned char transaction_cryptogram[8];	//25 BCD
	unsigned char cryptogram_info_data;			//33 BCD

	unsigned char reason_ola[2];				//34 IR 71
	unsigned char ola_date[3];					//36 DDMMYY
	unsigned char ola_time[2];					//39 HH:MM
	short shEmvAppIdLen;						//41 AID length. the AID from "605A" length - PCIDSS	
	
	unsigned char reserved[1];					//43

	struct   trans_tail_  tail;					//44
};

//SmartCard
struct trs_s_card_issuer_
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60" />
	unsigned char function;    //0x5C	<Opcode Value="0x5C" />

	unsigned char issuer_app_data[32];			//2 BCD
	unsigned char uchIssuerAppDataLength;		//34 The actual length of unpaced issuer_app_data, from 0 to 64.

	unsigned char terminal_IFD[4];				//35 BCD Terminal Interface Device Serial Number.

	long app_sequence_no;						//39 Application PAN Sequence Number (ICC tag '5F34').

	unsigned char app_sequence_no_used		:1;	//43
	unsigned char reserved					:7;

	struct   trans_tail_  tail;					//44
};

//SmartCard
struct trs_s_card_cvm_list_
{
	unsigned char opcode;		//0x60	<Opcode Value="0x60" />
	unsigned char function;		//0x9A	<Opcode Value="0x9A" />
	unsigned char sub_func;		//2		1-inf_header 2,3,4,5,6-inf1

	union
	{
		struct
		{
			short shCVMListLength;				//3 The length of the hexadecimal string the cvm list was made(BCD) from, upto 512 chars.
			unsigned char cvm_list_data[39];	//5 The first (39 * 2 = 78) chars ( sub_func = 1 -> chars 0<->77 )

		} inf_header;

		struct
		{
			unsigned char cvm_list_data[41];	//3 ( sub_func = 2 -> chars 78<->159 )( sub_func = 3 -> chars 160<->241 )( sub_func = 4 -> chars 242<->323 )( sub_func = 5 -> chars 324<->405 )( sub_func = 6 -> chars 406<->487 )( sub_func = 7 -> chars 488<->569 )

		} inf1;

	} info;

	struct   trans_tail_  tail;					//44
};

//SmartCard
struct trs_s_card_script_results_
{
	unsigned char opcode;		//0x60	<Opcode Value="0x60" />
	unsigned char function;		//0x9B	<Opcode Value="0x9B" />
	unsigned char sub_func;		//2		1-inf_header 2,3,4-inf1

	union
	{
		struct
		{
			short shScriptResultsLength;			//3 The length of the hexadecimal string the script results was made(BCD) from, upto 250 chars.
			unsigned char script_results_data[39];	//5 The first (39 * 2 = 78) chars ( sub_func = 1 -> chars 0<->77 )

		} inf_header;

		struct
		{
			unsigned char script_results_data[41];	//3 ( sub_func = 2 -> chars 78<->159 )( sub_func = 3 -> chars 160<->241 )( sub_func = 4 -> chars 242<->323 )

		} inf1;

	} info;

	struct   trans_tail_  tail;					//44
};

//SmartCard
struct trs_s_card_icc_ext_
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60" />
	unsigned char function;    //0x9C	<Opcode Value="0x9C" />

	unsigned char sApplicationLabel[32];		//2
	unsigned char uchApplicationLabelLength;	//34

	unsigned char reserved[9];					//35

	struct   trans_tail_  tail;					//44
};

// Finland
struct trs_sales_on_account_
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60" />
    unsigned char function;       //0x5D	<Opcode Value="0x5D" />

    unsigned char cp_name[16];
    unsigned char cp_account_num[12];
    unsigned char cp_related_num[10];	

	unsigned char reserved[4];

    struct   trans_tail_  tail;
};

struct trs_customer_survey_
{													
    unsigned char  opcode;           //0x60	<Opcode Value="0x60" />
    unsigned char  function;         //0x5E	<Opcode Value="0x5E" />
													
    unsigned short cashier_no;						//2
    unsigned char  checkout_bank; 					//4		0-99
    long           question_no;						//5
    
    unsigned char  end_ticket      :1;				//9
    unsigned char  start_ticket    :1;				//9
	unsigned char  yesno_type      :1;				//9
	unsigned char  numeric_type    :1;				//9
    unsigned char  yesno_answer    :1;				//9		0 - No, 1 - Yes
	unsigned char  zip_type        :1;				//9		HF #9031
	unsigned char  phone_type      :1;				//9		HF #9031
	unsigned char  by_function     :1;				//9		HF #9031 - KW

	unsigned long  numeric_answer;					//10
	unsigned char  zip_code[5];						//14	HF #9031
	unsigned char  phone_number[10];				//19	HF #9031
     
	unsigned short	ushSurveyLists;					//29
	unsigned short	ushSurveyListItem;				//31

	unsigned char bCustIgnoredSurvey		:1;		//33	FSD16206
	unsigned char bInformOnlyType			:1;		//33    FSD31359
	unsigned char bInformOnlyAnswer			:1;		//33    FSD31359
	unsigned char bBySubTotal				:1;		//33	FSD51799
	unsigned char bFlightNumberAnswer		:1;		//33	FSD432409
	unsigned char nuBit						:3;		//33

	unsigned char sRecordId[5];	                    //34	FSD16129 Record id (Zip Code Id)
    unsigned char reserved[5];						//39		

    struct   trans_tail_  tail;						//44
};

// TD#64966
struct trs_customer_survey_ext_
{													
    unsigned char  opcode;              // 0 0x70  TRANS_INFO2
    unsigned char  function;            // 1 0x80  TRANS_INFO2_CUST_SRV_QUESTION_EXT
				
	union 
	{
		/* zipcode data */
		struct 
		{
			unsigned char uchValue[10]; // 2
			unsigned char uscNU[10];	// 12
		} zipcode;
		
		/* phone number data */
		struct 
		{
			unsigned char uchValue[20]; // 2
		} phone;

		/* FlightNumber data */ //FSD444697
		struct
		{
		     unsigned char uchFlightNumberValue[8];	//2
			 unsigned char ucNU[12];				//10
		} flightNumber;
	} data;

    unsigned char bPhoneNumber    :1;	// 22
	unsigned char bZipcode        :1;	// 22
	unsigned char bFlightNumber   :1;	// 22
	unsigned char bNU			  :5;   // 22

	short	shFlightSegmentDiscount;		//23

    unsigned char NU[19];			    // 25

    struct   trans_tail_  tail;		    // 44
};

struct trs_community_partner_
{
	unsigned char opcode;           //0x60	<Opcode Value="0x60" />
	unsigned char function;         //0x65	<Opcode Value="0x65" />

	unsigned char final     :1;
	unsigned char voided    :1;
	unsigned char nu02      :1;
	unsigned char nu03      :1;
	unsigned char nu04      :1;
	unsigned char nu05      :1;
	unsigned char MCR_used  :1;
	unsigned char scanned   :1;

	unsigned char card_no[20];
	long		  amount;

	unsigned char reserved[17];
   
	struct   trans_tail_  tail;	
};

struct trs_bonus_buy_
{
	unsigned char opcode;           //0x60	<Opcode Value="0x60" />
	unsigned char function;         //0x68	<Opcode Value="0x68" />

	unsigned char nu00			:1;  //2
	unsigned char nu01			:1;
	unsigned char nu02			:1;
	unsigned char nu03			:1;
	unsigned char OptReturnTrans		:1; //FSD10576
	unsigned char OptReturnItem			:1; //FSD10576
	unsigned char cancel_item   :1;
	unsigned char subtract_item :1;

	unsigned char plu_code[7];       //3
	
	unsigned char type;              //10
	unsigned char valid_date[3];     //11
	
	         long BB_value;          //14
	         long sale_value;        //18
	         long savings;           //22
	
	unsigned char reserved[18];      //26 
   
	struct   trans_tail_  tail;      //44
};

struct trs_ej_info_bad_account_
{
	unsigned char opcode;         //0x60	<Opcode Value="0x60" />
	unsigned char function;       //0xA0	<Opcode Value="0xA0" />

	unsigned char account_no[10]; //(BCD 19)
    unsigned char account_length; 
    unsigned char crng_no;

	unsigned char MCR_used : 1;   
	unsigned char nu01     : 1;
	unsigned char nu02     : 1;
	unsigned char nu03     : 1;
	unsigned char nu04     : 1;
	unsigned char nu05     : 1;
	unsigned char nu06     : 1;
	unsigned char nu07     : 1;
	
	unsigned char reserved[29];

	struct        trans_tail_  tail;
};

struct trs_ej_info_price_inquery_
{
	unsigned char opcode;             //0x60	<Opcode Value="0x60" />
	unsigned char function;           //0xA1	<Opcode Value="0xA1" />
	
    unsigned char plu_code[7];        

    long          inquery_amount;     //total inquery
    long          prom_amount;        //total promotion             
    long          disc_amount;        //total discount

    long          plu_price;          
    long          org_price;          
    long          count;              
    long          dec_count;          
    unsigned char mult_sell_unit;     
    long          weight;             

    unsigned char execute_inquery :1; 
    unsigned char store_coupon    :1; 
    unsigned char vendor_coupon   :1; 
    unsigned char other_coupon    :1; 
    unsigned char WIC_item        :1; 
    unsigned char nu05            :1; 
    unsigned char nu06            :1; 
    unsigned char nu07            :1; 
	
	unsigned char reserverd;      

    struct trans_tail_  tail;
};

struct trs_ej_info_control_check_
{
	unsigned char  opcode;            //0x60	<Opcode Value="0x60" />
	unsigned char  function;          //0xA2	<Opcode Value="0xA2" />
 
	unsigned short CC_no;             
	
	unsigned char  accepted       :1; 
	unsigned char  nu01           :1;  
	unsigned char  nu02           :1;  
	unsigned char  nu03           :1;  
	unsigned char  nu04           :1;  
	unsigned char  nu05           :1;  
	unsigned char  nu06           :1;  
	unsigned char  nu07           :1;  

    unsigned char  ask_yes_no     :1; 
    unsigned char  manager_key    :1; 
    unsigned char  stop_activity  :1;  
    unsigned char  supervisor_key :1;
    unsigned char  warning_only   :1;
    unsigned char  valid_record   :1;
    unsigned char  delayed_auth   :1; 
    unsigned char  value_at_text  :1;
    
	unsigned char  privilege;         
	unsigned short cashier_no;         
    unsigned char  templates[2];        

	unsigned char  pos_status;        
	unsigned char  t_log_reporting_level;	// Publix reporting level #SL1671
	
	int				reason; //see CC_REASON
    unsigned char reserved[27]; 
	
	struct         trans_tail_  tail;
};

struct trs_ej_info_age_id_
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60" />
	unsigned char function;    //0xA3	<Opcode Value="0xA3" />
	
	unsigned char age;         //current age
    unsigned char date[3];     //birthday date

	unsigned char bypass   :1; //bypass age
 	unsigned char check    :1; //check age
	unsigned char accepted :1; //(Bypass Or Check) was accepted ( Yes - 1 , No - 0 ) 
	unsigned char no_sale  :1; //FSD16470
	unsigned char bCashierDeclined   :1;	//FSD42826 - Cashier Age Validation - 0 when is customer age tran , 1 when it's cashier age trans
	unsigned char bWasCancelled	     :1;	//FSD42826 - Cashier Age Validation 
	unsigned char bVoidItemAtEndOfTicket     :1; //FSD42826 - Cashier Age Validation 
	unsigned char bCashierDateOfBirthUpdate     :1; //FSD90762 - Cashier Age Validation 

    unsigned char plu_code[7]; //FSD16470
	short dep_nu;			   //FSD16470
	
	short shSupervisorID	;	//FSD42826 - Cashier Age Validation 
	unsigned char ushDeclinationReasonCode; //FSD102391
	unsigned char uchAgeRequired; //SPAR_SCOT-FSD415354  //19
    unsigned char reserved[24];                          //20
	struct   trans_tail_  tail;
};


struct trs_item_on_sale_
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60" />
	unsigned char function;    //0xA4	<Opcode Value="0xA4" />
	
   unsigned char code[7]; 

   unsigned char opt_qty_is_weight			:1;
   unsigned char opt_qty_is_decimal_qty	:1;
   unsigned char opt_qty_is_fuel_gallons	:1;	// PosPump. TESCO field name is "opt_qty_is_ltr"
   unsigned char opt_nu							:5;

	unsigned long org_price;    
   unsigned char org_qty;      
	unsigned long on_sale_price;    
   unsigned char on_sale_qty;      
			   long amount;    
			   long qty;      

   unsigned char reserved[16]; 
   
	struct   trans_tail_  tail;
};

    
//MicroTrax
struct trs_balance_inquiry_
{
	unsigned char opcode;           //0x60	<Opcode Value="0x60" />
	unsigned char function;         //0x6B	<Opcode Value="0x6B" />

	long EBT_CASH_balance;	
	long EBT_FOODSTAMPS_balance;	
    unsigned char auth_no[9];
	unsigned char reference_no[11]; //Eft refference no
   
	unsigned char ebt_cash_balance           :1;	
	unsigned char ebt_foodstamps_balance     :1;	
    unsigned char enhanced_MPR_voucher_print :1;
	unsigned char nu4                        :1;
	unsigned char nu5                        :1;
	unsigned char nu6                        :1;
	unsigned char nu7                        :1;
	unsigned char nu8                        :1;
	
	unsigned char reserved[13];
   
	struct   trans_tail_  tail;
};


struct trs_saved_ticket_
{
	unsigned char opcode;           //0x60			//0	<Opcode Value="0x60" />
	unsigned char function;         //0x78			//1	<Opcode Value="0x78" />

   	unsigned short ticket_no;						//2

	unsigned char save_at_sale_mode          :1;	//4
	unsigned char save_at_tender_mode        :1;	
	unsigned char save_at_training_mode      :1;	
	unsigned char saved_for_payment          :1; // invoice saved for payment
	unsigned char saved_for_split            :1; // split invoice saved for payment
	unsigned char opt_PackTransaction        :1; // Pack transaction for bakary tills.
	unsigned char TaxVoucherRequested        :1;
	unsigned char save_at_StockCount         :1; //FSD14517
	
	long  		   ticket_amount;					//5
	long  		   media_total;						//9
	short 		   ticket_items;					//13
	unsigned short supervisor_no;					//15
	unsigned char invoice_no[8];					//17      Invoice number
	unsigned char invoice_dt[3];					//25
	unsigned char  recalled_pos_no;					//28 Bug #4395 - recalled pos no, if this ticket is recalled ticket - Gonen
	unsigned short recalled_ticket_no;				//29 Bug #4395 - recalled ticket no, if this ticket is recalled ticket - Gonen

	unsigned char quick_save_flag			:1;		//31 //FSD16261
	unsigned char bStandbyTicket			:1;		//31   FSD45272
	unsigned char bUseInvNumverAsRefNumber  :1;     //31 FSD62787 
	unsigned char voidedOnlinePurchaseItems	:1;		//31	OmerR FSD157230
	unsigned char NU						:4;     //31
	
	//FSD52741 Ticket Saving Enhancements For Drive-Offs
	unsigned char drive_off_start_time[3];			//32	Start time
	unsigned char drive_off_end_time[3];			//35	Start time	
	unsigned long security_number;					//38  #63998

	unsigned char reason_type;						//42	0 = Standard,1 = Drive Off, 2 = Outstanding Fuel Payment
	unsigned char reserved[1];						//43
   
	struct   trans_tail_  tail;						//44
};


//EFT_FIN: Finland
struct trs_eft_req1_
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60" />
	unsigned char function;    //0x80	<Opcode Value="0x80" />
	
	unsigned char amount[12];        //amount: '1000....' = 10.00
    unsigned char type_trans[4];     //type of transaction(00) + type of tender(05) = "0005"
	unsigned char account[19];		 //account: '4920567890123455...'
	unsigned char auth_code[6];

    unsigned char reserved[1]; 
   
	struct   trans_tail_  tail;
};


//EFT_FIN: Finland
struct trs_eft_req2_
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60" />
	unsigned char function;    //0x81	<Opcode Value="0x81" />
	
	unsigned char exp_date[4];
    unsigned char mess_type[4];     //message type:
									//0100 = authorisation request
									//0101 = repetition of request
									//0400 = cancellation of authorisation
									//0401 = repetition of cancellation
	unsigned char orig_resp_code[2]; //original response code (used in cancelations)

	unsigned char failed                 :1; //request failed/not
 	unsigned char flg_cancel_subtract    :1; //cancel/subtract = TRUE
	unsigned char nu02     :1; 
	unsigned char nu03     :1; 
	unsigned char nu04     :1; 
	unsigned char nu05     :1; 
	unsigned char nu06     :1; 
	unsigned char nu07     :1; 

	unsigned char account[10]; //cr#2888
	unsigned char account_len;
    unsigned char reserved[20]; 

   
	struct   trans_tail_  tail;
};


//EFT_FIN: Finland
struct trs_eft_resp1_
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60" />
	unsigned char function;    //0x82	<Opcode Value="0x82" />
	
	unsigned char amount[12];        //amount: '000000001000' = 10.00
    unsigned char type_trans[4];     //type of transaction + type of tender = "0005"
	unsigned char account[19];		 //account: '4920567890123455...'
	unsigned char auth_code[6];

    unsigned char reserved[1]; 

	struct   trans_tail_  tail;
};

//EFT_FIN: Finland
struct trs_eft_resp2_
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60" />
	unsigned char function;    //0x83	<Opcode Value="0x83" />
	
    unsigned char mess_type[4];     //message type:
									//0110 = response to authorisation
									//0410 = response to cancellation
	unsigned char resp_code[2];     //response code
	unsigned char messg_ID[6];      //message ID from SOK
	unsigned char timestamp_resp[10]; //MMDDhhmmss
	unsigned char auth_code_resp[6];  //Authorisation code

	unsigned char failed                 :1; //request failed/not
 	unsigned char flg_cancel_subtract    :1; //cancel/subtract = TRUE
	unsigned char nu02     :1; 
	unsigned char nu03     :1; 
	unsigned char nu04     :1; 
	unsigned char nu05     :1; 
	unsigned char nu06     :1; 
	unsigned char nu07     :1; 

	unsigned short tender_no; //EFT_FIN_1
    unsigned char reserved[11]; 
   
	struct   trans_tail_  tail;
};

//PROM_CPN_REQ
struct promotion_coupon_required_
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60" />
	unsigned char function;    //0x87	<Opcode Value="0x87" />

	unsigned char promotion_no[5];				//2 bcd //PROM_CHNG (was 2)
	unsigned char no_coupon_required[7];		//7	BCD

	unsigned char delayed_promotion			:1;	//14
	unsigned char coupon_required_return	:1;	//14 PROM_CPN_REQ1
	unsigned char coupon_physical_scan		:1;	//14 coupon was physically scanned by cashier
	unsigned char bExtTrs			        :1;	//14 FSD18888
	unsigned char bExternalValidationLPE	:1;	//14 FSD16857
	unsigned char opt_was_canceled	        :1;	//14 TD#27963
	unsigned char opt_cancel 		        :1;	//14 TD#27963
	unsigned char opt_long_coupon_number	:1;	//14 FSD26780 - if the coupon_required length longer than 7 
												//		the coupon_required will be writen in the following 0x70,0x91 trs.

	unsigned char attached_plu[7];				// 15	 for coins PLU attached   
	short         count;						// 22

	unsigned char org_coupon_code[7];           // 24 BCD
	unsigned char org_coupon_code_len;          // 31

	unsigned char sSupData[8];                  // 32 Suplement data to the promotion coupon

	short         shCouponCodeLength;			// 40 #35566

	unsigned char bDigitalCoupon			:1;	// 42	FSD450172
	unsigned char bCouponCanceled			:1;	// 42	FSD450172
	unsigned char bNu						:6;	// 42

	unsigned char nu[1];                        // 43

    struct   trans_tail_  tail;
};

//PROM_CPN_REQ_EXT  FSD18888
struct promotion_coupon_required_ext_
{
	unsigned char opcode;						//0 0x70 <Opcode Value="0x70"/>
	unsigned char function;						//1 0x91 <Opcode Value="0x91"/>

	unsigned char org_coupon_code[23];			//2	BCD - (right justify, leading A's - at C4) (v8.6.3.8 is left justify see thier code)
	
	unsigned char sExternaData[6];              //25 //FSD394424, BCD-Serial Number
	short         shExternalDataLength;         //31 //FSD394424 - Serial Number length
	

	unsigned char nu[11];						//33

    struct   trans_tail_  tail;					//44
};
												//64
//CR8_BIGY
struct trs_msg5_plu_
{
	unsigned char opcode;      						//0 0x60	<Opcode Value="0x60" />
	unsigned char function;    						//1 0x8A	<Opcode Value="0x8A" />

	unsigned char opt_subtract             :1;		//2
	unsigned char opt_cancel               :1;		//2
	unsigned char opt_dep_sale			   :1;		//2
	unsigned char opt_item_sold			   :1;		//2
	unsigned char opt_recall_report 	   :1;		//2
	unsigned char opt_refund        	   :1;		//2
	unsigned char opt_post_void        	   :1;		//2
	unsigned char opt_recall_sale_not_allowed:1;	//2

	unsigned char descr_msg_plu[20];				//3
	unsigned char link_plu_code[7];					//23

	unsigned short dep_no;							//30
	unsigned char  uchMsgId;						//32
	unsigned char  uchMsgType;						//33
		
	unsigned char bBillPaymentPrint			: 1;	//34 temp solution for offline bill payments
	unsigned char bPlu_Msg_Ext				: 1;	//34 CR#6910
	unsigned char bPrintDetailsOnTicket		: 1;	//34 FSD14741
	unsigned char bInternalCodeIndentified	: 1;	//34 FSD20162
	unsigned char bBadBatchDateEntry		: 1;	//34 FSD20162
	unsigned char bOptWasCanceled       	: 1;	//34 FSD71422
	unsigned char bPOSItemMessageLinked		: 1;	//34 FSD234928
	unsigned char bControlCheckLinked		: 1;	//34 FSD234928

	unsigned char sInternalCode[7];					//35 FSD20162
	unsigned char uchCashierResponse;               //42 FSD71422
	unsigned char SCO_type;						    //43 FSD70677

	struct   trans_tail_  tail;						//44
};
//create for FSD403679 - PIM Enhancement
struct trs_pos_item_message_
{
	unsigned char opcode;      						//0 0x90	TRANS_INFO4
	unsigned char function;    						//1 0x09	TRANS_INFO4_POS_ITEM_MESSAGE

	unsigned char opt_subtract             :1;		//2
	unsigned char opt_cancel               :1;		//2
	unsigned char opt_dep_sale			   :1;		//2
	unsigned char opt_item_sold			   :1;		//2
	unsigned char opt_recall_report 	   :1;		//2
	unsigned char opt_refund        	   :1;		//2
	unsigned char opt_post_void        	   :1;		//2
	unsigned char opt_recall_sale_not_allowed:1;	//2
	unsigned char sPIM_DEscription[20];				//3
	unsigned char uchPIMId;							//23
	unsigned char uchPIMType;						//24
	unsigned char uchMinimumAge;					//25  
	unsigned char uchCashierResponse;               //26 
	short shDep;									//27
	unsigned char uchPluCode[7];					//29
	unsigned char uchNotInUse[8];					//36

	struct   trans_tail_  tail;						//44
};

struct trs_cash_withdrawal_eft_
{
	unsigned char opcode;         	//0x60	<Opcode Value="0x60"/>
	unsigned char function;       	//0x8C	<Opcode Value="0x8C"/>

	unsigned char flag_cash_withdrawal_eft		:1;	 
	unsigned char notused						:7;
   
	unsigned char reserved[41];

	struct   trans_tail_  tail;
};


struct trs_reward_tender
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60" />
    unsigned char function;       //0x6F	<Opcode Value="0x6F" />

    unsigned char voucher_id[11];
    unsigned char key_code[5];
	long				disc_per_qty;
	long				total_disc;
	long				total_gallons;
	char				fuel_grade;
	long				price_per_grade;


	 unsigned char manual :1;
 	 unsigned char unused :7;

    unsigned char nu[8];

    struct   trans_tail_  tail;
};

//CLICKS_EFT
/*struct trs_eft_nomad_print_slip_
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60"/>
    unsigned char function;       //0x71	<Opcode Value="0x71"/>

	unsigned char eft_terminal_ret[11];
	unsigned char eft_sequence_ret[11];
	unsigned char eft_merchant_ret[15];
  
    unsigned char reserved[5];

    struct   trans_tail_  tail;
};
*/
//CLICKS_EFT
struct trs_eft_nomad_print_slip1_
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60"/>
    unsigned char function;       //0x71	<Opcode Value="0x71"/>

	 unsigned char key1_eft[40];
	 unsigned char unuse[2];

    struct   trans_tail_  tail;
};

//CLICKS_EFT
struct trs_eft_nomad_print_slip2_
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60"/>
    unsigned char function;       //0x95	<Opcode Value="0x95"/>

	 unsigned char key2_eft[40];
	 unsigned char unuse[2];

    struct   trans_tail_  tail;
};

//CLICKS_EFT
struct trs_eft_nomad_print_slip3_
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60"/>
    unsigned char function;       //0x96	<Opcode Value="0x96"/>

	 unsigned char key3_eft[40];
	 unsigned char unuse[2];

    struct   trans_tail_  tail;
};

struct trs_pump_post_dec_
{
    unsigned char opcode;        //0 0x60	<Opcode Value="0x60"/>
    unsigned char function;      //1 0x97	<Opcode Value="0x97"/>

	 unsigned char account[10];   //2	
	 short         media_no;	   //12
	 long          amount; 	      //14
	 long	         volume;	      //18
	 short         declaine_code;	//22
	 unsigned char pump_no; 	   //24
 	 unsigned char	date[3]; 	   //25
	 unsigned char	time[3]; 	   //28
    unsigned char reseved[13];   //31
    struct   trans_tail_  tail;  //44
};


struct trs_pump_grade_price_id_
{
    unsigned char opcode;        //0 0x60	<Opcode Value="0x60"/>
    unsigned char function;      //1 0x98	<Opcode Value="0x98"/>

	 unsigned short price_id; 	   //2

    unsigned char  grade_id;     //4

	 long           price; 	      //5
    
    unsigned char reseved[35];   //9
    struct   trans_tail_  tail;  //44
};

//CLICKS_EFT
struct trs_eft_nomad_owner_name_
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60"/>
    unsigned char function;       //0x72	<Opcode Value="0x72"/>

	unsigned char eft_owner_name[42];
  
    struct   trans_tail_  tail;
};


//CLICKS_EFT
struct trs_eft_nomad_media_
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60"/>
    unsigned char function;       //0x70	<Opcode Value="0x70"/>

	unsigned short  card_type;
	unsigned short  media_no;
	long amount;
	long cashback;
	unsigned char account_eft[21];
	unsigned char enter_account					:2;
	unsigned char bVoidTenderIfEftNotConfirm	:1;	//FSD41937
	unsigned char not_use1						:5;
	unsigned char manual;					//card: 1-not MCR_used; 2-MCR_used;
    unsigned char auth_no[7];
											//cheque:3-not manual;  4-manual
    struct   trans_tail_  tail;
};

//CLICKS_EFT
struct trs_eft_nomad_budget_
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60"/>
    unsigned char function;       //0x74	<Opcode Value="0x74"/>

	unsigned char eft_trans_no[10];
	unsigned short eft_budget_period;
	short eft_exp_year;
    short eft_exp_month;
	long eft_open_to_buy_bal_ret;
	long eft_acct_bal_ret;
	long eft__plan_1;

    unsigned char reserved[14];

    struct   trans_tail_  tail;
};


//CLICKS_EFT
struct trs_eft_nomad_cheque_
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60"/>
    unsigned char function;       //0x75	<Opcode Value="0x75"/>

	unsigned long eft_cheque_clear_code;
    unsigned char eft_cheque_acc_num[16];
	unsigned long eft_cheque_number;
  
	unsigned char reserved[18];

    struct   trans_tail_  tail;
};

//EFT_NOMAD
struct trs_eft_nomad_trx_key_
{
	unsigned char opcode;		//0x60	<Opcode Value="0x60"/>
	unsigned char function;	//0x76		<Opcode Value="0x76"/>

	unsigned char	EFT_Trx_Key[33];
	long			Amount;

	unsigned char reserved[5];

	struct trans_tail_	tail;
};

//SelfScan22304FS
struct trs_scanpoint_save_report_
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60"/>
	unsigned char function;    //0x77	<Opcode Value="0x77"/>

	long scanpoint_scanned;
	long rescanned;

	unsigned char reserved[34];

	struct   trans_tail_  tail;
};

/*----------------------------------------------------------------------
Opcode: 0xD1
Start of ticket for miscellaneous transactions. To help identify start 
and end of tickets which are not wrapped by 0x21 and 0x05 opcodes
-----------------------------------------------------------------------*/
//!yaron
struct trs_misc_frame_						//OFS    Description
{
   unsigned char opcode;					//0		0xD1	<Opcode Value="0xD1"/>
   unsigned char func;                      //1     see MISC_TRANS_FUNC	<Opcode Value="0x00-0x02"/> 
   unsigned char filler[42];                //2      Future use
   struct   trans_tail_  tail;				//44	   TRS tail
};											

/*----------------------------------------------------------------------
Opcode: 0xD5
End of ticket for miscellaneous transactions. To help identify start 
and end of tickets which are not wrapped by 0x21 and 0x05 opcodes
-----------------------------------------------------------------------*/
//!yaron
struct trs_misc_end_                        //OFS    Description
{
   unsigned char opcode;					//0		0xD5	<Opcode Value="0xD5"/>
   unsigned char func;                      //1     see see MISC_TRANS_FUNC <Opcode Value="0x00-0x02"/>
   unsigned char filler[42];                //2      Future use
   struct   trans_tail_  tail;				//44	   TRS tail
};

//PrLn_CRQ3
struct trs_priceline_abn_
{
	unsigned char opcode;         //0x60	<Opcode Value="0x60"/>
    unsigned char function;       //0xB5	<Opcode Value="0xB5"/>

	unsigned char abn_nu[15];
	unsigned char unuse[27];

    struct   trans_tail_  tail;
};


struct trs_info_t7e_   // V7 EFT for phillipines.
{
	unsigned char opcode;      //0x17 TRANS_INFO_T7E	<Opcode Value="0x17"/>

	unsigned char t7e_invoice_number[6]; // 1
	unsigned char err_t7e_no;            // (7)  T7 0f-line(sale), 2 -T7 of-line (void),
									  // 3 - Bank of-line(sale), 4 - Bank of-line (void),
	unsigned short int  tender_no;    // 8
	unsigned char approval_code[6];   // 10
	long          ticket_amount;      // 16
	long          amount;             // 20

	unsigned char void_without_invoice_no	:1;
	unsigned char cancel_subtract_eft_t7e	:1;
	unsigned char non_EDC					:1;
	unsigned char post_void_trans			:1;
	unsigned char save_trans_t7				:1;
	unsigned char bReadExtT7eTrs			:1; 
	unsigned char bConfirmationTran			:1;		//Confirmation Message sent to eSP
	unsigned char bReferralNumEntered		:1;   // TD#57326 

	unsigned char cc_t7;   // 25
	short int     err_comm_t7;  // 26
	short int     response_code; // 28

	unsigned char issuer_name_t7[10]; // 30

	unsigned char original_pos_number; //40

	short shEftTerminalId;	//41

	unsigned char bApprovalCodeAsBCD	:1;	//43	//#66704
	unsigned char bAuthorizedOffline	:1; //FSD55825 - Accreditation Issue 
	unsigned char bVoidEFTTender		:1;	//FSD413134
	unsigned char bNU					:5;

	struct   trans_tail_  tail;  //44
};

//FSD27835
struct trs_info_t7e_ext_  //Adish
{
	unsigned char opcode;         //0x70    //0	<Opcode Value="0x70" TRANS_INFO2/>
    unsigned char function;       //0xBF    //1	<Opcode Value="0xBF" TRANS_INFO2_T7E_EXT/>

	unsigned char t7e_ext_invoice_number[22];	  //2

	unsigned char bIsBCDInvoiceNumber		:1;
	unsigned char not_use1					:7;   // 24

	char szEftTerminalId[19];					  //25 

    struct   trans_tail_  tail;				      //44	   TRS tail

};

//OEM points transaction
struct trs_info_oem_points_
{
	unsigned char opcode;         //0x60	<Opcode Value="0x60"/>
    unsigned char function;       //0xB9	<Opcode Value="0xB9"/>

	unsigned char member_card_no[20];
	long current_points_earned;
	long points_accumulated;
	unsigned char reserv[14];

    struct   trans_tail_  tail;
};

//METRO (ROW)
struct trs_cust_at_sot_
{
   unsigned char opcode;         //0	0x60	<Opcode Value="0x60"/>
	unsigned char function;       //1	0xBC	<Opcode Value="0xBC"/>
	unsigned char sub_func;			//2	1-inf1 2-inf2 3-inf3 4-inf4	<Opcode Value="0x01-0x04"/>
											
	union
	{
		unsigned char data[41];		//3
		struct 
		{
			unsigned char	payment_type;			//3
			unsigned short	cust_category;			//4
			unsigned long	rep_code;				//6
			unsigned short	liquor_type;			//10
			unsigned char	liquor_exp_dt[3];		//12

			unsigned char	opt_rounding  :1;		//15
			unsigned char	opt_case_disc :1;
			unsigned char	opt_first_rcl_inv :1;
			unsigned char	opt_wet_tax   :1;
			unsigned char	opt_nu2       :1;
			unsigned char  opt_frgn		  :1;
			unsigned char	opt_StdPriceOnly :1;
			unsigned char	opt_cod_customer  :1;

			//unsigned char	inv_rrp       :1;		//16
			//unsigned char	inv_markdown  :1;
			//unsigned char	inv_barcode   :1;
			unsigned char	vat_exempt    :1;		//16
			unsigned char	cred_card_fee :1;
			unsigned char	delivery_chg  :1;
			unsigned char   order_entry   :1;
			unsigned char   rebate_fg     :1;		// ROW
			unsigned char   internal_plu  :1;		// TD146800
			unsigned char	inv_nu        :2;		// TD146800

			unsigned short	home_state;				//17
			unsigned char	cust_status;			//19
			long			   cheque_limit;			//20
			long			   credit_limit;			//24
			unsigned short	block_code;				//28
			unsigned char	disc_cd;					//30
			long          surcharge_percent;    //31
			short			cust_at_sot_mcr;			//35
			unsigned char	cust_charge_posting	:1;	//37
			unsigned char	cust_offline			:1;
			unsigned char	cust_not_found			:1;
			unsigned char	cust_tax_exempt		:1;
			unsigned char   cust_branch				:1; //SALE_PROC
			unsigned char	cust_reserve			:3;
			
			unsigned char  staff_type;				//38
			unsigned char price_exception;		//39
			unsigned char price_type;				//40
			unsigned char type_paym_at_sot;			//41  SALE_PROC
			unsigned char type_return;				//42  START_UP_MENU_RETURN
			unsigned char inv_option;               //43  RRP indicator 			
		} inf1;

		struct
		{
			unsigned char liq_license[12];		//3
			unsigned char tax_id[10];           //15 For V8.7.3.50 (Metro)
			long          postal_code;				//25
			long			  cheque_amt;				//29
			long			  credit_amt;				//33
			unsigned char force_crd_rtrn;       //37
			long force_crd_amount;					//38
			unsigned char	reserv[2];				//42
		}inf2;

		struct 
        {
			unsigned char	wet_expiry_date[3];		  //3
			unsigned char   wet_expiry_msg      :1;   //6      
			unsigned char   CustOrderOnTill     :1;	  //6	bug20477_1:for extract+RDH from till
			unsigned char   nu                  :6;

			unsigned char   wet_dt_exp;               //7

			unsigned char   order_no[10];             //8  Order number 
			unsigned char   tax_id[16];               //18 For V8.7.4.0 (CC&C)
			unsigned char	ref_order_no[10];	      //34 FSD214852
		}inf3;

		//DelivChrg
		struct
		{
			unsigned char del_chg_type;              //3 
			unsigned long del_chg_val;               //4
			long cst_ord_deliv_chrg_amount;          //8 Customer orders 
			unsigned long cust_debtor_no;            //12 Customer debtor number  
			unsigned char TypeCO;					//16  CR19916
			
			long lTradeDiscPercent;                 //17  Trade discount percentage (CR #19636).
			struct									//21  FS3025
			{			
				unsigned char bPickPackPrompt   :1; //Answer Yes/No on the Pick&Pack prompt
				unsigned char bDeliveryPrompt   :1; //Answer Yes/No on the Delivery Chaege prompt
				unsigned char bits              :6;
			}Flags;
			unsigned char uchPickPackChargeType;     //22 FS3025
			unsigned long ulPickPackChargeRate;      //23 FS3025
			unsigned long ulMinDeliveryFee;          //27 FS3025
			unsigned char sWebOrderID[10];           //31 FS3026

			unsigned char reserv[3];                 //41
		}inf4;

		//CR#7805
		struct 
        {
			unsigned char   sPDA[10];				  //3  PDA serial number
			unsigned char   order_type[6];			  //13	FSD56986
			unsigned char   placed_by[15];			  //19	FSD56986	
			unsigned char   nu1[10];				  //34
		}inf5;

		//FSD13992
		//FSD254276 send inf6 for each product type/price code on customer/GSP level
		struct
		{
			struct FeesByProductType_
			{
				unsigned char ProductType;
				unsigned char uchDeliveryFeeType;
				long lDeliveryValue;
				unsigned char uchPNPFeeType;
				long lPNPValue;
			}FeesByProductType;														//3
			
			struct FeesByPriceCode_
			{
				unsigned short ushPriceCode;
				unsigned char uchDeliveryFeeType;
				long lDeliveryValue;
				unsigned char uchPNPFeeType;
				long lPNPValue;
			}FeesByPriceCode;														//14

			int iAltCustID;															//26

			long opening_balance;	//FSD238694										//30
			short index; 															//34	//Defect 423903 - POS auto recovery (borisya)
			unsigned char Inf6NU[8];												//36
		}inf6;

		//FSD254275 Tobacco order enhancement 
	    struct
        {                                      
			short          operatorNoAuth;											//3
			short          operatorNo;												//5
			unsigned char  nu1[37];													//7
		}inf7;   


	} info;

    struct   trans_tail_  tail;
};

struct trs_loyalty_msg_
{
    unsigned char opcode;			//0x60	<Opcode Value="0x60"/>
    unsigned char function;			//0xC0	<Opcode Value="0xC0"/> TRANS_INFO_LOYALTY_MSG
	
	unsigned char nu_1;				//2  Not Used
	unsigned char chLanguageID;		//3  NUM
    char sMsgNo[2];					//4	 BCD  -  Msg ID
	unsigned char sCardNo[20];	  
									// 0 - Customer Specific message
									// 1 - All-Loyalty
	unsigned char cDestination;		// 2 - Non-Loyalty customers

	unsigned char bRemoveSpecificLink	:1;
	unsigned char bMessageExpired		:1;
	unsigned char nu7					:6;

	unsigned char data[16];

    struct   trans_tail_  tail;
};

// Sundry item transaction. Item price and description captured at POS
struct trs_info_sundry_product_					//OFS	Description
{
    unsigned char opcode;          				//0		Opcode - 0x60	<Opcode Value="0x60"/>
    unsigned char function;        				//1		Subopcode - 0xB1 <Opcode Value="0xB1"/>

    unsigned char plu_code[7];     				//2		Item number (BCD) 
	unsigned char plu_desc[20];	  				//9		Item description
	
    unsigned char opt_liquor    :1;				//29	This is a liquor item
    unsigned char opt_tobacco   :1;				//29	This is a tobacco item
	unsigned char opt_standard  :1;				//29	Standard item (not liquor or tobacco)
	unsigned char opt_tax_excl	:1;				//29	Tax amount is exclusive (added to) item price
	unsigned char opt_sundry_ext:1;             //29    Extended sundry item transaction
	unsigned char nu            :3;				//29	Future use

    unsigned short liquor_capacity;		 		//30	Liters in item unit
	long     tax_amount;						//32	Tax on this item
	long     plu_price;							//36	Item price
	long     qty;								//40	Quantity sold
	    
    struct   trans_tail_  tail;					//44	Transaction tail
};

// Sundry item extention transaction. 
struct trs_info_ext_sundry_product_			
{
    unsigned char opcode;          				//0		Opcode - 0x60		<Opcode Value="0x60"/>
    unsigned char function;        				//1		Subopcode - 0xE9	<Opcode Value="0xE9"/>

    unsigned char plu_code[7];     				//2		Item number (BCD) 
	unsigned char plu_second_desc[10];	  		//9		Item second description   
	unsigned char nu[25];                       //19
	    
    struct   trans_tail_  tail;					//44	Transaction tail
};


// Information about a non-merchendise item sales (ROW, wholesale)
struct trs_info_non_merc_						//OFS	Description
{
    unsigned char opcode;         				//0		Opcode - 0x60		<Opcode Value="0x60"/>
	unsigned char function;		   				//1		Subopcode - 0xCB	<Opcode Value="0xCB"/>

    unsigned char plu_code[7];               	//2		Item number
	short dep_no;								//9		Department number

	unsigned char opt_non_merch	    :1;			//11    Non-merchendise item
	unsigned char opt_tax_excl		:1;			//11	Tax is GST exclusive
	unsigned char nu				:6;			//11	Future use
																	 
	long tax_amount;							//12	Tax on this item
	unsigned char reserved[28];					//16	Future use
    
    struct   trans_tail_  tail;					//44	Transaction tail			
};


struct trs_loyalty_mail_info_
{
	unsigned char	opcode;           //0x60	<Opcode Value="0x60"/>
	unsigned char	function;         //0xCC	<Opcode Value="0xCC"/>

	unsigned char	sCardNo[10];		// card no in BCD
    unsigned char	chMailDeliveryStatus;

	unsigned char	nu[31];

	struct   trans_tail_  tail;
};


struct trs_create_clubcard_
{
	unsigned char	opcode;           //0x60	<Opcode Value="0x60"/>
	unsigned char	function;         //0xD2	<Opcode Value="0xD2"/>

	unsigned char	sCardNo[10];		// card no in BCD
    unsigned char	chGeneralStatus;
	
	unsigned char  chSchemeId;			//FSD414790




	unsigned char	nu[30];

	struct   trans_tail_  tail;
};

/* ROW */
// wholesale price calculation info.
// wholesale price calculation info.
struct trs_info_price_calc_						//OFS	Description
{
    unsigned char opcode;         				//0		Opcode - 0x60	<Opcode Value="0x60"/>
	unsigned char function;		   				//1		Subopcode - 0xB3	<Opcode Value="0xB3"/>

    unsigned char plu_code[7];               	//2		Item number
	short dep_no;								//9		Department number
	unsigned char opt_staff_disc    :1;			//11	Staff discount was given
	unsigned char opt_cust_disc     :1;			//11	Customer discount was given
	unsigned char opt_manag_disc    :1;			//11	Manager discount was given
	unsigned char opt_negative		:1;			//11	The amount in this TRS needs to be reversed. item was voided or returned.
	unsigned char opt_ttl_disc		:1;			//11	Total trans discount
	unsigned char opt_del_prom      :1;         //11    Member promotion discount (delayed promotion) 
	unsigned char opt_immd_prom     :1;			//11	Member promotion discount (immediate promotion)
	unsigned char nu                :1;         //11	Future use
																	 
    long milk_levy;		 						//12	Levy on this item
	long wet_tax_amount; 						//16	WET tax amount
	long liq_subsidy;	 						//20	Liquor subsidy amount
	long discount_amount; 						//24	Discount amount (staff/customer/manager)
	long tax_amount;							//28	Tax on this item
	long case_discount;							//32	Case discount amount
	long surcharge_rate;						//36	Surcharge percent
    long wet_tax_rate;							//40	Wet tax rate (percentage)
    
    struct   trans_tail_  tail;					//44	Transaction tail			
};

/* ROW */  
struct trs_info_grid_calc_
{
    unsigned char opcode;                             //0x60	<Opcode Value="0x60"/>
	 unsigned char function;		                  //0xB2	<Opcode Value="0xB2"/>
		
    unsigned char plu_code[7];								//offset 2

	 unsigned char comparative_no;                      // offset 9
	 unsigned char comparative_flag  :1;	            //offset 10 
	 unsigned char special_price     :1;
	 unsigned char  bExtFee2IsStdPrice:1;				// the field extra_fee2 is stadard price from price lists
	 unsigned char bPriceIncludesGST  :1;
	 unsigned char	nu                :4; 

    unsigned short price_code;								//offset 11

	 long  tax_on_extra_fee1;									//offset	13 
    long  service_fee;                      				//offset 17  
    long  finance_fee; 				 							//offset 21	
    long  extra_fee1; 				 							//offset 25	
	 long  brocken_pack;											//offset 29
	 long  extra_fee2;											//offset 33
	 long  promotion_number;									//offset 37

	 unsigned char cp_prc_indicator;							//offset 41
    unsigned char nu1[2];								   	//offset 42
	 struct   trans_tail_  tail;							   //offset 44
};


/* ROW */
// wholesale GST calculation info.
struct trs_info_excl_calc_						//
{
    unsigned char opcode;         				//0		Opcode - 0x60		<Opcode Value="0x60"/>
	unsigned char function;		   				//1		Subopcode - 0xCD	<Opcode Value="0xCD"/>

    unsigned char plu_code[7];               	//2		Item number
	short dep_no;								//9		Department number
	
	long tax_on_cust_disc;		                //11	Tax on Customer Discount amount 
    long tax_on_staff_amount; 	                //15    Tax on Staff Discount amount 
	long tax_on_case_disc;		                //19	Tax on Case Discount amount 
	long tax_on_surcharge_amount;				//23	Tax on Surcharge amount 
	long tax_on_brocken_pack;	 				//27	Tax on Brocken pack
	long tax_on_service_fee; 					//31	Tax on Service fee
	long tax_on_extra_fee1;						//35	Tax on extra fee1
	long tax_on_extra_fee2;						//39	Tax on extra fee2
	

	unsigned char nu1[1];                       //43
    
    struct   trans_tail_  tail;					//44	Transaction tail			
};
 

// Return voucher issued (ROW)
struct trs_info_rtn_voucher_					//OFS	Description
{
	unsigned char opcode;						//0		0x60	<Opcode Value="0x60"/>
	unsigned char function;						//1		0x7d	<Opcode Value="0x7D"/>
	unsigned char sub_func;						//2		0: Issue	<Opcode Value="0x00-0x02"/>
												//		1: Redemption
												//		2: Payment
												//		3: Error (FSD59749)
	unsigned char vcr_no[10];					//3		Voucher number in BCD
	long	      amount;						//13	Voucher amount
	unsigned short rdmp_tender_no;				//17	Redemption tender number
	unsigned char cust_no[10];					//19    Customer number
	unsigned char type;							//29	// FSD#30639
	
	unsigned char bStatus					:1;	//30	FSD59749 '0'-Online '1'-Offline
	unsigned char bBarcodeAlreadyGenerated	:1;	//30	FSD59749 '0'-No		'1'-Yes
	unsigned char bStoreLineIssued			:1; //30	FSD234817
	unsigned char bReturnVoucherPrinted		:1; //30	FSD234817
	unsigned char bNU						:4;	//30	
	
	unsigned char uchReasonCode;				//31	FSD59749
												//		0 - Already scanned
												//		1 - Not found
												//		2 - Offline
												//		3 - Other Store // FSD#157394

	unsigned char uchVchNoLen;					//32

	short shDepNo;								//33 // FSD59749

	long	lSerialNumber;						//35	FSD234817
	unsigned char	bcdExpirationDate[3];		//39	FSD234817

	unsigned char ucMethod;						//42

	unsigned char filler[1];					//43    Future use	

	struct   trans_tail_  tail;					//44	tail
};

struct trs_gift_basket_
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60"/>
    unsigned char function;       //0xBD	<Opcode Value="0xBD"/>

    short gift_number;
	unsigned char start      :1;
	unsigned char end        :1;
	unsigned char void_gift  :1;

	unsigned char nu         :5;

    unsigned char reserved[39];

    struct   trans_tail_  tail;
};

//ROW:Metro
struct trs_info_add_credit_limit_
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60"/>
    unsigned char function;       //0xC3	<Opcode Value="0xC3"/> transaction "allow additional credit/check limit"

	unsigned char type_limit;		// 1 - Credit limit, 2 - Check limit
	long          amount;
	unsigned char cust_no[20];		//customer number

	unsigned char bAddedByAuthorizationCode :1; //FSD63571
	unsigned char nu                        :7;

	unsigned char sAuthorizationCode[10];		//FSD63571

	unsigned char un[6];

    struct   trans_tail_  tail;
};

//ROW:Metro;SALE_PROC:ACCT_PAYM_ALL_TENDER
struct trs_info_charge_paym_
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60"/>
    unsigned char function;       //0x7F	<Opcode Value="0x7F"/> payment by all tenders

	unsigned char type_paym_eot;
	long          tender_amount;
	long		  amount_ttl;
	short		  tender_no;

	unsigned char cust_no[20];		//customer number

	unsigned char un[11];

    struct   trans_tail_  tail;
};

//EFT_NMD_CLICKS
//EFT handle transaction
struct trs_handle_nmd_							//OFS	Description
{
	unsigned char opcode;						//0		Opcode - 0x60		<Opcode Value="0x60"/>
	unsigned char function;						//1		Subopcode - 0xBE	<Opcode Value="0xBE"/>

	unsigned long	handle_no;					//2		Handle number

	unsigned char opt_invoice	:1;				//6		invoice (ticket) handle
	unsigned char opt_item		:1;				//6		item (elec. voucher) handle
	unsigned char opt_media		:1;				//6		eft handle. not really useD: handle send in media_ext2
	unsigned char opt_cancel	:1;				//6		cancel handle
	unsigned char opt_nu		:4;				//6		Future use

	unsigned char plu_code[7];					//7     eft_nomad_300303
	unsigned char reserved[30];					//14		Not used
  
   struct   trans_tail_  tail;					//44	Transaction tail
};

//EFT_NMD_CLICKS
struct trs_prn_nmd_
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60"/>
    unsigned char function;       //0xBF	<Opcode Value="0xBF"/>
    unsigned char sub_function;   //number of string

	unsigned char	data[41];

    struct   trans_tail_  tail;
};


//Delivery charges
struct trs_info_deliv_chrg_
{
    unsigned char opcode;         //0x60   //0	<Opcode Value="0x60"/>
    unsigned char function;       //0x8D   //1	<Opcode Value="0x8D"/>

	long tax_rate;                         //2
	short tax_number;                      //6
	long delivery_amount;                  //8   //amount incl.tax
	long tax_on_delivery_amount;           //12 //tax amount into delivery amount
	unsigned char tax_ptr;                 //16

	long lPickPackAmount;                  //17 //amount incl.tax
	long lPickPackTaxAmount;               //21 //tax amount into pick&pack amount

	unsigned char sPluCode[7];             //25

	struct                                 //32
	{
		unsigned char bDeliveryFee		:1;
		unsigned char bPickPackFee		:1;
		unsigned char bItemLevelFee		:1;
		unsigned char bMinDeliveryFee	:1;
		unsigned char bSummaryInfo		:1;		//TD#327990; = 0, if the trs describes item info (this is for percentage case);   =1, if the trs describes summary info 
		unsigned char bPickPackPercent	:1;
		unsigned char bDeliveryPercent	:1;
        unsigned char nu				:1; 
	}Flags;

	unsigned char	uchFeesPrintFormat;		//33
	unsigned char	nu[10];					//34

    struct   trans_tail_  tail;				//44
};


//Self scanning recovery trs
struct trs_info_self_scanning_
{
    unsigned char opcode;         //0x60	<Opcode Value="0x60"/>
    unsigned char function;       //0xC6	<Opcode Value="0xC6"/>	TRANS_INFO_SELF_SCANNING


	unsigned char	bAdditionalItemsSelling			:1; // 2
	unsigned char	bSelfScanningTicketExecution	:1;
	unsigned char	bSelfScanningTicketParsed		:1;
	unsigned char	bSelfScanningReScanExecution	:1;
	unsigned char	bSelfScanReturnTicket			:1;
	unsigned char	bTicketFinished					:1;	// ticket parsed succesfully
	unsigned char	bOrderNumberAsTransNUmber	    :1; // #18119_U
	unsigned char	bSelfScanFrameTrs				:1; // FSD28467 GinatB, #376093:Self Scan Jumbo


	unsigned char chSelfSystemType;	//3  FAST_TRACK - 1 ,  HOME_SHOPPING - 2 , eCOMMERCE - 8, Mobile Scanning - 19

	unsigned char	sOrderNumber[8]; // 4

	unsigned char   sCustNoWithLeadingZero[20];							//12
	
	union
	{
		unsigned char	sRoadyOrderNumber[10];	// 32	BCD
		unsigned char   bcdOrderNumber[10];		// 32   BCD
	};
	short	shPosNumInFileName;				// 42	- Pos number from the self scan file name

    struct   trans_tail_  tail;
};

struct parking_data_
{
	char szParkingSpace[10];
	char szDeliveryMan[10];
	unsigned char NU[21];
};

//FSD#60132
struct online_order_
{
	unsigned char	bcdDateOfOrder[3];
	unsigned char	bcdTimeOfOrder[3];

	long			lVirtualTenderAuthAmount;//FSD#365331
	short			shVirtualTenderNumber;//FSD#365331
	unsigned char	NU[29];
};
//FSD#67023_1
struct later_scanning_
{
	unsigned char plu_code[7];						
	short qty;
	short msgNum;
	unsigned char bDepReq	:1;
	unsigned char NU1		:7;
	unsigned char NU[29];
};

//Self scanning recovery trs extension
struct trs_info_self_scanning_ext_
{
    unsigned char opcode;         //0x70	<Opcode Value="0x70"/>
    unsigned char function;       //0xE7	<Opcode Value="0xE7"/>	TRANS_INFO_SELF_SCANNING_EXT

	struct									//2
	{
		unsigned char bOnlineOrderIsActive :1;//FSD#60132
		unsigned char bLeftForLaterScanning:1;//FSD#67023_1
		unsigned char bAreaScaleVoidPackageStarted:1;// FSD 136864, bug #215634
		unsigned char bAreaScaleVoidPackageByUser:1;// FSD 136864, bug #215634
		unsigned char bEGroceryInProgress:1;//FSD#365331
		unsigned char bEGroceryManualProcessing	:1; //FSD#365331 - fixes after the AT
		unsigned char NU  :2;
	}StatusFlags;
	
	
	union									//3 should be 41 byte size
	{
		struct parking_data_ parking_data;
		struct online_order_ online_order;
		struct later_scanning_ later_scanning;
	}Data;

    struct   trans_tail_  tail;				// 44
};

 
//#271222 Self scanning recovery trs extension 2
struct trs_info3_self_scanning_ext2_
{
    unsigned char opcode;			//0x80	<Opcode Value="0x80"/>
    unsigned char function;			//0x56	<Opcode Value="0x56"/>	TRANS_INFO3_SELF_SCANNING_EXT2

	char szCustomerName[41];		//2
	char nu[1];						//43

    struct   trans_tail_  tail;		// 44
};																	     

/*----------------------------------------------------------------------
FSD257939
Opcode:	0x80 
Subopcode:	0x57
Additional discount information. This transaction will be logged
When a media transaction is changed to a discount transaction 
-----------------------------------------------------------------------*/
struct trs_info3_discount_ext_				//OFS	Description
{
    unsigned char opcode;					//0	0x80 <Opcode Value="0x80" />
    unsigned char function;					//1	0x57 <Opcode Value="0x57" /> TRANS_INFO3_DISCOUNT_EXT

    unsigned short tender_no;				//2	tender number
    unsigned char  type;					//4	tender type

    unsigned char account[21];				//5	account number (ascii)
    long tender_amount;						//26	previous tender value
    unsigned char reserve[14];				//30	unused
    
    struct   trans_tail_  tail;				//44	TRS tail
};							//64


/*----------------------------------------------------------------------
FSD294724
Opcode:	0x80 
Subopcode:	0x58
Additional media information. This transaction will be logged
When a media transaction is eWallet\Coupon and returns an SKU List
-----------------------------------------------------------------------*/
struct trs_info3_wiwallet_sku_				//OFS	Description
{
    unsigned char opcode;					//0	0x80 <Opcode Value="0x80" />
    unsigned char function;					//1	0x58 <Opcode Value="0x58" /> TRANS_INFO3_WIWALLET_SKU

	//	Total Available 42
	unsigned char invoice_number[6];		//2 (ascii)
    unsigned char account[21];				//8	account number (ascii)
	unsigned char sBCDInternalCode[7];      //29     BCD Internal Item code
	//	Flags
	unsigned char item_voided	 :1;		//36
	unsigned char nuFlag		 :7;
    unsigned char reserve[7];				//37	unused
    
    struct   trans_tail_  tail;				//44	TRS tail
};							//64

/* Rep code transaction */
struct trs_info_rep_code_  
{
    unsigned char	 opcode;			// 0x60	<Opcode Value="0x60"/>
    unsigned char  function;     // 0xBB		<Opcode Value="0xBB"/>
    unsigned char	 sub_opcode;   //1-trans, 2-item	<Opcode Value="0x01-0x02"/>
	 
    unsigned char plu_code[7];						
	long qty;
	unsigned char auto_rep_code  :1;
	unsigned char force_enter    :1;
	unsigned char cancel_item    :1;
    unsigned char subtract_item  :1;
	unsigned char void_rep_code  :1;
	unsigned char manual_enter   :1;
	unsigned char was_void       :1; //Bug#5171
    unsigned char bNonMerchandiseSale             :1; //FSD16776
	 
  	short rep_code;					//FSD8236
	short dept;						//FSD8236

	long lPlu_price;			//FSD11804
	long lAmount;				//FSD11804

    unsigned char date[3];		//FSD16776	Date (YYMMDD in BCD)
    unsigned char time[3];		//FSD16776	Time (HHMMSS in BCD)

	unsigned char    uchInvokeSource;  //0-None, 1-DIA

	long lDiscountAmount;			//KobiM - FSD75178

    unsigned char	 not_used[6];	//FSD11804
    struct			 trans_tail_  tail;
};

/* ON-LINE Trans info : invoice was recalled */
struct trs_info_inv_recall_
{	
    unsigned char opcode;             		//0x60	<Opcode Value="0x60"/>
    unsigned char function;           		//0xC7	<Opcode Value="0xC7"/>

    unsigned char	inv_no[8];	        		// offset 2
	 unsigned char	inv_date[3];		  		// offset 10

    unsigned char use_org_pos_no   :1;		// offset 13
	unsigned char opt_void_rcld_inv:1;      // void recalled invoice
    unsigned char opt_nu7          :6;
    unsigned char org_pos_no;					// offset 14

	 unsigned char	nu[29];				      // offset 15

    struct   trans_tail_  tail;
};


//Multi-Language
struct trs_info_lang_select_
{
    unsigned char opcode;             		//0x60	<Opcode Value="0x60"/>
    unsigned char function;           		//0xC9	<Opcode Value="0xC9"/>

    unsigned short customer_lang;
	 
    unsigned char manual_lang_change   :1;
    unsigned char opt_nu               :7;
    
	unsigned char origin ;	//FSD39780 EduardS
	unsigned char nu[38];

    struct   trans_tail_  tail;
};

//YaelB 6/3/06 FSD 11838. Add stock tender validation flag. 
struct trs_total_key_
{
	unsigned char opcode;    //0x60                 //0	<Opcode Value="0x60"/>
	unsigned char function;  //0x26                 //1	<Opcode Value="0x26"/>

	short items;                                    //2
	long	amount;                                 //4
  
	unsigned char stock_tender_validation_needed;	//8
	unsigned char IsGetTargetMessagePromoInTicket :1;//9
	unsigned char IsGetVoucherPromoInTicket		  :1;//9	
	unsigned char NU							  :6;//9
  
	unsigned char uchLastSubStateInSaleMode;	    //10 //#121898
	long media_total;								//11
	unsigned char reserved[29];                     //15

	struct   trans_tail_  tail;                     //44
};

struct trs_info_supp_data_
{
	unsigned char opcode;    //0x60                 //0	<Opcode Value="0x60"/>
	unsigned char function;  //0xCE                 //1	<Opcode Value="0xCE"/>

	unsigned short tender_no;                       //2
    unsigned char  type;                            //4
	unsigned char  data[8];                         //5
  
	unsigned char reserved[31];                     //13

	struct   trans_tail_  tail;                     //44
};

struct trs_info_barcode_prog_
{
	unsigned char opcode;    //0x60                 //0	<Opcode Value="0x60"/>
	unsigned char function;  //0xCF                 //1	<Opcode Value="0xCF"/>

	short          barcode_type;                    //2
	unsigned short segments;                        //4
	long           points;                          //6

	unsigned char bLoyaltyCardRequierd      :1;     //10
	unsigned char bWasCancelled				:1;
    unsigned char bIncludeInBarcodeGroup    :1;
	unsigned char bExeVoidCoupon            :1;
	unsigned char Nu						:4;

    unsigned char szBarcode[20]; //bcd              //11
	short shOrgBarcodeLen;                          //31
	unsigned char reserved[11];                     //33

	struct   trans_tail_  tail;                     //44
};

//FSD46343
//It's struct. for union in info2 trans.0x70;0xD0
struct ExtPosFormEftAccountTypes_
{
    unsigned char  form_id[3];				//3		these offsets for trans. 0x70;0xD0
	unsigned char  uchInputDestination;		//6
	unsigned short ushListValueID;			//7
	unsigned short usInputValueID;			//9
	unsigned short ushTenderNo;				//11
	unsigned char  uchCCTenderTrigger;		//13

	unsigned char  unUsExtForm[30];			//14
};

struct trs_info2_ext_pos_form_
{
    unsigned char  opcode;         //0x70	//0	<Opcode Value="0x70"/>
    unsigned char  function;       //0xD0	//1	<Opcode Value="0xD0"/>
	unsigned char  SubFunction;		// offset2: 1-InputDestinationEFTAccountType

	union
	{
		struct ExtPosFormEftAccountTypes_ ExtPosFormEftAccountTypes;

		unsigned char  uchInfo2ExtForm[41];		//3
	}ExtDataPosForm;

    struct   trans_tail_  tail;				//44
};


struct trs_info_segment_
{
	unsigned char	opcode;    //0x60				//0	<Opcode Value="0x60"/>
	unsigned char	function;  //0x8E				//1	<Opcode Value="0x8E"/>

	unsigned char	sCardNo[10];					//2   card no in BCD

	unsigned char	bSegmentInsert1		:1;			//12  0 - Delete Segment value
	unsigned char	bSegmentInsert2		:1;			//	  1 - Insert value into segment		
	unsigned char	bSegmentInsert3		:1;
	unsigned char	bSegmentInsert4		:1;
	unsigned char	bSegmentInsert5		:1;
	unsigned char	bSegmentInsert6		:1;
	unsigned char	bSegmentInsert7		:1;
	unsigned char	bSegmentInsert8		:1;

	unsigned char	bSegmentInsert9				:1;	//13
	unsigned char	bSegmentInsert10			:1;

	unsigned char	SegmentUpdatedInChipCard	:1;
	unsigned char	nu							:5;

	unsigned short	shSegment1;						//14
	unsigned short	shSegment2;						//16
	unsigned short	shSegment3;						//18
	unsigned short	shSegment4;						//20
	unsigned short	shSegment5;						//22
	unsigned short	shSegment6;						//24
	unsigned short	shSegment7;						//26
	unsigned short	shSegment8;						//28
	unsigned short	shSegment9;						//30
	unsigned short	shSegment10;					//32

	unsigned char	reserved[10];					//34

	struct   trans_tail_  tail;                     //44
};

struct trs_info_coupon_redemption_
{
	unsigned char opcode;    //0x60                 //0	<Opcode Value="0x60"/>
	unsigned char function;  //0xD3                 //1	<Opcode Value="0xD3"/>

	unsigned char card_no[20];                      //2
	unsigned char coupon_no[20];                    //22
	  
	unsigned short message_id;                      //42 //#11599 coupon message id

	struct   trans_tail_  tail;                     //44
};

struct trans_info_rolltainer_item_
{
	unsigned char opcode;                     //0x60
	unsigned char function;                   //0xEA

    unsigned char rolltainer_descr[30];       //2 
	unsigned char rolltainer_code[7];         //32
	long rolltainer_price;                    //39

	unsigned char nu[1];                      //43

	struct   trans_tail_  tail;				  //44	Transaction tail
};

struct trs_quick_update_
{
	unsigned char  opcode;	         //0x88	<Opcode Value="0x88"/>
	unsigned char  subopcode;	     // 1
	         			             // 1 - write
	unsigned char  func;	         // 2
                                     // 1 - write data
                                     // 2 - increment (according to size)
	unsigned char  qdx_no;	         // 3
	char           index[12];	     // 4	//If Relative file then record number left justified.
	short          position;	     // 16 possition within record
	unsigned char  size;	         // 18
   
   
	struct fc_flags_
	{
		unsigned char send_maint :1;
		unsigned char update_req :1;  
		unsigned char insert_req :1;
		unsigned char nu         :5;
		
		
	}flags;
   
   unsigned char  org_pos_no;        // 20
   unsigned char  data[23];	         // 21

   struct   trans_tail_  tail;       //44
};


struct trs_info_belgacom_
{
	unsigned char opcode;    //0x60                 //0	<Opcode Value="0x60"/>
	unsigned char function;  //0xD4                 //1	<Opcode Value="0xD4"/>

	unsigned char encrypted_tid[7];                //2 //bcd
	unsigned char counter_offset;                  //9 0-9
	unsigned char encryption_table_ref;            //10 0,3,4
	short         store_num;					   //11
	short         new_counter;                     //13
	short         message_id;                      //15
	long          amount;                          //17 
	  
	unsigned char reserved[23];                    //21

	struct   trans_tail_  tail;                    //44
};

struct trs_info_points_ext_
{
	unsigned char opcode;    //0x60                 //0	<Opcode Value="0x60"/>
	unsigned char function;  //0xD7                 //1	<Opcode Value="0xD7"/>

	short message_id;								//2
	long points;								    //4

	unsigned char barcode_points	:1;             //8
	unsigned char origion_points	:1;
	unsigned char bForgottenCard	:1;				// FSD#68201
	unsigned char nu4				:1;
	unsigned char opt_was_cancelled :1;				//Issue #3778SL
	unsigned char nu6				:1;
	unsigned char nu7				:1;
	unsigned char nu8				:1;

	unsigned short ushStoreNumber;					//9	FSD#68201

	long cancelled_points;						    //11
	long lTotalPointsAcc;							//15 TD#154072 from CR130941_ExtPoints
	unsigned char uchDecimalPlaces;                 //19 //TD#179171

	unsigned char nu[24];                           //20


	struct   trans_tail_  tail;                     //44
};


//Enh #9749 PHONE_CARD Hannaford AmyG
struct trs_phone_card_act_
{
    unsigned char opcode;         //0x60	//0	<Opcode Value="0x60"/>
    unsigned char function;       //0xD8	//1	<Opcode Value="0xD8"/>

	unsigned char ActionType;				//2
	unsigned char CardNo[22];				//3
	unsigned char AuthNo[9];				//25

    unsigned char ManuallySwipe			:1;	//34 card was swiped manualy
	unsigned char PhoneCardReturn		:1;	//Issue #8532SL
    unsigned char PhoneCardVoid			:1;	//Issue #8532SL
	unsigned char DeactivationAllowed	:1;	//Issue #8532SL
    unsigned char nu					:4; 

	unsigned char ActivationType;			//35 Issue #2711SL
	long		  Account2Balance;			//36 Issue #8532SL
	long		  PhoneCardDollarBalance;	//40 Issue #8532SL

    struct   trans_tail_  tail;				//44
};

//Issue #8532SL
struct trs_phone_card_act_ext_
{
    unsigned char opcode;         //0x70	//0	<Opcode Value="0x70"/>
    unsigned char function;       //0x49	//1	<Opcode Value="0x49"/>

	unsigned char Template[10];				//2
	unsigned char BarcodeDesc[20];			//12
	unsigned char ItemExpDate[7];			//32
	long		  TrsAmount;				//39

	unsigned char nu[1];					//43

    struct   trans_tail_  tail;				//44
};

//Issue #8532SL
struct trs_prepaid_wireless_
{
    unsigned char opcode;         //0x70	//0	<Opcode Value="0x70"/>
    unsigned char function;       //0x4A	//1	<Opcode Value="0x4A"/>

	unsigned char ActionType;				//2
	unsigned char CardNo[22];				//3
	unsigned char AuthNo[9];				//25

    unsigned char ManuallySwipe			:1;	//34 card was swiped manualy
	unsigned char WirelessReturn		:1;	//
    unsigned char WirelessVoid			:1;	//
	unsigned char DeactivationAllowed	:1;	//
    unsigned char nu					:4; 

	unsigned char ActivationType;			//35
	long		  TrsAmount;				//39
	unsigned char nu2[4];					//40

    struct   trans_tail_  tail;				//44
};

//Issue #8532SL
struct trs_prepaid_wireless_ext_
{
    unsigned char opcode;         //0x70	//0	<Opcode Value="0x70"/>
    unsigned char function;       //0x4B	//1	<Opcode Value="0x4B"/>

	unsigned char Template[10];				//2
	unsigned char BarcodeDesc[20];			//12

	unsigned char nu[12];					//32

    struct   trans_tail_  tail;				//44
};

//Issue #8532SL
struct trs_prepaid_wireless_ext2_
{
    unsigned char opcode;         //0x70	//0	<Opcode Value="0x70"/>
    unsigned char function;       //0x4C	//1	<Opcode Value="0x4C"/>

	unsigned char PINNumber[20];			//2
	unsigned char ControlNumber[20];		//22

	unsigned char nu[2];					//42

    struct   trans_tail_  tail;				//44
};

struct trs_chipcard_info_
{
	unsigned char	opcode;				//0x60	<Opcode Value="0x60"/>
	unsigned char	function;			//0x8F	<Opcode Value="0x8F"/>

	unsigned char	sCardNo[10];		// chip card no in BCD
	unsigned char	sData[24];				
	unsigned char	chCardType;
	short			shStatus;
	long			lAmount;

	unsigned char	bEmployeeCard;		//FSD13421 - Employee Card

	struct   trans_tail_  tail;
};


struct trs_chipcard_handle_msg_
{
	unsigned char	opcode;				//0x60	<Opcode Value="0x60"/>
	unsigned char	function;			//0x99	<Opcode Value="0x99"/>
	unsigned char	sub_func;

	unsigned char	sCardNo[10];		//3 chip card no in BCD
	unsigned char	chMsgLevel;			//13
	short			shMsgNumber;		//14
	short			shMsgUpdateStatus;	//16

	long			lProviderError;		//18

	unsigned char	nu[22];				//22

	struct   trans_tail_  tail;			//44 
};



/* ON-LINE Trans info : script was selected */
struct trs_onl_info_script_sales_
{
    unsigned char opcode;             	//offset 0 - opcode 0x60	<Opcode Value="0x60"/>
    unsigned char function;           	//offset 1 - function 0xD5	<Opcode Value="0xD5"/>
   
	unsigned char status;               //offset 2  - Status of prescription:
	                                    //   0 - uncommitted
	                                    //   1 - commited	                                   
	unsigned char surname[18];          //offset 3  - Patient's surname
	unsigned char patient_no[3];        //offset 21 BCD - Patient's number
    unsigned char script_no[3];         //offset 24 BCD

	unsigned char use_org_pos_no   :1;	//offset 27
  	unsigned char opt_void_script  :1;  //script is voided
	unsigned char opt_return_script:1;  //script is returned
    unsigned char opt_nu7          :5;      
	unsigned char org_pos_no;           //offset 28  
    
	unsigned char	seq_no;				//29	Script sequence #
	unsigned char   script_no4[4];      //30 BCD
    unsigned char	nu[10];				//34


    struct   trans_tail_  tail;         //offset 44
};

/* Payment info transaction for script */
struct  trs_info_script_paym_
{
    unsigned char opcode;             	//offset 0 opcode  0x60	<Opcode Value="0x60"/>
    unsigned char function;           	//offset 1 function 0xD6	<Opcode Value="0xD6"/>
	unsigned char sub_func;			    //2	1-inf1 2-inf2	
   
	union
    {
		struct 
		{
			unsigned char status;               //offset 3  - Status of prescription:
					                            //   0 - uncommitted
							                    //   1 - commited
			unsigned char surname[18];          //offset 4  - Patient's surname
			unsigned char patient_no[3];        //offset 22 BCD - Patient's number
			unsigned char script_no[3];         //offset 25 BCD

			unsigned char opt_void_script  :1;  //offset 28 script is voided
			unsigned char opt_rtrn_script  :1;  //script is returned
			unsigned char opt_offln_script :1;  //not found script indicator  // Pharmacy_SA
			unsigned char opt_auto_charge:1;//		auto-charge scrpt cr#3281	
			unsigned char opt_void_ret_com:1;//28	void of a returned committed script
			unsigned char opt_nu7          :3;  //not used

		    unsigned char commited_date[3];     //offset 29, date script commited from QDX // Pharmacy_SA
			unsigned long offline_script_no;    //offset 32, offline script number (max 8 digits).

			unsigned char seq_no;			//36
			unsigned char script_no4[4];	//37	BCD
			unsigned char	nu[2];			//41
		}inf1;

    	struct 
		{
			unsigned char drug_desc[14];        //offset 3  - Drug description	                                    
			unsigned char strength[10];         //offset 17 - Strength of drug
			long price;                         //offset 27 - Price of drug
			unsigned char tax_code;             //offset 31 - Tax-code
						
			unsigned char seq_no;				//32
			unsigned char nu[10];				//33	not used
		}inf2;
    };

	unsigned char opt_plu	:1;				//43	script sold as plu cr#3040
	unsigned char opt_void  :1;				//43	script voided
	unsigned char opt_rev_sold_upd_PO:1;	//43	Automatic reversal of a script that was sold after update from PO
	unsigned char opt_nu	:5;				//43	not used

    struct   trans_tail_  tail;         //offset 44
};

//FS1064
/* Barcode Programming info transaction */
struct trs_info_barcode_details_
{
    unsigned char opcode;             		//offset 0 - opcode 0x60	<Opcode Value="0x60"/>
    unsigned char function;           		//offset 1 - function 0xD9	<Opcode Value="0xD9"/>
   
	unsigned char type;						//offset 2  - Barcode Type:
											//   0 - PLU
											//   1 - Tender	                                   
											//   2 - Department
											//   3 - Promotion	                                   
											//   4 - Loyalty
											//   5 - Points	                                   
											//   6 - Segment
											//   7 - Save\Recall	                                   
											//   8 - Utility
	unsigned char barcode_len;				//offset 3 - Barcode length
	struct									//ofsset 4
	{
		unsigned char opt_scan         :1;
		unsigned char opt_key_entered  :1;
		unsigned char opt_ignore       :1;	//FSD11575
		unsigned char bProduced        :1;	//FSD18888
		unsigned char bValidated       :1;	//FSD18888
		unsigned char bCatalinaCoupon  :1;	//FSD19167 (FSD25612)
		unsigned char bCouponRejected  :1;	//FSD19167 (FSD25612)
		unsigned char opt_cancel	   :1;	
	}Options;

	unsigned char barcode[30];				//offset 5  BCD - Barcode buffer (right justify, leading zeroes)
	unsigned char uchUniqueKeyIdentifier;	//offset 35	FSD11575
	unsigned long ulBarcodeValue;           //offset 36 FSD25612
	unsigned char uchSubType;				//offset 40	FSD39663 - Storeline Parking Validation
	unsigned short ushBarcodeLineTemplateNo;//offset 41	FSD39663 - Storeline Parking Validation
	
	unsigned char bParkingVoucher		:1; //offset 43 FSD39663
	unsigned char bSaleFailure			:1; //offset 43 FSD#59750
	unsigned char bExtensionTrsUsed		:1;
	unsigned char bCouponConditionalOverride	:1;		//offset 43  FSD#139444
	unsigned char bLinkedToDataBar		:1;				//offset 43 FSD309681
	unsigned char bExtensionTrsExists	:1;				//offset 43 FSD438581
	unsigned char bAreaScaleItem		:1;				//offset 43 FSD439698
	unsigned char nu					:1;	//offset 43

    struct   trans_tail_  tail;				//offset 44
};


/*----------------------------------------------------------------------
TRANS_INFO3_LOAD_BARCODE_TO_DB
Opcode:		0x80
Subopcode:	0x07
FSD67534
Load Barcode to DB info transaction 
-----------------------------------------------------------------------*/
struct trs_info3_load_barcode_to_DB_
{
    unsigned char opcode;             		//0 - opcode 0x80	<Opcode Value="0x80"/>
    unsigned char function;           		//1 - function 0x07	<Opcode Value="0x07"/>
	long lQty;								//2
	unsigned char type;						//6 - Barcode Type: currently support only PLU (0)
											//   0 - PLU
											//   1 - Tender	                                   
											//   2 - Department
											//   3 - Promotion	                                   
											//   4 - Loyalty
											//   5 - Points	                                   
											//   6 - Segment
											//   7 - Save\Recall	                                   
											//   8 - Utility

	unsigned char bLoadBarcodeToDB		:1;	//7
	unsigned char nu					:7;	
	unsigned char barcode[30];				//8  BCD - Barcode buffer (right justify, leading zeroes)

	unsigned char nu_1[6];					//38
    struct   trans_tail_  tail;				//offset 44
};

/*----------------------------------------------------------------------
TRANS_INFO3_ANPR_DATA
Opcode:		0x80
Subopcode:	0x08
FSD67534
Save ANPR data to transaction
-----------------------------------------------------------------------*/
struct trs_info3_ANPR_Data_
{
    unsigned char opcode;             		//0 - opcode 0x80	<Opcode Value="0x80"/>
    unsigned char function;           		//1 - function 0x08	<Opcode Value="0x08"/>
	char szRegistrationNumber[7];			//2
	char szANPRTransactionNumber[5];		//9
	unsigned char nu1[30];					//14
	struct   trans_tail_  tail;				//offset 44
};

//Enh #10812 Signature Capture AmyG
struct trs_sigcap_hdr_
{
    unsigned char opcode;			//0x60	<Opcode Value="0x60"/>
    unsigned char function;			//0xDC	<Opcode Value="0xDC"/>
	unsigned char sub_func;			//0x01 Header record	<Opcode Value="0x01"/>

	short buffer_type;				//1=MTX; 2=INGENICO (2 byte BIN)
	short unzipped_buffer_size;
	short num_of_sigcap_seq;
	unsigned char nu1[35];

    struct   trans_tail_  tail;
};

//Enh #10812 Signature Capture AmyG
struct trs_sigcap_data_
{
    unsigned char opcode;			//0x60	<Opcode Value="0x60"/>
    unsigned char function;			//0xDC	<Opcode Value="0xDC"/>
	unsigned char sub_func;			//0x02 Data record	<Opcode Value="0x02"/>

	unsigned char seq_no;			//bcd 0x00 to 0x99
	unsigned char data[40];

    struct   trans_tail_  tail;
};

/*----------------------------------------------------------------------
Opcode:		0x60 
Subopcode:	0xE0
customer order status record
-----------------------------------------------------------------------*/
struct trs_info_order_status_               //OFS	Description
{
    unsigned char opcode;       		    //0     0x60	<Opcode Value="0x06"/>
	unsigned char function;		   		    //1		0xE0	<Opcode Value="0xE0"/>
	unsigned char sub_function;             //		1-order header status	<Opcode Value="0x01-0x02"/>
	                                        //		2-item line status

	unsigned char order_number[5];          //3   	Order number
	unsigned char order_reference_number[5];//8     Customer ref no.
 	unsigned char order_date[3];            //13	Order date
	unsigned char error_code; 		        //16	Error table(errors 1-255)
 
	union									//17
	{
		struct                              //17	Order header status 
		{
			unsigned char customer_no[10];  //17    Customer number      	             		
			unsigned char error_data[7];   //27    Error data
			unsigned char  inv_no[8];		//34    Invoice number
			unsigned char  order_status;    //42    0 - Successful
			                                //      1 - Errors during process 
		}inf1;								//43

		struct                              //17	Item line status
		{
			unsigned char  plu_no[7];       //17	Item code
			unsigned char  nu[19];          //24	not used
		}inf2;								//43
    };	

    unsigned char  CustOrderOnTill	  :1; //43	CR19916
	unsigned char bWebPaymentError    :1;   //43    Not used
    unsigned char bWebPaymentDenial   :1;
    unsigned char bOrderLocked        :1;
	unsigned char not_used            :4; 

	struct   trans_tail_  tail;				//44	TRS tail
};											//64

struct trs_info_ticket_points_
{
	unsigned char opcode;    //0x60                 //0	<Opcode Value="0x60"/>
	unsigned char function;  //0xDA                 //1	<Opcode Value="0xDA"/>

	long prom_no;                                   //2
	long points;								    //6
	unsigned char redeeming_fg;                     //10

	unsigned char reserved[33];                     //11
	
	struct   trans_tail_  tail;                     //44
};

struct trs_info_service_desk_vchr_
{
	unsigned char   opcode;    //0x60                 //0	<Opcode Value="0x60"/>
	unsigned char   function;  //0xDB                 //1	<Opcode Value="0xDB"/>

	unsigned char   plu_code[7];					  //2		plu number (BCD)
	unsigned short  dept;				           	  //9		Department number
	long            points;							  //11      Points accum to voucher.(sorry voucher)
	long            tender_amt;						  //15      Amount accum to tender voucher - bon avoir
	unsigned char   pts_return_type;                  //19      return type of points voucher (sorry voucher)
	unsigned char   tndr_return_type;                 //20      return type of tender voucher-bon avoir
	unsigned char   reason_code;                      //21      reason code of points voucher(sorry voucher)
	unsigned char   trs_type;                         //22      The type of the trs TENDER/POINTS/TENDER AND POINTS....

	unsigned char   opt_cancel			:1;           //23
	unsigned char   opt_was_cancel		:1;
	unsigned char   nu					:6;

	unsigned char   reserved[20];                     //24      To be filled.
	struct          trans_tail_  tail;                //44
};


// new seq type defines
#define NEW_SEQ_AFTER_EOD			1
#define NEW_SEQ_AFTER_COLD_START	2
#define NEW_SEQ_AFTER_RESET_TRS		3

struct trs_new_seq_num_ // FS1079
{
    unsigned char opcode;       		// TRANS_NEW_SEQ_NUM 0xB0 // TRC	<Opcode Value="0xB0"/>
	unsigned char type;          // 1   see list above
	unsigned char data[42];		 // 2
	struct   trans_tail_  tail;	 // 44						
};


struct trs_info_order_number_ 
{
    unsigned char opcode;       		// 0x60	<Opcode Value="0x60"/>
	unsigned char function;             // 0xDD	<Opcode Value="0xDD"/>
	unsigned char order_no[6];          // 2 	
	unsigned char sExtendedID[10];		// 8  order id, FSD5123
	unsigned char uchSeq;               // 18 - sequence of the transaction (1,2,3 etc Due to the fact that several order numbers will be sent in  a ticket..
	unsigned char sAdditionalID[10];		// 19 -FSD34074
	unsigned char not_used[13];		    // 29

	unsigned char bIgnore		:1;		// 42 ignore flag (for cancel home delivery/parcel pickup) 
	unsigned char bNU			:7;		// 
	unsigned char orderType;			// 43 order type, 1 - HOME_DELIVERY 
										//				  2 - PARCEL_PICKUP (FSD5123)
	struct   trans_tail_  tail;	        // 44						
};

struct trs_info_price_list_id_ 
{
    unsigned char opcode;       		// 0x60	<Opcode Value="0x60"/>
	unsigned char function;             // 0xDE	<Opcode Value="0xDE"/>
	unsigned short PriceListID;         // 2     
	unsigned char  Source;              // 4 (1 - from check out bank : 2 - from customer scheme) 
	unsigned char not_used[39];		    // 5
	struct   trans_tail_  tail;	        // 44						
};


//------------------------------------------------
//FS1081
struct trs_info_cust_acct_ID_
{
    unsigned char opcode;            //0x60   //0	<Opcode Value="0x60"/>
    unsigned char function;          //0xDF   //1	<Opcode Value="0xDF"/>

    unsigned char acct_num[10];      //BCD    //2

	long  accout_limit;                       //12
	unsigned char acct_pay_type;              //16

	//flags
	unsigned char loyalty_related                :1;     //17
	unsigned char offline                        :1;     //17
	unsigned char force_account                  :1;     //17
	unsigned char charge_ctrl_per_item           :1;     //17
	unsigned char offline_acct_as_cash_only      :1;     //17
	unsigned char bVoidCustAccnt                 :1;     //17 //FSD16729 Void Customer Account
	unsigned char bNextAppearanceNoticeDislpayed :1;     //17  FSD 18554
	unsigned char bMCRUsed                       :1;     //17   FSD43007

	long prv_balance;                          //18
	unsigned short pospond_pay_period;         //22
	unsigned char surcharge_type;              //24
	long          surcharge_rate;              //25
	unsigned char uchCustType;                 //29
	unsigned char uchSchemeNo;                 //30  //FS3938 Member Scheme number from barcode definition

	long          lCustAccntSurchRate;         //31  //FSD16729 Percentage from Reward enter by Cashier promotion ('Extra reward from customer account' type).
    unsigned long ulDiscountPercentage;		   //35	 //Defect #26776
	long		  lPlannedAmount;			   //39  TD#63158

	unsigned char bRecalculateCustomerData		:1; //43  //FSD278923 C&C Invoice Payment at POS Avivp , for recalculating customer debt
	unsigned char unusedBits					:7;	//43

    struct   trans_tail_  tail;                //44
};

//FDC;CR15968FS
struct trs_info_fuel_disc_cpn_
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60"/>
	unsigned char function;    //0xE1	<Opcode Value="0xE1"/>

	short			RebateFileID;		//2
	long			IDReference;		//4
	unsigned char	QID;				//8
	unsigned char	RebateNumber[3];	//9		BCD; pak/unpak
	unsigned char	RebateExpDate[3];	//12	BCD; pak/unpak
	long			RebateQAmount;		//15
	unsigned short	RebateDiscount;		//19
	long			TransTotal;			//21

	unsigned short	error_code;			//25	1 - error code, 0 - OK

	unsigned char	optFromFuelPromo	:1;	//27
	unsigned char	optNotUsed			:7;	//27

	unsigned short	days;					//28

	unsigned char   nu[14];					//30

	struct   trans_tail_  tail;
};

//--------------------------------
//FS1081
struct trs_info_cust_acct_tendering_
{
    unsigned char opcode;            //0x60   //0	<Opcode Value="0x60"/>
    unsigned char function;          //0xE5   //1	<Opcode Value="0xE5"/>
	unsigned char sub_function;      //0xEF   //2  //	
	                                              // 1- account_charge
	                                              // 2-account payment
												  // 3-account reversal.
												  // 4-Authorized over limit
												  // 5-Payment Cheque

												  // FSD24617
												  // 6-Charge Planned
												  // 7-Transfer from Planned to Used
												  // 8-Reduce Planned

    unsigned char acct_num[10];      //BCD    //3
    long payment_amt;                         //13
	unsigned char tender_due_day;             //17
	unsigned char tender_due_month;             //18
	unsigned short tender_due_year;             //19

	unsigned char uchAcctPaymDocSource;			//21	FSD 18556 , document issued entity
															//0 - POS
															//1 - FO
	unsigned char uchAcctPaymDocType[2];		//22	FSD 18556 , account payment doc TYPE
	unsigned char uchPosNum;					//24	FSD 18556 - The doc issued pos number
	unsigned char bcdAcctPaymDocID[6];			//25	FSD 18556 , BCD account payment doc ID

    unsigned char bEntrySource			:1;		//31 OmerC used by FO only
	unsigned char bNU					:7;		//31

	long lOriginalPaymentAmt;					//32 // TD#37861 GinatB - Save original amount in TRANS_INFO_CUST_ACCT_TENDERING
	
	unsigned char reserved[8];	                //36

    struct   trans_tail_  tail;            //44
};

//FS1094
struct trs_info_barcode_coupon_
{
    unsigned char opcode;			//0x60   //0	<Opcode Value="0x60"/>
    unsigned char function;         //0xE6   //1	<Opcode Value="0xE6"/>
	
	unsigned char code[7];			//BCD    //2
	unsigned char org_code[7];		//BCD    //9
    long count;                              //16
	long prom_no;                            //20
	
	short reward;							 //24 //FS5006
	
	unsigned char uchReceiptSeperation;		 //26 FSD11024 for reciept cut indication
	
	unsigned char reserved[17];              //27


    struct   trans_tail_  tail;              //44
};

//Enh #13271: Needed for Hannaford offline tender report. AmyG
struct trs_info_offline_eft_				//OFS	Description
{
    unsigned char opcode;					//0x60	//0	<Opcode Value="0x60"/>
    unsigned char function;					//0xE7	//1	<Opcode Value="0xE7"/>

    unsigned short  no;						//2		Tender number

    unsigned char opt_offline_credit   :1;	//4		
    unsigned char opt_offline_EBT      :1;	//4
    unsigned char opt_nu		       :6;	//4	

    unsigned char account[10];				//5		Account number
    unsigned char exp_date[2];				//15	Expiry date
    long          amount;					//17	Tender amount or cashback
    unsigned char auth_no[4];				//21	Authorization number
	unsigned char EBT_Voucher_No[11];		//25	EBT voucher no
    unsigned char account_len;				//36
    unsigned char auth_no_len			:4;	//37
	unsigned char len_nu				:4;

    unsigned char nu[6];					//38
    
    struct   trans_tail_  tail;				//44	Transaction tail
};

//FS1085
struct trs_info_pos_report_
{
    unsigned char opcode;			//0x60   //0	<Opcode Value="0x60"/>
    unsigned char function;         //0xE8   //1	<Opcode Value="0xE8"/>

	short          store_no;                 //2
	short          pos_no;                   //4
	unsigned long  ulLongStoreNumber;        //6 FSD63030
	unsigned char  filler[2];                //10
	unsigned short z_count;                  //12
	long           sales;                    //14
	long           discounts;				 //18
	long           gross_taking;             //22
	unsigned long  security_number;          //26
	unsigned char  report_mode;              //30 (0=x,1=z)
	unsigned char  eod_date[3];              //31 BCD
	unsigned char  nwd_date[3];              //34 BCD
	long		   promotions;               //37
		
	unsigned char  reserved[3];              //41

    struct   trans_tail_  tail;              //44
};
//FS1088
struct trs_info_invoice_header_
{
    unsigned char opcode;            //0x60   //0	<Opcode Value="0x60"/>
    unsigned char function;          //0xEB   //1	<Opcode Value="0xEB"/>
	unsigned char sub_function;      //       //2 For future use.
	unsigned char count;             //       //3 //The total number of transactions.
	unsigned char sequence;          //       //4 //The sequence of the trs in thw queue of the sent transactions.(Start from 1 end at count).                                              
    unsigned char info[39];                   //5 //Invoice header data in sequences.

    struct   trans_tail_  tail;               //44
};

// FSD70780
struct trs_document_
{
	unsigned char  opcode;            //0x80	//0	
    unsigned char  function;          //0x0f	//1	
	unsigned char  sub_opcode;					//2		0 = document details trns
												//		1 = document ticket trns
	
	unsigned short ushDocType;					//3 

	unsigned char  BCDDocumentID[8];			//5
	
	
	union										//13
	{
		struct									//13
		{
			unsigned char BCDReferenceNumber[10];			//13
			long lAmount;									//23	//Changed by Avivp for negative value
			unsigned char uchStatus;						//27
																 // 0 - DOC_AVAILABLE_STATUS_FOR_UPDATE_PROCESS_NONE
																 // 1 - DOC_AVAILABLE_STATUS_FOR_UPDATE_PROCESS_OPEN
																 // 2 - DOC_AVAILABLE_STATUS_FOR_UPDATE_PROCESS_CLOSE
			unsigned char uchSource;						//28
																 // 0 - POS
																 // 1 - FO
			unsigned long ulUserId;							//29        

			unsigned char sFillerDocumentInsertData[11];	//33
			
		}DocumentInsertData;
		
		struct												//13
		{
			unsigned char  BCDOriginalDate[3];				//13
			unsigned short ushOriginalPosNo;				//16
			unsigned long  ulOriginalTicketNo;				//18

			unsigned char sFillerLinkedTicketData[22];	//22
			
		}LinkedTicketData;

		
		struct												//13
		{
			unsigned char  uchLinkedType;					//13 
			unsigned short ushLinkedDocType;				//14
			unsigned char  BCDLinkedDocumentID[8];			//16
			
			unsigned char sFillerLinkedTicketData[20];		//24
			
		}LinkedDocumentData;
		struct												//13
		{
			unsigned char  uchFieldId;						//13 
			unsigned char  uchFieldType;					//14
			
			union 
			{
				struct 
				{
					long lLongValue;						//15
					unsigned char uchLongFiller[25];		//19

				}LongField;
				
				struct 
				{
					unsigned char uchTextBuffer[29];		//15

				}TextField;
				
			}FieldData;
			
			
		}UpdateDocumentData;
	}TransactionData;


	struct   trans_tail_  tail;               //44
};


//FS1088
struct trs_info_document_seq_
{
    unsigned char opcode;            //0x60   //0	<Opcode Value="0x60"/>
    unsigned char function;          //0xEC   //1	<Opcode Value="0xEC"/>
	unsigned char sub_opcode;                 //2 // 0- DOCUMENT DATA   (for recover).
	                                              // 1 - Sequence update.
	unsigned short ushDocType;                 //3 The document type.
	unsigned long  ulSequence;                 //5 The document sequence.                                   
	unsigned char  bPostVoid            :1;    //9 //Indicated the type of the seq.Should be ignored if sub opcode 0. 
	unsigned char  bMaintainSeq         :1;    //9 //Work with sequences. valid only for sub opcode 0.
	unsigned char  bAllowAdjustments    :1;    //9 //FS3199 - Allow adjustments after retrieve invoice.
    unsigned char  bRetrieveTrans       :1;    //9 //FS3199 - Retrieve order
	unsigned char  bDocReplaceTicket    :1;    //9 //FSD3788
	unsigned char  bDocSelectedFromKey  :1;    //9 //FSD3788
	unsigned char  bPrintDocToPrintLocation	:1;	//9 FSD30682
	unsigned char  unused               :1;


	unsigned char  uchTransType;                //10   0 - sale.   For subopcode 0.
											         //1 - Return.
	                                                 //2 - Tender.
	unsigned char  uchLinkedRtnType;            //11  
	unsigned char  uchPosTndrFunc;              //12   0 - None
	                                            //     1 - Account payment.
												//     2 - Account reversal.
	unsigned short ushFixedTndr;                //13  .

	unsigned char sCshrDispDesc[12];                 //15

	unsigned char uchPosMenuTenderState;       //27 FS3199
	unsigned char uchPrintingOption;           //28 FS3199

	unsigned char uchPrintLocationID;	//29 FSD39682
	
	unsigned char uchDeadLine[3];		//30 FSD40471 - DeadLine Date in BCD

	unsigned char uchPrinterNo;			//33	#50377		
	unsigned char uchPrintType;			//34	#50377			

	unsigned long ulAutomaticLocalSegment1;	// 35  FSD#96110
	unsigned long ulAutomaticLocalSegment2;	// 39  FSD#96110

	unsigned char filler[1];				   //43 FS3199
	
    struct   trans_tail_  tail;                //44
};

typedef enum trs_reason_code 
{ 
	eNone = -1,
	eReturn_item,
	eReturn_trs,
};


//FS1115 
struct trs_info_reason_code_
{
    unsigned char opcode;            //0x60   //0	<Opcode Value="0x60"/>
    unsigned char function;          //0xED   //1	<Opcode Value="0xED"/>
	unsigned char type;              //       //2  Reason code type (movement or return)
	
	unsigned short reason_id;        //       //3
	unsigned char description[16];   //       //5
    unsigned char bPostMovReason     :1;       //21//Indication this is a post movment reason.
	unsigned char bMovmentReason     :1;       //21//Indication this is a movment reason.
	unsigned char bCancelSubtrItem   :1;       //21//Bug21971:Flag is for cancel/subtract item
	unsigned char bSelectReasonCode :1;     //21//FSD#455024 bSelectReasonCode for recover indication
	unsigned char bNU     :4;                  //21//Not used
	unsigned short shResControlCheckContext ;  //22 CR N#852
	unsigned char uchItemMessageDecision;	   //24	//FSD234928
    unsigned char not_used[19];      //       //25
  
    struct   trans_tail_  tail;               //44
};

/* ROW Confectionary #19636 */
#ifdef PRJ_ROW
struct trs_info_trade_prom_calc_ 
{
    unsigned char opcode;             //0x60   // offset 0 <Opcode Value="0x60"/>
    unsigned char function;           //0xEE   // offset 1 <Opcode Value="0xEE"/>
		
    unsigned char plu_code[7];                 // offset 2					
 
    long lTradeDiscount;             // trade discount value           // offset 9
    long lPromDiscount;	             // promotional discount value     // offset 13
	long lTaxInclTradeDisc;          // tax amt incl. into trd.disc    // offset 17
	long lTaxInclPromDisc;           // tax.amt incl. into prom.dsc    // offser 21
	long lTradeDiscPercent;          // trade disc. percent            // offset 25
	long lTaxInclBasePrice;          // tax amt incl.into base prc     // offset 29
	long lBasePrice;                 // base price inclusive GST       // offset 33
   							
    unsigned char filler[7];		 // offset 37
    struct   trans_tail_  tail;		 // offset 44			
};
#endif

//FS1117
struct trs_info_reduce_tax_scheme_
{
	unsigned char opcode;            //0x60   //0	<Opcode Value="0x60"/>
	unsigned char function;          //0xEE   //1	<Opcode Value="0xEE"/>
	unsigned char source;            //       //2  source of selection: (1 - check out bank : 2 - customer scheme : 3 - manual selection) 
	unsigned char scheme_id;         //       //3
	unsigned char description[16];   //       //4
	unsigned char table[15];         //       //20 MAX_TAX
	unsigned char not_used[9];       //       //35 
	
	struct   trans_tail_  tail;               //44
};

// Versions control in POS
struct trs_wrong_version_alert_
{
    unsigned char opcode;         //0x63	// 0	
    
    unsigned short  subopcode;				// 1
    unsigned char function;					// 3

	//
	unsigned char component_name[22];		// 4
	unsigned short expected_ver[4];			// 26		
    unsigned short actual_ver[4];			// 34

    unsigned char pos_no;					// 42
    unsigned char pc_no;					// 43

    struct   trans_tail_  tail;             // 44
};
//FS1126
struct trs_info_cust_center_
{
    unsigned char opcode;            //0x60   //0	<Opcode Value="0x60"/>
    unsigned char function;          //0xF0   //1	<Opcode Value="0xF0"/>
	unsigned char sID[10];           //       //2  Customer center ID in BCD.

    unsigned char bNewEntry		:1;	 //        //12  //New Number
    unsigned char bGenerated	:1;  //       //12  //Generated number.
	unsigned char bVoidCustCntr :1; //        //12  //FSD16729 Void Customer Account
	unsigned char bNU           :5;  //       //12  

	unsigned char loyaltySchemeID;			  //13	//FSD3938
	unsigned char uchControlCheck;			  //14  //FSD5189
	unsigned short ushSegment;				  //15  //FSD5189
	unsigned char  uchIDLen;				  //17, length of sID in unpacked format
    unsigned char not_used[26];		          //18 

    struct   trans_tail_  tail;               //44
};
//FS1126
struct trs_info_cust_address_
{
    unsigned char opcode;            //0x60   //0	<Opcode Value="0x60"/>
    unsigned char function;          //0xF1   //1	<Opcode Value="0xF1"/>
	unsigned char uchSeq;           //       //2  Address sequence (1-99)
	unsigned char bDeliveryAddress   :1;	//3		
    unsigned char bMainAddress       :1;	//3
	unsigned char bVoidCustCntr      :1;    //3   FSD16729 Void Customer Account
	unsigned char bUpdateAddress	 :1;	//3:3 FSD34074	
	unsigned char bBillingAddress	 :1;	//3	  FSD240285
    unsigned char opt_nu		     :3;	//3
	unsigned char uchSource;                //4
	unsigned char sCustCntrID[10];          //5  BCD the owner customer center.

    unsigned char not_used[29];      //       //5 

    struct   trans_tail_  tail;               //44
};

struct trs_info_tender_additional_
{
    unsigned char opcode;            //0x60   //0	<Opcode Value="0x60"/>
    unsigned char function;          //0xF2   //1	<Opcode Value="0xF2"/>
    unsigned char subFunction;       //       //2   0-comments.
									//              1 - First data
	                                //              2 - Second data
	                                //              3 - Third data.

	union
	{
		struct
		{
			unsigned char sCheque[10]; //3
			unsigned char sBranch[20]; //13
			unsigned char uchBankCode;  //33      
			unsigned char uchCompanyCode;//34
			unsigned char uchTndrDueDay;     //35        
			unsigned char uchTndrDueMonth;       //36      
			unsigned short ushTndrDueYear;           //37  

			unsigned char sFiller[5];//39
			
		}FirstData;
		struct
		{
			unsigned char sIssuerBankName[20]; //3
			unsigned char sIssuerAccount[10];  //23
			unsigned char sFiller[8];

			
		}SecondData;
		struct
		{
			
			unsigned char sIssuerName[35];
			unsigned long ulVatID;
			unsigned char sFiller[2];
			
		}ThirdData;
		struct  //# 96102
		{
			unsigned char sIssuerAccount[30];  //3
			unsigned char sFiller[11];

			
		}FourthData;
		unsigned char sComments[41];
	}data;

    struct   trans_tail_  tail;               //44
};

// FS15934
struct trs_info_online_purchase_item_
{
	unsigned char opcode;    //0x60					//0	<Opcode Value="0x60"/>
	unsigned char function;  //0xF3					//1	<Opcode Value="0xF3"/> TRANS_INFO_ONLINE_PURCHASE_ITEM

	unsigned char plu_code[7];						//2 
    unsigned short SessionId;						//9
    struct flags_  									//11							
    {
		unsigned char card_swiped				:1;
        unsigned char auth_succeed				:1;
		unsigned char auth_failed				:1;
		unsigned char auth_timeout				:1;
        unsigned char void_without_auth			:1;  //nu
		unsigned char void_after_auth			:1;   
		unsigned char bBillPayment				:1;  //FS4002 
		unsigned char bPinSerialNum_ext_trans	:1;  //N#6755 pin serial number bigger than 15 chars get in extra trans
	}flags;
	unsigned short SchemeId;						//12
	unsigned char  AllowedReversal;					//14
	unsigned char ApplicationOption;				//15
	unsigned char AccountNum[10];					//16 
	unsigned char PinSerialNum[15];					//26
	unsigned char uchAuthConfUsed;					//41				  	
    
    unsigned char bNeedTenderValidation			:1; //42 FSD7315
    unsigned char bTenderValidationSucceed		:1; //42
	unsigned char bTenderValidationFailed		:1; //42
	unsigned char bVoidBeforeTenderValidation	:1; //42
	unsigned char bVoidAfterTenderValidation	:1; //42
	unsigned char void_after_timeout			:1; //42 FSD14337
	unsigned char bPinSn_is_BCD					:1;	//42
	unsigned char bExtendedAlphaNumPinSerialNum	:1; //42

	struct flags2_
	{
		unsigned char bTemplatePrintingSucceeded:1; //43 FSD14337
		unsigned char bTemplatePrintingFailed	:1; //43 FSD14337
		unsigned char bConfirmationSucceeded	:1; //43 FSD14337
		unsigned char bConfirmationFailed		:1; //43 FSD14337
		unsigned char bConfirmationTimeout		:1; //43 FSD14337
		unsigned char bAbortSucceeded			:1; //43 FSD14337
		unsigned char bAbortFailed				:1; //43 FSD14337
		unsigned char bAbortTimeout				:1; //43 FSD14337
	}flags2;
	                                          
	struct   trans_tail_  tail;               //44
};


/* Bill Payment CR #22761 */
struct trans_info_bill_payment_
{
    unsigned char opcode;             //0x60   // offset 0	<Opcode Value="0x60"/>
    unsigned char function;           //0xFA   // offset 1	<Opcode Value="0xFA"/>
		
    unsigned char sPluCode[7];        // offset 2					
 
    char sBarcode[13];                // offset 9 ,  Scanned barcode
    long lPaymentAmount;	          // offset 22,  Sell Amount
	struct flags                      // offset 26,  Flags
	{
		unsigned char bVoidItem   :1;		
		unsigned char nu          :7;
	}Flags;

    unsigned char sFiller[17];		 // offset 27    Not Used				   	

    struct   trans_tail_  tail;		 // offset 44		
};

struct trs_info_lay_by_
{
	unsigned char opcode;                  //0x60	<Opcode Value="0x60"/>
	unsigned char function;                //0xFB	<Opcode Value="0xFB"/>

	unsigned char bcdLayByID[10];          // offset 2
	unsigned char uchLayByStatus;          // offset 12
	unsigned char bcdLayByPaymDate[3];     // offset 13
	long lPaymentAmount;                   // offset 16
	long lTotalLayByAmount;                // offset 20
    unsigned char uchTtlPaymentNumber;     // offset 24
	unsigned char uchTtlPaymentFrequency;  // offset 25
	unsigned short ushDepositPercent;      // offset 26
	long lCancelFee;					   // offset 28 Cancellation Fee value

	unsigned char bOptVoidLayBy			:1;     // offset 32 Lay by is voided	
	unsigned char bOptWasCancelled		:1;     // offset 32 Lay by was voided
	unsigned char bMultiLayByAccounts	:1;
    unsigned char opt_nu7				:5;      

#ifdef PRJ_PRICELINE
	long lOutstanding;						//33	Outstanding amount
	unsigned char Filler[7];				//37
#else
	unsigned char bcdCustomerID[7];		   // offset 33
	short shSequenceNumber;				   // offset 40	
	unsigned char Filler[2];               // offset 42 
#endif

	struct trans_tail_ tail;               // offset 44
};

struct trs_online_info_lay_by_
{
	unsigned char opcode;                  //0x60	<Opcode Value="0x60"/>
	unsigned char function;                //0xFC	<Opcode Value="0xFC"/>
	
	unsigned char bcdLayByID[10];          // offset 2
	unsigned char bcdLayByStartDate[3];    // offset 12

	unsigned char bUseOrgPosNo     :1;	   // offset 15
  	unsigned char bOptVoidLayBy    :1;     // Lay by is voided	
    unsigned char opt_nu6          :6;      
	unsigned char uchOrgPosNo;             // offset 16

	unsigned char	nu[27];				   // offset 17
	struct trans_tail_ tail;               // offset 44
};

//FS18285
struct trs_info_order_prom_apport_
{
    unsigned char opcode;         //0x60	//0			<Opcode Value="0x60"/>
    unsigned char function;       //0xF6	//1			<Opcode Value="0xF6"/>

    unsigned char first			:1;			//2
    unsigned char last			:1;
	unsigned char nu02			:1;
    unsigned char nu03			:1;
	unsigned char nu04			:1;
	unsigned char nu05			:1;
	unsigned char nu06			:1;
	unsigned char nu07			:1;
    
    long  promotion_no;						//3

	struct									//7
	{
		unsigned char dep			:1;
		unsigned char nu09			:1;
		unsigned char nu10			:1;
		unsigned char nu11			:1;
		unsigned char nu12			:1;
		unsigned char nu13			:1;
		unsigned char nu14			:1;
		unsigned char nu15			:1;

		unsigned char code[7];
		long          apportionment_amount;
	}item[3];
    
    unsigned char reserved[1];				//43

    struct   trans_tail_  tail;
};


// EFT transactions waiting to be sent to bank
struct trs_manualy_settlement_
{
    unsigned char opcode;         //0x70	//0	<Opcode Value="0x70"/>
    unsigned char function;       //0x01	//1	<Opcode Value="0x01"/>

	unsigned char chEftPaymentStatus;	// 2
                                        // manual settlement - offline transaction record status
                                        //#define WAIT_FOR_TRANSMIT		    0
                                        //#define RECORD_SENT			    1
                                        //#define TRANSMITION_FAILED	    2
                                        //#define MANUALY_SENT			    3   //#23683 - changed to 3.
                                        //#define WAIT_FOR_AUTHORIZATION	4
                                        //#define READY_FOR_TRANSMIT
	unsigned short	usTransactionNumber;// 3
	unsigned short	usSessionId;		// 5
	unsigned char	TrsDate[3];   // 7  YMD
	unsigned char	TrsTime[3];   // 10  HMS
	unsigned char	CardNumber[10]; // 13 card no in BCD

    unsigned char	ExpiryDate[2];	// 23 Expiry date
    unsigned char	AuthNumber[4];  // 25 Authorization number in BCD
	unsigned char	IssueNumber;	// 29

	unsigned char   AccountType;	// 30
	unsigned char   TransactionType;// 31

	long	lPurchaseAmount;		// 32
	long	lTotalAmount;			// 36

	unsigned char	uchTndr;    	// 40  //The tender the transaction was finilized with (manual)
	unsigned char	uchPosNumber;	// 41
	unsigned char	ErrorCode[2];	// 42

    struct   trans_tail_  tail;
};


//FS19041
struct trs_info_form_
{
    unsigned char  opcode;         //0x60	//0	<Opcode Value="0x60"/>
    unsigned char  function;       //0xF8	//1	<Opcode Value="0xF8"/>

    unsigned char  form_id[3];				//2
	unsigned char  type;					//5
	unsigned char  data_entry_type;			//6
	unsigned char  data_input[32];			//7
	unsigned short code_input;				//39
	unsigned char  trans_processing_type;	//41  //FS3788
	unsigned char  date_type;				//42  //FS3788
    
    unsigned char sub_type;					//43  //#15639

    struct   trans_tail_  tail;
};

//FSD52912 - Extension for pos_form return type
struct trs_info2_form_ext_
{
    unsigned char  opcode;         //0x70	//0	<Opcode Value="0x70"/>
    unsigned char  function;       //0xEA	//1	<Opcode Value="0xEA"/>

    unsigned char  uchReturnType;			//2
	
	unsigned char  bVoided			:1;		//3
	unsigned char  bBelongsToPlu	:1;		//3 FSD75184
	unsigned char  bRefundCustDetails:1;	//3 FSD397810: WOW prompt for customer details after refund
	unsigned char  flags_nu			:5;		//3
    
    unsigned char uchPosFormExt_NU[40];		//4  

    struct   trans_tail_  tail;
};

//FS18338
struct trs_info_denomination_
{
	unsigned char  opcode;         //0x60	//0	<Opcode Value="0x60"/>
    unsigned char  function;       //0xFF	//1	<Opcode Value="0xFF"/>

    unsigned short denomination_id;			//2
	unsigned short tender_id;				//4
	long amount;							//6
	long count;								//10
	//#52848 - New cash office type are added
	unsigned char cash_office_type;			//14 1=declare,2=float,3=cash lift,4=paidout,5=receipt,6=roa,7=deposit , 8 = Safe Declaration,9= SCO ATM deposit (Acceptor),  10 = SCO ATM dispenser 
												 //see Bug#99936: defines + new INFO_TRS_FOREGN_CURRENCY = 11
    
	unsigned char bInformativePickup	:1;	//15 FS21416
	unsigned char bFirstTender			:1; //   FS21416
	unsigned char bVoid					:1;
	unsigned char opt_info		        :1; // FSD 8387 'Spot Check': Informative only, ignore this record.
	unsigned char bChangeOrder			:1;	// FSD12431. Flag for change order
	unsigned char nu5					:1;	//used by the FO
	unsigned char bDenominationType		:1;	//FSD56621	0=normal denomination , 1=ATM denomination
	unsigned char nu7					:1;

	unsigned short ticket_no;				//16
	unsigned char denomCount;				//18
    unsigned short ushDenomEntryID;			//19, #20633

	unsigned short ushCashierPosId;         //21
    
	unsigned char reserved[4];				//23

	struct									//27
	{
		unsigned char ucCurrency_fg  :1;	//  0   - Local
											//  1   - Foreign
		unsigned char ucPeriod_fg    :1;	//	0 - Current
											//	1 - Previous
		unsigned char filler         :6;
	}flags;

	unsigned long ulExchangeRate;			//28
	unsigned char DenomType;    //32 (1=Note, 2=Coin)	//#52848
	unsigned char reserved1[11];				//33

    struct   trans_tail_  tail;				//44
};

struct trs_info_sequence_
{
    unsigned char opcode;         //0x70	//0	<Opcode Value="0x70"/>
    unsigned char function;       //0x02	//1	<Opcode Value="0x02"/>

	unsigned char uchEntity;	// 2
	unsigned char uchSeqType;	// 3
	unsigned long ulSeq;        //4
	unsigned char bNew       :1;//8
	unsigned char bNU        :7;//8 

	unsigned char SeqSubType;//9 

	unsigned char	not_used[34];		// 10


    struct   trans_tail_  tail; //44
};

//FS20126
struct trs_plu_sale_ext_3_
{
    unsigned char	opcode;					//0	0x70 Info Transaction	<Opcode Value="0x70"/>
    unsigned char	function;				//1	0x04 TRANS_INFO_EXTRA_PLU_DATA	<Opcode Value="0x04"/>
    
    unsigned char	subDept[6];				//2	SubDept no. in BCD
    long			costPrice;				//8	cost Price
	long			nComparisonPrice;		//12 Comparison Price
	unsigned short	Promo_no;				//16 ////CR #6695
	char			pluCode[7];				//18 CRL 8442
	unsigned char	internalCode[7];		//25 CRL 8442
    unsigned char	bProhibitedsaleItem     		:1;	//32 FSD18705
    unsigned char	bRtcEmbeddedBarcode	    		:1;	//32 #27235: Indicate if a barcode is an RTC embedded barcode.
    unsigned char	bItemFollowsLinkItemChild	    :1;	//32	FSD14086
    unsigned char	bExcludePriceModifiedFromProm	:1;	//32	#40716
    unsigned char	bInputFilePLUSale				:1;	//32	CR52276
	unsigned char	bBarcodeInfoQuantityEmbedded 	:1;	//32 FSD236214
	unsigned char	bBarcodeInfoPriceEmbedded  	    :1;	//32 FSD236214
    unsigned char	bAcceptRaincheck				:1;	//32 FSD367404

	union
	{ 
		char		unknownItmReplacementPluCode[7];//33, bcd, #20415 fix.
		long        lBarcodeInfoPrice;				//33, #382516
	};

	unsigned char   price_type;				//40	FS19171; FSD25862_LayBy_Reliance
	unsigned char   uchChargeRelatedTndr;	//41	FSD29811 - The tender this item acts as a charge for. This indicates the item is a charge for a tender - If it has value.
    short	shSubtractedQty;			//42	#30168 & #35586

    struct trans_tail_	tail;			//44	TRS tail
};//64

//FSD52741 Ticket Saving Enhancements For Drive-Offs
struct trs_plu_sale_ext_4_
{
    unsigned char	opcode;					//0	0x70 Info Transaction	<Opcode Value="0x70"/>
    unsigned char	function;				//1	0xE0 TRANS_INFO2_PLU_SALE_EXT4	<Opcode Value="0xD3"/>
    
	unsigned char drive_off_start_time[3];	//2	Start time
	unsigned char drive_off_end_time[3];	//5	Start time


	long lGiftReceiptSequenceNumber;		//8 - Gift Receipt Transaction sequence - FSD55832.
	long lOriginalItemSeqNumber;			//12 //EyalAlSeq

	unsigned char bItemAllreadyPrintedOnKitchenDoc :1; //16	//FSD62785 - StoreLine Kitchen printing support
	unsigned char bAvailableForUpdate			   :1; //16 // FSD70780-6.4
	unsigned char bIsAlternativePrice			   :1; // FSD 144217
	unsigned char bDontPrintOnReceipt			   :1; // FSD 136864
	unsigned char bAreaScaleDepartmentSellPackage  :1; // FSD 136864
	unsigned char bManualExcludedFromPromotions	   :1; //16 FSD306746 - StoreLine Philippine Business Requirements 
	unsigned char bPriceAndWeightEmbedded		   :1;
	unsigned char bIsCharityItem					:1; //16 FSD#241449 - FSD#339547

	long lVoidedItemSeqNumber;				//17	BUG#70673 - after save/recall items do not appear on receipt

	unsigned long mrp_saving;				//21 FSD53400 MRP saving on this item
	unsigned long ulMarkdownSaving;			//25 FSD53400 Markdown saving on this item

    long SQM_Width; //fsd70782				//29	
	long SQM_Length; //fsd70782				//33
	unsigned char  UpdateStatus;			//37 // fsd70780-6.4
	unsigned short UpdatingCashier;			//38 // FSD70780-6.4
	unsigned char  BCDUpdateDate[3];		//40 // FSD70780-6.4
	
	unsigned char	uchEmbeddedTypeFromBarcode;	//43 Jumbo_BarcodePriceEmbeded				
    
    struct trans_tail_	tail;				//44	TRS tail
};//64



struct trs_info_parcel_
{
    unsigned char opcode;         //0x70	//0	<Opcode Value="0x70"/>
    unsigned char function;       //0x05	//1	<Opcode Value="0x05"/>

	unsigned short ushParcelID;         	// 2
	unsigned char  bHomeDelivery       :1;//4
	unsigned char  bParcelPickUp       :1;//4 
	unsigned char  bVoid               :1;//4 
	unsigned char  bReturn             :1;//4 
	unsigned char  bSpecifyAttachedItems	:1;//4
	unsigned char  bSkipLabelPrinting  :1;//4   #231421
	unsigned char  bNU                 :2;//4

	unsigned char  sDescription[20];		// 5
	char  uchQty;                      //25
	unsigned char uchParcelType;       //26
	unsigned short ushMinorLocation;   //27 FSD6248 layby parcel
	unsigned char	NU[15];		       //29


    struct   trans_tail_  tail; //44
};

struct trs_info_charge_data_
{
    unsigned char opcode;         //0x70	//0	<Opcode Value="0x70"/>
    unsigned char function;       //0x06	//1	<Opcode Value="0x06"/>
	unsigned char sub_function;   //	    //2 1-Home delivery 2-parcel pickup.

	unsigned char   uchChargeType;          //3
	long            lChargeValue;           //4
	unsigned short  ushParcelQty;           //8
	long            lTotAmt;                //10
	unsigned char   sFeeCode[10];           //14

	unsigned char   bIgnore             :1; //24
	unsigned char   bReturn             :1; //24

	unsigned char   bNU                 :6; //24

	unsigned char	NU[19];		            // 25


    struct   trans_tail_  tail; //44
};

//FS21416
struct trs_info_cash_lift_
{
    unsigned char opcode;         //0x70		//0	<Opcode Value="0x70"/>
    unsigned char function;       //0x09		//1	<Opcode Value="0x09"/>
	unsigned char sub_function;					//2  1=Regular,2=POST pickup

#ifndef BIG_NUMBER
    long          amount;						//3
    short         count;						//7
    unsigned char tender;						//9

	// PC generated options
    unsigned char previous_period :1;			//10
    unsigned char no_empl_update  :1;
    unsigned char opt_reprocess   :1; // B/O use
    unsigned char opt_remote      :1;
    unsigned char bCashLiftVoided :1;	//FSD90246
    unsigned char opt_nu05        :1;
    unsigned char opt_nu06        :1;
    unsigned char opt_nu07        :1;
    
    unsigned char pos_no;						//11
    unsigned char pc_no;						//12
	unsigned long supervisor_no;				//13
	unsigned short cashier_no;					//17
    
    unsigned char nu[25];						//19
#else
    __int64       amount;						//3
    short         count;						//11
    unsigned char tender;						//13

	// PC generated options
    unsigned char previous_period :1;			//14
    unsigned char no_empl_update  :1;
    unsigned char opt_reprocess   :1; // B/O use
    unsigned char opt_remote      :1;
    unsigned char opt_int64       :1; //FSD2733
    unsigned char opt_nu05        :1;
    unsigned char opt_nu06        :1;
    unsigned char opt_nu07        :1;
    
    unsigned char pos_no;						//15
    unsigned char pc_no;						//16
	unsigned long supervisor_no;				//17
	unsigned short cashier_no;					//21
    
    unsigned char nu[21];						//23
#endif
    struct   trans_tail_  tail;
};

#ifdef C4_STYLE_VENSAFE
// FS39670
struct trs_info_vensafe_ 
{
    unsigned char opcode;			//0x70		//0	<Opcode Value="0x70"/>
    unsigned char function;			//0x0E		//1	<Opcode Value="0x0E"/>

	char			sVensafeProductNum[7];		//2  BCD
	char			sVensafeSerialNum[4];		//9  BCD
	char			sScannedBarcode[12];		//13 BCD
	unsigned short	ushTemplateNumber;			//25
	long			lCount;						//27

	unsigned char opt_was_cancelled			:1;	//31
	unsigned char opt_cancel				:1;	//31
	unsigned char opt_nu					:6;	//31
    unsigned char nu[12];						//32
    struct   trans_tail_  tail;					//44
};
#else
// FS22935
struct trs_info_vensafe_ 
{
    unsigned char opcode;			// 0x70		// 0	<Opcode Value="0x70"/>
    unsigned char function;			// 0x0E		// 1	<Opcode Value="0x0E"/>

	char			sVensafeProductNum[7];		// 2
	char			sVensafeSerialNum[3];		// 9
	char			sScannedBarcode[7];			// 12
	unsigned short	ushTemplateNumber;			// 19
	long			lCount;						// 21

	unsigned char ucStatus;						// 25   FSD#60451
	
	unsigned char sVensafeRealEAN[13];		    // 26  FSD#60451
	
	char cVensafeTrsRefNum;						// 39
	unsigned char uchNumberOfItems;				// 40	FSD#59806
    unsigned char nu[3];						// 41

    struct   trans_tail_  tail;
};
#endif

struct trs_alert_host_lookup_  
{
   unsigned char opcode;         //0x63	<Opcode Value="0x63"/>
    
   unsigned short  subopcode;    //1 165 (xA5)	<Opcode Value="0xA5"/>
   unsigned char function;       //3

   unsigned char disp_message     :1;
   unsigned char drvfile_popup    :1;
   unsigned char ignore_alert     :1;
   unsigned char use_org_pos_no   :1;
   unsigned char get_text_msg     :1;
   unsigned char opt_nu15         :1;
   unsigned char opt_nu16         :1;
   unsigned char opt_nu17         :1;  // 4

   unsigned char  uchReason;   //5	   //  0 - Host unavailable
                                   //  1 - Unknown to host
                                   //  2 - Action cancel.

   unsigned char  sBCDUnknownItem[7]; //6
   unsigned char  data[29];           //13
   unsigned char org_pos_no;  //42
   unsigned char org_pc_no;   //43

    struct   trans_tail_  tail; //44
};

struct trs_info_ecca_ext_
{
	unsigned char opcode;			//0x70		//0	<Opcode Value="0x70"/>
    unsigned char function;			//0x10		//1	<Opcode Value="0x10"/>

	unsigned char	sEccaAuth[25];				//2
	
	unsigned char	NU[17];						//27

	struct   trans_tail_  tail;					//44
};

//CR19243_Kenia
/*----------------------------------------------------------------------
Opcode:		0xC1 
Automatic discount on total: Stamps Duty.
-----------------------------------------------------------------------*/
struct trs_stamps_duty_						//OFS	Description
{
    unsigned char opcode;					//0		0xC1	<Opcode Value="0xC1"/>


    unsigned char opt_upcharge			:1;	//1	Negative discount
    unsigned char opt_return_ticket		:1;	//1	For return ticket
	unsigned char opt_cancel_SD			:1;
	unsigned char nu1					:5;


    unsigned char discount_type;			//2	Discount number
    long          amount;					//3	Discount amount

	long  SDThresholdLast;					//7
	long TicketDiscountPercentSD;			//11
	long GivenDiscountableAmountSDLast;		//15

	unsigned char nu43[25];					//19
    
    struct   trans_tail_  tail;				//44	TRS tail
};

//FS19171_LayBysTax
/*----------------------------------------------------------------------
Opcode: 0xC2
Department, Lay by
-----------------------------------------------------------------------*/
struct trs_dep_lay_by_					//OFS	Description
{
    unsigned char opcode;						//0		0xC2	<Opcode Value="0xC2"/>
    unsigned short  dept;						//1		Department no.
	unsigned char   opt_tax_correction		:1;	//3
	unsigned char   opt_delayed_tax			:1;	//3
    unsigned char   exemptable              :1;	//3	FS19171_LayBysTax_3:Tax exempt given
    unsigned char   tax_included            :1;	//3	FS19171_LayBysTax_3:GST inclusive tax
	unsigned char   flg_void_cancel			:1; //3 bug22114
	unsigned char   tax_on_pmt				:1; //3 tax is applied on payments and deposits
	unsigned char   nu_opt2					:2;	//3


	unsigned char   LayByStatus;				//4
    unsigned char   TaxNo;						//5	(Delayed Tax)No of Tax 
	long            TaxableAmount;				//6
	long            AmountTax;					//10

    unsigned char  reserved[30];			//14	Not used
    struct   trans_tail_  tail;				//44	TRS tail
};

/*----------------------------------------------------------------------
Opcode: 0x70 function:0x15
Added information to miscellanoues transaction
-----------------------------------------------------------------------*/
//!yaron!
struct trs_info2_misc_trs_                   //OFS		Description
{
   unsigned char opcode;                     //0		0x70	<Opcode Value="0x70"/>
   unsigned char function;                   //1		0x15	<Opcode Value="0x15"/>

   unsigned char misc_func;                  //2		Misc. transaction function code (see 0xD1)
   unsigned char status;                     //3		0:ok
                                             //			1:failed
   unsigned short extended_status;           //4		Extended status code
   long			  amount;					 //6		amount
   unsigned char  referance[10];			 //10		Refernce # 		
   unsigned char filler[24];                 //20

   struct   trans_tail_  tail;               //44     TRS tail
};

/*----------------------------------------------------------------------
Opcode: 0x70 function:0x16
Delete lay-by customer record
-----------------------------------------------------------------------*/
//!yaron!
struct trs_info2_layby_del_cust_             //OFS		Description
{
   unsigned char opcode;                     //0		0x70	<Opcode Value="0x70"/>
   unsigned char function;                   //1		0x16	<Opcode Value="0x16"/>

   char sCustomerNum[10];					 //2		Customer ID		 
   unsigned char filler[32];                 //12

   struct   trans_tail_  tail;               //44     TRS tail
};


/*----------------------------------------------------------------------
Opcode: 0x70 function:0x17
Lay-By calculated tax. This is the tax which is supposed to be charged.
Used by Priceline. This opcode is used by the generic POS for other purpose.
-----------------------------------------------------------------------*/
struct trs_info2_layby_calc_tax_			//OFS	Description
{
   unsigned char opcode;                    //0		0x70
   unsigned char function;                  //1		0x17

   unsigned char bcdLayById[10];			//2		Lay by number
   unsigned char uchTaxId;					//12	Tax number
   long			 lTaxable;					//13	Taxable amount
   long			 lTax;						//17	Tax amount
   unsigned char uchfiller[23];				//21	Not used

   struct   trans_tail_  tail;				//44	TRS tail
};


//FS3199
struct trs_info_archive_invoice_
{
    unsigned char opcode;            //0x70   //0	<Opcode Value="0x70"/>
    unsigned char function;          //0x0F   //1	<Opcode Value="0x0F"/>

    unsigned short ushTransID;                //2  // Current trans.id
	unsigned char  bcdTransDate[3];           //4  // Current trans.date

	unsigned short ushPosNo;                  //7  // Current Pos number.                                   
	unsigned char  uchStatus;                 //9  // Status record (0-9)
	                                               // 0 - Open
												   // 1 - Completed
	                                               // 2 - Deleted

	long lTicketAmount;                       //10 // Ticket amount
	unsigned short ushDocumentType;           //14 // Document type
	unsigned char  sCustID[10];               //16 // Customer ID
	unsigned long  ulDocSeqNo;                //26 // Doc.Seq. number

	unsigned char  bUpdateCustDetails       :1; //30 // Update customer details in the qdx #195
	unsigned char  bAssignCustomerAsPrivate :1; //30 // FSD#96100 
	unsigned char  bAllowConsolidationDocument	:1;	//30  FSD#421963
	unsigned char  bSentArchStatusCombinedDoc	:1; //FSD#421963_PostVoidResell
	unsigned char  bNU                      :4; 

	unsigned char uchPaymentType;				//31
	
	long lTicketAmountExcludingTax;				//32 // FSD56853 Ticket amount excluding tax

	unsigned char NU[8];						//36 // Not used

    struct   trans_tail_  tail;                 //44
};

//FS3199
struct trs_invo_retrieve_invoice_
{
	unsigned char opcode;	  	      //0x70	<Opcode Value="0x70"/>
	unsigned char function;		      //0x14	<Opcode Value="0x14"/>

	unsigned short ushOrigTransID;            //2  // Retrieve Trans ID
	unsigned short ushOrigPosNo;	          //4  // Retrieve Pos ID
	unsigned char bdcOrigTransDate[3];	      //6  // Retrieve Trans date

	long lTicketAmount;                       //9  // Ticket amount
	unsigned short ushOrigDocType;            //13 // Doc.type

    unsigned long ulOrigDocSeqNo;             //15 // Doc.Seq.number
	unsigned char uchRetrieveType;            //19 // 0 - Retrieve regular invoice 
	                                               // 1 - Retrieve archive invoice

 	unsigned char bSaveAfterRetrieve     :1;  //20 // Second save after retrieve
	unsigned char bSkipRetrieveTrs       :1;  //20 // Skip this trs on the retrieve process
	unsigned char bTextFileIndication    :1;  //20 FS3199
	unsigned char bDuplicateInvoice      :1;  //20 FSD6814 
	unsigned char bUpdateCustDetails     :1;  //20 FSD6814
	unsigned char bNegativeInvoice       :1;  //20 FSD28527
	unsigned char nu                     :2;  //20 FS3199	

	
	unsigned short ushOrigCashierNo;		  //21	// Retrieve Cashier Number
	unsigned char bcdOrigTransTime[4];        //23  // Retrieve Trans. time
	unsigned char acct_num[10];				  //27 BCD , FSD 18554    	
   
	unsigned char reserved[7];                //37
	struct   trans_tail_  tail;               //44
};

/*----------------------------------------------------------------------
Opcode: 0xC3 function:
Send trace transaction
-----------------------------------------------------------------------*/
#define	TRANS_TRACE_SCREEN		(unsigned char) 0x01
#define	TRANS_TRACE_SOFT_KEY	(unsigned char) 0x02
#define TRANS_TRACE_KEYSTROKES	(unsigned char) 0x03

#define	BTN_TYPE_UNKNOWN         0
#define BTN_TYPE_STATE           1
#define BTN_TYPE_GROUP           2
#define BTN_TYPE_INP_LIST        3
#define BTN_TYPE_FUNC_CODE       4
#define BTN_TYPE_LIST            5
#define BTN_TYPE_KEYBOARD        6
#define BTN_TYPE_POS_FUNC        7
#define BTN_TYPE_SHORT_GROUP     8 
#define BTN_TYPE_FORCE_LOCATION 98
#define BTN_TYPE_WP_MENU        99
#define	BTN_TYPE_DATA			(unsigned char) 'D'
#define	BTN_TYPE_NEXT_PAGE		(unsigned char) 'N'


#define	BTN_NEXT_PAGE_DESCR "Next page button"

#define	OPERATION_OPEN	(unsigned char) 0x01
#define	OPERATION_CLOSE	(unsigned char) 0x02

#define	SCREEN_TYPE		(unsigned char) 0x01
#define	FORM_TYPE		(unsigned char) 0x02

#define FUNCTION_MODE_SALE		0
#define FUNCTION_MODE_TENDER	1

struct trs_trace_data_
{
	unsigned char	ucOpcode;	//0 <Opcode Value="0xC3"/> 0xC3 , TRANS_TRACE							
	unsigned char   ucEventType;//1	<Opcode Value="0x01,0x02"/> TRANS_TRACE_SCREEN or TRANS_TRACE_SOFT_KEY	

	struct 	//time HHMMSSMS, time with milliseconds 							//2	
	{
		unsigned short	Hour	:5; //hours, 0-24
		unsigned short	Minute	:6; //minutes, 0-60
		unsigned short	NotUsed	:5; //filler up to 16 bits = 2 byte
		unsigned short	Second	:6; //seconds, 0-60
		unsigned short	MSecond	:10;//milliseconds, 0-1000
	}OperationTime;

	union
	{
		struct
		{	
			unsigned char 	ucOperation  :4;	//1 - open, 2 - close, ...		//6
			unsigned char 	ucObjectType :4;	//1 - screen, 2 - form, ...
			unsigned char	sName[10];			//screen name					//7
			unsigned char	sFiller[27];										//17	
		}ScreenData;

		struct
		{
			unsigned char	ucBtnId;		//physical place in the screen		//6
			unsigned char	ucWindowSz;		//window size						//7
			unsigned char	ucBtnType;		//BTN_TYPE_GROUP/BTN_TYPE_FUNCTION/BTN_TYPE_LIST/BTN_TYPE_DATA/BTN_TYPE_SHORT_GROUP	//8
			unsigned char	sBtnIndex[6];	//button index in the QDX			//9
			long			lPreEnterValue;	//value entered before key invoked  //15
			unsigned char	sFiller[5];											//19
			unsigned char	sDescription[20];//short description, only 20 first characters instead of 50	//24	
			
		}SoftKeyData;

		struct 
		{
			unsigned char	ucMode;			//SALE = 0 or TENDER = 1 function mode	//6
			unsigned short	usRelativeKey;	//ASCII code							//7
			unsigned short	usFuncCode;		//function code							//9
			char			cPrivilege;		//privilege of key stroke				//11
			char			cKeyLock;		//key lock of key stroke				//12
			unsigned char	ucAlphanum;		//alphanumeric mode of key stroke		//13
			unsigned char	sFiller[30];	//filler								//14
		}KeyStrokeData;
	}data;
								
	struct			trans_tail_  Tail;											//44			
};

//FSD6795
struct trs_info2_init_loyalty_card_
{
	unsigned char opcode;                   //0		0x70	<Opcode Value="0x70"/>
	unsigned char function;                 //1		0x1E	<Opcode Value="0x1E"/>

	unsigned char sCardNum[20];				//2		Card number
	unsigned char sDate[3];					//22	Request date BCD yymmdd
	unsigned char sTime[3];					//25	Request time BCD hhmmss

	unsigned char uchStatus;				//28	loyalty card status 0-wait for response, 1-valid, 2- EDRC_CANCELLED, 3-Cancelled, 4-VOIDED, 5-EXCEEDLIMIT, 6-OFFLINEVALID, 7-COMM_ERR, 8-Not Exist, 

	unsigned char bAccepted	:1;				//29	Third Party Loyalty clubcard accepted
	unsigned char bVoided	:1;				//29
	unsigned char bScanned	:1;				//29
	unsigned char bCheckCrd	:1;
	unsigned char bTimeout	:1;				//29	//#51173
	unsigned char nu:3;						//29

	unsigned char sRspDate[3];				//30	Response date BCD yymmdd
	unsigned char sRspTime[3];				//33	Response time BCD hhmmss

	unsigned char uchSchemeNo;				//36	//FSD29692
	unsigned long ulErrorCode;				//37	//FSD42115	

	unsigned char filler[3];				//41

   struct   trans_tail_  tail;              //44    TRS tail
};

//FSD53587
struct trs_info2_init_loyalty_card_ext_
{
	unsigned char opcode;                   //0		0x70	<Opcode Value="0x70"/>
	unsigned char function;                 //1		0x1E	<Opcode Value="0xF3"/>

	unsigned char sCardNum[20];				//2		Card number
	unsigned char sStatusCode[4];			//22	Card Status Code

	unsigned char filler[18];				//26

	struct   trans_tail_  tail;             //44    TRS tail
};

struct  trs_info2_fiscal_eod_	//FS3742
{
	unsigned char			opcode;			//0x70	<Opcode Value="0x70"/>
	unsigned char			function;		//0x30	<Opcode Value="0x30"/>

	unsigned long			ulFiscalMFID;	//2
	__int64					ulMFDailyTotal;	//6
	__int64					i64MFGrandTotal;//14	

	char					cFiscalMFID[15];//22
	long					ReportZ_num;	//37
	
	
	unsigned char	bInformativeAfterCom98	:1;			//41		
	unsigned char	bDuringEOD				:1;				 
	unsigned char	bManualEODAtPos			:1;	
	unsigned char	bManualZReport			:1;			
	unsigned char	bNotUsed				:4;			
	
	
	unsigned short	sNumFiscReceipt;		//42
	struct   trans_tail_	tail;			//44
};

struct trs_info_ticket_status_
{
    unsigned char opcode;         //0x70	//0	<Opcode Value="0x70"/>
    unsigned char function;       //0x20	//1	<Opcode Value="0x20"/>

	unsigned short	ushPosNumber;			//2
	unsigned short	ushTicketNumber;		//4
	unsigned long	ulTicketAmount;			//6
	unsigned long	ulTotalCashAmount;		//10
	unsigned char	m_chTransactionDate[3];	//14 YYMMdd
	unsigned char	m_chTransactionTime[3];	//17 HHmmSS

	unsigned char	bVoucherPrinted		:1;	//20
	unsigned char	not_ussssed			:7;

	unsigned short	ushLevelNumber;			//21
	
	unsigned long	ulTaxAmount;			//23

	unsigned long	ulTaxVoucherNum;		//27

	unsigned char	NU[13];		            //31


    struct   trans_tail_  tail; //44
};

/* ON-LINE Trans info : voucher was redeemed */
struct trs_info_redeem_voucher_
{
    unsigned char opcode;             		//0x70	<Opcode Value="0x70"/>
    unsigned char function;           		//0x21	<Opcode Value="0x21"/>

    unsigned char	sVoucherNum[10];	    // offset 2

    unsigned char use_org_pos_no   :1;		// offset 12
	unsigned char bVoidFg          :1;      // void voucher
    unsigned char opt_nu7          :6;
    unsigned char org_pos_no;				// offset 13

	unsigned char	nu[30];				    // offset 14

    struct   trans_tail_  tail;
};

struct trs_info_unique_counters_
{
    unsigned char opcode;         //0x70	//0	<Opcode Value="0x70"/>
    unsigned char function;       //0x22	//1	<Opcode Value="0x22"/>

	unsigned short	ushCounterID;			//2
	unsigned long	ulNextCounterValue;		//4
	unsigned long	ulPreviousCounterValue; //8
	char			sText[20];				//12

	unsigned char	NU[12];		            //32


    struct   trans_tail_  tail; //44
};

struct trs_info_interim_use_
{
    unsigned char opcode;         //0x70	//0	<Opcode Value="0x70"/>
    unsigned char function;       //0x24	//1	<Opcode Value="0x24"/>

	unsigned long	ulInterimDenomination;	//2
	unsigned short	ushCounter;				//6

	unsigned char	bSaleMode					:1;		//8
	unsigned char	bTenderMode					:1;		//8
	unsigned char	not_used_bits				:6;		//8


	unsigned char	NU[35];		            //9

    struct   trans_tail_  tail; //44
};

//FSD3583
struct trs_info_gross_subtotal_
{
    unsigned char opcode;    //0x70	//0	<Opcode Value="0x70"/>
    unsigned char function;  //0x25	//1	<Opcode Value="0x25"/>

	long	lAmount;				//2

	unsigned char	NU[38];		    //13

    struct   trans_tail_  tail; //44
};

//FS4002
struct trs_info2_bill_payment_
{
    unsigned char opcode;         //0x70	//0	<Opcode Value="0x70"/>
    unsigned char function;       //0x26	//1	<Opcode Value="0x26"/>

	unsigned char	sBillPaymentNumber[35];	//2
	
	unsigned char	NU[7];		            //37

    struct   trans_tail_  tail; //44
};

// EFT transactions waiting to be sent to bank
struct trs_manualy_settlement_ext_
{
    unsigned char opcode;         //0x70	//0	<Opcode Value="0x70"/>
	unsigned char function;       //0x27	//1	<Opcode Value="0x27"/>

    unsigned char	sSponsorID[2];	// 2 FSD1798 Card sponsor ID (type)
   
	unsigned char	bVoidManualSettlement	    :1; //4 #63258 Void Manual EFT if signature cancelled
	unsigned char	bManualPanKey			    :1; //4 #70529 Need to save manual pan entry for offline eft.
    unsigned char	bManualConfirmEFTrequired   :1; //4 FSD93620: Processing Response code BY\B3(PINPAD Not Operational) For EFT
    unsigned char	bCardAccountTypeExist		:1;	//4 #127974: PCI Interface Changes. Recall Scenario.
	unsigned char	bNU						    :4; //4
    
	unsigned char   sTrack2[39];	                //5 FSD93620 Processing Response code BY\B3(PINPAD Not Operational) For EFT	
	
    struct   trans_tail_  tail;    // 44
};

//FSD1798
struct trs_bulk_giftcard_sale_
{
    unsigned char opcode;         //0x70	//0	<Opcode Value="0x70"/>
    unsigned char function;       //0x28	//1 <Opcode Value="0x28"/> TRANS_INFO2_BULK_GIFTCARD_SALE

	unsigned char 	sOrderNumber[10];		//2	 Order number for the Bulk sale, 
											//   please use define BULK_GIFT_CARD_ORDER_LEN in the code
	unsigned short	ushQuantity;			//12 Quantity of the gift cards	
	long 			lAmount;				//14 Amount of the Bulk gift card sale
	unsigned char	notInUse[26];			//18 Not used
	struct trans_tail_	tail;				//44 TRS tail
};

struct trs_giftcard_enquiry_
{
    unsigned char	opcode;			//0x70	//0	<Opcode Value="0x70"/>
    unsigned char	function;		//0x29	//1 <Opcode Value="0x29"/>	TRANS_INFO2_GIFTCARD_ENQUIRY

	unsigned char 	sGiftCardNum[20];		//2	 Gift Card number 
	long 			lAmount;				//22 Balance enquiry amount
	unsigned char	sExpiryDate[10];		//26 Expiry date in the format dd/mm/yyyy
	unsigned char	bExitByTimeOut;			//36 Exit by timeout, YES/NO
	unsigned short	ushResponseStatus;		//37 Response status code, 0 - ok, else - error
	unsigned char   bStartPrintTemplate	:1;	//FSD64469
	unsigned char   bEndPrintTemplate	:1;	//FSD64469
	unsigned char   bNuPrint			:6;
	unsigned char	notInUse[4];			//39 Not used
	struct trans_tail_	tail;				//44 TRS tail
};

//FSD3582 
struct trs_info2_local_barcode_
{
    unsigned char	opcode;									//0 0x70	<Opcode Value="0x70"/>
    unsigned char	function;								//1 0x31	<Opcode Value="0x31"/>TRANS_INFO2_LOCAL_BARCODE_ISSUED
	unsigned char   sub_function;							//2 0 = barcode printed (issued), 1 = barcode used .

	unsigned char barcode[20];								//3  BCD - Barcode buffer (right justify, leading zeroes)
	long		  amount;									//23
	unsigned char issue_date[3];							//27 BCD yymmdd					
	unsigned char expirty_date[3];							//30 BCD yymmdd						
	
	unsigned char   barcode_len;							//33
	unsigned char	uchManualAcceptForLimitStartDay	 :1;	//34 //FSD11893
	unsigned char	uchManualAcceptForLimitEndDay	 :1;	//34 //FSD11893
	unsigned char	uchManualAcceptOfCoupon		     :1;	//34 //FSD11893
	unsigned char	bReturned						 :1;	//34 //FSD22142
	unsigned char	bRejectionReason				 :4;	//34 //FSD314464 //For TRS_LOCAL_BARCODE_SUB_FUNC_REJECTED
	     
	unsigned char	bVoided			        :1;				//35 //FSD314464
	unsigned char	bTrainingMode			:1;				//35 //FSD314464
	unsigned char	bExtTrsPresent			:1;				//35 //FSD13078
	unsigned char	bLinkedToDataBar		:1;				//35 //FSD309681
	unsigned char	bCoupon					:1;				//35 //CR_TD#400922_CPN_EOT
	unsigned char	not_used_bits			:3;				//35 //NU	

	unsigned char   startDateBcdYYMMDD[3];					//36 BCD yymmdd . FSD19134
	unsigned char   uchExternalTenderNumber; 				//39 FSD19134
	unsigned char   uchRedemptionType;						//40 FSD19134
	
	unsigned char	uchPosNo;								//41 FSD18888 	
	unsigned short	ushStoreNo;								//42 FSD18888 	

	struct trans_tail_	tail;								//44 TRS tail
};


//FSD13078
struct trs_info2_local_barcode_ext_
{
	unsigned char	opcode;					//0		0x70	<Opcode Value="0x70"/>
	unsigned char	function;				//1		0x76	<Opcode Value="0x76"/>	TRANS_INFO2_LOCAL_BARCODE_ISSUED_EXT

	unsigned char	referenceNumber[10];	//2		BCD

	struct 
	{
		unsigned char uchType;
		long          lValue;

	}condition[3];							//12    FSD11575 - The condition the barcode met.
	unsigned char uchNumOfVaildConditions;	//27

	
	short shReward1;						//28	FSD18888
	short shReward2;						//30	FSD18888
	short shReward3;						//32	FSD18888
	short shReward4;						//34	FSD18888
	unsigned short	ushTicketNo;			//36	FSD18888
	unsigned short	ushBarcodeProgReference;//38	FSD18888: reference number from the barcode programing
	unsigned char	uchType;				//40	FDS41644 MarcellaR voucher(0)/coupon(1)
	unsigned char	uchDecimalInPrice;		//41	#50333
	unsigned char   uchExternalBarcodeType; //42    FSD61184
	unsigned char	nu[1];					//43	FDS41644 MarcellaR

	struct trans_tail_	tail;				//44	TRS tail
};


struct trs_info4_local_barcode_ext2_
{
    unsigned char	opcode;									//0 0x90	<Opcode Value="0x90"/>
    unsigned char	function;								//1 0x0E	<Opcode Value="0x0E"/>TRANS_INFO4_LOCAL_BARCODE_ISSUED_EXT2
	unsigned char decodedBarcode[20];						//2  BCD - Barcode buffer (right justify, leading zeroes)
	unsigned char uchBarcodeLen;							//22
	unsigned char nu[21];									//23
	struct trans_tail_	tail;								//44 TRS tail
};

//Discount extended transaction        
struct trs_discount_ext_
{
	unsigned char  opcode;						//0     0x13 <Opcode Value="0x13"/>	TRANS_DISCOUNT_EXT
    unsigned char  plu_code[7];					//1		Item number (if discount given to an item)
    unsigned short dept;						//8		Department number 

    unsigned char  opt_markdown_dep       :1;	//10	Indicates if markdown departement
	unsigned char  SingleConditionSingleUnit :1;//10	CRL338645 - Storeline_Promotion_Printing_on_Single_Line
    unsigned char  NU1                    :6;	//10	NU
	unsigned short ushMsgRewardlimit;           //11    FSD12648 - Message reward limit ( Reflection of the promotion configuration).
	short          shMultiReward[3];            //13    FSD22200 - For target message - Code support 6 multi rewards but currently only 2 are used. If in the future more are required they could be added in another trs.
   	long           lDecMultiReward[3];          //19    FSD22200 - For target message - Code support 6 decimal multi rewards but currently only 2 are used. If in the future more are required they could be added in another trs.
	unsigned char  sTargetTemplate[10];         //31    FSD22200 - The name of the target message name.

	unsigned char  NU[3];                       //41	NU                 
		
	struct trans_tail_	tail;					//44    tail

};

//Discount extended transaction        
struct trs_discount_ext2_
{
	unsigned char  opcode;						//0     0x27 <Opcode Value="0x27"/>	TRANS_DISCOUNT_EXT2
    unsigned char  sOfferCode[10];			//1		offer code number

	long	lBonusPoints;					//11
	long	lDiscountWithoutExclusiveTax;	//15

	unsigned char  NU[25];                  //19	NU                
		
	struct trans_tail_	tail;				//44    tail

};

struct trs_alert_giftcard_enquiry_  
{
   unsigned char	opcode;				//0x63	<Opcode Value="0x63"/>
    
   unsigned short	subopcode;			//1 167 (xA7)
   unsigned char	function;			//3

   unsigned char	disp_message     :1;
   unsigned char	drvfile_popup    :1;
   unsigned char	ignore_alert     :1;
   unsigned char	use_org_pos_no   :1;
   unsigned char	get_text_msg     :1;
   unsigned char	opt_nu15         :1;
   unsigned char	opt_nu16         :1;
   unsigned char	opt_nu17         :1;//4

   unsigned char	uchReason;			//5	//  0 - Host unavailable
											//  1 - Error response from MFS
											//  2 - Action cancel.

   unsigned short	ushResponseStatus;	//6 - in case uchReason is 1 this is the MFS error code 	
   unsigned char	sGiftCardNo[20];	//8 - Gift Card number
   unsigned char	NU[14];				//28
   unsigned char	org_pos_no;			//42
   unsigned char	org_pc_no;			//43

    struct   trans_tail_  tail;			//44
};


struct trs_info2_member_account_        //FS3649
{
	unsigned char opcode;               //0   0x70		<Opcode Value="0x70"/>
	unsigned char function;             //1   0x32		<Opcode Value="0x32"/>
	unsigned char sub_function;         //2		1-member account open balance info,
	                                    //		2-member account closing balance info,
	                                    //		3-first name,
										//		4-sure name,
										//		5-server date
										//		6-member account manually updated info 
										//		7-member account immediate reward
										//		8-member account redemption 
										//		9-member account triggers promotion
										//		10-member account rewarded by promotion
										//		11-member account accumulated by promotion
										//		13-balance per promotion (and per account)
										//		14-member account customer title + mobile number
										//		15-member account home number
										//		16-member account office number		
										//		17-member account fax number
		

	unsigned long ulMemberAccountID;    //3
	union                               //7
	{		
		struct
		{
			long          lOpenBalance;         
			unsigned long lSessionID;
			char nu[22];                        
		}inf1;

		struct
		{
			long          lEarnedValue;         
			long          lRedeemedValue;       
			long          lClosingBalance;   
			unsigned long lSessionID; 
			long          lOpenBalance;
			long          lEarnedValFromZero;

			unsigned char bInstantRedemption  :1;
			unsigned char bTrsWritenFromRecover :1;	// #42914
			unsigned char bDisplayBalanceonCustScreen :1;	// FSD71759
			unsigned char nu_inf2			    :5;
			
			char nu[5];							
		}inf2;		
	
		unsigned char szLoyaltyMemberFirstName[30];
		unsigned char szLoyaltyMemberSureName[30];
		unsigned char szServerDate[12];

		struct
		{
			long            lManuallyAddedValue; 
			unsigned char	bLoyaltyCardRequierd						 :1; //FSD16061
			unsigned char	bUpdatePromSrv						   	 :1;
			unsigned char	nuBits										 :6;
			unsigned char   szBarcode[20];   //bcd
			short OrgBarcodeLen;			 //Need this field because of pak/unpak change the barcode length
			char		  nu[3];                        
		}inf6;

		/* #23813, new structure				*/
		struct
		{
			long lPoints;							//7

			unsigned char	bBarcodePoints				:1; //11
			unsigned char	bWasCancelled				:1;
			unsigned char	bExtractRewardCoupon		:1;	//TD45367
			unsigned char	bUpdateMemberAccountBalance	:1;	//TD45784, TD45960
			unsigned char	bFallbackCoupon				:1; //FSD#139444
			unsigned char   bPointPromConfirmedByCashier:1;	//TD399362
			unsigned char	nu							:2;
			
			long			lPromId;				//12
			unsigned short  PromotionTriggerCount;  //16 FSD23692- the number of time a promotion was triggered 

			char			chCreditPointsType;		//18 TD43238
			
			long			lRewardingLoyaltyMemberAccount; // 19 TD#146671

			char			nu_17[14];				//23
		}inf7;

		//TD217931
		struct
		{
			long          lEarnedValue;				//7         
			long          lRedeemedValue;			//11
			long          lNumberOfTotalSavers;		//15
			char		  szCardId[15];				//19 //FSD414790
			char		  nu[3];					//34		
		}inf8;	
		
		//FSD 414790
		struct  
		{
			char szCustomerTitle[5];				//7
			char szLoyaltyMemberMobileNum[20];		//12
			char nu[5];								//32
		}inf14;
		
		//FSD 414790
		struct  
		{
			char szLoyaltyMemberHomeNum[20];		//7
			char nu[10];							//27
		}inf15;

		//FSD 414790
		struct  
		{
			char szLoyaltyMemberOfficeNum[20];		//7
			char nu[10];							//27
		}inf16;

		//FSD 414790
		struct  
		{
			char szLoyaltyMemberFaxNum[20];			//7
			char nu[10];							//27
		}inf17;


	};

	unsigned char promotionId[5];		//37		//FSD 14348 - BCD 10 digits
	unsigned char uchNumberOfDecimalPlaces; //42 #70371 Need to get Member account decimal places from general tables
	unsigned char bMSRBypassUsed	:1;	//43 340518
	unsigned char NU12513			:7; //43
    struct   trans_tail_  tail;			//44
};

//FSD11022
struct trs_info2_prompt_cashier_response_
{
    unsigned char	opcode;			//0x70	//0	<Opcode Value="0x70"/>
    unsigned char	function;		//0x69	//1 <Opcode Value="0x69"/> TRANS_INFO2_PROMPT_CASHIER_RESPONSE
	
	long lPromNum;							//2        
	unsigned char chApproveType;			//6
	long pValue;							//7
	unsigned char chCcResult;				//11
	long plSaversConfirmedByClient;			//12
	long plDynamicRedemptionPromSequence;	//16	//KobiM - TD#50965 - Supporting the DynamicRedemptionPromSequence attribute.
	unsigned char NU[24];					//20 
	
	struct trans_tail_	tail;				//44 TRS tail
};

//FSD11803
struct trs_info2_complementary_group_
{
	unsigned char	opcode;			//0x70	//0	<Opcode Value="0x70"/>
	unsigned char	function;		//0x6A	//1 <Opcode Value="0x6A"/>	TRANS_INFO2_COMPLEMENTARY_GROUP
	
	unsigned char	bComplementaryGroupNeeded; //2 
	char				szPluCode[7];						//3
	unsigned char NU[34];							//10 
	
	struct trans_tail_	tail;				//44 TRS tail
};

struct LoyaltyMsgHeader_					// //Loyalty Messages #3 and #5 
{
	unsigned char	uchLoyaltyMessageType;	//0
	unsigned short	ushMsgsQuantity;		//1
	long			lUncompressedMsgSize;	//3
	long			lCompressedMsgSize;		//7
	unsigned char	bOffline:1;				//11
	unsigned char	bRetroactive:1;	
	unsigned char	bNotRetroInWrongTicket:1;	// THIS IS TO SPECIFY UNUSUAL TRANSACTIONS FROM RTAPS
	unsigned char	bNU:5;
	unsigned short  ushOriginalTicketNu;	//12
	unsigned char	NU[26];					//14
};

struct StockMsgHeader_
{
	unsigned char	uchStockMessageType;	//0
	unsigned short	ushMsgsQuantity;		//1
	long			lUncompressedMsgSize;	//3
	long			lCompressedMsgSize;		//7
	unsigned char	NU[29];					//11
};
//RSCL_BLOCK:START
struct RsclSignatureCapture_
{
	unsigned char	uchSignatureCaptureMessageType;	//0
	unsigned short	ushMsgsQuantity;		//1
	long			lUncompressedMsgSize;	//3
	long			lCompressedMsgSize;		//7
	unsigned short	ushWidth;				//11
	unsigned short	ushHieght;				//13
	unsigned char	NU[25];					//15
};
//RSCL_BLOCK:END
//FSD58559
struct TicketData_
{
	unsigned char	uchStockMessageType;	//0
	unsigned short	ushMsgsQuantity;		//1
	long			lUncompressedMsgSize;	//3
	long			lCompressedMsgSize;		//7
	unsigned char	NU[29];					//11
};

struct trs_info2_ticket_type_
{
    unsigned char	opcode;			//0x70	//0		<Opcode Value="0x70"/>
    unsigned char	function;		//0x33	//1		<Opcode Value="0x33"/>
	unsigned short  ushTicketType;          //2,	1 .Add Customer
											//		2  Modify Customer (includes delete)
											//		3  Add Layby
											//		4. Modify Layby (includes delete)
											//		5. Layby Payment
											//		6 .Finalise Layby
                                            //		7. Cancel Layby(customer)
                                            //		8. RTS Confirmation
											//		9. Refund Unclaimed Deposit
											//		10.Payment reversal
                                            //		11 .Cancel Layby(store)
											//		12. Loyalty message ticket.
											//		13.Delivery Ticket (Stock Management DLL) 
											//		14. Stock Provider Request (Stock Management DLL)
											//		15 Third Party Loyalty Active  FSD 16852
											//		16 Non Payment	FSD36846
											//		17 Drive Off	FSD36846
											//      18 NCR Copient Loyalty Comm Log
											//		19 XML ticket data (EFT, DRE xml schema)
											//		20 Dynamic receipt printing data
											//		21 RX information SL_US Issue #18249 - PDX Pharmacy [EL1G+TammyE]
	                                        //      22 Debts coverage (FSD61185)
											//      23 M-DOT
											//      24 ZeevM CR# 19845 3rd Solutions
	
											//RSCL_BLOCK:START
											//		30 RSCL - Signature Capture
											//RSCL_BLOCK:END
	union									//4
	{
		//VERY IMPORTATNT VERY IMPORTATNT VERY IMPORTATNT VERY IMPORTATNT 
		//If you are going to add another struct to this union
		//that will be link to a 0x95 transaction (Zipped XML)
		//please make sure that the first 4 feilds are:
		//		1. unsigned char	uchMessageType;	//0
		//		2. unsigned short	ushMsgsQuantity;		//1
		//		3. long			lUncompressedMsgSize;	//3
		//		4. long			lCompressedMsgSize;		//7

		struct LoyaltyMsgHeader_ LoyaltyMsgHeader;
		struct StockMsgHeader_	 StockMsgHeader;
		//RSCL_BLOCK:START
		struct RsclSignatureCapture_ RsclSignatureCapture;
		//RSCL_BLOCK:END
		struct TicketData_		 TicketDataHeader; //FSD58559
		unsigned char NU[40];			
	};

	struct trans_tail_	tail;		//44 TRS tail
};

struct trs_info2_layby_financial_
{
    unsigned char  opcode;			//0x70	//0	<Opcode Value="0x70"/>
    unsigned char  function;		//0x34	//1	<Opcode Value="0x34"/>
	unsigned char  uchType;                 //2,  1  DEPOSIT
											//    2  PAYMENT.
											//    3  PAYMENT REVERSAL
											//    4  REFUND OF UNCLAIM DEPOSIT.
											//    5  FORFEITED DEPOSIT.
	long          lAmount;                  //3
	long          lPrvBalance ;             //7  
	unsigned char bcdLayByPaymentDate[4];   //11  LayBy payment date
	struct					//15
	{
		unsigned char bVoidLaybyFee	:1;	//15 mark this flag when layby fee is voided in layby cancel, so layby server can differentiate from the PAYMENT type
		unsigned char bFinaliseReversal :1; // #46253 TBR report uses this to handle Final payment when it needs to reverse a payment, due to over tender situation.
		unsigned char not_used	:6;
	}flags;

    unsigned char NU[28];			        //16
	
	struct trans_tail_	tail;		//44 TRS tail
};

//FSD1798
struct trs_info2_giftcard_activate_
{
    unsigned char	opcode;				//0x70		//0	<Opcode Value="0x70"/>
    unsigned char	function;			//0x35		//1 <Opcode Value="0x35"/>	TRANS_INFO2_GIFTCARD_ACTIVATE

    unsigned char   start_activation	            :1;	//2			
	unsigned char   end_activation		            :1;	//2			
	unsigned char   finished_read_out_card_session	:1;	//2
	unsigned char   GCM_flag		                :1;	//2 FSD63383  0: Gift Card 1: GCM Card
    unsigned char   bGiftCardActivationFailed       :1;	//2 FSD93620: Gift Card Activation Process (Provider = ECOM)
                                                        //            0: not Failed   1: Failed
    unsigned char   bOfflineEFTtran                 :1;	//2 FSD93620: Gift Card Activation Process (Provider = ECOM)
    unsigned char   NU1					            :2;	//2


	unsigned long	index;							//3  
	unsigned long	total_items;					//7
	
	unsigned short	ushSessionId;					//11 Gift Card activate session id

	unsigned char	NU[31];							//13 
	
	struct trans_tail_	tail;						//44 TRS tail
};


//FSD4930
struct trs_info2_zipcode_
{
    unsigned char	opcode;				//0x70		//0	<Opcode Value="0x70"/>
    unsigned char	function;			//0x36		//1 <Opcode Value="0x36"/>	TRANS_INFO2_ZIPCODE
	unsigned char	zipCode[10];					//2

	unsigned char	location[30];					//12
	unsigned char	NU[2];							//42
	
	struct trans_tail_	tail;						//44 TRS tail
};


// FSD6785
struct trs_ext_cust_info_
{
    unsigned char opcode;         //0x70	<Opcode Value="0x70"/>
    unsigned char function;       //0x39	<Opcode Value="0x39"/>	TRANS_INFO2_EXT_CUST_INFO
    unsigned char sub_function;   // 0 - number[20]
    							  // 1 - name  [40]
                                  // 2 - addres1 [40]
                                  // 3 - addres2 [40]
                                  // 4 - addres3 [40]
                                  // 5 - phone [20]
								  // 6 - date[12]
								  // 7 - time[10]
	                              // 8 - customer message[40] 
		                          // 9 - name and vat id (customer account).
                                  //10 - Profession (customer account).
	                              //11 - Fiscal office(customer account).
	                              //12 - New/Updated address.
								  //13 - name2 [40]
								  //14 - addres4 [40]
								  //15 - addres5 [40]
								  //16 - msg [40]
								  //17 - msg [40]
								  //18 - title: see "cust_info_combo_trs_field" in postype.h
								  //19 - surname [40]
								  //20 - phone2 [40]
								  //21 - promotion: see "cust_info_combo_trs_field" in postype.h
								  //22 - type: see "cust_info_combo_trs_field" in postype.h
								  //23 - state: see "cust_info_combo_trs_field" in postype.h
								  //24 - town [40]
								  //25 - post code [40]	                                 

    unsigned char first			:1; 
    unsigned char last			:1; 
	unsigned char bChequeVerif:1; 
	unsigned char nu1		  :5;

    unsigned char data[40];

    struct   trans_tail_  tail;
};



// FSD6785
struct trs_cheque_verif_data_
{
    unsigned char opcode;         //0x70	//0	<Opcode Value="0x70"/>
    unsigned char function;       //0x40	//1	<Opcode Value="0x40"/>	TRANS_INFO2_CHEQUE_VERIF_DATA
                                 
    unsigned char bCustomerData :1; 
	unsigned char nu1		    :7;			//2
	
	long		  lChequeAmount;			//3
	unsigned char szChequeNumber [8];		//7
	unsigned char szBankNumber   [13];		//15
	unsigned char szAccountNumber[13];		//28

	unsigned char nu2[3];					//41

    struct   trans_tail_  tail;				//44 TRS tail
};

//FSD3585 , this trs sent to update FO with data of '9220' messages used for 
//Animco third party loyalty server.
struct trs_info2_loyalty_transmission_pointer_
{
	unsigned char	opcode;				//0x70			 //0	<Opcode Value="0x70"/>
    unsigned char	function;			//0x41			 //1	<Opcode Value="0x41"/>	TRANS_INFO2_LOYALTY_TRANSMISSION_POINTER
	unsigned char   date_yymmdd[3];		//in bcd format  //2
	unsigned char	time_hhmmss[3];		//in bcd format  //5
	
	unsigned short  pos_number;			//8
	unsigned short  ticket_number;		//10
	unsigned char   send_status;		//0 = not sent, 1= success, 2 = failure.    //12

	unsigned char   opt_items_included	:1; //13 , tells if items included in the original message generated by the POS.
	unsigned char   opt_nu				:7;
	
	unsigned char auditNumber[5]; //14  bcd 10 digits
	unsigned char responseCode;   //19 response code from external loyalty server
	unsigned short numOfSendRetries;  //20 
	unsigned char nu[22];  //22

	struct trans_tail_	tail;						//44 TRS tail
};

/*----------------------------------------------------------------------
FSD2733.
Opcode: 0x70, function 42: to allow a maximum value of 21474836.48 on all amount fields with
                           the POS and FO application. GrandTotal may be with format __int64.
Dannyf 10/08/05 Add Fiscal info to transaction 0x70 0x42
Send this trans. before end of ticket transaction.
-----------------------------------------------------------------------*/
struct trs_info2_addition_ticket_total_		//OFS	Description
{
	unsigned char opcode;               //0   0x70		<Opcode Value="0x70"/>
	unsigned char function;             //1   0x42		<Opcode Value="0x42"/>
	unsigned char sub_function;         //2   reserve

    unsigned char opt_ticket_total       :1;//3		1:ticket total. 0:not a ticket total TRS
    unsigned char opt_void_ticket        :1;//3		Voided ticket
    unsigned char opt_save_ticket        :1;//3		Saved transaction
    unsigned char opt_recall_trans       :1;//3		Recalled transaction
    unsigned char opt_info               :1;//3		to update PC with POS grand ttl.
    unsigned char opt_tender_purchase    :1;//3		Tender purchase ticket
    unsigned char opt_NUi2_1             :2;//3		

    unsigned char opt_coupon_ticket      :1;//4		First item was a coupon	
    unsigned char opt_tender_ticket      :1;//4		First item was a tender
    unsigned char opt_IH_payment         :1;//4		First item is IH payment
    unsigned char opt_IH_purchase        :1;//4		First item is IH purchase	
    unsigned char opt_send_to_email      :1;//4		Send ticket by email
    unsigned char opt_NUi2_2             :3;//4		Not used

    unsigned short  ticket_no;				//5		Ticket amount
    unsigned char return_type;				//7 	Return type number (if a return ticket)
	__int64  GrandTotal;					//8		

	long	lFiscalTicketNumber;			//16    // Fiscal ticket number
	long	lFiscalSerialNumber;			//20    // Fiscal Serial number
	__int64 int64FiscalGrandTotal;			//24	// Fiscal Grand total
	unsigned short NRTResetCounter;			//32	// FSD5483
	unsigned long  OfficialReceipt;			//34	// FSD5483
	unsigned short ORResetCounter;			//38	// FSD5483
	long		   lAmount;					//40	// FSD5483

    struct   trans_tail_  tail;				//44	Transaction tail
};											//64

/*----------------------------------------------------------------------
FSD6814.
Opcode: 0x70, function 0x43, sub_function 0x00 : Invoice Header details.                         
-----------------------------------------------------------------------*/
struct trs_info2_ExtractHeaderDetails_		//OFS	Description
{
	unsigned char opcode;					 //0	<Opcode Value="0x70"/>
	unsigned char function;                  //1	<Opcode Value="0x43"/>
	unsigned char sub_function;              //2	<Opcode Value="0x00"/> 

	long lSegNumber;                         //3  Invoice number
	short shSeqDay;                          //7  Sequential day in year
	unsigned char Quality;                   //9  Customer Title from Cust.center
	unsigned short ushDocNum;                //10 Doc.type number
	unsigned short ushYear;					 //12 Year

	unsigned char paymentDueDate[3];		 //14 (YYMMDD in BCD)
	
	unsigned char nu[27];				     //17
	struct   trans_tail_  tail;				 //44	Transaction tail
};											 //64

/*----------------------------------------------------------------------
FSD6814.
Opcode: 0x70, function 0x43, sub_function 0x01 : Invoice Title details.                         
-----------------------------------------------------------------------*/
struct trs_info2_ExtractCustomerDetails_	 //OFS	Description
{
	unsigned char opcode;					 //0	<Opcode Value="0x70"/>
	unsigned char function;                  //1	<Opcode Value="0x43"/>
	unsigned char sub_function;              //2	<Opcode Value="0x01"/>

	unsigned char sub_details;    // 0 - number[20]
    							  // 1 - name1 [40]
								  // 1 - name2 [40]
                                  // 3 - addres1[40]
                                  // 4 - addres2[40]
                                  // 5 - addres3[40]
								  // 6 - addres4[40]
                                  // 7 - addres5[40]


    unsigned char data[40];                  //4 
	struct   trans_tail_  tail;				 //44	Transaction tail
};					
/*----------------------------------------------------------------------
FSD6814.
Opcode: 0x70, function 0x43, sub_function 0x02 : Invoice Line details.                         
-----------------------------------------------------------------------*/
struct trs_info2_ExtractLineDetails_
{
	unsigned char opcode;					 //0	<Opcode Value="0x70"/>	
    unsigned char function;                  //1	<Opcode Value="0x43"/>
    unsigned char sub_function;              //2	<Opcode Value="0x02"/>

	unsigned char sPluCode[7];               //3
	unsigned short ushDepNo;                 //10
    long lItemQty;		                     //12                       
    long lExclUnitAmount;                    //16
    long lExclAmount;                        //20
 	long lTaxRate;                           //24
	struct									 //28
	{ 
		unsigned char bDepSale          :1;
		unsigned char bReturnSale       :1;
		unsigned char bDecimalQty       :1;  //Weighted or decimal item
		unsigned char bNu               :5;
	};
	long lInclAmount;						//29 amount including tax

	unsigned char NotUsed[11];              //33
	struct   trans_tail_  tail;             //44
};

/*----------------------------------------------------------------------
FSD6814.
Opcode: 0x70, function 0x43, sub_function 0x03 : Invoice Tender details.                         
-----------------------------------------------------------------------*/
struct trs_info2_ExtractTenderDetails_
{
	unsigned char opcode;					 //0	<Opcode Value="0x70"/>	
    unsigned char function;                  //1	<Opcode Value="0x43"/>
    unsigned char sub_function;              //2	<Opcode Value="0x03"/>

	unsigned short ushTenderNo;				 //3		Tender number
	long lTenderAmount;                      //5
	unsigned char sTenderDescr[16];          //9

	unsigned char NotUsed[19];               //25
	struct   trans_tail_  tail;              //44
};

/*----------------------------------------------------------------------
FSD6814.
Opcode: 0x70, function 0x43, sub_function 0x04 : Invoice Tax details.                         
-----------------------------------------------------------------------*/
struct trs_info2_ExtractTaxDetails_
{
	unsigned char opcode;		            //0		<Opcode Value="0x70"/>
    unsigned char function;                 //1		<Opcode Value="0x43"/>
    unsigned char sub_function;             //2		<Opcode Value="0x04"/>

	unsigned char ushTaxNum;                //3  tax number
    long lTaxRate;                          //4

    long lTaxableAmount;				    //8  //H.T 
    long lTaxAmount;                        //12 //T.V.A
	long lTtlTaxAmount;                     //16 //T.T.C
	
	unsigned char NotUsed[24];              //20
	struct   trans_tail_  tail;             //44

};

/*----------------------------------------------------------------------
FSD6814.
Opcode: 0x70, function 0x43, sub_opcode 0x05 : Invoice Total details.                         
-----------------------------------------------------------------------*/
struct trs_info2_ExtractTotalDetails_
{
	unsigned char opcode;		            //0		<Opcode Value="0x70"/>
    unsigned char function;                 //1		<Opcode Value="0x43"/>
    unsigned char sub_function;             //2		<Opcode Value="0x05"/>

	// Ticket totals
	long lTtlDiscountAndRtrnAmount;         //3  //ttl discount & returns
	long lTtlWtDiscountAndRrtrnAmnt;        //7  //ttl without discount & returns

    long lTtlExclTaxAmount;	                //11 //ttl excl tax (HT)        
    long lTtlInclTaxAmount;                 //15 //ttl incl tax (TTL)

    // Tax totals
    long lTtlTaxableAmount;                 //19 HT
    long lTtlTaxAmount;                     //23 TVA
           
	unsigned char NotUsed[17];              //27
	struct   trans_tail_  tail;             //44
};

/*----------------------------------------------------------------------
FSD6814.
Opcode: 0x70, function 0x43, sub_function 0x06 : Invoice Customer Discount details.                         
-----------------------------------------------------------------------*/
struct trs_info2_ExtractCustDiscountDetails_
{
	unsigned char opcode;					 //0	<Opcode Value="0x70"/>
    unsigned char function;                  //1	<Opcode Value="0x43"/>
    unsigned char sub_function;              //2	<Opcode Value="0x06"/>

	struct
	{
		unsigned char bDiscountLine		:1;	 //3
		unsigned char bSubTotalDiscount	:1;
		unsigned char nu1				:6;
	};
	struct
	{
		unsigned char bCustDiscByNegDep	:1;	 //4
		unsigned char bPromotion		:1;
		unsigned char bDiscount			:1;
		unsigned char nu2				:5;
	};
	unsigned long DiscountNo;				 //5
	long Qty;								 //9
	long UnitPrice;							 //13
	long DiscountPercent;					 //17
	long TtlExclTaxAmt;						 //21
	long TtlInclTaxAmt;						 //25
	long TaxRate;							 //29 for DiscountLine only
	unsigned char PluCode[7];				 //33 for DiscountLine only
	unsigned char NotUsed[4];                //40
	struct   trans_tail_  tail;              //44
};

/*----------------------------------------------------------------------
FSD2733
Opcode: 0x70, function 0x44, trs_info_pos_report with numbers.                         
-----------------------------------------------------------------------*/
struct trs_info2_pos_report_bn_
{
    unsigned char opcode;			//0x70	//0		<Opcode Value="0x70"/>
    unsigned char function;         //0x44	//1		<Opcode Value="0x44"/>
    unsigned char sub_function;             //2: 1 or 2

	union 
	{
		struct
		{
			short          store_no;                 //3
			short          pos_no;                   //5
			unsigned short z_count;                  //7
			unsigned char  report_mode;              //9 (0=x,1=z)
			
			unsigned long  security_number;          //10
			
			unsigned char  eod_date[3];              //14 BCD
			unsigned char  nwd_date[3];              //17 BCD
			__int64        sales;                    //20
			__int64        discounts;				 //28
			
			unsigned char  reserved[8];              //36
		}InfPosRep1;

		struct
		{
			short          store_no;                 //3
			short          pos_no;                   //5
			unsigned char  report_mode;              //7 (0=x,1=z)
			
			__int64        gross_taking;             //8
			__int64		   promotions;               //16
			
			unsigned char  eod_date[3];              //24 BCD
			unsigned char  nwd_date[3];              //27 BCD
			
			unsigned char  reserved[14];              //30
		}InfPosRep2;

	}info;

    struct   trans_tail_  tail;              //44

};
/*----------------------------------------------------------------------
FSD3585
Opcode: 0x70, function 0x45.                       
-----------------------------------------------------------------------*/
struct trs_info2_ext_loyalty_reward_
{
    unsigned char opcode;		//0x70		//0	<Opcode Value="0x70"/>
    unsigned char sub_opcode;   //0x45		//1	<Opcode Value="0x45"/>
	
	struct 
	{
		unsigned char uchType;				//2
		unsigned char bcdPluCode[7];		//3
		unsigned short depNum;				//10
		long		   lNumOfRewards;		//12
	}rewardInfo;
	
	struct
	{
		unsigned char bRespOk	:1;			//16
		unsigned char bFlgNoUse :7;

		long		  lTotalRewardsPerTicket; //17
		long		  lPreviousBalance;		//21

	}gen_info;

	//FSD6795
	struct 
	{
		long lOpenBalance;					//25
		long lLoyaltyRedemptionsCounter;	//29
		long lLoyaltyTrxCounter;			//33
		char sServiceCode[2];				//37
		char sSecurityCode[5];				//39
	}RocksInfo;
	
	struct   trans_tail_  tail;             //44
};

/*----------------------------------------------------------------------
FSD6248 Lay By
Opcode: 0x70 (TRANS_INFO2), function 0x47 (TRANS_INFO2_ITEM_ADDITIONAL_INFO)                      
-----------------------------------------------------------------------*/
struct trs_info2_item_additional_info_
{
    unsigned char	opcode;				//0x70	//0	<Opcode Value="0x70"/>
    unsigned char	function;			//0x47	//1 <Opcode Value="0x47"/>	TRANS_INFO2_ITEM_ADDITIONAL_INFO

	unsigned char	sDescription[20];			//2 - item description
	long			lOriginalSequence;			//22
	unsigned char   bNotPresentFlag	:1;			//26
	unsigned char	bIgnoreFlag		:1;
	unsigned char	bAttachFlag		:1;
	unsigned char	bLaybyResellItem	:1;	//FSD18818 mark resell layby item from voiding item with promotions
	unsigned char	bUseUnknownItemDesc	:1;	//FSD14087
	unsigned char	bInsertLaybyPromo	:1;	//FSD18818
	unsigned char	NU_flags		:2;

	unsigned long   ulPluPrice ;                //27
    unsigned char	BCDID[2];					//31	attached parcel id in BCD format
	unsigned char	uchPrintLocationID;			//33 FSD39882 Enhanced ticket schemes
	char			chIndicatorForItem[2];		//34 FSD39882 Enhanced ticket schemes
	unsigned short	ushDocType;					//36
    unsigned char	NU[6];						//38
	
	struct trans_tail_	tail;					//44 TRS tail
};

struct trs_msg5_plu_ext_	//CR#6910
{
	unsigned char opcode;      //0x70	<Opcode Value="0x70" />
	unsigned char function;    //0x46	<Opcode Value="0x46" />

	unsigned char descr_msg_plu[22];	//2
	unsigned char User_Input[20];		//24

	struct   trans_tail_  tail;			//44
};


struct trs_msg5_plu_ext2_	//CR#6910
{
	unsigned char opcode;      //0x70	<Opcode Value="0x70" />
	unsigned char function;    //0x2A	<Opcode Value="0x2A" />

	unsigned char templateName[10];	//2
	
	unsigned char bPrintOnReceipt   :1; //12 ,  #16616
	unsigned char bSeparateTemplate :1; //12  FSD54935
	unsigned char bPrintMsgAtEndTicket  :1; //12  FSD71422
	unsigned char bPrintOncePerTicket   :1; //12  FSD71422  
	unsigned char Nu			        :4;

	unsigned char BatchNumber[11];		//13
	unsigned char ExpiryDate[10];	//24
	unsigned char uchNumOfReceiptCopies;    //34  FSD71422 
	unsigned char notUsed[9];               //35
	
	struct   trans_tail_  tail;			//44
};

struct trs_info2_unique_id_seq_			//FSD7345
{
	unsigned char opcode;				//0 //0x70								<Opcode Value="0x70"/>
    unsigned char function;				//1	//0x48	 TRANS_INFO2_UNIQUE_SEQ_ID	<Opcode Value="0x48"/>
	
	unsigned char uchSeqType;           //2 //Sequence Type (2=Tender, 3=Refund)
    unsigned char uchReturnType;		//3
	unsigned char sSeqID[10];			//4 //BCD ,Unique ID Sequence number.
	
	unsigned char	NU[30];	             //14

	struct   trans_tail_  tail;			 //44
};



// FSD6785
struct trs_gnrl_cust_info_
{
    unsigned char opcode;			//0xC4	<Opcode Value="0xC4"/>
    unsigned char function;			// 0 CUST_INFO_ORIGINAL
									// 1 CUST_INFO_FISCAL
									// 2 CUST_INFO_ACCOUNT
									// 3 CUST_INFO_HOME_DELIVERY
									// 4 CUST_INFO_PARCEL_PICK
									// 10 CUST_INFO_ACCT_VATID
									// 11 CUST_INFO_CHEQUE_VERIF
									// 12 CUST_INFO_LAYBY

    unsigned char sub_function;		// 0 - number[20]
    								// 1 - name  [40]
									// 2 - addres1 [40]
									// 3 - addres2 [40]
									// 4 - addres3 [40]
									// 5 - phone [20]
									// 6 - date[12]
									// 7 - time[10]
									// 8 - customer message[40] 
									// 9 - name and vat id (customer account).
									//10 - Profession (customer account).
									//11 - Fiscal office(customer account).
									//12 - New/Updated address.
									//13 - name2 [40]
									//14 - addres4 [40]
									//15 - addres5 [40]
									//16 - msg [40]
									//17 - msg [40]
									//18 - title: see "cust_info_combo_trs_field" in postype.h
									//19 - surname [40]
									//20 - phone2 [40]
									//21 - promotion: see "cust_info_combo_trs_field" in postype.h
									//22 - type: see "cust_info_combo_trs_field" in postype.h
									//23 - state: see "cust_info_combo_trs_field" in postype.h
									//24 - town [40]
									//25 - post code [40]
									//26 - Cust Vat Number - string[15]

    unsigned char bFirst		:1; 
    unsigned char bLast			:1; 
	unsigned char bIgnore		:1;
	unsigned char bLaybyDueDateChanged	:1;	//#25872
	unsigned char nu1			:4;
    unsigned char data[40];

    struct   trans_tail_  tail;
};

//CR#9244
struct trs_info2_plu_with_emb_price_
{
	unsigned char opcode;				//0 //0x70		<Opcode Value="0x70"/>
    unsigned char function;				//1	//0x49		<Opcode Value="0x49"/>

    unsigned char code[7];				//2		Item number (BCD)
	unsigned char FullCodePlu[14];		//9		item number with emb.price
	
	unsigned char bDisablePresentOfWeigtAndPricePerKilo :1; //23 

	unsigned char	NU[20];	             //24

	struct   trans_tail_  tail;			 //44
};

/*----------------------------------------------------------------------
FSD6248 Lay By Account Details
Opcode: 0x70 (TRANS_INFO2), function 0x4A (TRANS_INFO2_LAYBY_ACC_DETAIL)                      
-----------------------------------------------------------------------*/

struct trs_info2_layby_acc_detail_
{
    unsigned char	opcode;				//0x70	// 0	<Opcode Value="0x70"/>
    unsigned char	function;			//0x4A	// 1	<Opcode Value="0x4A"/>
	unsigned char	bcdLayByID[10];				// 2
	unsigned char	uchLayByStatus;				// 12
	unsigned char	bcdLayByDueDate[4];			// 13
	long			lMinDeposit;				// 17
	unsigned short	ushMinorLocation;			// 21
	unsigned char	bcdLayByOpenDate[4];		// 23
	long			lFeeAmnt;					// 27
	long			lTotalAmnt;					// 31
	long			lOutstandingBalance;		// 35
    unsigned short	ushDueDateExtension;		// 39 
	unsigned char	bFuelOfferGiven	:1;			// 41
	unsigned char	not_used		:7;			// 41
    unsigned short	ushMaxDueDateExtension;		// 42
	
	struct trans_tail_	tail;			   //44 TRS tail


};

/*----------------------------------------------------------------------
FSD6248 Lay By Message response Details
Opcode: 0x70 (TRANS_INFO2), function 0x2E (TRANS_INFO2_LAYBY_MESSAGE)                      
-----------------------------------------------------------------------*/

struct trs_info2_layby_message_
{
    unsigned char	opcode;			//0x70	// 0	<Opcode Value="0x70"/>
    unsigned char	function;		//0x2E	// 1 	<Opcode Value="0x2E"/>

	unsigned short	ushMessageId;			// 2
	unsigned char	bMessageWasRead :1;		// 4 YES/NO
	unsigned char	not_used		:7;		// 4
	
    unsigned char	sAnswer[39];			// 5 
	
	struct trans_tail_	tail;				//44 TRS tail
};


/*
	Opcode: 0x95 - TRANS_EXT_DATA External messages to send via T-LOG                    
 */
struct trs_ext_data_
{
	unsigned char	opcode;				//0x95	// 0	<Opcode Value="0x95"/>
	unsigned char	uchDataType;				// 1	Data types:								
												//												Defines:	
												//			1-LoyaltyMessages( zipped XML )		[LOYALTY_MSG = 1]	
												//			2-StockMessages (zipped XML)		[STOCK_MSG	 = 2]
												//			3-Stock Print Messages				[STOCK_PRINT_MSG = 3]
												//			4-Logix (NCR) Loyalty Messages ( zipped text )
												//			5-Rscl Signature Capture Messages	[SIGNATURE_CAPTURE_MSG = 5]
												//6- POS transaction schema in XML format //FSD58559
												//7- POS transaction data in XML format    // FSD58559
												//			8 - PDX Sold Request SL_US Issue #18249 - PDX Pharmacy [EL1G+TammyE]
												//			9 - M-DOT
												//			10 - ZeevM CR# 19845 3rd Solutions
												//			11 - POS transaction data in XML format, Additional data	//FSD#373244_XmlCompressToEJ

														
	unsigned char	Data[41];					// 2

	unsigned char	bStartBit	:1;				// 43 // Bits...
	unsigned char	bEndBit		:1;				 
	unsigned char	dataLen		:6;	         //FSD58559			 


	struct trans_tail_	tail;					//44 TRS tail
};

/*----------------------------------------------------------------------
DR#6625
Opcode: 0x70, function 0x50, fiscal sub-total .
-----------------------------------------------------------------------*/
struct trs_info2_fiscal_sub_total_
{
	unsigned char opcode;    //0x70                 //0	<Opcode Value="0x70"/>
	unsigned char function;  //0x50                 //1	<Opcode Value="0x50"/>

	short items;                                    //2
	long  amount;									//4
  
	unsigned char reserved[36];                     //8

	struct   trans_tail_  tail;                     //44
};

/*----------------------------------------------------------------------
#10425
Opcode: 0x70, function 0x51, Add segment to prom engine
-----------------------------------------------------------------------*/
#define  BARCODE_PROGRAMING_SEG_TRIGGER		0	//FSD12648
#define  MANUAL_FUNCTION_SEG_TRIGGER		1	//FSD12648
#define  LAYBY_SEG_TRIGGER					2	//FSD14864
#define  TS_SEG_TRIGGER					    3	//FSD36846 - Ticket scheme trigger.
#define  TPL_NO_RESPONSE_SEG_TRIGGER		4	//FSD42115 Everyday reward card redemption, when third party loyalty server does not respond
#define	 TPL_NO_RESPONSE_STAFF_DIS_SEG_TRIGGER 5 //FSD42115 EDRC redemption when third party loyalty server does not respond but staff discount exist.
#define	 TPL_EDRC_WITH_SEGMENT_TRIGGER		6	//FSD53587
#define  POPULATION_SEG_TRIGGER				7	//FSD231586 StoreLine Philippines Legal Requirement for Tax Deduction 
#define  PROHIBIT_POINTS					8   // Epic 429380
 
struct trs_info2_add_segment_
{
	unsigned char opcode;    //0x70                 //0	<Opcode Value="0x70"/>
	unsigned char function;  //0x51                 //1	<Opcode Value="0x51"/>
 
	unsigned long ulSegment;                        //2
	unsigned char uchSegmentopCode;     //6
  
	struct           //7
	{
		unsigned char opt_ignore   :1;  //FSD12648
		unsigned char opt_thirdPartyReport :1;  //FSD12648
		unsigned char opt_descOnCustomerDisplay	:1;	//FSD12648
		unsigned char opt_descOnOperatorDisplay	:1;	//FSD12648
		unsigned char opt_voided		:1;	//FSD231586StoreLine Philippines Legal Requirement for Tax Deduction
		unsigned char opt_NU			:3;	//FSD12648
	}Options;
 
	unsigned char uchTriggerType;					//8	FSD12648: 0 - barcode programing, 1 - manual function
	unsigned char uchBarcodeLen;					//9	FSD12648
	unsigned char sBarcode[10];						//10FSD12648: Barcode in BCD
 
	unsigned char uchNumberOfRewardsTriggered;		//20 #15334
	unsigned char uchSchemeNo;						//21
	
	long  lMaxSpendOnRewardCalculation;				//22 //FSD231586 StoreLine Philippines Legal Requirement for Tax Deduction 
	
	unsigned char reserved[18];                     //26
 
	struct   trans_tail_  tail;                     //44
};
 


/*----------------------------------------------------------------------
FSD# 7610
Opcode: 0x70, function 0x53, eft session id.
-----------------------------------------------------------------------*/
struct trs_info2_eft_session_
{
	unsigned char opcode;    //0x70                 //0	<Opcode Value="0x70"/>
	unsigned char function;  //0x53                 //1	<Opcode Value="0x53"/>
	long	sessionID;								//2
	unsigned char uchProviderID;					//6
	unsigned char uchAuthNum[22];					//7
	
	struct flags_auth_  							//29							
    {
	    unsigned char auth_succeed				:1;
		unsigned char auth_failed				:1;
		unsigned char auth_timeout				:1;
		unsigned char void_after_auth			:1;   //For auth trs which was voided
		unsigned char bBillPayment				:1;  
		unsigned char bWasPrinted  				:1;
		unsigned char bCancellation				:1;  //Void trs
		unsigned char bNUCC						:1;	
	}flags_auth; 

	unsigned char uchOfflineEftTenderId;			//30 // CR#96167

	unsigned char not_used[13];						//31

	struct trans_tail_ tail;						//44
};

/*----------------------------------------------------------------------
FSD# 7610
Opcode: 0x70, function 0xE1, OLA Session execution, Generic Services
-----------------------------------------------------------------------*/
//FSD55825 - remove bOlaPartDone
struct trs_info2_ola_session_
{
	unsigned char opcode;    //0x70                 //0	<Opcode Value="0x70"/>
	unsigned char function;  //0xE1                 //1	<Opcode Value="0xE1"/>

	struct olaFlags_
	{
		unsigned char bPosPartDone	: 1;
		unsigned char schemeNumber	: 6; //FSD55425
		unsigned char bTemplatePrintingSucceeded		: 1;
	}olaFlags;										//2
	
	unsigned char olaRequestType;					//3		//0 - Unknown, 
															//1 - Payment, 
															//2 - Void, 
															//3 - Refund
	long lAmount;									//4
	unsigned char number[7];						//8
	unsigned char serializedSession[29];			//15
	struct trans_tail_ tail;						//44
};

/*----------------------------------------------------------------------
Opcode: 0x80, function 0x1A, OLA Session execution, Generic Services
-----------------------------------------------------------------------*/
struct trs_info3_ola_session_ext_
{
	unsigned char opcode;    //0x80                 //0	<Opcode Value="0x80"/>
	unsigned char function;  //0x1A                 //1	<Opcode Value="0x1A"/>

	
	long lTriggerTransactionSeq;					//2
	
	// FSD70144
	unsigned char sEFTTerminalID[8];				//6
	unsigned char sEFTTransactionID[6];				//14

	struct olaFlagsExt_
	{
		unsigned char bOlaPartDone											:1; //TD143070
		unsigned char bGseCustomerSlipPrinted								:1;	//EVGAUS
		unsigned char bGseStoreSlipPrinted									:1; //EVGAUS
		unsigned char bRecreateNotNeeded									:1; //FSD259707
		unsigned char bPrintSlip											:1; //TSC - PayPoint - CR #235029
		unsigned char bConfirmationRequired									:1; //FSD298953 - EFT Solution for Aserv
		unsigned char bEServicesTemplatePrinted								:1; //FSD365694
		unsigned char bEserviceTemplatePrintSeperateSlip					:1;//FSD370728
	}olaFlagsExt;										//20


	long lCommitTransactionSeq;					//21 TSC - PayPoint - CR #235029

	int iStatus;									//25 //FSD#298953
	unsigned char  unchSessionTemplateName[10];		//29
	struct 
	{
		unsigned char bDontPrintCustomerCopy :1;	//39
		unsigned char bDontPrintStoreCopy	:1;
		unsigned char nu					:6;

	}olaFlagsExt1;

	unsigned char nu[4];							//40
	
	struct trans_tail_ tail;						//44
};

/*----------------------------------------------------------------------
Opcode: 0x80, function 0x94,  OnlineGSEIdentifier 
-----------------------------------------------------------------------*/
struct trs_info3_online_identifier_
{
	unsigned char opcode;    //0x80                 //0	<Opcode Value="0x80"/>
	unsigned char function;  //0x94                 //1	<Opcode Value="0x"/>
	
	
	unsigned char bcdOnlineIdentifier[10];				//2   //FSD407160
	unsigned char NU[32];								//12
	
	struct trans_tail_ tail;						//44
};



/*----------------------------------------------------------------------
Generic Services
Opcode: 0x70, function 0xE4, OLA Session execution identifier key, 
-----------------------------------------------------------------------*/
struct trs_info2_ola_identifier_Key_
{
	unsigned char opcode;    //0x70                 //0	<Opcode Value="0x70"/>
	unsigned char function;  //0xE4                 //1	<Opcode Value="0xE4"/>

	unsigned short int  tender_no;					//2
	char identifierKey[39];							//4	increase to 39 for TD453946
	unsigned char bWasRecoveryTndr;					//43
	//unsigned char not_used[1];						//43
	struct trans_tail_ tail;						//44
};

/*----------------------------------------------------------------------
FSD# 7962
Opcode: 0x70, function 0x1D
-----------------------------------------------------------------------*/
struct trs_info2_ccms_timestamp_
{
	unsigned char opcode;							//0  0x70 TRANS_INFO2
	unsigned char function;							//1  0x1D TRANS_INFO2_CCMS_TIMESTAMP
	unsigned char date[3];							//2  BCD Date yymmdd
	unsigned char time[3];							//5  BCD Time HHMMSS
	unsigned char acct_num[20];						//8
	
	unsigned char not_used[16];						//28
	struct trans_tail_ tail;						//44
};

/*----------------------------------------------------------------------
FSD# 7934
Opcode: 0x70, function 0x1C, header record
-----------------------------------------------------------------------*/
struct trs_micr_hdr_
{
    unsigned char opcode;			//0x70 - 0
    unsigned char function;			//0x1C - 1
	unsigned char sub_func;			//0x01 Header record - 2

	short	 unzipped_buffer_size;	//3
	short	 num_of_micr_seq;		//5
	unsigned char nu1[37];			//7

    struct   trans_tail_  tail;		//44
};

/*----------------------------------------------------------------------
FSD# 7934
Opcode: 0x70, function 0x1C, data record
-----------------------------------------------------------------------*/
struct trs_micr_data_
{
    unsigned char opcode;			//0x70 - 0
    unsigned char function;			//0x1C - 1
	unsigned char sub_func;			//0x02 Data record - 2

	unsigned char seq_no;			//bcd 0x00 to 0x99 - 3
	unsigned char data[40];			//4

    struct   trans_tail_  tail;		//44
};

/*----------------------------------------------------------------------
FSD# 3122
Opcode: 0x70, function 0x07, rss14 data
-----------------------------------------------------------------------*/
struct trs_info2_rss_data1_
{
    unsigned char opcode;							// 0	// TRANS_INFO2
    unsigned char function;							// 1	// TRANS_INFO2_RSS_DATA1

	unsigned char weight_digits;					// 2
	unsigned char weight[3];						// 3	// AI #310 or #320 (BCD)

	unsigned char embedded_price_digits;			// 6
	unsigned char embedded_price[8];				// 7	// AI #390 or #392 (BCD)

	unsigned char quantity[4];						// 15	// AI #30 (BCD)

	unsigned char packaging_date[3];				// 19	// AI #13 (YYMMDD BCD)
	unsigned char sell_by_date[3];					// 22	// AI #15 (YYMMDD BCD)
	unsigned char expiration_date[3];				// 25	// AI #17 (YYMMDD BCD)
	unsigned char production_date[6];               // 28   //enh #5673

	unsigned char uchWeightUnits;					// 34

	unsigned char reserved[9];						// 35

	struct trans_tail_ tail;						// 44
};

/*----------------------------------------------------------------------
FSD# 3122
Opcode: 0x70, function 0x08, rss data2
-----------------------------------------------------------------------*/
struct trs_info2_rss_data2_
{
    unsigned char opcode;							// 0	// TRANS_INFO2
    unsigned char function;							// 1	// TRANS_INFO2_RSS_DATA2

	unsigned char batch_lot_number[20];				// 2	// AI #10
	unsigned char serial_number[20];				// 22	// AI #21

	unsigned char country_of_origin[2];				// 24	// AI #422 (BCD)

	struct trans_tail_ tail;						// 44
};

/*----------------------------------------------------------------------
FSD# 216989 
Opcode: 0x70, function 0x97, rss data3
-----------------------------------------------------------------------*/
struct trs_info2_rss_data3_
{
    unsigned char opcode;							// 0	// TRANS_INFO2
    unsigned char function;							// 1	// TRANS_INFO2_RSS_DATA3

	unsigned char GlobalLocationNum[13];			// 2
	unsigned char PaymentSliptRefNum[25];			// 15
	
	unsigned char reserved[4];						// 40

	struct trans_tail_ tail;						// 44
};

/*----------------------------------------------------------------------
FSD# 216989 
Opcode: 0x70, function 0x98, rss data4
-----------------------------------------------------------------------*/
struct trs_info2_rss_data4_
{
    unsigned char opcode;							// 0	// TRANS_INFO2
    unsigned char function;							// 1	// TRANS_INFO2_RSS_DATA4

	unsigned char AmountPayable[15];				// 2

	unsigned char reserved[27];						// 17

	struct trans_tail_ tail;						// 44
};


/*----------------------------------------------------------------------
FSD# 7934
Opcode: 0x60, function 0xED, Alb Reason Code
-----------------------------------------------------------------------*/
struct trs_info_reason_code_US_VERSION_
{
	unsigned char opcode;							// 0	// TRANS_INFO
	unsigned char function;							// 1	// TRANS_INFO_REASON_CODE

	unsigned long type;								// 2	// reason code type

	unsigned long reason_code;						// 6	// reason code
	unsigned char reason_desc[30];					// 10	// reason code description
	
	unsigned char reserved[4];						// 40

	struct trans_tail_ tail;						// 44
};

/*----------------------------------------------------------------------
FSD# 7934
Opcode: 0x70, function 0x1B, QSR
-----------------------------------------------------------------------*/
struct trs_info2_qsr_
{
    unsigned char opcode;							// 0	// TRANS_INFO2
    unsigned char function;							// 1	// TRANS_INFO2_QSR

	unsigned char qsr_trans_opcode;					// 2	// QSR Transaction Opcode

	union											// 3	// QSR Transaction
	{
		// ------------------------------------------------------------------------------------------------------------
		struct item_sale_							////////// Item Sale (0x01: QSR_INFO_TRANS_ITEM_SALE)
		{
		unsigned char plu_code[7];					// 3	// PLU Code of Item
		unsigned char item_type;					// 10	// Type of Item (Make Item, Combo, etc)

		unsigned long external_sale_handle;			// 11	// External Sale Handle

		long quantity;								// 15	// Quantity Sold
		long sell_price;							// 19	// Total Selling Price

		unsigned char suggested_sale_indicator		:1;	// 23	// Suggested Sale Item?
		unsigned char upsized_sale_indicator		:1;			// Upsized Item?
		unsigned char overwritten_sell_by_date		:1;			// Sell by Date was Overwritten?
		unsigned char in_combo						:1;			// Indicates the item is part of a combo with the same handle #
		unsigned char alternative_sale_indicator	:1;			// Alternative Item Chosen?
		unsigned char quantity_as_weight			:1;			// Quantity is Really a Weight
		unsigned char reserved_23					:2;

		unsigned char swapped_plu_code[7];			// 24	// If Upsized or Alternated, the Original Item

		unsigned long external_segment_handle;		// 31	// External Segment Handle

		unsigned char sell_by_date[3];				// 35	// Sell by Date (BCD MMDDYY)
		unsigned char sell_by_date_override[3];		// 38	// Overwritten Sell by Data (BCD MMDDYY)

		short qty_msu_ratio;						// 41
		} item_sale;

		// ------------------------------------------------------------------------------------------------------------
		struct ingredient_							////////// Ingredient (0x02: QSR_INFO_TRANS_INGREDIENT)
		{
		unsigned char plu_code[7];					// 3	// PLU Code of Ingredient

		unsigned long external_sale_handle;			// 10	// External Sale Handle where this Ingredient was Used
		unsigned char item_plu_code[7];				// 14	// Item PLU this Ingredient was Used
		long factor;								// 21	// Quantity of Ingredient Sold
		long additional_cost;						// 25	// Additional Price of Ingredient
		long operator_id;							// 29	// Operator Maint ID of Operator Used
		unsigned long external_segment_handle;		// 33	// External Segment Handle where this Ingredient was Used

		unsigned char reserved[6];
		} ingredient;

		// ------------------------------------------------------------------------------------------------------------
		struct special_order_						////////// Special Order (0x03: QSR_INFO_TRANS_SPECIAL_ORDER)
		{
		unsigned char reserved[40];					// 3
		} special_order;

		// ------------------------------------------------------------------------------------------------------------
		struct pre_pack_mode_						////////// Pre Pack Mode (0x04: QSR_INFO_TRANS_PRE_PACK)
		{
		unsigned char reserved[40];					// 3
		} pre_pack_mode;

		// ------------------------------------------------------------------------------------------------------------
		struct order_instructions_					////////// Order Instructions (0x05: QSR_INFO_TRANS_ORDER_INSTRUCTIONS)
		{
		unsigned char section;						// 3	// Instructions Text Section
		unsigned char last_transaction		:1;		// 4
		unsigned char reserved				:7;
		unsigned char text[38];						// 5	// Instructions Text
		} order_instructions;

		// ------------------------------------------------------------------------------------------------------------
		struct waste_mode_							////////// Waste Mode (0x06: QSR_INFO_TRANS_WASTE)
		{
		unsigned char reserved[40];					// 3
		} waste_mode;

		// ------------------------------------------------------------------------------------------------------------
		//Enh #9219SL - QSR Future Order.
		struct future_order_mode_					////////// Future Order Mode (0x07: QSR_INFO_TRANS_FUTURE_ORDER)
		{
		unsigned char order_number[12];				// 3
		unsigned char customer_id[3];				// 15 bcd
		unsigned char order_status;					// 18	0 ?EFuture Order New 
													//		1 ?EFuture Order Update
													//		2 ?EFuture Order Delete

		unsigned char reserved[24];					// 19
		} future_order_mode;

		// ------------------------------------------------------------------------------------------------------------
		struct dont_record_inventory_mode_			////////// Dont Record Mode (0x08: QSR_INFO_TRANS_DONT_RECORD_INVENTORY)
		{
		unsigned char reserved[40];					// 3
		} dont_record_inventory_mode;

		// ------------------------------------------------------------------------------------------------------------
		struct package_								////////// Package (0x09: QSR_INFO_TRANS_PACKAGE)
		{
		unsigned long number;						// 3	// Package Number

		unsigned char begin						:1;	// 7	// Start of Package?
		unsigned char end						:1;			// End of Package?
		unsigned char reserved_7				:6;

		unsigned long price;						// 8	// Package Price
		unsigned long count;						// 12	// Number of Items in Package

		unsigned char plu_code[7];					// 16	// Package PLU Code

		unsigned char reserved[20];					// 23
		} package;
		// ------------------------------------------------------------------------------------------------------------
		struct cust_info_1_							////////// cust info part 1 (0x0A: QSR_INFO_TRANS_CUST_INFO_1)
		{
		unsigned char first_name[20];			// 3	
		unsigned char last_name[20];			//23
		} cust_info_1;

		// ------------------------------------------------------------------------------------------------------------
		struct cust_info_2_							////////// cust info part 2 (0x0B: QSR_INFO_TRANS_CUST_INFO_2)
		{
		unsigned char middle_initial;			//3
		unsigned char area_code[3];				//4
		unsigned char phone_number[7];			//7
		unsigned char state[2];					//14
		unsigned char zip_code[5];				//16
		unsigned char city[20];					//21
		unsigned char reserved[2];				//41
		} cust_info_2;

		// ------------------------------------------------------------------------------------------------------------
		struct cust_info_3_							////////// cust info part 3 (0x0C: QSR_INFO_TRANS_CUST_INFO_3)
		{
		unsigned char street_name_1[20];			// 3	
		unsigned char street_name_2[20];			//23
		} cust_info_3;

		// ------------------------------------------------------------------------------------------------------------
		struct cust_info_4_							////////// cust info part 4 (0x0D: QSR_INFO_TRANS_CUST_INFO_4)
		{
		unsigned char business_name[40];			// 3	
		} cust_info_4;

		// ------------------------------------------------------------------------------------------------------------
		struct pickup_info_							////////// Pickup Info (0x0E: QSR_INFO_TRANS_PICKUP_INFO)
		{
		unsigned char order_payment_status;			//3		0 ? Future Order (COD)
													//		1 ? Future Order Paid

		unsigned char date[3]; // BCD mmddyy		//4
		unsigned char time[3]; // BCD hhmmss		//7
		unsigned char person_to_pickup[20];			//10
		unsigned char customized_order_status;		//30
		unsigned char qsr_order_executed	:1;		//31 
		unsigned char reserved_7			:7;

		unsigned char reserved[11];					//32
	
		} pickup_info;
		
		// ------------------------------------------------------------------------------------------------------------
		struct item_instructions_					////////// Item Instructions (0x0F: QSR_INFO_TRANS_ITEM_INSTRUCTIONS)
		{
		unsigned char section;						// 3	// Instructions Text Section
		unsigned char item_plu_code[7];				// 4	// PLU code that the instructions belongs to.
		unsigned long external_sale_handle;			// 11	// External Sale Handle where this Ingredient was Used
		unsigned char last_transaction		:1;		// 15
		unsigned char reserved				:7;
		unsigned char text[27];						// 16	// Instructions Text
		} item_instructions;

		// ------------------------------------------------------------------------------------------------------------
		struct pay_later_							////////// Pay Later Ticket (0x10: QSR_INFO_TRANS_PAY_LATER)
		{
		unsigned char reserved[40];					// 3
		} pay_later;

		// ------------------------------------------------------------------------------------------------------------
		struct reference_information_				////////// Reference Information (0x11: QSR_INFO_TRANS_REFERENCE_INFO)
		{
		unsigned char text[40];					// 3
		} reference_information;

	} qsr_trans;

	unsigned char	special_order				:1;	// 43	// Is this a Special Order?
	unsigned char	waste						:1;			// Is this Waste Info?
	unsigned char	dont_record					:1;			// Don't Record Inventory?
	unsigned char	reserved_43					:5;

	struct trans_tail_ tail;						// 44
};

/*----------------------------------------------------------------------
FSD8152
Opcode: 0x70, function 0x1F, delayed fiscal lines.
-----------------------------------------------------------------------*/

struct trs_info2_delayed_fiscal_prom_line_
{
	unsigned char opcode;    //0x70                 //0	<Opcode Value="0x70"/>
	unsigned char function;  //0x1F                 //1	<Opcode Value="0x1F"/>
	long		  discount_amount;					//2
	long		  discount_percent;					//6
	
	unsigned char opt_automatic     :1;			    //10
	unsigned char opt_order			:1;
	unsigned char not_in_use		:6;			    

	unsigned char prom_name[20];				    //11
	long		  tax;								//31

	char		  filler[9];						//35
	
	struct   trans_tail_  tail;                     //44
};

struct trs_info2_end_ticket_vouchers_
{
	unsigned char opcode;    //0x70                 //0	<Opcode Value="0x70"/>
	unsigned char function;  //0x54                 //1	<Opcode Value="0x54"/>

	long lActiveKidsPromotionBasicPoints;			//2 // FSD9034
	long lActiveKidsPromotionBonusPoints;			//6 // FSD9034

	char filler[34];								//10

	struct trans_tail_ tail;						//44
};

//FSD 11456
struct trs_non_post_void_eft_				//OFS	Description
{
    unsigned char opcode;					//0		0x60	<Opcode Value="0x60"/>
    unsigned char function;					//1		0x08	<Opcode Value="0x08"/>
	long          amount;					//2
    unsigned char account[21];				//6		account number (ascii)
    unsigned char auth_no[9];				//27	authorization number
    unsigned char NO3[8];					//36	
    
    struct   trans_tail_  tail;				//44	TRS tail
};		

//FSD7148_OfflineGiftVouch
struct trs_info2_gift_vouch_acc_conversion_
{
	unsigned char opcode;    //0x70                 //0	<Opcode Value="0x70"/>
	unsigned char function;  //0x2D                 //1	<Opcode Value="0x2D"/>
	unsigned char subfunction;						//2	:  1(full number),2(conversion)-online; 5(full),6(conversion)-offline

	unsigned short NoTender;						//3
	long		   lAmountGF;						//5
	union
	{
		struct
		{
			unsigned char FullAccountOffl[30];		//9
			char NU1[5];
		}AcctGVFull;
		struct 
		{
			unsigned char AccountGiftVouch[30];		//9
			char NU2[5];
		}AcctConversionGF;
	};

	struct trans_tail_ tail;						//44
};

struct trs_info2_tax_voucher_printed_
{
    unsigned char opcode;         //0x70	//0	<Opcode Value="0x70"/>
    unsigned char function;       //0x55	//1	<Opcode Value="0x55"/>

	unsigned short	ushPosNumber;			//2
	unsigned short	ushTicketNumber;		//4
	unsigned long	ulTicketAmount;			//6
	unsigned long	ulTotalCashAmount;		//10
	unsigned char	m_chTransactionDate[3];	//14 YYMMdd
	unsigned char	m_chTransactionTime[3];	//17 HHmmSS
	unsigned short	ushLevelNumber;			//20
	unsigned long	ulTaxAmount;			//22
	unsigned long	ulTaxVoucherNum;		//26
	unsigned char	NU[14];		            //30

	struct trans_tail_ tail;				//44
};

//FSD9306
struct trs_info2_post_void_
{
   	unsigned char opcode;            //0x70       //0	<Opcode Value="0x70"/>
   	unsigned char function;          //0x3A       //1	<Opcode Value="0x3A"/>

   	unsigned short ushTransID;                    //2  // Current trans.id
	unsigned char  bcdTransDate[3];               //4  // Current trans.date

	unsigned short ushTransPosNo;                 //7  // Current Pos number.                                   
	unsigned char  uchPostVoidStatus;             //9  // Post Void Status

    unsigned char not_used;                       //10  // not used                                                	                                   

	long lTicketAmount;                           //11  // Ticket amount

	unsigned short ushCnclTransID;                //15  // Cancellation trans.id
	unsigned char  bcdCnclTransDate[3];           //17  // Cancellation trans.date
	unsigned short ushCnclTransPosNo;             //20  // Current Pos number.     

    unsigned short ushOrigTransID;                //22  // Original trans.id
	unsigned char  bcdOrigTransDate[3];           //24  // Original trans.date
	unsigned short ushOrigTransPosNo;             //27  // Original Pos number.       

    unsigned short ushPostVoidCounter;            //29  // Pos Void Counter                                                
    unsigned char NU[13];                         //31  // Not used

    struct   trans_tail_  tail;                    //44
};

//Work around for version 8710 .
struct trs_info2_end_of_ticket_apportmnt_
{
		unsigned char opcode;				//0	<Opcode Value="0x70"/>
	   	unsigned char function;				//1	<Opcode Value="0x3B"/>
		
		unsigned char bEnd		:1;			//2
		unsigned char bnu		:7;

		unsigned char NU[41];				//3 // Not used
		struct   trans_tail_  tail;			//44
};


//FSD9306
struct trs_invo2_post_void_resell_
{
	unsigned char opcode;	  	       //0x70	<Opcode Value="0x70"/>
	unsigned char function;		       //0x3C	<Opcode Value="0x3C"/>

	unsigned char uchTrsType;          //2  // 1 - Post Void
	                                        // 2 - Resell

	unsigned short ushOrigTransID;      //3  // Retrieve Trans ID
	unsigned short ushOrigPosNo;	    //5  // Retrieve Pos ID
	unsigned char  bdcOrigTransDate[3]; //7  // Retrieve Trans date

	
	unsigned char reserved[34];               //10
	struct   trans_tail_  tail;               //44
};

//FSD7315, FSD433403
struct trs_info2_guid_
{
  unsigned char opcode;            //0x70       //0		<Opcode Value="0x70"/>
  unsigned char function;          //0x56       //1		<Opcode Value="0x56"/>
  unsigned char uchguid[32];	                //2
  long MMId;									//34	CR337587

  unsigned char bPrintCouponStatus				:1;	//38	//FSD433403
  unsigned char bPrintableCouponIndication	    :1;			//FSD433403
  unsigned char bPrintConirmFooterLines	        :1;	        //CR448058
  unsigned char bnu							    :5;

  unsigned char nu[5];							//39 
  struct   trans_tail_  tail;					//44
};

//FSD7315
struct trs_info2_print_line_
{
	unsigned char opcode;            //0x70       //0		<Opcode Value="0x70"/>
	unsigned char function;          //0x57       //1		<Opcode Value="0x57"/>

	unsigned char bNoMask					:1	;			// 2 CR337587
	unsigned char bIsLarge					:1	;			// 2 CR337587
	unsigned char bBold						:1	;			// 2 CR337587
	unsigned char bNU1						:5	;			// 2

	unsigned char BarcodeLen;								// 3 CR71648

	unsigned char bMasked					:1	;			//4//FSD#66478
	unsigned char bEncrypted				:1	;			//4//FSD#66478
	unsigned char bStartSplitTransaction	:1	;			//4//FSD#66478
	unsigned char bEndSplitTransaction		:1	;			//4//FSD#66478
	unsigned char bBarcodeITF				:1;				// 4 CR71648
	unsigned char bBarcodeCode128P			:1;				// 4 CR337587
	unsigned char bPrintOnlyBarCode			:1	;			//PaulG	(CR409559)
	unsigned char bNU						:1	;			//4


  unsigned char  line[39];                     //5
  struct   trans_tail_  tail;                  //44
};


//FSD7315
struct trs_info2_print_confirm_
{
  unsigned char opcode;            //0x70       //0		<Opcode Value="0x70"/>
  unsigned char function;          //0x58       //1		<Opcode Value="0x58"/>
  unsigned short  plu_seq;                       //2
	unsigned char bMasked					:1;				//4//FSD#66478 - may use it later
	unsigned char bEncrypted				:1	;			//4//FSD#66478 - may use it later
	unsigned char bStartSplitTransaction	:1	;			//4//FSD#66478
	unsigned char bEndSplitTransaction		:1	;			//4//FSD#66478
	unsigned char bNU						:4	;			//4
  unsigned char  line[39];                     //5
  struct   trans_tail_  tail;                  //44
};


//FSD7315
struct trs_info2_print_footer_
{
  unsigned char opcode;            //0x70       //0		<Opcode Value="0x70"/>
  unsigned char function;          //0x59       //1		<Opcode Value="0x59"/>
  unsigned char count;    //2
  unsigned char nu[2];                        //2
  unsigned char  line[39];                     //5
  struct   trans_tail_  tail;                  //44
};

//#12818
struct trs_info2_cancel_prom_apportion_
{
	unsigned char opcode;					//0	
	unsigned char function;					//1
	unsigned char uchCancellationReason;	//2		#13970 - reason for promotion apportionment cancellation
	unsigned char NU[41];					//3
	struct   trans_tail_  tail;				//44
};

//FSD11256
struct trs_info2_ticket_start_time_
{
  unsigned char opcode;            //0x70      //0	<Opcode Value="0x70"/>
  unsigned char function;          //0x61      //1	<Opcode Value="0x61"/>
  long			 pos_no;						        //2
  long			 ticket_no;					        //6
  long			 start_time;					     //10
  unsigned char nu[30];                        //14
  struct   trans_tail_  tail;                  //44
};


//FSD2615
struct trs_info2_bill_payment_ext0_
{
   unsigned char opcode;            //0x70      //0		<Opcode Value="0x70"/>
   unsigned char function;          //0x62      //1		<Opcode Value="0x62"/>
   unsigned char GUID[36] ; //2           //format 8-4-4-4-12
   unsigned char authorized :1;   //38
   unsigned char item_void     :1; //38
   unsigned char item_adviced    :1;          //38
   unsigned char nubits     :5;
   long  card_limit;     //39
   unsigned char nu[1];               //43
   struct   trans_tail_  tail;                  //44
};

//FSD2615
struct trs_info2_bill_payment_ext1_
{
  unsigned char opcode;            //0x70      //0	<Opcode Value="0x70"/>
  unsigned char function;          //0x63      //1	<Opcode Value="0x63"/>
  unsigned char barcode[12];      //2 
  unsigned char accountNumber[12]; //14
  unsigned char billerName[12];             //26
  unsigned long billerID;        //38
  unsigned char barcodeExtExist :1;        //42
  unsigned char billerNameExtExist :1;      //42
  unsigned char accountNumberExtExist :1; //42                     //43
  unsigned char nu :5;  //42 
  unsigned char nu1 ;  //43
  struct   trans_tail_  tail;                  //44
};

//FSD2615 
struct trs_info2_bill_payment_ext2_
{
  unsigned char opcode;            //0x70      //0	<Opcode Value="0x70"/>
  unsigned char function;          //0x64      //1	<Opcode Value="0x64"/>
  unsigned char IdentifyId[7];    //2
  unsigned short schema_id;      //9
  unsigned char BpBCDbarcode[26];				//11 asafr FSD64471 BCD bill payment barcode
  unsigned char nu[7];							//37

  struct   trans_tail_  tail;                  //44
}; 




//FSD2615
struct trs_info2_bill_payment_ext3_
{
   unsigned char opcode;            //0x70      //0 <Opcode Value="0x70"/>
   unsigned char function;          //0x65      //1	<Opcode Value="0x65"/>
   unsigned short plu_seq_no;                   //2  //reference to the plu                   
   long    credit ;                    //4
   long    debit;   //8  	   
   long    cash ;                               //12
   long    cheque;                              //16
   long    other;                               //20 
   unsigned char advice_status  :2;      //24
   unsigned char nu0      :6;     //24 

	long			MaxPayment;						//25 asafr FSD64471
	long			MinPayment;						//29 asafr FSD64471
	long			CreditLimit;					//33 asafr FSD64471
	long			DebitLimit;						//37 asafr FSD64471

	unsigned char nu[3];                            //41 
   struct trans_tail_  tail;                  //44
};


//FSD2615
struct trs_info2_bill_payment_biller_name_ext_
{
  unsigned char opcode;            //0x70      //0	<Opcode Value="0x70"/>
  unsigned char function;          //0x66      //1	<Opcode Value="0x66"/>
  char biller_name[42]  ;            //2                    //
  struct trans_tail_  tail;                  //44
};
//FSD2615
struct trs_info2_bill_payment_account_number_ext_
{
  unsigned char opcode;            //0x70      //0	<Opcode Value="0x70"/>
  unsigned char function;          //0x67      //1	<Opcode Value="0x67"/>
  char account_number[42];        //2
  struct trans_tail_  tail;                  //44
};
//FSD2615
struct trs_info2_bill_payment_barcode_ext_
{
  unsigned char opcode;            //0x70      //0	<Opcode Value="0x70"/>
  unsigned char function;          //0x68      //1	<Opcode Value="0x68"/>
  char barcode[42];                //2    //42
  struct trans_tail_  tail;                  //44
};

//FSD11256

struct trs_transaction_description_
{
  unsigned char opcode;            //0xC8      //0	<Opcode Value="0xC8"/>
  unsigned char original_opcode;				     //1
  long			 id;							        //2
  unsigned char description[38];               //6
  struct   trans_tail_  tail;                  //44
};


// FS10526
struct trs_info_parking_card_ 
{
	unsigned char opcode;			//0x70		//0	<Opcode Value="0x70"/>
	unsigned char function;			//0x2B		//1	<Opcode Value="0x2B"/>

	char	sParkingCardNumber[7];		        //2		BCD

	char	sCreationTime[4];					//9		BCD FSD59807
	char	sEndValidTime[4];					//13	BCD FSD59807
	unsigned char	bPaymentRequired	:1;		//17		FSD59807
	unsigned char	bConfirmed			:1;		//17
	unsigned char	bNu					:6;		//17
	char	sEmbeddedDate [4];					//18	BCD FSD226065
	char	sEmbeddedTime [3];					//22	BCD FSD226065	
	char	sExitCode[5];						//25	BCD FSD226065
	unsigned char uchParkingExitCodeLength;		//30		FSD226065
	unsigned char bcdExitCode[13];				//31	BCD FSD#226065_Ver5

	struct   trans_tail_  tail;                 //44
};

// FSD10094 - 2 Person Operation
struct trs_info2_two_po_ 
{
    unsigned char	opcode;			//0x70		//0	<Opcode Value="0x70"/>
    unsigned char	function;		//0x2F		//1 <Opcode Value="0x2F"/>	TRANS_INFO2_TWO_PO

	unsigned char	uchTwoPOMode;				//2 TWOPO_NO_MODE, TWOPO_SINGLE_MODE, TWOPO_DUAL_MODE
	unsigned short	ushCashierId;				//3 CashierId in 2 PO
	unsigned short	ushCheckerId;				//5 CheckerId in 2 PO


    unsigned char nu[37];						//7
    struct   trans_tail_  tail;                 //44
};

// FSD8152 - C4 Carta-pass 
struct trs_info2_gen_seg_info_
{
    unsigned char	opcode;			//0x70		//0	<Opcode Value="0x70"/>
    unsigned char	function;		//0x3D		//1	<Opcode Value="0x3D"/>

	long lSaveGenSgmntNewTotal;					//2   
	long lSaveGenSgmntProms;					//6 
	long lLastDirectSegmentPromsPotentialRewards;//10 , #15618- only promotions directly depend on the general segment.
	unsigned char nu[30];						//14
    struct   trans_tail_  tail;                 //44
};

//FSD9032
struct trs_info2_scale_check_
{
    unsigned char  opcode;         //0x70	//0	<Opcode Value="0x70"/>
    unsigned char  function;       //0x4F	//1	<Opcode Value="0x4F"/>

    unsigned long  weight;					//2
	    
    unsigned char reserved[38];				//6

    struct   trans_tail_  tail;
};

//FSD7315
struct trs_info2_independent_print_line_
{
  unsigned char opcode;            //0x70       //0		<Opcode Value="0x70"/>
  unsigned char function;          //0x6B       //1		<Opcode Value="0x6B"/>
  unsigned char is_first_line_in_group     :1;  //2
  unsigned char is_inline                  :1;
  unsigned char lines_in_group              :6;   //limited to 64 lines in group 
  unsigned char nu[2];                          //3
  unsigned char  line[39];                     //5
  struct   trans_tail_  tail;                  //44
};

// TD_SL Issue #8665
struct trs_carwash_ext_
{
    unsigned char opcode;		//0 0x70
    unsigned char function;		//1 0x6C
	
	unsigned char plu[7];		//2
	
	long lTaxAmount;			//9
	long lTaxRate;				//13

	unsigned char nu[27];		//17

    struct   trans_tail_  tail;	//44
};

//FSD11252 - PSI in ticket
struct trs_info2_stock_mng_info_
{
    unsigned char	opcode;			//0x70		//0	<Opcode Value="0x70"/>
    unsigned char	function;		//0x6D		//1	<Opcode Value="0x6D"/>
	unsigned char	sub_function;				//2
	unsigned char nu[41];						//3
    struct   trans_tail_  tail;                 //44
};

//#15302 - Start/End info ticket frame transaction
struct trs_info_ticket_frame_
{
    unsigned char	opcode;			//0x50		//0 TRANS_INFO_TICKET_FRAME	<Opcode Value="0x50"/>

	unsigned char	bStartInfoTicket	:1;		//1 - indication for start/end ticket transaction
	unsigned char	bPrntDiscTotalAmnt	:1;
	unsigned char	bPrintDataOnFO		:1;
	unsigned char   bForceCloseFrame	:1;		//0 - not forced , 1 - forced
	unsigned char	flags_nu			:4;		//1 - not used

	unsigned long	lAction;					//2 - action that calls start/end info ticket frame
												//SIGN_ON_ACTION		1
												//SIGN_OFF_ACTION		2
												//X_REPORT_ACTION		3
												//END_OF_DAY_ACTION		4
												//DOC_SETTING_ACTION	5   
												//GIFT_RECEIPT_ACTION	6   
												//GIFT_CARD_ENQ_ACTION	7  
												//REORG_RCPT_FINISH_MEDIA 8  
												//DOC_LOCAL_PRINT_ACTION 9   
												//ADD_FLOAT_ACTION       10  //Trs. number 0x07 (TRANS_FLOAT)
												//PICK_UP_ACTION         11  //Trs. number 0x09 (TRANS_CASH_LIFT) 
												//DECLARATION_ACTION     12  //Trs. number 0x0B (TRANS_DECLARE)
												//PAIDOUT_ACTION         13  //Trs. number 0x16 (TRANS_PAIDOUT_RECEIPT)
												//RECEIPT_ACTION         14  //Trs. number 0x16 (TRANS_PAIDOUT_RECEIPT)
												//POS_SHIFT_ACTION       15
												//PRICE_UPDATE_ACTION    16  //#35357 (FSD16243)
												//SPOT_CHECK_ACTION      17	// FSD 42257
												//ITEM_PRICE_INQUERY_ACTION 		18  // #46596
												//ONLINE_PURCHASE_REPRINT_ACTION	19	// FSD 45606
												//CC_REFUSAL_ACTION					20 //#55823
												//FUNCTION_TRIGGERING_ACTION		21  // FSD62343  
												//ITEM_PROMOTION_INQUIRY_ACTION		22	//FSD53695
												//SWITCH_TWOPO_ACTION				23	//FSD53695
												//EXIT_POS_ACTION					24  //FSD53695
												//POS_SHUT_DOWN_ACTION				25  //FSD53695
												//CHANGE_PASSWORD_ACTION			26  //FSD53695
												//SUSPEND_PRINTER_ACTION			27  //FSD53695
												//RESUME_PRINTER_ACTION				28  //FSD53695
												//EMPTY_CASH_DISPENSER_ACTION		29  //FSD53695
												//SUSPEND_RESUME_COIN_DISPENSER_ACTION	30  //FSD53695
												//AUTOMATIC_ACTIONS						31  //FSD53695
												//EMERGENCY_DRAWER_OPEN_ACTION	  		32  //FSD57905
												//NO_SALE_TICKET						33
												//TAX_VOUCHER_ACTION	  				34  //Bug 69908
												//SECURE_ACTION							35  //CR53695 
												//UNSECURE_ACTION						36  //CR53695 
												//ENTER_TRAINING_ACTION					37  //CR53695 
												//EXIT_TRAINING_ACTION					38  //CR53695 
												//WRONG_PASSWORD_ACTION					39  //CR53695 
												//REBOOT_POS_ACTION						40  // TD#52053
												//CHIP_CARD_MESSAGE						41  //CR53695 
												//MANUAL_EOD_ACTION						42  //CR53695 
												//START_INFO_FOREIGN_CURRENCY			59	//Bug#99936
												//EXTERNAL_LOYALTY_ERRORS				69
												

	unsigned short  shShiftId;					//6 Shift_Management in Remote Office
	unsigned char	chSubAction;				//8 sub-action additional info to the action code //CR53695
	unsigned char	nu[35];						//9
    struct   trans_tail_  tail;                 //44
};

//FSD13421 - Employee Card
struct trs_info2_employee_card_
{
	unsigned char	opcode;						//0x70	//0	
	unsigned char	function;					//0x6F	//1

	unsigned char	sCardNumber[20];					//2
	unsigned char	bEmployeeCardInTicket		:1;		//22
	unsigned char	bEmployeeClockInOut			:1;		//22
	unsigned char	NU_BITS						:6;		//22

	long			lSegment;							//23
	long			lAmount;							//27

	unsigned char	uchClockingType;					//31 FSD39873	0-Clock-Out, 1-Clock-In
	unsigned short	ushCashierID;				//32
	unsigned char	nu[10];								//34

	struct   trans_tail_  tail;                 		//44
};


//FSD7315
struct trs_info2_print_item_footer_
{
  unsigned char opcode;            //0x70       //0		<Opcode Value="0x70"/>
  unsigned char function;          //0x71       //1		<Opcode Value="0x71"/>
	unsigned char nu[1];                          //2
	unsigned char BarcodeLen;								// 3 CR71648
	unsigned char bMasked					:1;				//4//FSD#66478
	unsigned char bEncrypted				:1	;			//4//FSD#66478
	unsigned char bStartSplitTransaction	:1	;			//4//FSD#66478
	unsigned char bEndSplitTransaction		:1	;			//4//FSD#66478
	unsigned char bBarcodeITF				:1;				// 4 CR71648
	unsigned char bNU						:3	;			//4
  unsigned char  line[39];                     //5
  struct   trans_tail_  tail;                  //44
};

//#15639
struct trs_info2_forms_collection_
{
	unsigned char opcode;		//0x70		//0	<Opcode Value="0x70"/>
	unsigned char function;		//0x72		//1	<Opcode Value="0x72"/>
	
	unsigned char uchCollectionID[3];		//2

	unsigned char bStart		:1;			//5
    unsigned char bEnd			:1;			//5
    unsigned char bBelongsToPlu	:1;			//5 FSD75184
    unsigned char bManualTrigger:1;			//5 FSD306746 - StoreLine Philippine Business Requirements
	unsigned char reserved		:4;			//5

	unsigned char  reason_type;				//6

	unsigned char	nu[37];					//7
	
	struct  trans_tail_ tail;				//44
};


//FSD2615
struct trs_info2_bill_payment_advice_guid_
{
    unsigned char opcode;		//0x70		//0	<Opcode Value="0x70"/>
	unsigned char function;		//0x73		//1	<Opcode Value="0x73"/>
    unsigned char guid[37];               //2  null terminated guid 8-4-4-4-12
	unsigned char advice_success  :1;                 //39
    unsigned char nubits          :7; 
    unsigned char nu[4];                 //40
    struct  trans_tail_ tail;				//44
};

//FSD2615
struct trs_info2_bill_payment_advice_tender_
{
    unsigned char opcode;		//0x70		//0	<Opcode Value="0x70"/>
	unsigned char function;		//0x74		//1	<Opcode Value="0x74"/>
    unsigned char account[21];  //2  null terminated account
    unsigned char type;       //23
    long amount;              //24
	unsigned char nu[16];   //28
	struct  trans_tail_ tail;				//44
};

struct trs_info2_bill_payment_advice_barcode_
{
    unsigned char opcode;		//0x70		//0	<Opcode Value="0x70"/>
	unsigned char function;		//0x75		//1	<Opcode Value="0x75"/>
    unsigned char barcode[42];                         //2
	struct  trans_tail_ tail;				//44
};

//FSD7148 16820+16821
struct trs_ola_airtime_ext0_ 
{
  unsigned char opcode;		//0x60		//0		<Opcode Value="0x60"/>
  unsigned char function;		//0x28		//1	<Opcode Value="0x28"/>
  unsigned char sub_func;	 //A0        //2	<Opcode Value="0xA0"/>	
  char PinSerialNumber[21];   //3
  long ProviderTranSeqNumber;       //24
  unsigned char nu0[16];                          //28
  struct  trans_tail_ tail;				//44
};

//FSD7148 16820+16821
struct trs_ola_airtime_ext1_
{
  unsigned char opcode;		//0x60		//0			<Opcode Value="0x60"/>
  unsigned char function;		//0x28		//1		<Opcode Value="0x28"/>
  unsigned char sub_func;	 //A1        //2		<Opcode Value="0xA1"/>
  char ProviderOrderNumber[21];  //3
  unsigned char nu0[20];    //24 
  struct  trans_tail_ tail;				//44
};

// info transaction pickup bag barcode (FSD14665)
struct trs_info2_pickup_bag_
{
	unsigned char opcode;    //0x70                 //0	<Opcode Value="0x70"/>
	unsigned char function;  //0x6E                 //1	<Opcode Value="0x6E"/>
	
	unsigned char barcode[7];//2, barcode of the pickup bag, in bcd format.
	unsigned char uchBarcodeLen;					//9
	unsigned char ucBagType;						//10 0-Pickup bag; 1-ATM Reference No.//FSD56621
	unsigned char NU[33];                           //11
	
	struct   trans_tail_  tail;                     //44
};

struct trs_info2_pick_up_tender_
{
    unsigned char   opcode;   //0x70 // 0		<Opcode Value="0x70"/>
	unsigned char   function; //0x78 // 1		<Opcode Value="0x78"/>
	
	unsigned short  ushPosNo;        // 2 	
	unsigned short	ushCashierNumber;// 4
	unsigned short	ushTenderId;	 // 6

	struct PickUpFlags_				     // 8
	{
		unsigned char  bTenderPickedUp  :1; 
		unsigned char  bOfflineMode     :1; 
		unsigned char  bTenderDeclared  :1;	//FSD16191
		unsigned char  bTenderCorrected	:1;	//FSD32316
		unsigned char  bAmountEdited	:1;	//FSD32316
		unsigned char  bReprocess		:1;
		unsigned char  bChequeEdit		:1;
		unsigned char  bSafeTransfer    :1;   
	}Flags;
	
	unsigned char   bcdSeqNumber[5];	//9	//ShlomitG - 21/12/06 - FSD16191 correction (The sequence number (10 places string) is too long for a 'long' type)
	//unsigned long   ulSequenceId;    // 9	// FSD16191

    long	lNewAmount;			//14	FSD32316	

	struct Flags2_						// 18
	{
		unsigned char bROAAddCheque		:1;
		unsigned char NU				:7;
	}Flags2;

	long	lPickedUpAmount;			// 19 #285530

	char	filler[21];					// 23

	struct   trans_tail_  tail;      // 44
};									

//FSD 14348
struct trs_info2_voucher_reward_
{
	unsigned char  opcode;    //0x70                 //0	<Opcode Value="0x70"/>
	unsigned char  function;  //0x77                 //1	<Opcode Value="0x77"/>
	unsigned char  promotionId[5];					 //2		    
	long		   promotionCount;					 //7
	long		   rewardAmount;					 //11
	long		   lQualifySpent;					 //15

	//FSD 16857
	unsigned char  uchType;							//19	//0 - voucher	(VOUCHER_REWARD_TRS_VOUCHER)
															//1 - coupon	(VOUCHER_REWARD_TRS_COUPON)
	
	unsigned char  barcode[20];						 //20
	unsigned char  uchBarcodeLen;					 //40
	unsigned char  notuse[3];						 //41
		
	struct   trans_tail_  tail;                     //44
};

//FSD 14348
struct trs_info2_header_trigger_
{
	unsigned char  opcode;    //0x70                 //0	<Opcode Value="0x70"/>
	unsigned char  function;  //0x84                 //1	<Opcode Value="0x84"/>
	unsigned char  promotionId[5];					 //2		    
	long		   promotionCount;					 //7
	unsigned long  lQualifySpent;					 //11
	unsigned long  numitemspartecipating;			 //15	// AlbertoA FSd 41651
	unsigned char reward_type;						 //19	// AlbertoA FSd 41651
	unsigned char reward_destination;				 //20	// AlbertoA FSd 41651
	unsigned char	uchExternalReferenceID[10];		 //21	//BCD
	unsigned char uchExternalReferenceIDLen;		 //31	//BCD //FSD55670
	unsigned char notuse[12];						 //32
		
	struct   trans_tail_  tail;                     //44
};


//FSD 12841
struct trs_info2_issue_number_alloc_request_
{
	unsigned char  opcode;    //0x70                 //0	<Opcode Value="0x70"/>
	unsigned char  function;  //0x3E                 //1	<Opcode Value="0x3E"/>
	unsigned long  ulBarcodeRefNumber;				 //2
	
	unsigned char notuse[38];						 //6
		
	struct   trans_tail_  tail;                     //44
};
struct trans_info2_fiscal_end_ticket_
{
    unsigned char   opcode;   //0x70 // 0		<Opcode Value="0x70"/>
	unsigned char   function; //0x82 // 1		<Opcode Value="0x82"/>

	unsigned char   uchDocType;                    //2      RECEIPT Value=0x02 / REFUND_DOCUMENT Value=0x03 /INVOICE Value=0x04 / GIFT_CARD_DOCUMENT Value=0x05 //CR402214
    unsigned long   ulFiscalDeviceReceiptNumber;   //3   
   
	char filler[37];
	
	struct   trans_tail_  tail;      // 44
};

//Index/Defect #9896SL/#9896SL
struct trs_info2_rx_sale_
{
	unsigned char opcode;				//0 <Opcode Value="0x70"/> TRANS_INFO2
	unsigned char function;				//1 <Opcode Value="0x86"/> TRANS_INFO2_RX_SALE

	unsigned char rx_num[5];			//2 bcd
	unsigned char rx_e_ticket	:1;		//7
	unsigned char is_voided		:1;
	unsigned char not_used_bits :5;

	long		  rx_quantity;			//8	  Enh #8716
	unsigned char rx_fill_number[2];	//12  BCD	 Enh #8716
	unsigned char rx_partial_fill[4];	//14  BCD	 Enh #8716

	unsigned char received_price_rqst;	//18  Enh #12000

	unsigned char not_used[25];			//19

	struct trans_tail_ tail; //44
};

/*----------------------------------------------------------------------
Opcode: 0x70 subopcode 0x86

At the end of the ticket the POS checks if the total tax equals to the total
tax on the individual 01/02/03 records. If not then the last record is adjusted.
This TRS logs the adjustment details.
Used by Priceline. This opcode is used by the generic POS for other purpose.
-----------------------------------------------------------------------*/
struct trs_item_tax_adj_				//OFS	Description
{
	unsigned char opcode;				//0		0x70
	unsigned char function;				//1		0x86

	long original_tax_excl;				//2		The original tax exlusive amount in fixed record
	long adjustment_value;				//6		The tax adjusment value
	unsigned short seq_number;			//10	Sequence number of fixed record

	unsigned char not_used[32];			//12
	                                          
	struct   trans_tail_  tail;         //44
};


// 0x88 //FS18712 Third Party loyalty
struct trs_info2_third_part_loyalty_
{
    unsigned char  opcode;         //0x70	//0	<Opcode Value="0x70"/>
    unsigned char  function;       //0x88	//1 TRANS_INFO2_THIRD_PARTY_LOYALTY	<Opcode Value="0x88"/>

    unsigned char  BLCardNumber[10];				//2
	unsigned long  lPointsEarned;				//12	
	unsigned long  lVolume;			//16	
    unsigned char reserved[24];				//20

    struct   trans_tail_  tail; // 44
};

struct trs_info2_dummy_points_
{
	unsigned char opcode;         	//0x70 //0	<Opcode Value="0x70"/>
	unsigned char function;       	//0x89 //1 TRANS_INFO2_DUMMY_POINTS	<Opcode Value="0x89"/>

	unsigned long program_no;		
	unsigned long promotion_no;
	unsigned char plu_code[7]; //BCD
	unsigned char price[7];
	long		  points;
	short		  count; // counts the total numbers of promotions given 
	short		  dep_no;

	unsigned char reserved[12];

   struct   trans_tail_  tail;
};

//FSD16060 - holds refund data which need to be delivered to a Third Party  
struct trs_info2_Third_Party_Data_
{
	unsigned char opcode;         	//0x70 //0 <Opcode Value="0x70"/>
	unsigned char function;       	//0x8A //1 TRANS_INFO2_THIRD_PARTY_REFUND_DATA	<Opcode Value="0x8A"/>

	

	unsigned char	szPlu_code[7]; //BCD 2
	unsigned short	shDep_no;		//9
	unsigned char szRefundId[17];	//11
	unsigned short ushReturnType;	//28
	
	unsigned char reserved[14];//30

   struct   trans_tail_  tail;//44 TRS tail
};

//FSD16060 - holds refund data on an item(plu or dep).
//This transaction will be executed only when an item(plu or dep) is being refund in contrast with
//TRANS_INFO_REASON_CODE transaction which is executed in a lot of other scenarios rather than 
//a refund (in control checks for examples). 
struct trs_info2_Refund_Item_Data_
{
	unsigned char opcode;         	//0x70 //0	<Opcode Value="0x70"/>
	unsigned char function;       	//0x8B //1 TRANS_INFO2_REFUND_ITEM_DATA	<Opcode Value="0x8B"/>


	unsigned char	szPlu_code[7];	//BCD 2
	unsigned char	szDep_no[2];		//9
	unsigned short ushReturnType;	//11
	
	long lRefundAmount;				//13
	
	struct                              //14
	{
		unsigned char opt_refund_was_cancelled         :1; //This refund was cancelled
		unsigned char opt_refund_plu			       :1;//Refunded plu or dep
		unsigned char opt_NU						   :6;
	}Options;
	
	unsigned char reserved[26];//18

   struct   trans_tail_  tail;//44 TRS tail
};


/*----------------------------------------------------------------------
Opcode:   0x60
Function: 0x56
Info Store Count transaction
-----------------------------------------------------------------------*/
struct trs_info_store_count_
{
	unsigned char  opcode;				             //0  //0x60	<Opcode Value="0x60"/>
	unsigned char  function;                         //1  //0x56	<Opcode Value="0x56"/>

	unsigned char  bcdPageStoreCount[4];			 //2  //Reference number
	
	unsigned char not_used[38];						 //6
		
	struct   trans_tail_  tail;                     //44
};

struct TrsInfoBarcodeToEjdetails_
{
    unsigned char opcode;             		//offset 0 - opcode 0x70	<Opcode Value="0x70"/>
    unsigned char function;           		//offset 1 - function 0x83	<Opcode Value="0x83"/>
	unsigned char pakBarcode[30];			//offset 2  BCD - Barcode buffer (right justify, leading zeroes)
	unsigned char uchPakBarcodeLen;			//offset 32 BCD - Barcode buffer lenght //TD#382820
	unsigned char nu[11];					//offset 33 FSD11575

    struct   trans_tail_  tail;				//offset 44
};

//FSD14741
struct trs_info2_prom_ext_ 
{
	unsigned char opcode;		//0x70		//0	<Opcode Value="0x70"/>
    unsigned char function;     //0x7A		//1	<Opcode Value="0x7A"/>

	unsigned char Description[20];			//2		#19303

	unsigned char bPromComplexity			:1;	//22	#20726
	unsigned char bItemAlreadyTriggeredPromo:1;//22 //FSD16361
	unsigned char bTriggeredProm			:1;//22 //FSD16361
	unsigned char bDontUpdateItemPrice		:1;//22 //FSD53701
	unsigned char bDelayedPromotion			:1;//22 //Bug 118404
	unsigned char bZeroOrgRewardAmount      :1;//FSD231586
	unsigned char bAddTaxToRewardAmount     :1;//FSD231586
	unsigned char bCalcRewardExcludeTax		:1;

	unsigned char uchDiscountAllocationPrinting;	//23	//FSD16200
													//      99 - IGNORE ( FSD22200).
	
	long          lNewQty ;					//24	#22718 - added for C4 organize-receipt quantity. could be 0 on re-calculation.
											       //unlike the qty field on 03 which is always bigger than 0, even on re-calculation.
	long		  lManualDiscountValue;					//28
	long		  lOrgRewardVal;						//32 //FSD16361
	long		  lWghDecimalVal;		//36 FSD25302 store the weight\decimal\volume value

	unsigned char uchORScheme;	//40 FSD25302 Organized Receipt Scheme

	unsigned short ushManualDiscountIndex;//41 
	unsigned char uchThresHold;//43 

	struct trans_tail_  tail;				//44
};

//FSD16361
struct trs_info2_prom_ext2_
{
	unsigned char opcode;		//0x70		//0	<Opcode Value="0x70"/>
    unsigned char function;     //0xA0 		//1	<Opcode Value="0xA0"/>

	unsigned char szOrganizedReceiptSchemeTmpl[10];//2 //FSD16361

	unsigned char uchLastTriggeredPromotion;	//12 KobiM - CR40512
	long		  lConfigRewardAmount;			//13 FSD42115 We need to know promotion reward amount
	unsigned char uchDecimalPlaceInReward;		//17 FSD42115 We need to know the decimal places in the reward
												//	 The value should be consistent with how the promotion is configured:
												//	 0 - System Default Decimal
												//	 9 - No decimal point
												//	 1 to 3 means 1 to 3 decimal points

	unsigned char external_ref_id[10];			// 18 	// US SL Issue #17861/Enh #17861 [RandyB]
	long	lWghDecimalValApportion;			// 28 #69782
	unsigned char uchRewardTender;				// 32 #69900
	long lTotalSaversNum;						// 33 //Bug 103667
	long lNewSaversNum;							// 37 //Bug 103667
	unsigned short ushLineID;					// 41 //FSD#89180(save line ID)
	unsigned char  bDisableRewardLinePrintingOnTicket	:1;		// 43 //TD#329306
	unsigned char bRecalculateTaxAfterProm				:1;		 //43 FSD305075 StoreLine Philippine Legal Requirements
	unsigned char bMemberCardRequired					:1;		//43 FSD#444616_3
	unsigned char  bNu12								:5;		// 43


	struct trans_tail_  tail;				//44
};


//FSD16187
struct trs_info2_cheque_details_ 
{
	unsigned char opcode;		//0x70		//0	<Opcode Value="0x70"/>
    unsigned char function;     //0x85		//1	<Opcode Value="0x85"/>

//FSD264423 Tender cheque
#ifdef PRJ_ROW
	unsigned char sub_function;				//2

											//0 - drawerName[25], 
											//1 - bcBankID [2]
											//2	- bcdBSB[3]
											//3 - bcdAccNum[5]
											//4 - bcdChqNum[5];
	
	unsigned char bFirst		:1;			//3
	unsigned char bLast			:1;
	unsigned char nu			:6;

	unsigned char data[40];					//4

#else
	unsigned char bcdChequeNumber[4];			//2		BCD
	unsigned char bcdChequeBankNumber[6];		//6		BCD
	unsigned char bcdChequeAccountNumber[6];		//12	BCD

	unsigned char reserved[26];				//18
#endif

	struct trans_tail_  tail;				//44
};

//Issue #9564SL: Gift Card Batch Activation
//Gift card batch transaction - EAN128 activations only
struct trs_gift_card_batch_header_
{
    unsigned char opcode;					//0	0x70	<Opcode Value="0x70"/>
    unsigned char function;					//1	0x79	<Opcode Value="0x79"/>

	unsigned char BatchNo[5];				//2	 BCD
	long IndividualCardValue;				//7
	unsigned char NumOfCardsInBatch;		//11 BCD
	long TotalBatchValue;					//12

    unsigned char BatchProcessed			:1; //16 Indicates if card has been send to EFT
    unsigned char GiftCardVoid				:1;	//16 Indicates if batch item has been voided
    unsigned char nu_001					:6;

	long TrsBatchNo;						//17 2 digit batch number assigned per transaction (1-99)
	unsigned char nu[23];					//21

    struct   trans_tail_  tail;				//44
};

//Issue #9564SL: Gift Card Batch Activation
//Gift card batch transaction - EAN128 activations only
struct trs_gift_card_batch_details_
{
    unsigned char opcode;					//0	0x70	<Opcode Value="0x70"/>
    unsigned char function;					//1	0x7B	<Opcode Value="0x7B"/>

	long		  Index;					//2  Gift card index - used internally to differentiate gift cards
	unsigned char BatchNo[5];				//6  BCD Always 9 bytes unpaked
	unsigned char CardNo[11];				//11 BCD
	unsigned char CardNoLen;				//22
	long TrsAmount;							//23
	unsigned char PluCode[7];				//27 BCD

    unsigned char BatchCardProcessed		:1; //34 Indicates if card has been send to EFT
    unsigned char GiftCardVoid				:1;	//34 Indicates if batch item has been voided
    unsigned char nu_001					:6;

	unsigned char BatchResultCode;			//35 Result code from MTX: 0=Bad, 1=Good, 99=Duplicate (not supported by MTX at this time)
	unsigned char nu[8];					//36

    struct   trans_tail_  tail;				//44
};

/*----------------------------------------------------------------------
Opcode:		0x70
Subopcode:	0x7C
list of schemes that a promotion and member are linked to and were given reward #55079
-----------------------------------------------------------------------*/
struct trs_info2_mmbr_prom_schemes_		//OFS	Description
{
	unsigned char opcode;	  			//0		0x70
	unsigned char function;				//1		0x7C
	int GroupID;						//2
	unsigned char MaxRewards;			//6
	unsigned char TotalRewardCount;		//7	
	unsigned char TicketRewardCount;	//8
	unsigned char CardNo[20];			//9
	unsigned char filler[15];			//29
	struct   trans_tail_  tail;			//44
};

//Issue #9564SL: Alert trs for BAD and DUPLICATE batch recs
struct trs_alert_gift_card_batch_
{
	unsigned char opcode;				//0	0x63	<Opcode Value="0x63"/>
	unsigned short subopcode;			//1	17006 or 17007
	unsigned char function;				//3
	
	unsigned char disp_message    :1;	//4
	unsigned char drvfile_popup   :1;
	unsigned char ignore_alert    :1;
	unsigned char use_pos_no      :1;
	unsigned char get_text_msg    :1;
	unsigned char nu05            :1;
	unsigned char nu06            :1;
	unsigned char nu07            :1;
	
	unsigned char GC_batch_number[5];	//5 BCD
	unsigned char GC_batch_card_no[11];	//10 BCD
	long GC_batch_card_amt;				//21
	short GC_batch_card_no_len;			//25
	unsigned char nu[17];				//27
	
	struct   trans_tail_  tail;			//44
};

struct trs_info2_online_purchase_ext_
{
	unsigned char opcode;    //0x70				//0	<Opcode Value="0x70"/>
	unsigned char function;  //0x87				//1	<Opcode Value="0x87"/>  TRANS_INFO2_ONLINE_PURCHASE_EXT

	unsigned short ushOnlinePurchaseProvider;	//2 FSD17863  Provider ID ( Using trs as ext to trs_info_online_purchase_item_ which was suppose to be its real purpose).
	unsigned char sPinSerialNum[28];			//4	FSD28793 - changed from 15 to 28
	unsigned char sPreTrack2[2];				//32	FSD22770, #33897  - any chars before track2.

	unsigned char bConfirmationRequestRequired :1; //34 //FSD55425
	unsigned char bVoidedOffline			   :1; //34 //FSD55425
	unsigned char bPrintAsPartOfMainReceipt    :1; //34 //FSD217766
	unsigned char bBarcode                     :1; //34 // Epic 350305 - decode info from barcode before activation (NZL IK)
	unsigned char NU						   :4;

	long lVoidedItemSeq;						//35 FSD55425 DF OnSite
	short shAccountNumberLen;					//39
	unsigned char uchWhenToSendOLPAuhtorization;//41  FSD#67382
	unsigned short ushOffset2OLASessionTrs;		//42  FSD#67382
	                                          
	struct   trans_tail_  tail;					//44
};

struct trs_info2_online_purchase_ext2_                       //FSD21868
{
	
	   unsigned char opcode;								//0	// 0x70 //TRANS_INFO2
	   unsigned char function;  							//1	// 0xC4 //TRANS_INFO2_ONLINE_PURCHASE_EXT2
	   
	   unsigned char uchOptionNumber[39];                       //2
	   unsigned char NU[3];							    	//42
	   
	   struct   trans_tail_  tail;							//44           
};

struct trs_info2_online_purchase_ext3_                       //FSD40047
{
	   unsigned char opcode;								//0	// 0x70 //TRANS_INFO2
	   unsigned char function;  							//1	// 0xC7 //TRANS_INFO2_ONLINE_PURCHASE_EXT3

	   unsigned char uchBarcodeType;							    	//2
	   unsigned char uchBarcode[30];                        //3
	   short	shSessionID;								//33
	   long		lResponseFlags;								//35
	   long lLotteryItemOrderId;							//39	
	   unsigned char NU;									//43 

	   struct   trans_tail_  tail;							//44           
};

//FSD153313
struct trs_info3_online_purchase_ext4_
{
	unsigned char opcode;								// 0 TRANS_INFO3   0x80
	unsigned char function;								// 1 TRANS_INFO3_ONLINE_PURCHASE_EXT4 

	char sMaskedAccountNumber[30];						// 2

	unsigned char unUsed[12];							// 32
	struct   trans_tail_  tail;							// 44
};

struct trs_info3_online_purchase_ext5_
{
	unsigned char opcode;								// 0 TRANS_INFO3   0x80
	unsigned char function;								// 1 TRANS_INFO3_ONLINE_PURCHASE_EXT5 

	char sCardGroupType[30];						// 2
	char sExpDate[5];

	unsigned char unUsed[7];							// 32
	struct   trans_tail_  tail;							// 44
};

//OmerR FSD157230 this will represent an info transaction issued at failure of confirmation with GSE regarding online purchase item
struct trs_info3_ola_purchase_item_confirmation_failed_ 
{
	unsigned char	opcode;								// 0	TRANS_INFO3	0x80
	unsigned short  function;							// 1	TRANS_INFO3_ONLINE_PURCHASE_CONFIRMATION_FAILED 
	unsigned short  store_id;							// 3
	char provider_transaction_id[36];					// 5
	unsigned short	provider_scheme;					// 41
	unsigned char unUsed[1];							// 43
	struct   trans_tail_  tail;							// 44	
};

//OmerR FSD157230 this will represent an info transaction issued upon voiding an online purchase item while saving transaction 
//so we will know there were voided online items while recalling
struct trs_info3_voided_online_items_in_saved_trs_ 
{
	unsigned char	opcode;								// 0	TRANS_INFO3	0x80
	unsigned short  function;							// 1	TRANS_INFO3_VOIDED_ONLINE_ITEMS_IN_SAVED_TRS 
	unsigned char unUsed[41];							// 3
	struct   trans_tail_  tail;							// 44	
};

//FSD16201
struct trs_info2_member_account_update_
{
	unsigned char opcode;    //0x70           //0	<Opcode Value="0x70"/>
	unsigned char function;  //0x8C           //1	<Opcode Value="0x8C"/>

	unsigned char bcdLoyaltyCardNum[10];	//2

	unsigned char uchOperationSource;		//12
										//MEMBER_ACCOUNT_TRS_SOURCE_POS	
										//MEMBER_ACCOUNT_TRS_SOURCE_FO
										//MEMBER_ACCOUNT_TRS_SOURCE_EXTERNAL

	unsigned char uchType;					//13
										//	MEMBER_ACCOUNT_TRS_TYPE_EARN					
										//	MEMBER_ACCOUNT_TRS_TYPE_REDEEM
										//	MEMBER_ACCOUNT_TRS_TYPE_MANUAL_UPDATE

	unsigned char uchRedeemType;			//14
										// MEMBER_ACCOUNT_REDEEM_TYPE_GIFT
										// MEMBER_ACCOUNT_REDEEM_TYPE_VOUCHER
										// MEMBER_ACCOUNT_REDEEM_TYPE_PROM
										// MEMBER_ACCOUNT_REDEEM_TYPE_GIFT_START
										// MEMBER_ACCOUNT_REDEEM_TYPE_VOUCHER_START	

	unsigned long ulMemAcctID;				//15
	long lValue;							//19 Can be Positive or negative(for voiding)
	
	union									//23
	{
		unsigned char POS_BcdDest[20];				//23 size equal to MEMBER_ACCOUNT_MAX_REDEEM_DEST

		struct 
		{
			unsigned char bcdDest[16];			//23
			long batchNumber;					//39
		}FO_Dest;

		char szTemplateName[20];					//23    #63719
		

	}destUnion;
	
	unsigned char uchReasonCode;			//43
	                                          
	struct   trans_tail_  tail;               //44
};

// FSD19186
struct trs_info2_self_scan_text_line_
{
	unsigned char opcode;    //0x70           //0	<Opcode Value="0x70"/>
	unsigned char function;  //0x8E           //1	<Opcode Value="0x8E"/>

	unsigned char uchOrderNumber;			  //2
	unsigned char szTextLine[40 + 1];		  //3

	struct   trans_tail_  tail;               //44
};


/*----------------------------------------------------------------------
Opcode: TRANS_INFO2 (0x70), subopcode TRANS_INFO2_SUBITEM (0x8F)

FSD20957 - Sub items. Used for Roady.
-----------------------------------------------------------------------*/
struct trs_info2_subitem_					//OFS	Description
{
    unsigned char opcode;					//0		TRANS_INFO2 (0x70) <Opcode Value="0x70"/>
	unsigned char function;					//1		TRANS_INFO2_SUBITEM (0x8F) <Opcode Value="0x8F"/>
	unsigned char subFunction;				//2		Sub Function

	unsigned char bStart	:1;				//3
	unsigned char bEnd		:1;
	unsigned char nu		:6;

	union {
		struct {									// --- Sub Function 1
			char subPlu[7];							//4		Sub PLU, BCD
			char parentPlu[7];						//11	Parent PLU, BCD
			char description[20];					//18	Item description
			long lPrice;							//38	Price, BCD
			unsigned short ushDep;					//42	Departement
		} data1;

		struct {									// --- Sub Function 2
			unsigned char uchTaxId;					//4	Tax ID
			unsigned long lQuantity;				//5
			
			unsigned char bIgnoreSurchargeItemQty :1;	//9	Indicates the item quantity should be ignore in the DS processing for 'S' lines items. FSD34869.
			unsigned char nu3					  :7;

			char nu2[34];								//10
		} data2;
	};

    struct   trans_tail_  tail;				//44	Transaction tail
};											//64


/*----------------------------------------------------------------------
Opcode: TRANS_INFO2 (0x70), subopcode TRANS_INFO2_TICKET_TAX (0x3F)

20789 - taxes in post void ticket. New info transaction.
For some scenario (in the middle of the ticket) we need the info transaction only. 
The data structure almost the same like in trs_ticket_tax_	structure.
-----------------------------------------------------------------------*/
struct trs_ticket_info_tax_					//OFS	Description
{
    unsigned char opcode;					//0		TRANS_INFO2 (0x70)	<Opcode Value="0x70"/>
	unsigned char function;					//1		TRANS_INFO2_TICKET_TAX (0x3F)	<Opcode Value="0x3F"/>

    unsigned char tax_no;					//2		Tax rate number
    long 			taxable_amount;			//3		Taxable amount
    long 			tax_amount;				//7		Tax amount

    unsigned char exemptable   :1;			//11	Tax exempt given
    unsigned char tax_included :1;			//11	GST inclusive tax
    unsigned char opt_nu2      :1;			//11	Not used
    unsigned char opt_nu3      :1;			//11	Not used
    unsigned char opt_nu4      :1;			//11	Not used
    unsigned char opt_nu5      :1;			//11	Not used
    unsigned char opt_nu6      :1;			//11	Not used
    unsigned char opt_nu7      :1;			//11	Not used

    unsigned char exempt_no[10];			//12	BCD 19 digits right justify

    long 			FS_forgive_taxable;		//22	Food stamps forgiven taxable amount
    long 			FS_forgive_tax;			//26	Food stamps forgiven tax amount
    long 			nt_amount;				//30	Not used
    long 			tax_refund_amount;		//34	refunded tax
	unsigned char   type;					//38    Tax type FS22354
	unsigned long   rate;					//39    Tax rate FS22354

    unsigned char reserved	;				//43	Not used
    struct   trans_tail_  tail;				//44	Transaction tail
};											//64

/*----------------------------------------------------------------------
Opcode: TRANS_INFO2 (0x70), subopcode TRANS_INFO2_DISPENSE_DATA (0x8D)

-----------------------------------------------------------------------*/
struct trs_info2_atm_data_				//OFS	Description
{
    unsigned char opcode;					//0		TRANS_INFO2 (0x70)			<Opcode Value="0x70"/>
	unsigned char function;					//1		TRANS_INFO2_ATM_DATA (0x8D) <Opcode Value="0x8D"/>

	unsigned char sub_opcode;               //2     1 - Dispense
	                                        //      2 - Deposit
											//		3 - Declaration
											//		4 - Session
											//      6 - Reject Box Reset Counter //FSD#218589 (V.13)

    unsigned char uchActionType;			//3		Action Type:
	                                        //      1 - Payment (deposit only)
	                                        //      2 - Change
	                                        //      3 - Return
	                                        //      4 - Cash Exchange
	                                        //      5 - Add Loan
	                                        //      6 - PickUp
	                                        //      7 - Tender Purchase
	                                        //      8 - Tender Correction
	                                        //      9 - Paid Out 
	                                        //     10 - Void tender 
											//	   11 - Paid In
											//	   12 - Declaration
											//	   13 - Begin Deposit
											//     14 - Cancel Deposit
											//	   15 - Cash Deposit Without Cash Office Effect
											//	   16 - Local Dispense
											//	   17 - Empty Device

    long lActualDispAmount;					//4		Actual dispense amount as returned from SP
    long lRemainingAmount;      			//8		Remaining amount to be dispensed (calculated)

	long lDepositAmount;					//12    Deposited amount 
	short shTenderNumber;					//16	FSD47004 Tender number

	long lReasonCode;						//18    FSD#218589

	unsigned short ushATMTransactionID;		//22    FSD#218589

	unsigned char bEnded	    :1;			//24    FSD#218589
	unsigned char bCancelled    :1;			//24    FSD#218589
	unsigned char bSession		:1;			//24    FSD#218589
	unsigned char bNU		    :5;			//24    FSD#218589
	
	long lStockChangeAmount;			    //25	FSD#218589

    long lCountAmount;						//29	FSD#218589 V.9
	long lRejectBoxResetCounterAmount;      //33    FSD#218589(V.13)

	unsigned char reserved[7];				//37	Not used
    
	struct   trans_tail_  tail;				//44	Transaction tail
};							

/*----------------------------------------------------------------------
Opcode: TRANS_INFO2 (0x70), function TRANS_INFO2_PRICE_UPDATED_AT_POS (0x90)

FSD16243 - Item registration.
-----------------------------------------------------------------------*/
struct trs_info2_price_update_atPOS_			//OFS	Description
{
    unsigned char opcode;						//0	<Opcode Value="0x70"/>	TRANS_INFO2 (0x70) 
	unsigned char function;						//1 <Opcode Value="0x90"/>		TRANS_INFO2_PRICE_UPDATED_AT_POS (0x90)

	unsigned char PluCode[7];					//2		

	unsigned char ApproveCancelFlag		:1;		//9
	unsigned char bPriceWasUpdate		:1;		
	unsigned char bItemNotFoundInHost	:1;		
	unsigned char NUAppFlg				:5;		//9

	long		  lPrice;						//10
	long		  lOldPrice;					//14

	unsigned short DepNo;						//18

    unsigned char reserved[24];					//20	Not used

    struct   trans_tail_  tail;					//44	Transaction tail
};

/*----------------------------------------------------------------------
Opcode: TRANS_INFO2 (0x70), function TRANS_INFO2_SPECIAL_TOTALS (0x92)

FSD18559 - Invoice Enhancement.
-----------------------------------------------------------------------*/
struct trs_info2_special_totals_
{
	unsigned char opcode;		// 0x70				//0 <Opcode Value="0x70"/>
	unsigned char function;		// 0x92				//1	<Opcode Value="092x"/>
	unsigned char sub_func;							//2
								// 0 - regular total(not in use)
								// 1 - Items subtotals
								// 2 - Items and promotions subtotals								
								// 3 - departments subtotal // FSD122445


	long amount;									//3
	long nt_amount;									//7
	long lVatExclAmount;							//11
	long qty;										//15

	unsigned char reserved[25];						//19

	struct trans_tail_ tail;						//44
};

/*----------------------------------------------------------------------
Opcode: TRANS_INFO2 (0x70), function TRANS_INFO2_START_PROMOTION_SECTION (0x93)

FSD14741 - Organized Receipt
-----------------------------------------------------------------------*/
struct trs_info2_promotion_section_
{
	unsigned char opcode;		// 0x70				//0 <Opcode Value="0x70"/>
	unsigned char function;		// 0x93				//1	<Opcode Value="0x93"/>
	  
	unsigned char start		:1;						//2
    unsigned char end       :1;
    unsigned char nu	    :6;

	unsigned char szTemplate[10];					//3
    
    unsigned char type;								//13	FSD122445
								// 0 - regular promotion section
								// 1 - departments section
								// 2 - general section

	union 
	{
		struct
		{
			long SingleConditionSingleUnitPromAmt;
		}type2;

		unsigned char reserved[30];					//14
	}data;

    struct   trans_tail_  tail;						//44

};


/*----------------------------------------------------------------------
Opcode: TRANS_INFO2 (0x70), function TRANS_INFO2_SECURITY_NUMBER (0x94)
-----------------------------------------------------------------------*/

struct trs_info2_security_number_
{
	unsigned char opcode;		// 0x70				//0 <Opcode Value="0x70"/>
	unsigned char function;		// 0x94				//1 <Opcode Value="0x94"/>
	  
	unsigned long securityNumber;					//2

	unsigned char reserved[38];						//6

    struct   trans_tail_  tail;						//44

};

/*----------------------------------------------------------------------
Opcode: TRANS_INFO2 (0x70), function TRANS_INFO2_TRIGGER_COUNT (0x95)
-----------------------------------------------------------------------*/

struct  trs_info2_trigger_count_
{
	unsigned char opcode;		// 0x70				//0 <Opcode Value="0x70"/>
	unsigned char function;		// 0x95				//1 <Opcode Value="0x95"/>
	  
	long lPromotionNo;                              //2
	long lTRiggerCount;		            			//6

	unsigned char reserved[34];						//10

    struct   trans_tail_  tail;						//44
};

//FSD16207
struct  trs_info2_confirmed_promotion_
{
	unsigned char opcode;							//0 <Opcode Value="0x70"/>
	unsigned char function;	 						//1 <Opcode Value="0x96"/> TRANS_INFO2_CONFIRMED_PROMOTION

	unsigned char uchType;							//2
	  
	long lPromotionNo;                              //3
	long lQty;		            					//7
// Modified here for PLU code			
	unsigned char plu_code[7];						//11
	unsigned char chRedeemedpointFromSecondryCard	:1;	//18
	unsigned char nu_bytes								:7;	//18
	long lpointRedeemedForRedemption;				//19											
	unsigned char nu[21];							//23

    struct   trans_tail_  tail;						//44
};
//FSD16855
struct  trs_info2_gift_multi_redem_
{
	unsigned char opcode;							//0 <Opcode Value="0x70"/>
	unsigned char function;	 						//1 <Opcode Value="0x9C"/> TRANS_INFO2_GIFT_MULTIPLE_REDEM_RESERVATION 

	unsigned char uchType;							//2		// Type of gift redemption (redemption[0]/reservation[1]/pickup[2])
	unsigned char  sPluCode[7];						//3		// Gift item code
	unsigned char uchRewardType ;					//10	// Reward Type
	long		  lRedeemPoints;					//11	// redeemed points for gift

	unsigned char bcdLoyaltyCardNum[10];			//15	// BCD loyalty card number
	unsigned char bWasCanceled	:1;					//25	the plu was cancelled	TD109473
	unsigned char bNotUsed		:7;	

	unsigned char nu[18];							//26	// not used bytes

    struct   trans_tail_  tail;						//44
};
/*
struct  trs_info2_gift_multi_redem_
{
	unsigned char opcode;							//0 <Opcode Value="0x70"/>
	unsigned char function;	 						//1 <Opcode Value="0x9C"/> TRANS_INFO2_GIFT_MULTIPLE_REDEM_RESERVATION 
													//	<Opcode Value="0x97"/> TRANS_INFO2_GIFT_MULTIPLE_REDEM_PICKUP
	unsigned char uchType;							//2
	unsigned char  sPluCode[7];						//3  
	unsigned char uchReservation;					//10
		unsigned char uchRewardType ;				//11
	unsigned char bcdLoyaltyCardNum[10];			//12

	unsigned char nu[22];							//22

    struct   trans_tail_  tail;						//44
};
*/
//FSD14082 for dynamic plu attribute, similar to QDX 198 struct DynamicPluAtt_, except sAttValue[50] not added cause not needed, and too big.
struct trs_info2_dynamic_attribute_		
{
	unsigned char  opcode;							//0 <Opcode Value="0x70"/>
	unsigned char  function;	 					//1 <Opcode Value="0x9A"/> TRANS_INFO2_DYNAMIC_ATTRIBUTE

	unsigned char  sPluCode[7];						//2 BCD KEY PLU Number 

	unsigned char  uchRecordType;					//9		 1 - 	sAttValueOpenText 
														//   2 -	sAttValueCombo
														//	 3 -	sAttValueAmount

   unsigned char  AttId[2];							//10 BCD 

   unsigned char  subject;							//12 //Dynamic attribute allocated to : Plu or Department or ...

   unsigned char  bAllowAsMemberPromotionReward	:1;	//13 FSD14082
   unsigned char  bMRP							:1;	//	 FSD18003
   unsigned char  bDataTrsFollows               :1; //
   unsigned char  bProhibitPromotionReward    	:1; //13 FSD25305
   unsigned char  bPromotionsAllowedOnThisAtt	:1; //13 FSD26803 - Indicates whether to include promotions conected to this item attribute in the XML for LPE.
   unsigned char  bSendDynamicAttTransaction	:1; //13 FSD41496 - DEEE_Contribution
   unsigned char  NU_flags						:2;
   
   long			  lAttValue;						//14
   long			  lAmount;							//18 FSD166552
   short		  uchQty;							//22 FSD166552
   unsigned char  uchSaleType;					    //24 Bug #348631/348659 - 0-Normal Sale,1-Void Item,2-Refund Item
   unsigned char  nu[14];							//25

	long			lOverrideAttValue;				//39	//FSD14086		
	unsigned char	bIAValueIsOverride			:1;	//43	//FSD14086	
	unsigned char	NU							:7;	//43

    struct   trans_tail_  tail;						//44

};

//FSD41496 - DEEE_Contribution - This transaction will save Attribute's value according to its type
struct trs_info2_dynamic_attribute_value_
{
	unsigned char  opcode;							//0 <Opcode Value="0x70"/>
	unsigned char  function;	 					//1 <Opcode Value="0xC5"/> TRANS_INFO2_DYNAMIC_ATT_VALUE

	unsigned char  uchRecordType;					//2		 1 - 	sAttValueOpenText 
														//   2 -	sAttValueCombo
														//	 3 -	sAttValueAmount
														//	 4 - _LinkToItemAttribute
														//	 5 - _YesNoType
	unsigned char  uchAttId[2];						//3 BCD  Attrubute's ID

	union											//5
	{
		unsigned char sOpenTextValue[30];			//5
		struct
		{
			unsigned char uchValueCombo;			//5
			unsigned char Combo_NU[29];				//6
		}stComboValue;
		struct
		{
			long lValue;							//5
			unsigned char uchNumberOfDecimals;		//9
			unsigned char Value_NU[25];				//10
		}stValue;
	}uAttValue;

	unsigned char DIAValue_NU[9];					//35
	struct   trans_tail_  tail;						//44

};






//DELHAIZE , showing barcode to cashier.
struct trs_info2_barcode_display_		
{
	unsigned char  opcode;							//0 <Opcode Value="0x70"/>
	unsigned char  function;	 					//1 <Opcode Value="0x9B"/> TRANS_INFO2_BARCODE_DISPLAY

	unsigned char  sBarcode[20];					//2 ascii .
	unsigned char  sDescription[16];				//22

	unsigned char  bIsCanceled					:1; //38 //TD#122834
	unsigned char  bCheckIfPromotionCoupon		:1;	// 38 TD#245403
	unsigned char  unused						:6; //38 NU

	long lCount;							        //39 // TD#122470 //TD#136869
    
	unsigned char  nu[1];							//43  

    struct   trans_tail_  tail;						//44
};

//FSD18936 #26236 - holds the qsr table number 
struct trs_info2_Table_Number_
{
	unsigned char opcode;         	//0x70 //0 <Opcode Value="0x70"/>
	unsigned char function;       	//0xA1 //1 TRANS_INFO2_TABLE_NUMBER	<Opcode Value="0xA1"/>
	
	unsigned short	ushTableNumber	;		//2

	unsigned char reserved[40];//4

   struct   trans_tail_  tail;//44 TRS tail
};

//FSD18937 #27165 - Indicates a Kms message 
struct trs_info2_Kms_Trs_Msg_
{
	unsigned char opcode;         	//0x70 //0 <Opcode Value="0x70"/>
	unsigned char function;       	//0xA1 //1 TRANS_INFO2_KMS_TRS_MSG	<Opcode Value="0xA2"/>

	unsigned char reserved[42];//2

   struct   trans_tail_  tail;//44 TRS tail
};



//YaelB. Add support for Alpha-Numeric terminalId
struct trs_info2_ola_result_ext3_             
{
	unsigned char opcode;      //0x70	
	unsigned char function;    //0x9D	

	char sTerminalId[20];			//2
    long  lOldAmountBalance;        //22   
	unsigned char filler[18];     //26 Not used      

	struct   trans_tail_  tail;               //44     TRS tail
};

/*----------------------------------------------------------------------
Opcode: TRANS_INFO2 (0x70), function TRANS_INFO2_ORC_PLU_SALES (0x9E)

FSD16361 - Organized Receipt
-----------------------------------------------------------------------*/
struct trs_info2_ORC_plu_sales_		
{
	unsigned char  opcode;							//0 <Opcode Value="0x70"/>
	unsigned char  function;	 					//1 <Opcode Value="0x9E"/> TRANS_INFO2_ORC_PLU_SALES

	unsigned char  code[7];							//2		Item number (BCD)
	unsigned char  bPrintWithQty		 				:1;//9		print with quantity
	unsigned char  bDisplaySaleLineWithPriceAfterPromo	:1;//9 FSD25302
	unsigned char  bCaseFollowsLinkedItem				:1;//9 FSD25302
	unsigned char  bStandardAndInfoLine					:1;//9 FSD25302
	unsigned char  bCombineSaleAndPromotionLine			:1;//9 FSD25302
	unsigned char  bDisplayCartonSaleLine				:1;//9 FSD25302
	unsigned char  bReturnItem							:1;//9 FSD25302
	unsigned char  bMarkAsCartonFromPromotion			:1;//9

    unsigned short ushDeptNum;				//10	Department number
	unsigned char  uchTaxComb;				//12
	long		   lQty;					//13
	long		   lOrgPrice;				//17
    long           lAmount;					//21    quantity*price   

	long           lSingleItemPriceAfterPromotion;	//25	FSD25302
	unsigned short	ushLinkRatio;					//29	FSD25302
	unsigned char	uchReturnType;					//31	FSD25302
	short			shCartonQty;					//32	FSD14086
	long			lDiscountAmount;				//34

	unsigned char  bDisplayCaseRefundSaleLine		 	:1;	//38	//FSD46987
	unsigned char  NU								 	:7;

	long			lSingleItemPriceAfterPromotionRest;		//39 // TD113019
	
	unsigned char	nu_43[1];								//43
    
    struct   trans_tail_  tail;						//44
}; 
/*-----------------------------------------------------------------------------
Opcode: TRANS_INFO2 (0x70), function TRANS_INFO2_ORC_COMBINED_PROMO_NET_SALES (0x9F)

FSD16361 - Organized Receipt
-------------------------------------------------------------------------------*/
struct trs_info2_ORC_combined_promo_net_sales_		
{
	unsigned char  opcode;							//0 <Opcode Value="0x70"/>
	unsigned char  function;	 					//1 <Opcode Value="0x9F"/> TRANS_INFO2_ORC_COMBINED_PROMO_NET_SALES

    long		  lPromoNum;						//2
	long		  lTotalQtyParticipatItems;			//6
    long		  lNetAmountParticipatItems;		//10 (item price+discount)*quantity
	long		  lAverageNetPricePerItem;			//14 net amount/total quantity
	
	unsigned char bStartEndIndication	 		:1;	//18 print with quantity
	unsigned char bPrintPromoLineBeforePlu		:1;	//18
	unsigned char bCombineSaleAndPromotionLine	:1;	//18 FSD25302
	unsigned char bCaseFollowsLinkedItem		:1;	//18 FSD25302
	unsigned char bDisplayCartonSaleLine		:1;	//18 FSD25302
	unsigned char bManuallTriggered				:1; //18
	unsigned char NU					 		:2;	//18	

	long lTotalDiscountAmountPerPromotion;			//19
	unsigned char uchRewardDestination;				//23
	unsigned char  nu_24[20];						//24
    struct   trans_tail_  tail;						//44
}; 

/*-----------------------------------------------------------------------------
Opcode: TRANS_INFO2 (0x70), function TRANS_INFO2_ORC_REWARD_SPLIT_BY_REDEMPTION_INFO (0xA4)

FSD16361 - Organized Receipt 
-------------------------------------------------------------------------------*/
struct trs_info2_ORC_reward_split_by_redemption_info_		
{
	unsigned char  opcode;							//0 <Opcode Value="0x70"/>
	unsigned char  function;	 					//1 <Opcode Value="0xA4"/> TRANS_INFO2_ORC_REWARD_SPLIT_BY_REDEMPTION_INFO

    unsigned char  szPluCode[7];					//2		Item number (BCD)
	unsigned char  bItemWasSubstracted	 :1;//9	
	unsigned char  bItemWasCanceled		 :1;//9	
	unsigned char  bManualDiscount		 :1;//9	
	unsigned char  bPercentageDiscount	 :1;//9	
	unsigned char  bPointsReward    	 :1;//9   	Points given as reward
	unsigned char  bDiscountFlag         :1;//9	Item/department "discount allowed" flag. Used in cases of promotions
	unsigned char  bPromComplexity		 :1;//9		
	unsigned char  bItemAlreadyTriggeredPromo:1;//9

    unsigned short ushDeptNum;				//10	Department number
	
	unsigned char  uchTaxComb;				//12
	unsigned char  uchReturnTypeNumber;		//13
	long		   lQuantity;				//14
	long           lPrice;					//18
    long           lAmount;					//22    
	long		   lRedemptionNumber;		//26
	long		   lPromoNumber;			//30

	unsigned char uchApportionmentType;     //34
	unsigned char uchRewardType;			//35
	unsigned char uchGroupType;             //36

	unsigned char bDepTransDisc			:1;//37
	unsigned char bPluTransDisc			:1;//37
	unsigned char bMultisaver			:1;//37
	unsigned char bRewardedItem			:1;//37
	unsigned char nu_37					:4;//37NU	
	
	long lOriginalRewardField;			//38
	unsigned char uchRewardDestination;	//42
	unsigned char  nu_43;			//43

    struct   trans_tail_  tail;				//44

};

/*-----------------------------------------------------------------------------
Opcode: TRANS_INFO2 (0x70), function TRANS_INFO2_ORC_REWARD_SPLIT_BY_REDEMPTION_INFO_EXT (0xB0)

FSD16361 - Organized Receipt 
-------------------------------------------------------------------------------*/
struct trs_info2_ORC_reward_split_by_redemption_info_ext_		
{
	unsigned char  opcode;							//0 <Opcode Value="0x70"/>
	unsigned char  function;	 					//1 <Opcode Value="0xB0"/> TRANS_INFO2_ORC_REWARD_SPLIT_BY_REDEMPTION_INFO_EXT
  	
	unsigned char szDescription[20];				//2 Promotion Description
	unsigned char nu_22[22];						//22
    struct   trans_tail_  tail;						//44
};

/*-----------------------------------------------------------------------------
Opcode: TRANS_INFO2 (0x70), function TRANS_INFO2_DATA (0xA6)

FSD25302 - Organized Receipt Scheme Enhancement
To be used with all generic transactions that hold data, add new sub_func to hold new data
FSD32316 - Moved flags to be within each structure of union. This allows each subfunction to define their own flags
-------------------------------------------------------------------------------*/
struct trs_info2_data_
{
	unsigned char opcode;		//0 <Opcode Value="0x70"/>
	unsigned char function;	 	//1 <Opcode Value="0xA6"/> TRANS_INFO2_DATA

    unsigned char sub_func;		//2 Sub Function code
										//1 - DISPLAY_TTL_DISCOUNT
										//2 - PRINT_PROMO_BLOCK_HEADER
										//3 - ITEM ATTRIBUTE TEXT VALUE.
										//4 - ASK_PROM_WHAT_TRIGGERED
										//5 - EDIT_TENDER_ECCA_NAME				
										//6 - EDIT_TENDER_ECCA_NUMBER			
										//7 - EDIT_TENDER_CUST_NUM				
										//8 - EDIT_TENDER_CUST_NAME			
										//9 - ORGRCPT_PLU_PRINT_DATA

	union						//4 maximum size of this union is 41 bytes
	{
		unsigned char general_data[41];	//the maximum size of data is 41 bytes, new structure or data should go in this union

		struct
		{
			unsigned char bOldLaybyTicket		:1;		//3 flags
			unsigned char bPrintInFinishMedia	:1;		//FSD122446
			unsigned char NU					:6;		//

			long lTotalDiscAmount;			//to be used with DISPLAY_TTL_DISCOUNT only
		}stTtlDisc;

		struct
		{
			unsigned char bOldLaybyTicket	:1;		//3 flags
			unsigned char NU				:7;		//3

			char sTmplPromoBlockHeader[10];	//to be used with PRINT_PROMO_BLOCK_HEADER only
		}stTmplPromoBlockHeader;

		struct
		{
			unsigned char  bReprocess				:1;		//3 flag
			unsigned char  bLastField				:1;		//3 flag
			unsigned char  nu_bits					:6;		//3 flag

			char sNewFieldData[40];

		}stChequeDetailEdit;			//to be used with all EDIT_TENDER sub functions

		struct
		{
			long lPrice;			//Price to be printed on receipt
			long lAmount;			//Amount to be printed on receipt

			char sNewFieldData[33];

		}stOrgRcptPluPrintData;	
		//new structures go here, max size 41 bytes
	}data;

    struct   trans_tail_  tail;		//44
};

struct trs_info2_cashier_discount_	//29725
{
	unsigned char opcode;		//0 0x70				//0 <Opcode Value="0x70"/>
	unsigned char function;		//1 0xAC	
	
	unsigned char type;			//2	Type=1 Segment, Type=2 Response
	unsigned char bExecuteEOTProm	:1;
	unsigned char NUNU				:7;
	union						//4
	{
		struct  
		{
			long			lSegmentID;
		}Segment;
		struct  
		{
			unsigned long	i_lPromNum;		
			unsigned char	i_chApproveType;	
			long			i_pValue;
			unsigned char	i_chCcResult;
			long			i_lSaversConfirmedByClient;
		}Response;		                  
	};
	unsigned char reserved[26]; 
    struct   trans_tail_  tail;						//44
};

struct trs_info2_updated_ext_card_
{
	unsigned char opcode;		// 0x70				//0 <Opcode Value="0x70"/>
	unsigned char function;		// 0x5A				//1 <Opcode Value="0x5A"/> TRANS_INFO2_CONFIRM_EXT_CARD_UPDATED
	
	
	unsigned char card_no[20];						// 2  card no in ascii null terminated
    long          UpdatedCust_points;				// 22 Points Updated on card

	unsigned char bCardUpdateResult		:1;			//26    0 OK , 1 NOK
	unsigned char nu					:7;

    long          UpdatedCardNumber;				// 27 Number of Card Updates 0 - 9999

	unsigned char reserved[13];						// 31

    struct   trans_tail_  tail;						//44
};

//FSD47073 - Enhance TransID to 33 from 24.
struct trs_ola_card_authentication_			
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60"/>
	unsigned char function;    //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;    //0xA2	<Opcode Value="0xA2"/>

	unsigned char option;      //3    1 - record1 (inf1)
	                           //     2 - record2 (inf2)

	union                      //4
	{
		struct  
		{
			unsigned char TransID[33];
			unsigned char ECI[2];   
		}inf1;
		struct  
		{
			unsigned char CAVData[28];
			unsigned char notused[7]; 
		}inf2;		                  
	};
	
	
	unsigned char notused[5];				//39
	
	struct   trans_tail_  tail;             //44
};

struct trs_ola_secure_data_			
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60"/>
	unsigned char function;    //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;    //0xA3	<Opcode Value="0xA3"/>

	unsigned char option;      //3  1 - Name, 2 - Sponsor, 3 - Result
	union                      //4
	{
		unsigned char Name[25];
		unsigned char Sponsor[25];
		unsigned char Result[25];
	};

	unsigned char notused[15];				//29
	
	struct   trans_tail_  tail;         //44
};

struct trs_ola_certificate_details_			
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60"/>
	unsigned char function;    //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;    //0xA4	<Opcode Value="0xA4"/>

	unsigned char option;      //3    1 - Merchant, 2 - CardHolder, 3 - TransStain
	union                      //4
	{
		unsigned char Merchant[24];
		unsigned char CardHolder[24];
		unsigned char TransStain[28];
	};

	unsigned char notused[12];				//32
	
	struct   trans_tail_  tail;         //44
};

struct trs_invoice_vat_calculation_			
{
	unsigned char opcode;		//0  0x70
	unsigned char function;		//1  0xA3
	unsigned char sub_func;		//2	1 - Vat Groups Summary (Net Value)
								//	2 - Vat Groups Summary (Vat Value)
	long lVatGroup1;			//3
	long lVatGroup2;			//7
	long lVatGroup3;			//11
	long lVatGroup4;			//15
	long lVatGroup5;			//19
	long lVatGroup6;			//23
	long lVatGroup7;			//27
	long lVatGroup8;			//31
	long lZeroVat;				//35

	char filler[5];				//39
	
	struct   trans_tail_  tail;         //44
};

/*-----------------------------------------------------------------------------
Opcode: TRANS_INFO2 (0x70), function TRANS_INFO2_CASH_CHANGE_CORRECTION (0xA7)

FSD16283 - Cash Change Correction
-------------------------------------------------------------------------------*/
struct trs_info2_cash_change_correction_		
{
	unsigned char  opcode;			//0 <Opcode Value="0x70"/>
	unsigned char  function;	 	//1 <Opcode Value="0xA7"/> TRANS_INFO2_CASH_CHANGE_CORRECTION

	long lOriginalAmount;			//2
	long lAdditionalAmount;			//6
	long lPaidAmount;					//10
	long lChangeAmount;				//14

	unsigned char  nu_18[26];		//18
	struct   trans_tail_  tail;	//44
};

struct trs_pharmacy_item_  //FSD26364
{
	unsigned char opcode;      //0x70	
	unsigned char function;    //0xA8	


	unsigned char PhBatchNumber[11]; //2
	unsigned char PhExpiryDate[10];  //13
	
	//FSD35059 
	unsigned char  MediRiteType;	//23   MEDIRITE_SALE = 1  or MEDIRITE_REFUND = 2   
	unsigned short LocationNum;		//24
	unsigned long  DocketNum;		//26
	unsigned short IssueLocationNum;//30

	unsigned char notused[12];		//32
	

	struct   trans_tail_  tail;         //44
};

struct trs_pharmacy_item2_  //FSD26364
{
	unsigned char opcode;      //0x70	<Opcode Value="0x70"/>
	unsigned char function;    //0xA9	<Opcode Value="0xA9"/>


	unsigned char PhDoctorName[20]; //2
	unsigned char PhPatientName[20]; //22
	unsigned char notused[2];		//42
	

	struct   trans_tail_  tail;         //44
};

/*-----------------------------------------------------------------------------
Opcode: TRANS_INFO2 (0x70), function TRANS_INFO2_POS_SHIFT (0xAA)








Shift_Management in Remote Office
-------------------------------------------------------------------------------*/
struct trs_info2_pos_shift_		
{
	unsigned char  opcode;			//0 <Opcode Value="0x70"/>
	unsigned char  function;	 	//1 <Opcode Value="0xAA"/> TRANS_INFO2_POS_SHIFT


	unsigned short ushPosNo;			  //2
	unsigned short shPosShiftId;		  //4
	unsigned char  bPosShiftStatus   :1;  //6
	unsigned char  nu_bits           :7;  



	unsigned char  nu[37];		        //7
	struct   trans_tail_  tail;	        //44
};


// FSD#28264
struct trs_info2_inge_voucher_  //0x70 0xAB
{
    unsigned char opcode;       //0		TRANS_INFO2
    unsigned char subopcode;	//1		TRANS_INFO2_INGE_VOUCHER
    unsigned char function;		//2     values: 1 - Activation, 2 - Confirmation, 3 - Cancellation
	
	unsigned char bcdRefNumber[5]; //3      bcd , reference number identifying the item .
								   //		produced by the mobile card provider .

	unsigned char ucPrintBarcode;	// 8
	unsigned char ucBarcodeFormat;  // 9

	unsigned char ucType;			// 10  Values: 0 - Reload Mobile, 1 - Gift Card // FSD#59750

	unsigned char bSuccess   :1;	//11
	unsigned char bConfirmed :1;
	unsigned char bPrinted	 :1;
	unsigned char bTrsExt    :1;    // FSD#59750
	unsigned char nu	     :4;

	union 
	{
		/* data stored upon requesting the PIN from the mobile card provider */
		struct 
		{
			unsigned char bcdPluCode[7];		 // 12
			unsigned char bcdGenCode[8];		 // 19
			unsigned char bcdUniqueTrsNumber[3]; // 27 
			unsigned short ushSchemeId;			 // 30
			unsigned char uchGenCodeLength;		 // 32
			unsigned char uscNU[8];				 // 33
		} getPin;
		
		/* data stored upon  PIN confirmation against the mobile card provider */
		struct 
		{
			unsigned char bcdPINCode[16];		//12
			unsigned char bcdPINSerialCode[10]; //28
			unsigned char bcdExpiryDate[3];		//38  yymmdd
		} confirmPin;

		// FSD#59750
		// Data stored upon requesting the gift card from the gift card provider
		struct 
		{
			unsigned char szBalanceAmount[12]; // 12
			unsigned short ushSchemeId;		   // 24
			unsigned char bcdPluCode[7];	   // 26
			unsigned char uscNU[8];			   // 33
			
		} requestGiftCard;

		// FSD#59750
		// Data stored upon gift card confirmation against the gift card provider
		struct 
		{
			unsigned short ushSchemeId;		    // 12
			unsigned char cEntryMode;		    // 14
			unsigned char bcdAmount[6];		    // 15
			unsigned char bcdBalanceAmount[6];  // 21
			unsigned char bcdPluCode[7];	    // 27
			unsigned char uscNU[7];			 	// 34
			
		} confirmGiftCard;
		
	}data;
	
	unsigned char uchProviderName;			//41 provider "name" is in fact enumeration .
	unsigned char uchPINCodeLength;			//42
	unsigned char uchPINSerialCodeLength;	//43
    struct   trans_tail_  tail;				//44
};

// FSD#59750
struct trs_info2_inge_voucher_ext_  // 0x70 0xFC
{
	unsigned char opcode;         // 0		TRANS_INFO2		
    unsigned char subopcode;	  // 1		TRANS_INFO2_INGE_VOUCHER_EXT

	unsigned char sBarcode[32];   // 2

	unsigned char uchBarcodeLen;  // 34

	unsigned char NU[9];		  // 35
	
	struct trans_tail_ tail;	  // 44
};

//Bug #29984
struct trs_customer_count_
{
	unsigned char opcode;			//0	<Opcode Value="0x70"/>
	unsigned char function;			//1	<Opcode Value="0xAD"/>

	long lCustCount;				//2 Bug # 1096696, Zen version,  allow negative values.
	unsigned char nu[38];			//10

	struct   trans_tail_  tail;		//44
};

//FSD24344
struct trs_info2_ignore_
{
	unsigned char opcode;			//0	<Opcode Value="0x70"/>
	unsigned char function;			//1	<Opcode Value="0xAE"/>

	unsigned char nu[40];			//2
	unsigned char uchOrgOpcode;		//42	opcode of original transaction
	unsigned char uchOrgFunction;		//43	function of original transaction

	struct   trans_tail_  tail;		//44
};

//Enh #12593SL - BrianS
struct trs_info2_fiscal_sales_
{
	unsigned char opcode;       // 0 // TRANS_INFO2
    unsigned char function;     // 1 // TRANS_INFO2_FISCAL_SALES 0x5B
	
	long tender_num;			// 2
	char sales_total[10];       // 6

	char chTaxID;				// 16 //FSD345511
	__int64 ia64TaxAmount;		// 17 //FSD345511

	unsigned char NU[19];       // 25
 
    struct   trans_tail_  tail;      // 44
};

//Enh #13526SL
struct trs_freedom_customer_ID_
{
    unsigned char opcode;				//0	0x70   
    unsigned char function;  			//1	0x5C        
    unsigned char cust_ID[4];			//2	BCD  
	
	unsigned char frdm_rclled_ok	:1;	//6
	unsigned char nu_1				:7;	//6 not used
	
    unsigned char nu[37];      			//7	not used
    struct   trans_tail_  tail;                
};

//Issue #8897SN: EBTWIC
struct trs_info2_ebtwic_
{
    unsigned char opcode;									// 0	// TRANS_INFO2 0x70
    unsigned char function;									// 1	// TRANS_INFO2_EBTWIC	0x99

	unsigned char subopcode;								// 2	// EBTWIC SubOpcode

	union
	{
		// ------------------------------------------------------------------------------------------------------------
		struct ebtwic_ticket_frame_							// 0x01: EBTWIC_INFO_TRANS_TICKET_FRAME
		{
			unsigned short PosNo;							// 3	Pos number (BCD) (0-9999) 
			unsigned char PAN[10];							// 5	PAN number (BCD)
			unsigned char PANLength;						//15	PAN number length (0-99)
			unsigned char StateCode[2];						//16	State Code
			unsigned char szStateFIPS;						//18	State FIPS (hex)
			short iStateCodeLen;							//19	Length of state code
			unsigned char nu[23];							//21	not used
		} ebtwic_ticket_frame;

		// ------------------------------------------------------------------------------------------------------------
		struct ebtwic_item_sale_							// 0x02: EBTWIC_INFO_TRANS_ITEM_SALE
		{
			unsigned char PluCode[7];						// 3	PLU Code of Item (BCD)
			short Category;									//10	WIC Category
			short Subcategory;								//12	WIC Subcategory
			long Quantity;									//14	Quantity
			short Count;									//18	Item count
			long Price;										//20	Price
			long Amount;									//24	Sell Amount
			unsigned char nu[16];							//28	not used
		} ebtwic_item_sale;

		// ------------------------------------------------------------------------------------------------------------
		struct ebtwic_error_								// 0x06: EBTWIC_INFO_TRANS_ERROR
		{
			unsigned char PAN[10];							// 3	PAN number (BCD)
			unsigned char PANLength;						//13	PAN number length (0-99)
			unsigned char ErrorCode[2];						//14	Error code BCD (0-9999)
			unsigned char nu[28];							//16	not used
		} ebtwic_error;

		// ------------------------------------------------------------------------------------------------------------
		struct ebtwic_ticket_total_							// 0x08: EBTWIC_INFO_TRANS_TICKET_TOTAL
		{
			long TenderAmount;								// 3	Tender amount
			long WICCouponTotal;							// 7
			long WICPromotionTotal;							//11
			long WICDiscountTotal;							//15
			long WICItemTotal;								//19
			long WICItemCount;								//23
			long WICNetTotal;								//27	Item ttl - cpn ttl + disc ttl + prom ttl
			unsigned char nu[13];							//31	not used
		} ebtwic_ticket_total;

		// ------------------------------------------------------------------------------------------------------------
		struct ebtwic_benefit_details_						// 0x09: EBTWIC_INFO_TRANS_RX_DETAILS
		{
			unsigned char IssuerID[15];						// 3
			unsigned char StartDate[4];						//18	BCD YYYYMMDD
			unsigned char EndDate[4];						//22	BCD YYYYMMDD
			unsigned char nu[18];							//26	not used
		} ebtwic_benefit_details;

		// ------------------------------------------------------------------------------------------------------------
		struct ebtwic_transaction_signature_				// 0x0A: EBTWIC_INFO_TRANS_TRANS_SIGN
		{
			unsigned char TransSignLen;						// 3	length 0-99
			unsigned char NumOfRecs;						// 4	how many trans sign data records total
			unsigned char RecordNumber;						// 5	
			unsigned char TransSignData[38];				// 6	data can be up to 99 byte total so we need to support continuation records
		} ebtwic_transaction_signature;

		// ------------------------------------------------------------------------------------------------------------
		struct ebtwic_ticket_tax_							//0x0B: EBTWIC_INFO_TRANS_TICKET_TAX
		{
			unsigned char tax_no;							//3
			long taxable_amount;							//4
			long tax_amount;								//8

			unsigned char NU[32];							//12
		} ebtwic_ticket_tax;

		// ------------------------------------------------------------------------------------------------------------
		struct ebtwic_tax_details_							//0x0C: EBTWIC_INFO_TAX_DETAILS
		{
			unsigned char plu_code[7];						//3

			unsigned char opt_FS_payment            :1;		//10
			unsigned char opt_cost_plus				:1;		//10
			unsigned char opt_non_merch				:1;		//10
			unsigned char opt_negative				:1;		//10
			unsigned char opt_discount_allowed		:1;		//10
			unsigned char opt_nu					:3;		//10

			unsigned char tax_ptr;							//11
			unsigned char mult_sell_unit;					//12
			long          amount;							//13
			long          retn_surcharge_percent;			//17
			long          qty;								//21
			unsigned short  dept;							//25

			unsigned char NU[17];							//27
		} ebtwic_tax_details;

		// ------------------------------------------------------------------------------------------------------------
		//Data used to rebuild class CBenefitsList to print benefits reports (at EOT or recover ticket)
		struct ebtwic_benefits_list_						// 0x20 EBTWIC_INFO_BENEFITS_LIST
		{
			unsigned char Type;								// 3	Type of data
															//		0x01 = original benefits (BenefitsList)
															//		0x02 = eligible benefits (BenefitsWorlArea)
															//		0x03 = ending benefits (BenefitsBalance)
															//		0x04 = next period benefits (NextBenefitsList)
			unsigned char SubType;							// 4	0x01 = Header or 0x02 = Details
			union
			{
				struct ebtwic_benefits_header_
				{
					short NumOfDetailRecs;					// 5	length 0-9999
					unsigned char PAN[10];					// 7	PAN number (BCD)
					unsigned char PANLength;				//17	PAN number length (0-99)
					unsigned char StateCode[2];				//18	State Code
					unsigned char EndDate[4];				//20	BCD YYYYMMDD
					short BlockCount;						//24
					short CompressedBufferSize;				//26
					short UnCompressedBufferSize;			//28
					unsigned char nu[14];					//30	not used
				}ebtwic_benefits_header;

				struct ebtwic_benefits_details_compressed_
				{
					short RecordNumber;						// 5
					unsigned char NumOfBytes;				// 7
					unsigned char BenefitListData[36];		// 8
				}ebtwic_benefits_details_compressed;

			}ebtwic_benefits_data;	//union

		} ebtwic_benefits_list;		//struct

		// ------------------------------------------------------------------------------------------------------------
		struct ebtwic_ticket_end_							// 0x99: EBTWIC_INFO_TRANS_TICKET_END
		{
			unsigned short PosNo;							// 3	Pos number (BCD) (0-9999) 
			unsigned char PAN[10];							// 5	PAN number (BCD)
			unsigned char PANLength;						//15	PAN number length (0-99)
			unsigned char StateCode[2];						//16	State Code
			unsigned char szStateFIPS;						//18	State FIPS (hex)
			short iStateCodeLen;							//19	Length of state code
			unsigned char nu[23];							//21	not used
		} ebtwic_ticket_end;

	} ebtwic_trans;

	struct trans_tail_ tail;								// 44
};

struct trs_info2_ppt_gift_card_extra_data_	
{
	unsigned char opcode;				//0		0x70   
    unsigned char function;			    //1		0xB1 TRANS_INFO2_PPT_GIFT_CARD_EXTRA_DATA        
   
	unsigned short shPPtApprovalCode;	//2
	unsigned short shPPtErrorCode;		//4
	long lRequestedAmount;				//6 relevant to all but inquiry
	unsigned char ola_date[4];  //10
	unsigned char ola_time[2];  //14
    unsigned char STAN[7];		//16
    unsigned char nu[21];      		//23	
    struct   trans_tail_  tail;     //44      
};

//FSD13919
struct trs_info2_fsa_
{
	unsigned char opcode;						// 0 0x70
	unsigned char function;						// 1 0xB2

	long RxAmount;								// 2
	long NonRxAmount;							// 6
	
	unsigned char nu[34];						//10

	struct trans_tail_ tail;					//44
};
#define TRS_INFO2_ALT_ITEM_FOLLOW_LINK_ITEM			1
#define TRS_INFO2_ALT_ITEM_FOLLOW_LINK_ITEM_REFUND	2
struct trs_info2_alternative_plu_sale_
{
    unsigned char opcode;				//0		0x70 TRANS_INFO2
    unsigned char sub_opcode;  			//1		0xB3 TRANS_INFO2_ALTERNATIVE_PLU_SALE
	unsigned char function;				//2		1 - TRS_INFO2_ALT_ITEM_FOLLOW_LINK_ITEM-
										//		2 - TRS_INFO2_ALT_ITEM_FOLLOW_LINK_ITEM_REFUND	//FSD46987

	union trs_alternative_plu_			//3
    {
		
		struct trs_item_follow_linked_item_
		{
			unsigned char	bCancel						:1;	//3	
			unsigned char	bSubstract					:1;	//3	
			unsigned char	bAcceptPriceOverride		:1;	//3		Price override done on this item
			unsigned char	bPriceOverride				:1;	//3		Price override 
			unsigned char	bCaseSale     				:1;	//3	
			unsigned char	bWasCancelled     			:1;	//3	
			unsigned char	bNU		     				:2;	//3	

			long			price;						//4		Item price
			long			amount;						//8		Amount received for this item
			long			count;						//12
			unsigned char	code[7];					//16	Item number (BCD)
			unsigned char	iReturnType;				//23	Return Type
			long			org_price;					//24
			long			unit_amount;				//28
			long			lOrgAmount;					//32
			unsigned short	ushRatio;					//36
			unsigned char	nu[6];      				//38

		} trs_item_follow_linked_item;	

		struct trs_item_follow_linked_item_refund_	//3			//TODOORC46987
		{
			unsigned char	nu[41];      					//3
		} trs_item_follow_linked_item_refund;
		
    } alternativPlu;

    struct   trans_tail_  tail;     //44 
};


//FSD 27622
struct trs_info2_eft_inserted_in_tender_mode_
{
    unsigned char opcode;				//0		// 0x70 //TRANS_INFO2
    unsigned char function;  			//1		// 0xB4 //TRANS_INFO2_EFT_INSERTED_IN_TENDER_MODE
	
    unsigned char nu[42];      			//2	
    struct   trans_tail_  tail;			//44           
};

//FSD29692
#define TRANS_INFO2_GENERAL_CARD_GEN_INFO 1
struct trs_info2_general_card_
{
	unsigned char opcode;           //0 	0x70 <Opcode Value="0x70" />
	unsigned char sub_opcode;       //1 	0xB5 <Opcode Value="0xB5 (TRANS_INFO2_GENERAL_CARD)" />
	unsigned char function;         //2 	0 - Not used
									//  	1 - General Info

	union general_card_				//3
    {
		struct general_info_						//3
		{
			unsigned char	uchSchemeNo;						//3 1 to 9
			unsigned char	uchIssueNo;							//4
			unsigned char	sCardNo[15];						//5  Card no in BCD
			unsigned char	sMasterCardNo[15];					//20 Master card no in BCD
			unsigned char	uchCardNoLen;						//35
			unsigned char	uchMasterCardNoLen;					//36
			unsigned short	ushExpYear;							//37
			unsigned char	uchExpMonth;						//39



			unsigned char	bAccepted  					:1;		//40 Card was accepted
			unsigned char	bVoided 	   				:1;		//40 Card was voided
			unsigned char	bReEntry       				:1;		//40 Clubcard re-entry
			unsigned char	bScanned  					:1;		//40 Card was scanned.
			unsigned char	bMCRUsed  					:1;		//40 Card was swiped else keyd in.
			unsigned char	bChipCardUsed				:1;		//40
			unsigned char   bStaffDiscCard				:1;		//40
			unsigned char	nu1							:1;		//40
			
			unsigned char	bMasterCardFromBarcode		:1;		//41
			unsigned char	bVoidBarcodeWhenSchemeVoided:1;		//41
			unsigned char	nu							:6;		//41

			unsigned short  uchCardStoreNo;						//42 Member card store number #10555
		} generalInfo;

	} generalCard;


	struct   trans_tail_  tail;							// 44
};

//FSD16273
struct trs_info2_manual_eod_
{
	unsigned char opcode;			//0	<Opcode Value="0x70"/>
	unsigned char function;			//1	<Opcode Value="0xB6"/>

	unsigned char nu[42];			//2

	struct   trans_tail_  tail;		//44
};

struct trs_info2_status_
{
	unsigned char opcode;			//0	<Opcode Value="0x70"/>
	unsigned char function;			//1	<Opcode Value="0xB7"/>
	unsigned char uchType;          //2 Status type    0 - TENDER ENDORSEMENT
	unsigned char uchStatus;          //3 Status     0 - SUCCESS
	                                //             1 - FAILURE

	union                       //4
	{
		struct                  // Card information
		{
			unsigned char uchTndr;         //4 
			unsigned char uchEndorseType;  //5
		}EndorseData;                  
		unsigned char sData[40];     //4          
	}DATA;								
	
	struct   trans_tail_  tail;		//44
};

//FSD 30642
struct trs_info2_parking_voucher_
{
    unsigned char opcode;				// 0		// 0x70 //TRANS_INFO2
    unsigned char function;  			// 1		// 0xB8 //TRANS_INFO2_PARKING_VOUCHER

	unsigned char szVoucherNumber[7];  // 2

	struct								
	{
		unsigned char bPOSMode	   :1;  // 9
		unsigned char bVoided	   :1;	// 9		FSD39663
		unsigned char ucNU		   :6;  // 9
	} flags;
	
    unsigned char ucNU[34];      		// 10

    struct   trans_tail_  tail;			// 44           
};

//FSD 26154 sec. 7.4-7.8
struct trs_info2_fuel_mode_changed_
{
    unsigned char opcode;							// 0	// 0x70 //TRANS_INFO2
    unsigned char function;  						// 1	// 0xB9 // fuel info trsTRANS_INFO2_FUEL_MODE_CHANGED
    unsigned char sub_function;						// 2

	unsigned char uchNumOfChangedPumpOrZeroForAll;	// 3
	unsigned short ushCashierNo;					// 4
	unsigned char szCashierName[20];				// 6
		
	unsigned char NU[18];							// 26

	struct   trans_tail_  tail;						// 44           
};

//FSD6916
struct trs_info2_EmplCorporNo_
{
    unsigned char opcode;							// 0	// 0x70 //TRANS_INFO2
    unsigned char function;  						// 1	// 0xBA //TRANS_INFO2_EMPLOYEE_CORPORATE_NO
    
	unsigned char  EmployeeCorporateNumber[5];		// 2     BCD
	
	unsigned char NU[37];							// 7

	struct   trans_tail_  tail;						// 44           
};


//#34702 - performance issue
struct trs_redemption_summary_
{
	unsigned char opcode;			//0	<Opcode Value="0x70"/>
	unsigned char function;			//1	<Opcode Value="0xBB"/>

	unsigned short ushCount;			//2

	unsigned char	bStart			:1; //4
	unsigned char	bEnd			:1;
	unsigned char	nuBits			:6;
	
	unsigned char nu[39];			//5

	struct   trans_tail_  tail;		//44
};


//FSD50476
struct trs_pickup_counter_
{
	unsigned char opcode;					//0	<Opcode Value="0x70"/>
	unsigned char function;					//1	<Opcode Value="0xDB"/>
	
	unsigned char uchCount;					//2
	unsigned char uchResetPickupCounter :1; //3
	unsigned char nu1					:7;
	unsigned char nu[40];					//4


	struct   trans_tail_  tail;		//44
};

//FSD 29694
struct trs_info2_eft_ext_session_
{
    unsigned char opcode;					//0		// 0x70 //TRANS_INFO2
    unsigned char function;  				//1		// 0xBC //TRANS_INFO2_EFT_EXT_SESSION
	
	short	shSessionID;					//2

	unsigned long	lEftTerminalId;			//4
	unsigned char	sMaskedAccount[20];		//8
	unsigned short	eft_result_code;		//28
	short			shTenderNo;				//30
	long			tender_amount;			//32
	unsigned char	uchEftSessionType;		//36

	unsigned char	uchSessionStarted	:1;	//37
	unsigned char	uchSessionEnded		:1;	//37
	unsigned char	uchVerifySignature	:1;	//37
	unsigned char   uchOldCard			:1; //37
	unsigned char	bSendEftPrintData	:1;	//37
	unsigned char	eftNU				:3;	//37

	long			lEftTransNumber;		//38		//EFT transaction Number

    unsigned char	nu[2];      			//42	
    struct			trans_tail_  tail;		//44           
};
//FSD26778 - new trs
struct trs_info2_bill_payment_data_
{
	unsigned char opcode;			//0	<Opcode Value="0x70"/>
	unsigned char function;			//1	<Opcode Value="0x5D"/>
	unsigned char sub_function;     //2		1 - data info 1,
	                                //		2 - data info 2,
									//		3 - data info 3,
									//		4 - data info 4,
	                                    
	short shSessionId;				//3
	
	unsigned char opt_cancel				:1; //5	 Bill cancellation
    unsigned char opt_was_cancelled			:1; //5	 Original Bill was canceled
	unsigned char bWasPrinted				:1; //5  If the Slips was printed   
	unsigned char nu_flags					:5; //5

	union                           //6
	{		
		struct
		{
			unsigned char sInvoiceNum[6];				//6
			unsigned char sBillPaymentBarcode[20];		//12  BCD format
			long lBillPaymentAmount;					//32	
			long lBillPaymentCommisionAmount;			//36
			unsigned char uchBarcodeLen;				//40
			unsigned char nu[3];						//41
		}inf1; 

		struct
		{
			long lDiscount;					//6
			long lInterest;					//10
			unsigned char nu[30];			//14				
		}inf2;		

		struct
		{
			unsigned char sProductName[21]; //6			
			unsigned char nu[17];			//27      
		}inf3;

		struct
		{
			unsigned char sBillerName[21];	//6			
			unsigned char nu[17];			//27       
		}inf4;

		struct 
		{
			unsigned char uchItemNumber[7];			//6
			unsigned char uchItemType		:2;		//13
			unsigned char nu_6_bits			:6;
			long lBillPaymentAmount;		//14
			long lBillPaymentCommisionAmount;		//18
			unsigned char nu[22];					//22
		}inf5;
	};

	struct   trans_tail_  tail;		//44
};

/*----------------------------------------------------------------------
Opcode: TRANS_INFO2 (0x70), subopcode TRANS_INFO2_PCARD (0x5E)

Phone card issue/recharge or phone voucher sale
-----------------------------------------------------------------------*/
struct trs_info2_pcard_					//OFS		Description
{
    unsigned char	opcode;				//0			0x70		
    unsigned char	function;			//1			0x5E		
	unsigned char   sub_func;			//2			Future use
	
	unsigned long	trace_id;			//3			Item handle received from subsystem
	unsigned char	track2[21];			//7			Track2 data
#ifdef PRJ_PRICELINE
	unsigned long	ulHandle;			//28
	long			amount;				//32
	unsigned char	uchStatus;			//36		see GiftCardTransStatus
	unsigned char	filler[4];			//37		Not used
#else
	long			balance;			//28		new gift card balance 
	unsigned char	filler[9];			//32		Not used
#endif

	unsigned short  scheme_id;			//41		Sheme number

	unsigned char	opt_issue	:1;		//43		Card issue
	unsigned char	opt_recharge:1;		//43		Card recharge
	unsigned char	opt_voucher :1;		//43		Voucher sale
	unsigned char   opt_tender	:1;		//43		Tender (gift card)
	unsigned char   opt_offline :1;		//43		Gift card trasanction done in offline.
	unsigned char	opt_Info	:1;		//43		record for internal use by the pos
	unsigned char	opt_Undo	:1;		//43		This is an undo transaction
	unsigned char	opt_notused	:1;		//43		


	struct trans_tail_	tail;			//44 TRS tail
};

struct trs_info2_pcard1_					//OFS		Description
{
    unsigned char	opcode;				//0			0x70		
    unsigned char	function;			//1			0x5E		
	unsigned char   sub_func;			//2			1

	unsigned char	StorelineTransID[36];	//3

	unsigned long	ulHandle;			//39
	unsigned char	opt_issue	:1;		//43		Card issue
	unsigned char	opt_recharge:1;		//43		Card recharge
	unsigned char	opt_voucher :1;		//43		Voucher sale
	unsigned char   opt_tender	:1;		//43		Tender (gift card)
	unsigned char	opt_nu:4;			//43		

	struct trans_tail_	tail;			//44 TRS tail
};

struct trs_info2_pcard2_					//OFS		Description
{
    unsigned char	opcode;				//0			0x70		
    unsigned char	function;			//1			0x5E		
	unsigned char   sub_func;			//2			2

	unsigned char	TraceNo[10];	//3
	unsigned char	ReceiptNo[10];	//13
	long GC_Balance;				//23
	unsigned char bcdExpDate[3];	//27
	unsigned long	ulHandle;			//30
	short			RespCode;			//34
	unsigned char	bcdIssueDate[3];	//36
	unsigned char	bcdIssueTime[3];	//39
	unsigned char	filler1[1];			//42

	unsigned char	opt_issue	:1;		//43		Card issue
	unsigned char	opt_recharge:1;		//43		Card recharge
	unsigned char	opt_voucher :1;		//43		Voucher sale
	unsigned char   opt_tender	:1;		//43		Tender (gift card)
	unsigned char	opt_nu:4;			//43		

	struct trans_tail_	tail;			//44 TRS tail
};

struct trs_info2_pcard3_					//OFS		Description
{
    unsigned char	opcode;				//0			0x70		
    unsigned char	function;			//1			0x5E		
	unsigned char   sub_func;			//2			3

	unsigned long	ulHandle;			//3
	unsigned char	ServerMessage[34];	//7

	char filler[3];						//41

	struct trans_tail_	tail;			//44 TRS tail
};

//This transaction holds the transID of the undo/offline message sent in background
struct trs_info2_pcard4_				//OFS		Description
{
    unsigned char	opcode;				//0			0x70		
    unsigned char	function;			//1			0x5E		
	unsigned char   sub_func;			//2			4

	unsigned char	UndoOflnTransID[36];//3

	unsigned long	ulHandle;			//39

	unsigned char	bUndo		:1;		//43
	unsigned char	bOffline	:1;
	unsigned char	bNU			:6;

	struct trans_tail_	tail;			//44 TRS tail
};

//<QdxFile Number="68" Name="transact.qdx" Type="Relative" RecordSize="64" Key="2" />
//FSD28669
struct trs_info2_accumulated_vat_retrn_
{
	
	   unsigned char opcode;								//0	// 0x70 //TRANS_INFO2
	   unsigned char function;  							//1	// 0xBD //TRANS_INFO2_ACCUMULATED_VAT_RETURN
	   
	   long  lTotalAccumulatVatAmount;						//2
	   unsigned short ushSubTransaction;					//6
	   
	   
	   unsigned char	bWasCanceled   				:1;		//8 
	   unsigned char	nu7							:7;		//8

	   long lTotalTicketAmount;								//9	   //KobiM - CRL81109
	   
	   unsigned char NU[31];								//13   #68341- remove security number
	   
	   struct   trans_tail_  tail;							//44           
};

struct trs_info2_vat_return_media_
{
	
	   unsigned char opcode;								//0	// 0x70 //TRANS_INFO2
	   unsigned char function;  							//1	// 0xBE //RANS_INFO2_VAT_RETURN_MEDIA
	   
	   unsigned short ushSubTransaction;					//2
	   unsigned char NU[40];								//4
	   
	   struct   trans_tail_  tail;							//44           
};

struct trs_info2_ola_payment_card_result_       //FS3012
{
	unsigned char opcode;      //0x60	<Opcode Value="0x60"/>	
	unsigned char function;    //0x28	<Opcode Value="0x28"/>
	unsigned char sub_func;    //0x49	<Opcode Value="0x49"/>
 
	unsigned short ushSessionId;      //3
	unsigned char bcdExpiryDate[2];   //5  //MMYY
	
	unsigned char sAcountNumber[20];	//7 
	long lOldAmountBalance;				//27 
	long lNewAmountBalance;				//31 
	
	short shResponseCode;             //35 
	char NotUsed[7];				  //37

	struct   trans_tail_  tail;         //44 
};
struct trs_info2_send_prom_response_
{
	
	   unsigned char opcode;								//0	// 0x70 //TRANS_INFO2
	   unsigned char function;  							//1	// 0xC1 //TRANS_INFO2_SEND_PROM_RESPONSE
	   
	   unsigned long lPromNum;								//2
	   unsigned char uchApproveType;						//6 
	   long			 lValue;								//7	
	   unsigned char uchCcResult;							//11
	   long			 lSaversConfirmedByClient;				//12
	   unsigned char NU[28];								//16
	   
	   struct   trans_tail_  tail;							//44           
};

struct trs_info2_ticket_scheme_                             //FSD36846
{
	
	   unsigned char opcode;								//0	// 0x70 //TRANS_INFO2
	   unsigned char function;  							//1	// 0xC3 //TRANS_INFO2_TICKET_SCHEME
	   
	   unsigned short ushTicketScheme;                      //2
	   unsigned char  uchTransMode;							//4 0 - Sale, 1 - Refund

	   unsigned char  bWithholdSales			:1;			//5	FSD69851
	   unsigned char  bWithholdTax				:1;			//5 FSD69851
	   unsigned char  bNU						:6;
	   unsigned char NU[38];								//6

	   struct   trans_tail_  tail;							//44           
};

//RSCL_BLOCK:START
struct trs_info2_rscl_log_in_								
{

	   unsigned char opcode;								//0	// 0x70 //TRANS_INFO2
	   unsigned char function;  							//1	// 0xC6 //TRANS_INFO2_RSCL_LOG_IN

	   unsigned short	cashier_no;		                    //2
	   unsigned char	uchLogin	:1;						//4	1-login, 0- logout
	   unsigned char	nu			:7;	
	   unsigned long    lRsclLoginSequenceNumber;			//5
	   unsigned char	NU[35];								//9

	   struct   trans_tail_  tail;							//44           
};
//RSCL_BLOCK:END

//FSD52912
struct trs_info2_parent_return_type_
{
	
	   unsigned char opcode;								//0	// 0x70 //TRANS_INFO2
	   unsigned char function;  							//1	// 0xE9 //TRANS_INFO2_PARENT_RETURN_TYPE
	   
	   unsigned char uchStatus			:1;					//2 //0 - start
																//1 - end
	   unsigned char bVoided			:1;					//2
	   unsigned char uch_NU				:6;					//2
																
																
	   unsigned char uchType;								//3 Return Type
	   unsigned short ushEjLine;							//4 The line number of Return Type description
	   unsigned char NU[38];								//6
	   
	   struct   trans_tail_  tail;							//44           
};

//TRANS_SCOT Start
//RSCL_BLOCK:START
struct Trs_SCO_General_
{
		unsigned char GeneralBuff[44];
		struct   trans_tail_  tail;							//44 
};

struct trs_scot_log_in_								
{

	   unsigned char opcode;								//0	// 0x80 //TRANS_SCOT
	   unsigned char function;  							//1	// 0x00 //TRANS_SCOT_LOG_IN

	   unsigned short	cashier_no;		                    //2
	   unsigned char	uchLogin	:1;						//4	1-login, 0- logout
	   unsigned char	nu			:7;	
	   unsigned long    lRsclLoginSequenceNumber;			//5
	   unsigned char	NU[35];								//9

	   struct   trans_tail_  tail;							//44           
};

struct trs_scot_force_weight_								
{

	   unsigned char opcode;								//0	// 0x80 //TRANS_SCOT
	   unsigned char function;  							//1	// 0x10 //TRANS_INFO3_SCOT_FORCE_WEIGHT

	   unsigned char	plu_number[7];		                //2 //BCD
	   long				weight;								//9
	   long				fVariance;							//13 //TD43020
	   unsigned char	NU[27];								//17
	   
	   struct   trans_tail_  tail;							//44      
};

struct trs_scot_security_weight_violation_								
{

	   unsigned char	opcode;								//0	// 0x80 //TRANS_SCOT
	   unsigned char	function;  							//1	// 0x11 //TRANS_INFO3_SCOT_SECURITY_WEIGHT_VIOLATION

	   unsigned char	plu_number[7];		                //2 //BCD
	   unsigned char    violation_type;						//9
	   long				weight;								//10
	   unsigned long    lRsclLoginSequenceNumber;			//14	   
	   unsigned long	lProduceWeight;						//18 #52857	
	   unsigned short	ushLearningResetThreshold;			//22 TD43020
	   unsigned short	ushCashierID;						//24 FSD69934 - StoreLine SCO Cashier Intervention Transaction	
	   unsigned char	NU[18];								//26

	   struct   trans_tail_  tail;							//44           
};

struct trs_scot_security_weight_learning_								
{

	   unsigned char opcode;								//0	// 0x80 //TRANS_SCOT
	   unsigned char function;  							//1	// 0x12 //TRANS_INFO3_SCOT_SECURITY_WEIGHT_LEARNING

	   unsigned char	plu_number[7];		                //2 //BCD
	   long				weight;								//9
	   unsigned long    lRsclLoginSequenceNumber;			//13
	   unsigned char	learningMode;						//17
	   unsigned short	ushMinLearningSamples;				//18	//TD43020
	   unsigned short	ushZeroWeightLearningThreshold;		//20	//FSD110921
	   
	   unsigned char	NU[22];								//25

	   struct   trans_tail_  tail;							//44           
};


struct trs_rscl_intervention_report
{
		unsigned char	opcode;								//0	// 0x80 //TRANS_SCOT
		unsigned char	function;  							//1	// 0x13 //TRANS_INFO3_RSCL_INTERVENTION_REPORT
		unsigned short	cashier;							//2
		unsigned short	shInterventionId;					//4
		unsigned short	shInterventionSource;				//6
		unsigned char Intervention_sub_type_Id;				//8	FSD69934 StoreLine SCO Cashier Intervention Transaction
		unsigned char	NU[35];								//9	
		struct   trans_tail_  tail;							//44           

};
//RSCL_BLOCK:END
#define	EVERDAY_REWARD 1

struct trs_info2_electronic_voucher_
{
	   unsigned char opcode;								//0	// 0x70 //TRANS_INFO2
	   unsigned char subOpcode;  							//1	// 0xC8 //TRANS_INFO2_ELECTRONIC_VOUCHER
	   unsigned char function;								//2 // 1 - EVERDAY_REWARD FSD42115

	   union
	   {
		   struct											//EVERDAY_REWARD
		   {
			   unsigned char	uchBCDExpiryDate[4];		//3  YYYYMMDD as unpak. 
			   unsigned char	uchStatus;					//7  1 - Present, 2 - Not present
			   unsigned char	uchPeriod;					//8  0 - Current, 1 - Next

			   unsigned char	bVoided				:1;		//9
			   unsigned char	nu_flags			:7;		//9

			   unsigned short	ushChargeStoreID;			//10 1 - 9999
			   unsigned short	ushMaxFuelLimit;			//12 0 - 999
			   unsigned long	ulMemberAccountID;			//14 1 - 9999
			   unsigned long	ulMemberAccountAddValue;	//18 1 - 999999999 (Can be converted to up to 3 decimal point (0.001 - 999999.999), depending on member account decimal point definition)
			   unsigned char	sCardNo[20];				//22  //#48994
			   unsigned char	uchDecimalPlace;			//42  //#50379
			   unsigned char	filler[1];					//43
		   }everydayReward;

	   }info;

    struct   trans_tail_  tail;								//44

};

struct trs_info2_eft_cashout_rounding_						//FSD42120		
{

	   unsigned char opcode;								//0	// 0x70 //TRANS_INFO2
	   unsigned char subOpcode;  							//1	// 0xD1 //TRANS_INFO2_EFT_CASHOUT_ROUNDING

	   long lCashoutAmount;									//2
	   long	lCashoutCorrection;								//6
	   unsigned char	filler[34];							//10

	   struct   trans_tail_  tail;							//44           
};



#define	RESUME_PAYMENT 1
#define	NON_PAYMENT	   2
/*----------------------------------------------------------------------
Opcode:		0x70 
Subopcode:	0xC9
function:	1 RESUME_PAYMENT: 
			2 NON_PAYMENT
Swap Payment (POS information) transaction
-----------------------------------------------------------------------*/
struct trs_info2_swap_payment_
{
	unsigned char opcode;								//0	// 0x70 //TRANS_INFO2
	unsigned char subOpcode;  							//1	// 0xC9 //TRANS_INFO2_SWAP_PAYMENT
	unsigned char function;								//2 // 1 - RESUME_PAYMENT	FSD36846
															// 2 - NON_PAYMENT		FSD36846

	union
	{
	   struct											//RESUME_PAYMENT
	   {
			unsigned char uchFormNumber[9];				//3		Form ID
			unsigned char bcdNonPaymentDate[3];			//12	Date (YYMMDD in BCD)
			unsigned char bcdNonPaymentTime[3];			//15	Time (HHMMSS in BCD)
			unsigned char bcdNonPaymentPosNo[2];		//18	Pos Number	
			unsigned char bStartTicket		:1;			//20
			unsigned char bWithholdSales	:1;			//20	FSD69851
			unsigned char bWithholdTax		:1;			//20	FSD69851
			unsigned char bTenderCorrection	:1;			//20	#117215 Need identify tender correction ticket in resume payment
			unsigned char NU				:4;
			
			unsigned char filler[23];					//21
	   }resumePayment;

	   struct											//NON_PAYMENT
	   {
			unsigned char bcdExpiryDate[3];				//3		Date (YYMMDD in BCD)
			unsigned char bNonPaymentTicket			:1;	//6
			unsigned char NU						:7;	//6			

			unsigned char filler[37];					//7
	   }nonPayment;

	}info;

    struct   trans_tail_  tail;					//44
};

#define	PUMP_DATA 1
/*----------------------------------------------------------------------
Opcode:		0x70 
Subopcode:	0xCA
function:	1 PUMP_DATA: pump data trs extension 
Fuel Data (POS information) transaction
-----------------------------------------------------------------------*/
struct trs_info2_fuel_data_
{
	unsigned char opcode;								//0	// 0x70 //TRANS_INFO2
	unsigned char subOpcode;  							//1	// 0xCA //TRANS_INFO2_FUEL_DATA
	unsigned char function;								//2 // 1 - PUMP_DATA FSD36846

	union
	{
	   struct											//PUMP_DATA
	   {
		    unsigned char uchPumpHangUpDate[3];					//3		Date (YYMMDD in BCD)
			unsigned char uchPumpHangUpTime[3];					//6		Time (HHMMSS in BCD)
		    unsigned char uchPumpPickUpDate[3];					//9		Date (YYMMDD in BCD)
			unsigned char uchPumpPickUpTime[3];					//12	Time (HHMMSS in BCD)
			unsigned char	filler[29];							//15
	   }pumpData;

	}info;

    struct   trans_tail_  tail;					//44

};


#define	TRS_LOCATION_EXTENSION1	0

/*----------------------------------------------------------------------
Opcode:		0x70 
Subopcode:	0xCB
function:	0 TRS_LOCATION_EXTENSION1: location trs extension 1
Location (POS information) transaction
-----------------------------------------------------------------------*/
struct trs_info2_location_						//OFS	Description
{
	unsigned char opcode;					//0		0x70	TRANS_INFO2
	unsigned char subOpcode;  				//1		0xCB	TRANS_INFO2_LOCATION
	unsigned char function;					//2		0 - location trs extension 1

	unsigned short ushCheckoutBankStoreNo;	//3
	unsigned char uszPosShortDesc[6];		//5	    FSD#159233 POS Short Description
	unsigned char uchSelfScanningIndicator;	//11	FSD#390396 3 = QuickScan, 4 = SelfPay.
	unsigned char filler[32];				//12

	struct   trans_tail_  tail;				//44	Transaction tail
};											//64

/*----------------------------------------------------------------------
Opcode:		0x70 
Subopcode:	0xCD
Function:	0
FSD28467 GinatB
-----------------------------------------------------------------------*/
struct trs_info2_self_scan_rescan_diff_
{
    unsigned char opcode;		//0 0x70
    unsigned char function;		//1 0xCD TRANS_INFO2_SELF_SCAN_RESCAN_DIFF

    long lSelfScanQty;			//2
	long lRescanQty;			//6
	long lSelfScanAmnt;			//10
	long lRescanAmnt;			//14
	
	unsigned char NU[26];		//18 Not used

    struct   trans_tail_  tail;	//44
};

//TRANS_SCOT End


/*----------------------------------------------------------------------
Opcode:		0x70 
Subopcode:	0xCE
FSD45606 C4 Wynid ETopUp - ETopUp data transaction 
-----------------------------------------------------------------------*/
struct trs_info2_etopup_item_data_
{
	unsigned char opcode;								//0	// 0x70 //TRANS_INFO2
	unsigned char function;  							//1	// 0xCE //TRANS_INFO2_ETOPUP_ITEM_DATA

	unsigned char sPluCode[7];							//2		// BCD
	long price;											//9
	unsigned char szPinSerialNumber[21];				//13	// EFTAG_DATA_NUM_SERIE
	unsigned char szExpiryDate[9];						//34	// EFTAG_DATA_DATE_F
	unsigned char NU;									//43

	struct   trans_tail_  tail;							//44           
};


/*----------------------------------------------------------------------
Opcode:		0x70 
Subopcode:	0xCF
FSD45606 C4 Wynid ETopUp - ETopUp data transaction extension
-----------------------------------------------------------------------*/
struct trs_info2_etopup_item_data_ext1_
{
	unsigned char opcode;								//0	// 0x70 //TRANS_INFO2
	unsigned char function;  							//1	// 0xCF //TRANS_INFO2_ETOPUP_ITEM_DATA_EXT1

	unsigned char szAuthNumber[9];						//2		// EFTAG_DATA_CALL_N
	unsigned char szMerchantNumber[13];					//11	// EFTAG_DATA_NCO
	unsigned char sTransSeqNumber[9];					//24	// EFTAG_DATA_SEQ
	unsigned short ushSchemeId;							//33
	struct {
		unsigned char bConfirmationFailed    : 1;
		unsigned char bConfirmationSucceeded : 1;
		unsigned char bVoided				 : 1;
		unsigned char NU					 : 5;
	} flags;											//35
	unsigned char NU1[8];								//36

	struct   trans_tail_  tail;							//44           
};
/*----------------------------------------------------------------------
Opcode:		0x70 
Subopcode:	0xD2
-----------------------------------------------------------------------*/
#define LONG_ITEM_DESCRIPTION   1; // for function of pluDataTrs FSD42113 

struct trs_info2_plu_data_									//FSD42113		
{

	   unsigned char opcode;								//0	// 0x70 //TRANS_INFO2
	   unsigned char subOpcode;  							//1	// 0xD2 //TRANS_INFO2_PLU_DATA
	   unsigned char function;								//2 //  1 (LONG_ITEM_DESCRIPTION) --- for FSD42113 long item description

	   union
	   {
		   unsigned char NU:8;								//3 
	   }flags;
	   union
	   {
		   unsigned char sData[40];							//4
	   }data;
	   struct   trans_tail_  tail;							//44           
};

/*----------------------------------------------------------------------
Opcode:		0x70 
Subopcode:	0xD3
-----------------------------------------------------------------------*/
struct trs_info2_return_extra_information_					//FSD30639		
{

	unsigned char opcode;								//0	0x70 //TRANS_INFO2
	unsigned char function;  							//1	0xD3 //TRANS_INFO2_RETURN_EXTRA_INFORMATION

	unsigned char sDate[3];								//2 yymmdd (BCD)
	unsigned short ushFiscalTicketNumber;				//5 Fiscal ticket number
	unsigned short ushPosNo;							//7 Pos number

	unsigned char sData[35];							//9
	   
	struct   trans_tail_  tail;							//44           
};

/*----------------------------------------------------------------------
Opcode:		0x70 
Subopcode:	0xD4
-----------------------------------------------------------------------*/
struct trs_info2_return_voucher_sequence_number_			//FSD30639		
{

	unsigned char opcode;								//0	0x70 //TRANS_INFO2
	unsigned char function;  							//1	0xD4 //TRANS_INFO2_RETURN_VOUCHER_SEQUENCE_NUMBER
	unsigned char sub_func;								//2		0: Issue	<Opcode Value="0x00-0x02"/>
														//		1: Redeem
														//		2: Not redeemed

	unsigned char type;									//3
	unsigned long ulSeq_num;							//4
	long lTicket_amount;								//7
	unsigned char sData[32];							//11

	struct   trans_tail_  tail;							//44           
};

/*----------------------------------------------------------------------
Opcode:		0x70 
Subopcode:	0xD5
-----------------------------------------------------------------------*/
struct trs_info2_rpc_cc_deposit_			//FSD48165		FSD28354
{

	unsigned char opcode;								//0	0x70 //TRANS_INFO2
	unsigned char function;  							//1	0xD5 //TRANS_INFO2_RPC_CC_DEPOSIT
	unsigned char sub_func;								//2		1: CC
														//				11: CC deposit
														//				12: CC balance enquiry
														//		2: RPC
														//				21: RPC deposit
		
	unsigned char bMaximumDeposit	:1;					//3	
	unsigned char bEFTPayment		:1;					//3	0 for first D5,otherwise depands on tender type
	unsigned char bCashPayment		:1;					//3	0 for first D5,otherwise depands on tender type
	
	unsigned char	bDepositOffline		:1	;			//3 1:deposit commit fail for first D5.
	unsigned char	bEFTOnLineSAF		:1	;
	unsigned char   bUnPaidDeposit		:1;				//3	not for first D5.//#54626
	unsigned char	bSuccessFulDeposit	:1;				//3	//#54799
	unsigned char bFlagUN				:1;					//3	

														/*
														1:Maximum deposit
														2:EFT payment 
														3:cash payment
														4:deposit								
														*/

	unsigned char bVoid	:1;								//4
	unsigned char bKeyed:1;								//4
	unsigned char bFailed:1;							//4 not used
	unsigned char bCanceled:1;							//4 for voiding tender
	unsigned char bCanceledPrinted:1;					//4 for voiding tender printing
	unsigned char bCounted:1;							//4 for voiding tender
	unsigned char bSwiped:1;							//4 For CC only 	
	unsigned char bScanned:1;							//4 For CC only

	long	lMaxAmountAllowed;							//5 Maximum deposit allowed of RPC for first D5 record (otherwise 0) in
														//  ticket, or amount of deposit tender for other D5 records
	long	lAmount;									//9

	unsigned char sCardNo[16];							//13 BCD Format
	long	lSessionId;						//#53845	//29 for first D5 in ticket,keep session id of CC
	unsigned char sExpiryDate[4];						//33 BCD Format
	unsigned short ushTenderNo;							//37
	long	lSupervisor;								//39
	unsigned char uchDepositCount;									//43

	struct   trans_tail_  tail;							//44           
};

/**************************************************
DESCRIPTION:  TRANS_GENERAL_LONG_DATA struct.
			This transaction will be used to send
			transactions storing long data.

Fields:		unsigned char uchCurrentTransPosition: Holds the current trans position
				among trs_general_long_data_ transactions.
			unsigned char uchTotalTransCount: Holds the total trs_general_long_data that
				should be sent to cover all data.
			unsigned long ulDataLength: Holds the current data length.
			E.g.: We want to send 50 bytes of certain continuous data, then we should send 2
			trs_general_long_data_:
			First:  uchCurrentTransPosition <- 1 , uchTotalTransCount <- 2 , ulDataLength <- 36
					szData <- the first 36 bytes.
			Second: uchCurrentTransPosition <- 2 , uchTotalTransCount <- 2 , ulDataLength <- 14	
					szData <- the last 14 bytes.

Who     When        What
-----   --------    ----
NemerN	27/04/08	FSD42325. 
***************************************************/
struct trs_general_long_data_
{
	unsigned char opcode;								//0		Value: 0xC9 (TRANS_GENERAL_LONG_DATA) 
	unsigned char function;  							//1		Possible values:
																/*
																1 -	GENERAL_DATA_ENCRYPTED_PASSWORD , FSD42325.
																*/
	unsigned char uchCurrentTransPosition;				//2		 
	unsigned char uchTotalTransCount;					//3
	unsigned long ulDataLength;							//4
	char szData[36];							//8

	struct   trans_tail_  tail;							//44           
};

// FSD90637 - START
/**************************************************
DESCRIPTION:  TRANS_GENERAL_LONG_DATA2 struct.
			This transaction will be used to send
			transactions storing long data.  

  NOTE:		This structure was copied from the TRANS_GENERAL_LONG_DATA struct and
			modified to include an algorithm type byte and to reserve 5 bytes for future
			use.  This leaves 30 bytes for the actual long data.

Fields:		unsigned char uchCurrentTransPosition: Holds the current trans position
				among trs_general_long_data2_ transactions.
			unsigned char uchTotalTransCount: Holds the total trs_general_long_data that
				should be sent to cover all data.
			unsigned long ulDataLength: Holds the current data length.
			unsigned char uchAlgorithmType: AlgorithmType

			E.g.: We want to send 50 bytes of certain continuous data, then we should send 2
			trs_general_long_data2_:
			First:  uchCurrentTransPosition <- 1 , uchTotalTransCount <- 2 , ulDataLength <- 30
					szData <- the first 30 bytes.
			Second: uchCurrentTransPosition <- 2 , uchTotalTransCount <- 2 , ulDataLength <- 20	
					szData <- the last 20 bytes.

Who     When        What
-----   --------    ----
KeithW	25/02/10	FSD90637. 
***************************************************/
struct trs_general_long_data2_
{
	unsigned char opcode;								//0		Value: 0xC9 (TRANS_GENERAL_LONG_DATA) 
	unsigned char function;  							//1		Possible values:
																/*
																2 -	GENERAL_DATA_ENCRYPTED_PASSWORD2 , FSD90637.
																*/
	unsigned char uchCurrentTransPosition;				//2		 
	unsigned char uchTotalTransCount;					//3
	unsigned long ulDataLength;							//4
	unsigned char uchAlgorithmType;						//8		Contains the value of GSP: POS_PARAM.rec_25.uchPOSPasswordValidation
	unsigned char uchNU[5];								//9

	char szData[30];									//14

	struct   trans_tail_  tail;							//44           
};
//FSD90637 - END

/*----------------------------------------------------------------------
Opcode:		0x70 
Subopcode:	0xD6
-----------------------------------------------------------------------*/
struct trs_info2_giftcard_extra_data_		//FSD45975
{
	unsigned char opcode;								//0	// 0x70 //TRANS_INFO2
	unsigned char function;  							//1	// 0xD6 //TRANS_INFO2_GIFTCARD_EXTRA_DATA

	char psResponseCode[4];								//2
	char pszApplicationNo[3];							//6
	char pszExpireDate[5];								//9
	char pszAuthNumber[9];								//14	//9 is enough for FSD45975 (Wynid EFT message size)
	char szMerchantID[16];								//23	//FSD55425
	char NU[5];											//39
	
	struct   trans_tail_  tail;							//44
};

//FSD45186 
struct trs_Info2EmvAuthenticData_
{
	unsigned char opcode;      //0x70	<Opcode Value="0x70" />
	unsigned char function;    //0xD7	<Opcode Value="0xD7" />
	
	unsigned char EmvIssuerAuthenticationData[20];	//TC transaction confirmation; from field "IssuerAuthenticationData"
													// for customer, for EMV templates
	long lEmvAmountOther;							//22	TD228081

    unsigned char reserved[18]; 
   
	struct   trans_tail_  tail;
};

/*----------------------------------------------------------------------
TRANS_INFO2_MARK_FISCAL_UNSECURED_TRS
Opcode:		0x70 
Subopcode:	0xDC
-----------------------------------------------------------------------*/
struct trs_info2_mark_fiscal_unsecure_trs_			//FSD #40832	
{
	unsigned char opcode;								//0	0x70 //TRANS_INFO2
	unsigned char function;  							//1	0xD4 //TRANS_INFO2_MARK_FISCAL_UNSECURED_TRS
	unsigned char bIsUnsecuredTrs	:1;					//2			0 secure 1 unsecure		
	unsigned char nu1				:7;					//2
	long ticket_total;
	unsigned char nu[37];								//7

	struct   trans_tail_  tail;							//44     
	
};

/*----------------------------------------------------------------------
TRANS_INFO2_HOME_SHOPPING_DETAILS
Opcode:		0x70
Subopcode:	0xDD
-----------------------------------------------------------------------*/
struct trs_info2_home_shopping_details_info1_
{
	char	sFileID[20];					// 0
	char	sCarRegistration[12];			// 20
	char	nu[9];							// 32
											// 41
};

struct trs_info2_home_shopping_details_info2_
{
	char	sCustomerName[20];				// 0
	char	sCustomerAccountNumber[13];		// 20
	char	nu[8];							// 33
											// 41
};

struct trs_info2_home_shopping_details_							// #50118
{
	unsigned char opcode;										//0	0x70 //TRANS_INFO2
	unsigned char function;  									//1	0xD4 //TRANS_INFO2_HOME_SHOPPING_DETAILS
	unsigned char subfunction;									//2
	
	union {														//3
		struct trs_info2_home_shopping_details_info1_ info1;	//3 info1
		struct trs_info2_home_shopping_details_info2_ info2;	//3 info2
	};

	struct   trans_tail_  tail;							//44
};

/*----------------------------------------------------------------------
Opcode:		0x70
Subopcode:	0x5F
Remote Account transaction response
-----------------------------------------------------------------------*/
struct trs_info2_remac_response_		//OFS	Description
{
	unsigned char opcode;	  			//0		0x70
	unsigned char function;				//1		0x5F

	unsigned char text[25];				//2		Response text
	long balance;						//27	Account balance

	unsigned char opt_topup	:1;			//31	Topup transaction
	unsigned char opt_purchase:1;		//31	Purchase transaction
	unsigned char opt_failed:1;
	unsigned char opt_nu	:5;

	unsigned char trans_no[6];			//32  Thor Transaction number in BCD exluding merchant code and site number:
										//	  TTTTTYYMMDDS
										//	  TTTTT: ticket number
										//	  YYMMDD: date
										//	  S : sequeantial number in ticket
	unsigned char notused[6];			//38
	struct   trans_tail_  tail;			//44
};

/*----------------------------------------------------------------------
Opcode:		0x70
Subopcode:	0xE2
HASH PAN EFT Account Info2 transaction for the US
-----------------------------------------------------------------------*/
//Issue #17534SL
struct trs_info2_hash_PAN_US_					//OFS	Description
{
	unsigned char opcode;						// 0 0x70
	unsigned char function;						// 1 0xE2

	char HashAcctNo[40];						// 2 Hashed account number from EFT/MTX	
	unsigned char nu[2];						//42

	struct trans_tail_ tail;					//44
};

struct trs_info2_ola_summary_
{
	unsigned char uchOpcode;					// 0	0x70
	unsigned char uchFunction;					// 1	0xE3

	unsigned char  sUniqueTransId[3];			// 2	BDC - unique number sent to mosaic
	unsigned char  sTransDate[3];				// 5	BDC - OLA date
	unsigned char  sTransTime[3];				// 8	BDC - OLA time
    unsigned char  uchTransType;				// 11	0 - Purchase
												//		1 - Airtime
												//		2 - Refund
												//		3 - Airtime, Reversal(see posdef.h as well)
	unsigned char  sTerminalId[4];				// 12	BCD - OLA Terminal ID
    unsigned char  uchResponseCode;				// 16	Profile returned from esocket
	unsigned long  lRequestedAmount;			// 17   Requested amount
	unsigned long  lActualAmount;				// 21   Requested amount
	unsigned char  sPanNumber[10];				// 25   BCD - Account Pan
	unsigned char  sResponseCode[2];			//35	//51561

	unsigned char  Filler[7];					// 37
	
	struct trans_tail_ tail;					// 44
};

/*----------------------------------------------------------------------
TRANS_INFO2_ITEM_RESTRICTED
Opcode:		0x70 
Subopcode:	0xE6
-----------------------------------------------------------------------*/
struct trs_info2_item_restricted_trs_			//FSD55819
{
	unsigned char opcode;								//0	0x70 //TRANS_INFO2
	unsigned char function;  							//1	0xE6 //TRANS_INFO2_ITEM_RESTRICTED
	unsigned char item_id[7];							//2
	unsigned short shDepartmentId;						//9
	unsigned char uchReasonType;						//11  1- DEA Hard-lock
														//	  2- Time Restriction
	unsigned short shGroupLayoutId;						//12

	unsigned char nu[30];								//14

	struct   trans_tail_  tail;							//44     
	
};
/*----------------------------------------------------------------------
TRANS_INFO2_CUSTOMER_DETAILS
Opcode:		0x70 
Subopcode:	0xEB
-----------------------------------------------------------------------*/
struct trs_info2_customer_details_trs_			//FSD54877
{
	unsigned char opcode;						//0	0x70 //TRANS_INFO2
	unsigned char function;  					//1	0xEB //TRANS_INFO2_CUSTOMER_DETAILS
	unsigned char uchType;						//2   0 = Address1
												//	  1 = Address2
												//	  2 = Address3
	unsigned char uchData[40];					//3
	unsigned char nu;							//43

	struct   trans_tail_  tail;					//44     
	
};

/*----------------------------------------------------------------------
TRANS_INFO2_CUSTOMER_DETAILS_EXT
Opcode:		0x70 
Subopcode:	0xEC
-----------------------------------------------------------------------*/
struct trs_info2_customer_details_ext_trs_			//FSD54877
{
	unsigned char opcode;						//0	0x70 //TRANS_INFO2
	unsigned char function;  					//1	0xEC //TRANS_INFO2_CUSTOMER_DETAILS_EXT
	
	unsigned char uchSureName[20];				//2
	unsigned char uchTitle[4];					//22
	unsigned char uchInitials[3];				//26
	long lPluMsgSeq;							//29
	unsigned char nu[11];					    //33

	struct   trans_tail_  tail;					//44     
	
};

/*----------------------------------------------------------------------
TRANS_INFO2_GIFT_RECEIPT
Opcode:		0x70 
Subopcode:	0xE8
-----------------------------------------------------------------------*/
struct trs_info2_gift_receipt_trs_			//FSD55832
{
	unsigned char uchOpcode;					//0	0x70 //TRANS_INFO2
	unsigned char uchFunction;  				//1	0xE8 //TRANS_INFO2_GIFT_RECEIPT

	unsigned short ushSequenceNumber;			//2	Record sequence number
	long lQuantity;					//4 Quantity

	unsigned char uchPluCode[7];				//8

	unsigned char uchNotUsed[29];				//15

	struct   trans_tail_  tail;					//44     
	
};

/*----------------------------------------------------------------------
TRANS_INFO2_FOREIGN_CURRENCY
Opcode:		0x70 
Subopcode:	0xEF
-----------------------------------------------------------------------*/
struct trs_info2_foreign_currency_trs_			//FSD55806
{
	unsigned char opcode;						//0	0x70 //TRANS_INFO2
	unsigned char function;  					//1	0xEF //TRANS_INFO2_FOREIGN_CURRENCY
	
	long lForeignCurrencyAmount;					//2
	long lExchangeRate;							//6
	
	
	unsigned char nu[34];					    //10

	struct   trans_tail_  tail;					//44     
	
};

/*----------------------------------------------------------------------
TRANS_LOYALTY_CARD_EXCHANGE
Opcode:		0x70
Subopcode:	0xF1
-----------------------------------------------------------------------*/
struct trs_info2_loyalty_card_exchange_			//FSD57203
{
	unsigned char opcode;						//0	0x70 //TRANS_INFO2
	unsigned char function;  					//1	0xF1 //TRANS_LOYALTY_CARD_EXCHANGE
	
	unsigned char sOldCard[21];					// 2
	unsigned char sNewCard[21];					// 23

	struct   trans_tail_  tail;					//44     
};

/*----------------------------------------------------------------------
FSD58540 Cash Voucher
TRANS_INFO2_CASH_VOUCHER
Opcode:		0x70
Subopcode:	0xF4
-----------------------------------------------------------------------*/
struct trs_info2_cash_voucher_
{
	unsigned char	opcode;					//0		0x70	<Opcode Value="0x70"/>
	unsigned char	function;				//1		0xF4	<Opcode Value="0xF4"/>	TRANS_INFO2_CASH_VOUCHER

	unsigned char	uchFunctionType;		//2		1 - Sale
											//		2 - Redemption

	unsigned char	sVoucherSerialStart[7];	//3		BCD
	unsigned char	sVoucherSerialEnd[7];	//10	BCD
	unsigned char	uchLenOfSerial;			//17	Len of voucher serial number

	unsigned char	bCanceled			:1;	//18
	unsigned char	uchNu				:7;	//18

	unsigned char	notInUse[25];			//19	Not used

	struct trans_tail_	tail;				//44	TRS tail
};

//SL_US Issue #17615 [ShlomitG]
struct trs_lanehawk_clear_item_
{
	unsigned char opcode;					//0		0X70
	unsigned char function;					//1		0XFA
	unsigned char code[7];					//2
	unsigned char nu[35];					//9
	struct trans_tail_ tail;				//44
};


//Global Transaction
struct trs_info2_ola_extra_data_header_
{
	unsigned char opcode;					//0		0X70
	unsigned char function;					//1		0XFD
	char data[42];							//2    see  ola_extra_data_header_
	struct trans_tail_ tail;				//44
};	

struct ola_extra_data_header_
{
	unsigned short ushClientID;				//Offset2
	unsigned short ushApplicationID;		//Offset4
	unsigned char	uchNumberOfTransactions;	//Offset6
	char Filler[37];						//Offset7
} ;

//Global Transaction
struct trs_info2_ola_extra_data_
{
	unsigned char opcode;					//0		0X70
	unsigned char function;					//1		0XFE
	unsigned char uchTrsType;				//2     see ola_extra_data_Transaction_Types
	char data[41];							//3    see  ola_extra_data_Transaction_Data_
	struct trans_tail_ tail;				//44	
};

enum ola_extra_data_transaction_types_
{
	TransactionTypeHeader				=	0,
	TransactionTypeNumeric				=	1,
	TransactionTypeShortAscii			=	2,
	TransactionTypeLongAscii			=	3
};

enum ola_extra_data_field_types_
{
	FieldTypeByte			=	0,
	FieldTypeInt16			=	1,
	FieldTypeInt32			=	2,
	FieldTypeInt64			=	3,
	FieldTypeFloat			=	4,
	FieldTypeDate			=	5,
	FieldTypeTime			=	6,
	FieldTypeBinary			=	7,
	FieldTypeString			=	8,
	FieldTypeBCDDateTime	=	9
};

struct ola_extra_data_Transaction_Data_
{
	union
	{
		struct ola_extra_data_transaction_data_type_numeric_
		{
			unsigned char uchField1Id;		//Offset3
			unsigned char uchField1Type;	//Offset4  --> see ola_extra_data_FieldTypes
			long lField1Value;				//Offset5

			unsigned char uchField2Id;		//Offset9
			unsigned char uchField2Type;	//Offset10 --> see ola_extra_data_FieldTypes
			long lField2Value;		 		//Offset11

			unsigned char uchField3Id;		//Offset15
			unsigned char uchField3Type;	//Offset16 --> see ola_extra_data_FieldTypes
			long lField3Value;		 		//Offset17

			unsigned char uchField4Id;		//Offset21
			unsigned char uchField4Type;	//Offset22 --> see ola_extra_data_FieldTypes
			long lField4Value;		 		//Offset23

			unsigned char uchField5Id;		//Offset27
			unsigned char uchField5Type;	//Offset28 --> see ola_extra_data_FieldTypes
			long lField5Value;		 		//Offset29

			unsigned char uchField6Id;		//Offset33
			unsigned char uchField6Type;	//Offset34 --> see ola_extra_data_FieldTypes
			long lField6Value;				//Offset35
			
			unsigned char nu [5];			//offset 39

		} ola_extra_data_transactionData_type_numeric;

		struct ola_extra_data_transaction_data_short_ascii_
		{
			unsigned char uchField1Id;		//Offset3
			unsigned char uchField1Type;	//Offset4 --> see ola_extra_data_FieldTypes
			char sField1Value[18];			//Offset5

			unsigned char uchField2Id;		//Offset23
			unsigned char uchField2Type;	//Offset24 --> see ola_extra_data_FieldTypes
			char sField2Value[18];			//Offset25

			unsigned char nu ;			//offset 39
		} ola_extra_data_transaction_data_short_ascii;

		struct ola_extra_data_transaction_data_long_ascii_
		{
			unsigned char uchFieldId;		//Offset3
			unsigned char uchFieldType;		//Offset4 --> see ola_extra_data_FieldTypes
			char sFieldValue[39];			//Offset5
		} ola_extra_data_transaction_data_long_Ascii;
	}transaction_data;
};


//FSD61079
struct trs_info2_log_function_trigger_ 
{
	unsigned char opcode;					//0		0X70
	unsigned char function;					//1		0X7E		TRANS_INFO2_LOG_FUNCTION_TRIGGER
	unsigned char uchBCDFunctionID[2];		//2
	char		  chFunctionName[20];		//4
	unsigned char uchFunctionTriggerStatus;	//24
	char		  sReference[15];			//25	ASCII	FSD67989 Machine reference
	unsigned char bcdHomeDeliveryAuthorizationNumber[3];//40	//FSD#437596
	unsigned char uchHomeDeliveryFeesItemsCounter;//43			//FSD#437596					
	struct trans_tail_ tail;				//44	
};

//FSD52846: Supporting EMV Chip Cards
#define	EMV_MANUAL_FALLBACK				1
#define	PURCHASE_ANALYSIS_DATA_HEADER	2
#define	PURCHASE_ANALYSIS_DATA			3	

struct trs_info2_emv_chip_cards_
{
	unsigned char opcode;						//0	0x70 //TRANS_INFO2
	unsigned char function;  					//1	0xFF //TRANS_INFO2_EMV_CHIP_CARDS
	unsigned char subFunction;  				//2	//1 EMV_MANUAL_FALLBACK
													//2	PURCHASE_ANALYSIS_DATA_HEADER
													//3 PURCHASE_ANALYSIS_DATA

	union
	{
		struct
		{
			unsigned char sPosProductId[12];				//3	#65395
			unsigned char sPrimaryAccountNumberSource[2];	//15
			unsigned char nu[27];							//17
		}stEmvManualFallback;

		struct
		{
			unsigned char uchTotalRecords;				//3
			unsigned char nu[40];						//4
		}stPurchaseAnalysisDataHeader;

		struct stPurchaseAnalysisData_
		{
			unsigned char uchIndex;						//3
			unsigned char sData[40];					//4
		}stPurchaseAnalysisData;

	}info;

	struct   trans_tail_  tail;					//44 
};

//FSD245239
struct trs_info2_extra_code_
{
	unsigned char opcode;					//0		0x70
	unsigned char function;					//1		0x03		TRANS_INFO2_EXTRA_CODE

	unsigned char sExtraCode[20];			//2
	unsigned char sPluNumber[7];			//22	BCD
	unsigned char uchUOSType;				//29	NUM	1-EA, 2-MP, 3-CS, 4-SH
	long lQty;								//30

	unsigned char qtyMultiPack;				//34
	unsigned short qtyShipper;				//35
	unsigned char fullShipperPrice[2];		//37
	unsigned char NU[5];					//39

	struct trans_tail_ tail;				//44
};

/*----------------------------------------------------------------------
Opcode: 0x70 function:0x18
Queue Buster information
-----------------------------------------------------------------------*/
struct trs_info2_qbuster_					//OFS	Description
{
	unsigned char uchOpc;					//0		0x70
	unsigned char uchFunc;					//1		0x18

	unsigned char uchCardId[24];			//2		QBuster card ID
	unsigned char uchfiller[18];			//26	Not used

	struct   trans_tail_  tail;				//44	TRS tail
};

struct trs_info3_vending_session_			//FSD#59806
{
	unsigned char opcode;					//0		0X80
	unsigned char function;					//1		0X01		TRANS_INFO3_VENDING_SESSION
	
	unsigned char PosPartDone			:1;	//2
	unsigned char bWasVoided			:1;	//2
	unsigned char bToBeRecalled			:1;
	unsigned char bNotToBeSoldOnRecall	:1;	//2
	unsigned char NU1					:4;	//2

	unsigned char   uchRequestType;			//3 //1-new barcode 0-cancel item
	unsigned short  ushSequence;				//4
	unsigned char	sTransDate[3];			//6 BCD
	unsigned char	sTransTime[3];			//9 BCD											
	unsigned char   sBarcode[7];				//12 barcode in BCD
	unsigned char	uchNumOfItems;				//19 number of items in barcode
	unsigned char	uchStatus;					//20 status of transaction 
	unsigned char   nu2[23];					//21

	struct trans_tail_ tail;				//44	
};
/*----------------------------------------------------------------------
Opcode: 0x96
PLU sale extention record 5
FSD 61034 - Fuelling Start and End times
-----------------------------------------------------------------------*/
struct trs_plu_sale_ext5_
{
	unsigned char uchOpcode;					//0		0x96 <Opcode Value="0x96" />

	char szFuellingStartTime[7];				//1
	char szFuellingEndTime[7];					//8

	char cVensafeTrsRefNum;						//9

	unsigned char uchFuelFunctionNo;          //16  FSD102401: NUM  1=Normal  5=Drive-off  6=Outstanding Fuel Payment 10=Pump-test
	unsigned short ushGroupId;                //17

	unsigned char bcdSTDOrderNumber[10];		//19 FSD#259707
	unsigned char bcdOriginalStdItemPluCode[7];	//29 FSD#259707

	unsigned char bSoldAsUnknownItem				:1;	//36 FSD#259707
	unsigned char bItemCommitRequested				:1;	//36 FSD#259707
	unsigned char bECommerceItem  					:1;	//36 FSD#365331
	unsigned char bAutomaticVoid  					:1;	//36 FSD#422204
	unsigned char NU36								:4;	//36

	long lVatAdjusment;						//37
	short	shNumberOfExtandedWarrantyLinkedItems;	//41	//FSD414790

	unsigned char uchNotUsed[1];				//43

	struct trans_tail_ tail;					//44

};
//FSD#358503 - Start
struct trs_plu_sale_ext7_
{
    unsigned char	opcode;					//0	0x80 Info Transaction	<Opcode Value="0x80"/>
    unsigned char	function;				//1	0xF2 TRANS_INFO3_PLU_SALE_EXT7	<Opcode Value="0xF2"/>
	char OLPSecondaryBarcode[42];		//2

	struct trans_tail_	tail;				//44	TRS tail
};
//FSD#358503 - End

//FSD#439874 - Start
struct trs_plu_sale_ext8_
{
    unsigned char	opcode;						//0	0x80 Info Transaction	<Opcode Value="0x90"/>
    unsigned char	function;					//1	0xF2 TRANS_INFO4_PLU_SALE_EXT8	<Opcode Value="0x14"/>
	long			lParkingBarcodeCounter;		//2

	unsigned char	bIsDailyCharge			:1;	//6
	unsigned char	bParkingItemWasVoided	:1;	//6
	unsigned char	bNu						:6; //6

	char			nu[37];						//7

	struct trans_tail_	tail;					//44	TRS tail
};
//FSD#439874 - End

//FSD#437272 - Start
struct trs_chip_card_info_
{
    unsigned char	opcode;						//0	0x90 Info Transaction
    unsigned char	function;					//1	0x15 TRANS_INFO4_CHIP_CARD_INFO

	unsigned char   uchChipCardNumber[8];		//2
	unsigned char   uchLastPurchaseDate[4];		//10
	long lBalancePoints;						//14
	unsigned short  ushSegmentID;				//18
	unsigned char   bCancelled			:1;		//20
	unsigned char   bChipCardIssueCoupon:1;
	unsigned char   NotInUse			:6;
	
	unsigned char   uchFiscalID[10];
	char			nu[13];						//21
	
	struct trans_tail_	tail;					//44	TRS tail
};
//FSD#437272 - End

/*----------------------------------------------------------------------
Opcode: 0x98
DEP sale extention record 2
FSD 61034 - Fuelling Start and End times
-----------------------------------------------------------------------*/
struct trs_dep_sale_ext2_
{
	unsigned char uchOpcode;					//0		0x98 <Opcode Value="0x98" />

	char szFuellingStartTime[7];				//1
	char szFuellingEndTime[7];					//8

	short		  shSubtractedQty;				//15 //Bug 87769
	unsigned char bRepeat					:1;	//17 //#89180
	unsigned char bNU						:7;	//17
	unsigned char uchFuelFunctionNo;            //18  FSD102401: NUM  1=Normal  5=Drive-off  6=Outstanding Fuel Payment 10=Pump-test
	unsigned char uchNotUsed[25];				//19

	struct trans_tail_ tail;					//44

};

/*----------------------------------------------------------------------
FSD62787
TRANS_INFO2_TICKET_REFERENCE_NUMBER
Opcode:		0x70
Subopcode:	0x7F
-----------------------------------------------------------------------*/
struct trs_info2_reference_number_  
{
    unsigned char  opcode;		            //0	  <Opcode Value="0x70"/>  
    unsigned char  function;                //1   <Opcode Value="0x7F"/> 	   

	unsigned long lReferenceNumber;		    //2

	unsigned char bcdOrderTime[3];          //6
	unsigned char bcdPaymentTime[3];        //9

    unsigned char	 not_used[32];	        //12

    struct			 trans_tail_  tail;     //44
};

/*----------------------------------------------------------------------
TRANS_INFO2_UPDATE_TRANS
Opcode:		0x70
Subopcode:	0xDF
-----------------------------------------------------------------------*/
struct trs_info2_update_trs_
{
	unsigned char opcode;				// 0	// TRANS_INFO2
	unsigned char function;				// 1	// TRANS_INFO2_UPDATE_TRANS
	unsigned char sub_function;			// 2	// i.e. UPDATE_TRS_TYPE_SALE, UPDATE_TRS_TYPE_DISCOUNT

	long updatedItemReferenceNumber;	// 3         Seq # of the item/dep being voided
	long currentItemReferenceNumber;	// 7         Seq # of the void
	long ticketStartReferenceNumber;	// 11

	long QtyRemoved;					// 15      //Issue #17935SL/17948: Add qty of this line that was removed by either cancel or subtract
	long QtyRemovedSellAmount;			// 19      //Issue #17935SL/17948: Add sell amount of this line that was removed by either cancel or subtract

	long subUpdatedItemReferenceNumber;	// 23      // Issue #18183
	unsigned char reserved_27[17];		// 27

	struct trans_tail_ tail;			// 44
};

//#67438
/*----------------------------------------------------------------------
TRANS_INFO2_CLEAN_TRS_CACHE
Opcode:		0x70
Subopcode:	0xEE
-----------------------------------------------------------------------*/
struct trs_info2_clean_trscache_
{
	unsigned char opcode;      //0x70	<Opcode Value="0x70" />
	unsigned char function;    //0xEE	<Opcode Value="0xEE" />

	unsigned char reserved[42];                     //2

	struct   trans_tail_  tail;                     //44

};

/*----------------------------------------------------------------------
TRANS_INFO3_FUEL_FUNCTION_TRIGGER
Opcode:		0x80
Subopcode:	0x02
-----------------------------------------------------------------------*/
struct trs_info3_fuel_function_triggering_
{
	unsigned char opcode;               //0  	<Opcode Value="0x80" />
	unsigned char sub_opcode;		    //1  	<Opcode Value="0x02" />

	unsigned char function;             //2    1 - Function 'Mode changes'
	                                    //	   2 - Function 'Stop pump'
                                        //     3 - Function 'Restart pump'
	unsigned char uchPumpNumber;        //3
	unsigned char uchPumpMode;          //4
	unsigned char bcdTime[3];           //5  
	unsigned short shOperatorId;		//8		//#126570
	unsigned short shStoreNum;			//10	//#126570

	unsigned char reserved[32];         //12            

	struct   trans_tail_  tail;         //44

};
/*----------------------------------------------------------------------
TRANS_INFO3_ONLINE_PURCHASE_EXT
Opcode:		0x80
Subopcode:	0x03
-----------------------------------------------------------------------*/
struct trs_info3_online_purchase_ext_
{
	unsigned char opcode;        //0  	<Opcode Value="0x80" />
	unsigned char function;      //1  	<Opcode Value="0x03" />

	unsigned char  szAdditionalReferenceForOla[15];	//2 FSD61084
	unsigned char  szReferenceNumber[12];           //17 
	unsigned char  uchAllowVoidItem;                //29   //FSD392122 - allow void OLP item
	unsigned char  bSpecialOnlineItem           :1; //30   //FSD392122 - OLP item conneced to DIA ('special' item)
	unsigned char  bManualETopUpConfirmation	:1;
	unsigned char  bNU                          :6;
	unsigned short shDynamicAttrId;                 //31   //FSD392122 - Special Dynamic Attribute OLP Item number
	unsigned char uchETopUpPhoneNumber[7];			//33
	unsigned short ushProviderRestrictions;			//40	//TD450592
	unsigned char reserved[2];						//42                  
	
	struct   trans_tail_  tail;  //44

};


/*----------------------------------------------------------------------
TRANS_INFO3_PURCHASE_ORDER_NUM
Opcode:		0x80
Subopcode:	0x04
-----------------------------------------------------------------------*/
struct trs_info3_purchase_order_num_
{
	unsigned char opcode;        //0  	<Opcode Value="0x80" />
	unsigned char function;      //1  	<Opcode Value="0x04" />

	unsigned char  szPurchaseOrderNo[36];	//2

	unsigned char reserved[6];  //38        

	struct   trans_tail_  tail;  //44

};

/*----------------------------------------------------------------------
TRANS_INFO3_FISCAL_ITEM_SALE_ERROR
Opcode:		0x80
Subopcode:	0x05
-----------------------------------------------------------------------*/
struct trs_info3_fiscal_item_sale_error_
{
	unsigned char opcode;					//0  	<Opcode Value="0x80" />
	unsigned char function;					//1  	<Opcode Value="0x05" />

	unsigned char uchPLUCode[7];			//2		plu code
	long		  lQty;						//9		quantity

	unsigned char opt_qty_is_weight		 :1;//13    /
	unsigned char opt_qty_is_decimal_qty :1;//13
	unsigned char bNu					 :6;//13

	unsigned char reserved[30];				//14        

	struct   trans_tail_  tail;  //44
};


// TD#53437
/*----------------------------------------------------------------------
TRANS_INFO3_CLUBCARD_DETAILS_EXT
Opcode:		0x80
Subopcode:	0x06
-----------------------------------------------------------------------*/
struct trs_info3_clubcard_info_ext_
{
	unsigned char opcode;				// 0  	<Opcode Value="0x80" />
	unsigned char function;				// 1  	<Opcode Value="0x06" />

	unsigned char szCustomerName[20];	// 2
	
	unsigned char NU[22];				// 22        

	struct trans_tail_ tail;			// 44
};

//FUEL Totals transactions - START
struct trs_pump_totals_
{
    unsigned char opcode;      //0x60
    unsigned char function;    //0x89

	 short nNozzle;
	 short nGrade;
	 long  lIndexNumber;
	 long  lPump;
	 long  lActiveReadNumber;
	 long  lShiftNumber;
	 long	 lVolume;
	 long	 lValueA;
	 long	 lValueB;
	 long	 lDateTime;

    unsigned char BadRecords           :1;
    unsigned char nused                :7;
    
    unsigned char reseved[5];

    struct   trans_tail_  tail;
};

//CR740 amir
//-------------------------------------------------
struct trs_tank_reading_header_
{
    unsigned char opcode;      //0x60 //0
    unsigned char function;    //0xA5 //1

	 unsigned char  EndOfDayRead  :1; //2
	 unsigned char	 ForceRead	  :1;
	 unsigned char	bIsRfs		  :1; //FSD 61034
	 unsigned char	 NotUsed	  :5;
	 unsigned char  NoOfTankRecs;     //3

	 char szReadDate[7];			  //4 //FSD 61034	
	 char szReadTime[7];              //11 //FSD 61034
	 char szTankGaugeDate[7];		  //18 //FSD 61034
	 char szTankGaugeTime[7];		  //25 //FSD 61034

    unsigned char reseved[12];        //32

    struct   trans_tail_  tail;       //44
};

struct trs_tank_reading_detail_
{
    unsigned char opcode;       //0x60 //0
    unsigned char function;     //0xA6 //1

	 unsigned char  TankNo;		       //2    
	 unsigned char  Status1;	       //3
	 unsigned char  DataMap;	       //4
	 long 			 lFuelLevel;       //5
	 long 			 lWaterLevel;      //9
	 short 			 lTemprature;     //13
	 unsigned char  Status2;	   	  //15
	 long 			 lVolume;		  //16
	 long 			 lValue;		  //20
	 long 			 lPencePerLitter; //24

	 unsigned char uchNotUsed;		  //28

	 long lProduct;					  //29 FSD 61034
	 long lTankCapacity;			  //33 FSD 61034

	 unsigned char uchPluCode[7];	  //37 FSD 61034

    struct   trans_tail_  tail;		  //44
};

struct trs_pump_reading_header_
{
    unsigned char opcode;      //0x60 //0
    unsigned char function;    //0xA7 //1

	 unsigned char  EndOfDayRead  :1; //2
	 unsigned char	 ForceRead	  :1;
	 unsigned char  bIsRfs		  :1; //FSD 61034
	 unsigned char	 NotUsed	  :5;
	 unsigned char  NoOfPumpRecs;     //3

	 char szReadDate[7];			  //4 //FSD 61034
	 char szReadTime[7];              //11 //FSD 61034
    unsigned char reseved[26];        //18

    struct   trans_tail_  tail;       //44
};

struct trs_pump_reading_detail_
{
    unsigned char opcode;      //0x60 //0
    unsigned char function;    //0xA8 //1

	 unsigned char  PumpNo;			//2																			  
	 unsigned char  Status;			//3															  
	 unsigned char  StatusNozzele1;	//4																	  
	 long 			 lVolume1;		//5
	 unsigned char  StatusNozzele2; //9																		  
	 long 			 lVolume2;		//10
	 unsigned char  StatusNozzele3;	//14																	  
	 long 			 lVolume3;		//15
	 unsigned char  StatusNozzele4;	//19																	  
	 long 			 lVolume4;		//20																		   

    unsigned char reseved[20];		//24

    struct   trans_tail_  tail;
};

struct trs_delivery_reading_header_
{
    unsigned char opcode;      //0x60 //0
    unsigned char function;    //0xA9 //1

	 unsigned char  EndOfDayRead  :1; //2
	 unsigned char  bIsRfs		  :1; //FSD 61034
	 unsigned char	 NotUsed	  :6;
	 unsigned char  NoOfDeliveryRecs; //3

	 char szDeliveryReadDate[7];      //4 FSD 61034
	 char szDeliveryReadTime[7];      //11 FSD 61034

    unsigned char reseved[26];		  //18

    struct   trans_tail_  tail;       //44
};

struct trs_delivery_reading_detail_
{
    unsigned char opcode;      //0x60	//0
    unsigned char function;    //0xAA	//1
	unsigned char sub_function;			//2

	unsigned char   TankNo;				//3
	char  szStartDate[7];		//4  //FSD61034
	char  szEndDate[7];			//11 //FSD61034
	char  szStartTime[5];		//18 //FSD61034
	char  szEndTime[5];			//23 //FSD61034
	long  lStartVolume;		//28
	long  lEndVolume;		//32
	long  lAdjDeliveryVolume;//36
	long  lAdjTemrature;		//40

    struct   trans_tail_  tail;			//44
};

//FSD 61034
struct trs_delivery_reading_detail_ext_
{
	unsigned char opcode;      //0x60   //0
    unsigned char function;    //0xAA   //1
	unsigned char sub_function; //0x01  //2

	unsigned long lStartTcVolume;		//3
	unsigned long lStartWater;			//7
	unsigned long lStartTemp;			//11
	unsigned long lStartHeight;			//15

	unsigned long lEndTcVolume;			//19
	unsigned long lEndWater;			//23
	unsigned long lEndTemp;				//27
	unsigned long lEndHeight;			//31

	unsigned long lAdjustedTcCompDeliveryVol; //35

	unsigned char uchNotUsed[5];		//39

    struct   trans_tail_  tail;			//44
};

//FUEL Totals transactions - END

//PUMP-NOZZLE-TANK configuration transaction
struct trs_tank_nozzle_pump_config_
{
	unsigned char uchOpcode;					//0		0x97 <Opcode Value="0x97" />

	unsigned short ushPump1;					//1
	unsigned short ushNozzle1;					//3
	unsigned short ushTank1;					//5

	unsigned short ushPump2;					//7
	unsigned short ushNozzle2;					//9
	unsigned short ushTank2;					//11

	unsigned short ushPump3;					//13
	unsigned short ushNozzle3;					//15
	unsigned short ushTank3;					//17

	unsigned short ushPump4;					//19
	unsigned short ushNozzle4;					//21
	unsigned short ushTank4;					//23

	unsigned short ushPump5;					//25
	unsigned short ushNozzle5;					//27
	unsigned short ushTank5;					//29

	unsigned short ushPump6;					//31
	unsigned short ushNozzle6;					//33
	unsigned short ushTank6;					//35

	unsigned short ushPump7;					//37
	unsigned short ushNozzle7;					//39
	unsigned short ushTank7;					//41

	unsigned char  uchNotUsed;					//43

	struct trans_tail_ tail;					//44

};

struct trs_changed_working_date_
{
	unsigned char opcode;      			//0		0x80
	unsigned char function;    			//1		0x09

	unsigned char old_wrk_date[3];		//2
	unsigned char new_wrk_date[3];		//5


    unsigned char nu[36];				//8

    struct   trans_tail_  tail;			//44
};

//FSD64199 - definition for barcode details extension transaction
struct trs_info_barcode_details_ext_
{
	unsigned char uchOpcode;						//0	0x80	TRANS_INFO3
	unsigned char uchFunction;						//1 0x0A	TRANS_INFO3_BARCODE_DETAILS_EXT

	unsigned char uchBarcodeDeclinationReasonCode;	//2

	unsigned char bFallbackBarcode	:1;				//3
	unsigned char NotUsed			:7;		

	unsigned char bcdSecondBarcode[20];				//4  //FSD#67382

	unsigned char uchSecondBarcodeLen;				//24

	unsigned char	arrPLUIDForParkingMinutesChargeBCD[7];		// 25	FSD#439874
	unsigned char	arrPLUIDForParkingDailyChargeBCD[7];		// 32	FSD#439874
	unsigned short	ushParkingCourtesyTimeMinutes;				// 39	FSD#439874
	
	unsigned char nu[3];							//41
	
	struct   trans_tail_  tail;						//44
};

/*----------------------------------------------------------------------
FSD28013 GS1 DataBar
TRANS_INFO3_DATABAR
Opcode:		0x80
Subopcode:	0x0B
-----------------------------------------------------------------------*/
struct trs_info3_databar_
{
    unsigned char opcode;							// 0	TRANS_INFO3			0x80
    unsigned char function;							// 1	TRANS_INFO3_DATABAR	0x0B

	unsigned char bStartTrs					:1;		// 2	Mark start trs
	unsigned char bEndTrs					:1;		// 2	Mark end trs
	unsigned char bSuccessfulDataBarScan	:1;		// 2	Successful data bar scanning
	unsigned char bCancel					:1;		// 2
	unsigned char bWasCancel				:1;		// 2
	unsigned char bNU						:3;		// 2

	unsigned char uchLenOfDataInTrs;				// 3	//Length of data in trs

	unsigned char uchData[40];						// 4

	struct trans_tail_ tail;						// 44
};

//FSD66628: subopcodes for trans 0x80, 0x0C	TRANS_INFO3_VOUCHER_DETAILS_EXT    AND
//options for:
// 1. search trs - TE->uchOptionSearchClubCardVoucherTrs , 
// 2. Write trs 0x80, 0x0C: TE->uchOptionCompleteClubCardVoucherTrs
#define DetailsClubCardVoucherFromResponse						1		// Details of voucher from response
#define DetailsClubCardVoucherBeforeCompletionTransaction		10		// if trans 0x04 exists for this voucher
#define DetailsChangeTenderForClubCardVoucher					20		// if media trs 0x04 exist for TenderChange of ClubCardVoucherTender

//FSD66628 - definition for ClubCardVoucher details extension transaction
struct trs_info80_CCVoucher_details_ext_
{
    unsigned char opcode;             	// 0 0x80	TRANS_INFO3
    unsigned char function;           	// 1 0x0C	TRANS_INFO3_VOUCHER_DETAILS_EXT
	unsigned char sub_func;			    // 2	1  inf1 - DetailsClubCardVoucherFromResponse;
										//      10 inf2	- DetailsClubCardVoucherBeforeCompletionTransaction
										//		20 inf3 - DetailsChangeOfClubCardVoucher
   
	union
    {
		unsigned char uchData[41];								//3

		struct													//3
		{
			unsigned char bVoucherApproved					:1; // 3; 0 - Approved externally, 1 - Approved locally 
			unsigned char BOOL								:7;

			unsigned short uchSessionId;						// 4
			unsigned char  uchActionType;						// 6; see posdef.h; the same type in 0x60, 0x28, 0x34
			unsigned char  BCDAccountNumber[10];				// 7; BCD, Number of ClubCardVoucher
			long		   lAmount;								// 17 Amount from response, details of Voucher

			unsigned char  uchNu[23];							// 21
			
		}inf1;

    	struct													//3
		{
			unsigned char  BCDAccountNumber[10];				// 3; BCD, Number of ClubCardVoucher
			long		   lAmount;								// 13 Amount of VoucherBeforeCompletionTransaction

			unsigned short uchSessionId;						// 17

			unsigned char  uchChangeTenderNo;					// 19 Number of tender from "Change tender" for ClubCardVoucher

			unsigned char bNoChangeIsGivenForThisTender		:1;	// 20 Parameter from "change tender" for ClubCardVoucher
			unsigned char bNU								:7;

			unsigned char  uchNu[23];							// 21

		}inf2;

		struct 
		{
			long			lChangeAmount;						// 3
			unsigned short	ushTenderChange;					// 7

			unsigned char bNoChangeIsGivenForThisTender	:1;		// 9
			unsigned char bNUChangeTender				:7;		// 9

			unsigned char uchNu[34];							// 10
		}inf3;
    };

	struct   trans_tail_  tail;							//44
};

/*----------------------------------------------------------------------
FSD55426 and FSD61519: Octopus + R$ Data
Opcode:		0x80	TRANS_INFO3
function:	0x0D	TRANS_INFO3_OCTOPUS_DETAILS
-----------------------------------------------------------------------*/
struct trs_octopus_data_      
{
	unsigned char opcode;						//0		//0x80	TRANS_INFO3
	unsigned char function;						//1		//0x0D	TRANS_INFO3_OCTOPUS_DETAILS

	long			lRDPaymentAmount;			//2     R$ Payment amount
	long			lRDRemainingValue;			//6		R$ Balance after transaction
	long			lRemainingValue;			//10	Octopus Balance after transaction
	unsigned short	ushRDBasicIssued;			//14	R$ Basic Points in ticket
	unsigned short	ushRDExtraIssued;			//16	R$ Extra Points in Ticket ( from promotion )
	long			lRDollarPromotionAmount;	//18	The Discount that was received by Redeem R$ (refer to R$ redeem Member account). 
	long			lExcludeBPAAmount;			//22	Exclude BPA Amount in ticket 

   unsigned char filler[18];					//26 Not used      

   struct   trans_tail_  tail;               //44     TRS tail
};

//FSD67194
struct trs_info3_online_purchase_item_ext_      
{
	unsigned char opcode;						//0		//0x80	TRANS_INFO3
	unsigned char function;						//1		//0x0E	TRANS_INFO3_ONLINE_PURCH_ITEM_EXT

	long			lAmount;						// 2 Amount of item

	unsigned char	bOptRefundItem				:1; // 6 return item ; MM item
	unsigned char	bOptNegativeItem			:1; // 6 other negative trans, but not cancel, subtract, void...It maybe MM, external payout
	unsigned char	bNuOpt						:6; // 6



   unsigned char filler[37];					//7 Not used      

   struct   trans_tail_  tail;					//44     TRS tail
};

struct trs_alert_load_qdx_after_short_EOD_
{
    unsigned char uchOpcode;						//0x63	<Opcode Value="0x63" />
    short shAlertNO;								// 1		<199 />	
	short shPosNo;									// 3
	unsigned char uchGSPValue;						// 5
    unsigned char uchStartEndRequiredFlag;			// 6
	unsigned char uchOperationText[27];				//7
    unsigned char data[10];							// 34
    struct   trans_tail_  tail;						// 44
};


struct trs_alert_invoice_PDF_
{
    unsigned char opcode;         //0x63	<Opcode Value="0x63" />
    
    unsigned short  subopcode;	  // 1		<Opcode Value=1012 />
    unsigned char function;		  // 3	

    unsigned char disp_message     :1;
    unsigned char drvfile_popup    :1;
    unsigned char ignore_alert     :1;
    unsigned char use_org_pos_no   :1;
    unsigned char get_text_msg     :1;
    unsigned char opt_nu15         :1;
    unsigned char opt_nu16         :1;
    unsigned char opt_nu17         :1;  // 4
	unsigned char InvoiceNum[5];        //5 
	long          lErrorNum;            //10

    unsigned char data[28];				// 14
    unsigned char org_pos_no;			// 42
    unsigned char org_pc_no;			// 43

    struct   trans_tail_  tail;			// 44
};

// FSD#85881
struct trs_info3_online_reward_message_id_
{
	unsigned char opcode;						// 0		0x80	TRANS_INFO3
	unsigned char function;						// 1		0x14    TRANS_INFO3_ONLINE_REWARD_MESSAGE_ID

	unsigned long ulPromotionID;				// 2

	unsigned short ushMessageID;				// 6

	unsigned char NU[36];						// 8

	struct   trans_tail_  tail;					// 44
};

// FSD#85881
struct trs_info3_online_reward_promotion_data_
{
	unsigned char opcode;						// 0		0x80	TRANS_INFO3
	unsigned char function;						// 1		0x15	TRANS_INFO3_ONLINE_REWARD_PROMOTION_DATA

	unsigned short ushMessageID;				// 2
	unsigned short ushDefaultOfflineMessageID;	// 4
	unsigned short ushResult;					// 6

	unsigned char ucOfflineType;				// 8

	unsigned long lAmount;						// 9

	unsigned char sRedemptionCode[28];			// 13

	unsigned char bPrintBarcode	:1;				// 41
	unsigned char bNU			:7;				// 41
	
	unsigned short ushTemplateID;               // 42       //  TD355833

	struct   trans_tail_  tail;					// 44
};

// FSD#85881
struct trs_info3_online_reward_redemption_data_
{
	unsigned char opcode;						// 0		0x80	TRANS_INFO3
	unsigned char function;						// 1		0x16	TRANS_INFO3_ONLINE_REWARD_REDEMPTION_DATA
	
	unsigned short ushResult;					// 2

	unsigned long lAmount;						// 4

	unsigned char ucOfflineType;				// 8

	unsigned char sRedemptionCode[28];			// 9

	unsigned char NU[7];						// 37

	struct   trans_tail_  tail;					// 44
};

// FSD#85881
struct trs_info3_online_reward_guid_
{
	unsigned char opcode;						// 0		0x80	TRANS_INFO3
	unsigned char function;						// 1		0x17	TRANS_INFO3_ONLINE_REWARD_GUID

	unsigned char sGUID[36];					// 2

	unsigned char bPromotion	   :1;			// 38
	unsigned char bRedemption	   :1;			// 38
	unsigned char bRequestSent     :1;			// 38
	unsigned char bResponseArrived :1;			// 38
	unsigned char bCancelled	   :1;			// 38
	unsigned char bNU			   :3;			// 38

	unsigned char NU[5];						// 39

	struct   trans_tail_  tail;					// 44
};

// FSD#85881
struct trs_info3_online_reward_image_
{
	unsigned char opcode;				        // 0		0x80	TRANS_INFO3	
	unsigned char function;						// 1		0x1E	TRANS_INFO3_ONLINE_REWARD_IMAGE

	unsigned char sImageName[42];				// 2

	struct trans_tail_ tail;					// 44
};

// FSD#85881
struct trs_info3_online_reward_print_line_
{
	unsigned char opcode;				        // 0		0x80	TRANS_INFO3	
	unsigned char function;						// 1		0x18	TRANS_INFO3_ONLINE_REWARD_PRINT_LINE

	unsigned char sLine[40];                    // 2
	
	unsigned char cAllignment;					// 42
		
	unsigned char bBold	:1;						// 43
	unsigned char bIsLarge	:1;					// 43		CR359647
	unsigned char NU		:6;					// 43

	struct   trans_tail_  tail;                 // 44
};

/*----------------------------------------------------------------------
FSD61185
TRANS_INFO3_NON_PAYMENT_TRANSACTION
Opcode:		0x80
Subopcode:	0x19
-----------------------------------------------------------------------*/
struct trs_info3_non_payment_
{
    unsigned char opcode;           //offset 0      0x80 <Opcode Value="0x80" />

    unsigned char sub_opcode;       //offset 1      0x19 <Opcode Value="0x19" />

	unsigned char uchSubFunction;   //offset 2      0 - non-payment, 1-drive off

	unsigned char uchTrsType    ;   //offset 3      0 - debt, 1- debt coverage

    unsigned char uchDataType;      //offset 4
								  // 1 - customer name  [30 char] and transaction info ((amount, tender, status).
                                  // 2 - addres 1 [30 char]
                                  // 3 - addres 2 [30 char]
                                  // 4 - addres 3 [30 char]
                                  // 5 - postcode [7 char]
								  // 6 - car info1[30 char]
								  // 7 - car info2[30 char]
	                              // 8 - reg number[7 char] 
                                  // 9 - External ticket identifier[6 char] 
	                              //10 - Offline debtor coverage data                                 
		                                                          
	unsigned char first_fg       :1; //offset 5
	unsigned char end_fg         :1;
	unsigned char nu_bits        :6;                            

    unsigned char data[30];          //offset 6

	long lTrsAmountmount;            //offset 36
	unsigned char uchTenderNo;       //offset 40
    unsigned char uchStatus    ;     //offset 41

	unsigned char nu[2];             //offset 42

    struct   trans_tail_  tail;      //offset 44
};


/*----------------------------------------------------------------------
FSD95450 - Home Shopping extra data
Opcode:		0x80	TRANS_INFO3
function:	0x1B	TRANS_INFO3_SELF_SCAN_SUMMARY
-----------------------------------------------------------------------*/
struct trs_info3_self_scan_summary_       
{ 
	unsigned char opcode;					//0		//0x80	TRANS_INFO3
	unsigned char function;					//1		//0x1B	TRANS_INFO3_SELF_SCAN_SUMMARY

	long		  lOrderAmount;				//2     
											
											//offset 6
	unsigned char bRefundTrs		:1;		//0 - No, 1 - Yes(Refund)
	unsigned char nu_bits			:7;       

	unsigned char uchResultCode;		//7	//0 - "OK", 
											//1 - "Error: Invalid Order"
											//2 - "Error: Payment Card Declined"
											//3 - "Error: Payment Card Referred"
											//4 - "Error: Item Not Found"
											//5 - "Error" System Failure"

	unsigned char sOrderNumber[8];			//8 
	
	unsigned char chSelfSystemType;			//16 
												//1 - FAST_TRACK, 
												//2 - HOME_SHOPPING
												

    unsigned char filler[27];				//17 Not used      

    struct   trans_tail_  tail;             //44  TRS tail
};

/*----------------------------------------------------------------------
FSD61180
Opcode:		0x80	TRANS_INFO3
function:	0x1C	TRANS_INFO3_GENERIC_CARD
-----------------------------------------------------------------------*/
struct trs_info3_generic_card_      
{
	unsigned char opcode;						//0		//0x80	TRANS_INFO3
	unsigned char function;						//1		//0x1C	TRANS_INFO3_GENERIC_CARD

	unsigned short	ushSchemeID;			    //2     Scheme Id
	unsigned short	ushLoyaltyType;			    //4		Loyalty Type	
	unsigned char   sExternalIdentifier[20];    //6     External Identifier
	unsigned char   CardNumber[10];			    //26    Card Number BCD
	unsigned char   uchActionType;              //36    enActionType
    unsigned long   ulOriginalTransID;          //37    Original Trans number (for enCollectLater action type)

    unsigned char   filler[3];					//41    Not used      

    struct   trans_tail_  tail;                 //44    TRS tail
};

/*----------------------------------------------------------------------
FSD61180
Opcode:		0x80    TRANS_INFO3
Subopcode:	0x1D    TRANS_INFO3_EXTERNAL_VOUCHER
-----------------------------------------------------------------------*/
struct trs_info3_external_voucher_
{
    unsigned char opcode;							// 0	TRANS_INFO3			
    unsigned char function;							// 1	TRANS_INFO3_EXTERNAL_VOUCHER	

	unsigned char uchVoucherType;	                // 2	1 - 'voucher'  type
	                                                //      2 - 'coupon'   type
	                                                //      3 - 'external' type 
	unsigned char uchExtVoucherType;				// 3	1 - 'FuelLoyalty' type
	unsigned char sVoucherNo[20];			        // 4	BCD Barcode 	
	unsigned char uchVoucherLength;	                // 24	

	unsigned char sDate[6];                         // 25  Voucher date YYMMDD - can be exp or issue
	unsigned short ushRefID;                         //31   FSD428027 Voucher Ref ID

	unsigned char nu[11];    						// 33

	struct trans_tail_ tail;						// 44
};

struct trs_info3_print_point_promo_      
{
	unsigned char opcode;						//0		//0x80	TRANS_INFO3
	unsigned char function;						//1		//0x1F	TRANS_INFO3_PRINT_POINT_PROMO

	unsigned char szDesc[21];					//2
	long		  lPoints;					    //23
    unsigned char bcdPromNumber[5];				//27    BCD 10 digits
	unsigned char bGiftItemRedemption	:1;		//32	//TD129084+129085
	unsigned char bNotUsed				:7;	


    unsigned char   filler[11];					//33    Not used      

    struct   trans_tail_  tail;                 //44    TRS tail
};

//#108211
/*----------------------------------------------------------------------
TRANS_INFO3_PROM_TOTALS
Opcode:		0x80
Subopcode:	0x20
-----------------------------------------------------------------------*/
struct trs_info3_prom_totals_
{
	unsigned char opcode;      //0x80	<Opcode Value="0x80" />
	unsigned char function;    //0x20	<Opcode Value="0x20" />

	short shPromCount;								//2

	unsigned char reserved[40];                     //4

	struct   trans_tail_  tail;                     //44
};

/*----------------------------------------------------------------------
FSD61180
TRANS_INFO3_SESSION_PRINT_DATA
Opcode:		0x80
Subopcode:	0x21
-----------------------------------------------------------------------*/
struct trs_info3_session_print_data_
{
	unsigned char opcode;      //0x80	<Opcode Value="0x80" />
	unsigned char function;    //0x21	<Opcode Value="0x21" />

	char szSerializedSession[30];					//2
	char szZone[12];                                //32

	struct   trans_tail_  tail;                     //44
};

/*----------------------------------------------------------------------
FSD61185
TRANS_INFO_OLA_DEBT_DATA
Opcode:		0x60
Subopcode:	0x28
-----------------------------------------------------------------------*/
struct trs_ola_debt_coverage_response_ 
{
    unsigned char opcode;					//0		<Opcode Value="0x60"/>
    unsigned char function;					//1	    <Opcode Value="0x28"/>
    unsigned char sub_func;					//2	    <Opcode Value="0xA5"/>	

    unsigned char szSiteName[20];           //3
    unsigned char uchPaymType;              //23
	unsigned short ushTenderNum;            //24

	unsigned long  ulOriginalTicketNo;      //26 
	unsigned short ushOriginalPosNo;        //30
	unsigned short ushOriginalStoreNo;      //32

	unsigned char nu[10];                   //34
    struct  trans_tail_ tail;				//44
};

/*----------------------------------------------------------------------
FSD61185
TRANS_INFO_OLA_DEBT_DATA_EXT
Opcode:		0x60
Subopcode:	0x28
-----------------------------------------------------------------------*/
struct trs_ola_debt_coverage_response_ext_
{
    unsigned char opcode;					//0		<Opcode Value="0x60"/>
    unsigned char function;					//1	    <Opcode Value="0x28"/>
    unsigned char sub_func;				    //2	    <Opcode Value="0xA6"/>	

    unsigned char szDate[10];               //3
    unsigned char szTime[8];               //13                   
    unsigned char szRegNumber[7];          //21
  
    long lAmount;                          //28
    long lGrade;                           //32
    long lVolume;                          //36

	unsigned char nu[4];                   //40
    struct  trans_tail_ tail;	           //44
};

/*----------------------------------------------------------------------
FSD61185
TRANS_INFO_OLA_DEBT_DATA_EXT
Opcode:		0x60
Subopcode:	0x28
-----------------------------------------------------------------------*/
struct trs_ola_debt_coverage_response_ext2_
{
    unsigned char opcode;					//0		<Opcode Value="0x60"/>
    unsigned char function;					//1	    <Opcode Value="0x28"/>
    unsigned char sub_func;				    //2	    <Opcode Value="0xA8"/>	
	
    unsigned char szFuelGrade[20];               //3
	
	unsigned char nu[21];                   //23
    struct  trans_tail_ tail;	           //44
};

// TD#116482
struct trs_info2_inge_voucher_ext2_  // 0x80 0x22
{
	unsigned char opcode;				  // 0		TRANS_INFO3		
    unsigned char subopcode;			  // 1		TRANS_INFO3_INGE_VOUCHER_EXT2

	unsigned char bcdPINSerialCode[10];   // 2

	unsigned char NU[32];				  // 12
	
	struct trans_tail_ tail;			  // 44
};

//FSD93620: PCI Interface Change
struct trs_info3_eft_status_ // 0x80 0x23
{
	unsigned char opcode;				  // 0		TRANS_INFO3		
    unsigned char subopcode;			  // 1		TRANS_INFO3_EFT_STATUS

	short shSessionActionType;			  // 2	

	unsigned char sPinPadSerialNum[8];	  // 4

	unsigned short ushActionStatus;		  // 12
	
	unsigned char NU[30];				  // 14
	
	struct trans_tail_ tail;			  // 44
};

//FSD90244_NewMoneyRequestFromPOS
struct trs_info3_NewMoney_Remote_Request_header_
{
    unsigned char opcode;       //0x80				//0
    unsigned char function;     //0x24				//1     TRANS_INFO3_REMOTE_REQUEST_HDR

    unsigned char message_type;						//2 8-Money request (see posdef.h: MessageTypeMoneyRequestInTrs80_24)
    unsigned short messageId;						//3 for future use
    
    unsigned char status;							//5   13-outstanding   
                                                          //    1-Approved
														  //    4-declined    
                    
	unsigned char szRequestDate[3];                 //6 BCD                                                                                            
	unsigned char szRequestTime[3];					//9 BCD  
                                
	unsigned char szActionDate[3];					//12 BCD                                          
	unsigned char szActionTime[3];					//15 BCD                                          

    unsigned char bInfoFg					:1;		//18
	unsigned char NU						:7;		//18

    unsigned short cshr_no;							//19
	unsigned short pos_no;							//21
	unsigned short action_user_no;					//23      

    unsigned char reserved[19];						//25

    struct   trans_tail_  tail;						//44
};

//FSD90244_NewMoneyRequestFromPOS
struct trs_info3_NewMoney_Remote_Request_detail_
{
	unsigned char opcode;      //0x80				//0
	unsigned char function;    //0x25				//1		TRANS_INFO3_REMOTE_REQUEST_DETAIL
             
	unsigned short tender_id;						//2
    unsigned short denomination_id;					//4
    
    long          lOrgAmount;						//6
    long          lActualAmount;					//10
    
    short         OrgQty;							//14
    short         ActualQty;						//16

	long          lOrgTotalAmount;					//18
    long          lActualTotalAmount;				//22
    
    unsigned char bInfoFg				:1;			//26
	unsigned char NU					:7;			//26

    unsigned char reserved[17];						//27

	struct   trans_tail_  tail;						//44       
};

	//FSD121064 - MorA 4.8.2010 - Start
struct trs_info3_query_tender_promo_
{
	unsigned char opcode;      //0x80				//0
	unsigned char function;    //0x27				//1		TRANS_INFO3_QUERY_TNDR_PROMO
             
	unsigned short  query_tender_no;						//2
    long			query_amount;					//4
    long            tender_amount;					//8
    long            query_response;					//12
	long			final_discount_amount;			//16
	unsigned short  final_tender_number;			//20
    
    unsigned char NonEftTender				:1;		//22
	unsigned char ClosingTender				:1;		
	unsigned char NU						:6;		

    unsigned char reserved[21];						//23

	struct   trans_tail_  tail;						//44       
};
	//FSD121064 - MorA 4.8.2010 - End

//KobiM - FSD121574
struct trs_segment_sales_
{
    unsigned char opcode;			//0   //0xCE <Opcode Value="0xCE" />

	unsigned short ushSegmentID;	//1
	short shPosNumber;				//3
	unsigned char uchTaxRateID;		//5
	long lSegmentSales;				//6

	unsigned char reserved[34];		//10

    struct   trans_tail_  tail;    // 44
};

// TD108436: Prism Emv Data for Recovery
struct trs_info3_prism_emv_data_ {
	unsigned char opcode;					// 0		TRANS_INFO3
	unsigned char subopcode;				// 1		TRANS_INFO3_PRISM_EMV_DATA (0x28)
	unsigned char EmvAppId[22];			// 2
	unsigned char EmvAppLabel[20];		// 24
	struct trans_tail_ tail;				// 44
};

//FSD 134730 Rimi external loyalty	
struct trs_info3_ticket_total_data_
{
	unsigned char opcode;	//0		TRANS_INFO3
	unsigned char subopcode; //1	TRANS_INFO3_TICKET_TOTAL

	long  discountable_amount; //2
	unsigned char reserved[38]; //6

	struct trans_tail_ tail;
};

/*----------------------------------------------------------------------
FSD121160 StoreLine Action per Ticket Type enhancement
6.17 New Transaction
TRANS_INFO3_ATTRIBUTE_TRANSACTION	
Opcode:		0x80
Subopcode:	0x2A
-----------------------------------------------------------------------*/
struct trs_info3_attribute_transaction_
{
	unsigned char opcode;	    //0	TRANS_INFO3
	unsigned char subopcode;    //1	TRANS_INFO3_ATTRIBUTE_TRANSACTION

	unsigned char bHomeDelivery	        :1;	//2	
	unsigned char bParcelPickup	        :1;		
	unsigned char bSkipReceiptPrinting	:1;		    
    unsigned char bSkipOnPrompt     	:1;				
	unsigned char bSTDSale	            :1;         //#220804
	unsigned char bRefundSale           :1;         //#220804
	unsigned char bLaybySale            :1;         //#220804
	unsigned char bLaybyModify	        :1;         //#220804

	unsigned char bDocSetting           :1; //3     //#220804
	unsigned char bNonPurchase	        :1;         //#220804    
	unsigned char nu			        :6;

	unsigned char reserved[40]; //4

	struct trans_tail_ tail;
};

struct trs_info3_SCOT_item_restriction_ 
{
	unsigned char opcode;					// 0		TRANS_INFO3
	unsigned char subopcode;				// 1		TRANS_INFO3_SCOT_ITEM_RESTRICTION (0x30)
	
	unsigned char bIsApproved	:1;			//2			FALSE means approved
	unsigned char nu			:7;

	unsigned char age;						//3			(0 means variable age)

	unsigned char nu2[40];					//4
	struct trans_tail_ tail;				//44
};

//FSD 134730 Rimi external loyalty	
//pp.cashier.no, pp.pos_no, ushTicket, tmp_trs.ola_ans.tail.date, tmp_trs.ola_ans.tail.time
struct trs_info3_ext_loyalty_error_key_
{
	unsigned char opcode;		//0		TRANS_INFO3
	unsigned char subopcode;	//1	TRANS_INFO3_EXT_LOYALTY_ERR_KEY

	unsigned short ushCashier;	//2
	short shPOS;				//4
	unsigned short ushTicket;	//6
	char date[3];				//8
	char time[3];				//11
	unsigned char reserved[30];	//14

	struct trans_tail_ tail;
};

//FSD 134730 Rimi external loyalty	
struct trs_info3_ext_loyalty_error_data_
{
	unsigned char opcode;	//0		TRANS_INFO3
	unsigned char subopcode; //1	TRANS_INFO3_EXT_LOYALTY_ERR_DATA

	long  ticket_amount; //2
	long  discountable_amount;			//6
	unsigned char sCard[30];			//10	
	unsigned char bCardinBCDFormat :1;	//40
	unsigned char Flags			   :7;
	unsigned char reserved[3];			//41

	struct trans_tail_ tail;
};


/*----------------------------------------------------------------------
TRANS_INFO3_BASKET_ITEMS
Opcode:		0x80
Subopcode:	0x37
-----------------------------------------------------------------------*/
struct trs_basket_items_
{
	unsigned char opcode;					//0 //0x80	<Opcode Value="0x80" />
	unsigned char function;					//1 //0x37	<Opcode Value="0x21"						

	unsigned char uchBasketItemID[7];			//2
	unsigned short ushBasketItemDepartment;	//9
	long lBasketItemPrice;					//11
	long lBasketItemQuantity;				//15
	long lBasketItemAmount;					//19
	unsigned char uchBasketItemTaxId;			//23
	long lBasketItemTaxRate;					//24
	unsigned char bBasketItemIsWeighted	:1;	//28
	unsigned char bBasketItemLastItem	:1;
	unsigned char bBasketItemUnUsedbits	:6;
	unsigned char BasketItemUnUsed[15];		//29

	struct   trans_tail_  tail;				//44                   
};

struct trs_info3_loyalty_masked_account_
{
	unsigned char opcode;
	unsigned char subOpcode;

	unsigned char sMaksedAccount[30];
	unsigned char NotUsed[12];

	struct trans_tail_ tail;
};

struct trs_info3_masked_account_
{
	unsigned char opcode;
	unsigned char subOpcode;

	unsigned char sMaksedAccount[30];
	unsigned char FunctionUsed;
	unsigned char NotUsed[11];

	struct trans_tail_ tail;
};	

// FSD217889 - TRANS_FISCAL_SIG_DATA - 0xCF
struct trs_fiscal_signature_data_
{
	unsigned char opcode;			//0
	unsigned char first		:1;		//1
	unsigned char last		:1;
	unsigned char NotUsed	:6;
	unsigned char uchLastDataSize;	//2
	unsigned char sData[41];		//3

	struct trans_tail_ tail;		//44
};	

// FSD217889 - TRANS_INFO3_FISCAL_SIG_DATA_PRINT - 0x80-0x41
struct trs_fiscal_signature_data_for_printing_
{
	unsigned char opcode;				//0 0x80
	unsigned char function;				//1 0x41
	unsigned char invoiceDate[3];		//2 Date (YYMMDD in BCD)
	unsigned char invoiceTime[3];		//5 Time (HHMMSS in BCD)
	unsigned char sInvoiceNumber[20];	//8 STR - 20 chars should be enough
	unsigned char sPrintedSignature[4];	//28
	
	unsigned short ushVersionA;			//32
	unsigned short ushVersionB;			//34
	unsigned short ushVersionC;			//36
	unsigned short ushVersionD;			//38

	unsigned short ushDocType;			//40
	
	unsigned char nu[2];                //42

	struct trans_tail_ tail;			//44
};	

// FSD217889 - TRANS_INFO3_TAX_REASON - 0x80-0x4E
struct trs_info3_tax_reason_
{
	unsigned char opcode;				//0 0x80
	unsigned char function;				//1 0x4E
	unsigned char sReason[40];			//2 
	unsigned char nu[2];                //42

	struct trans_tail_ tail;			//44
};	


/*----------------------------------------------------------------------
FSD#139444: Coupon Validation Enhancement. Transaction for "Coupon conditionals override".
TRANS_INFO3_COUPON_CONDITIONAL_OVERRIDE
Opcode:		0x80
Function:	0x3C
-----------------------------------------------------------------------*/
struct trs_info3_coupon_conditional_override_
{
    unsigned char opcode;             		//offset 0 - opcode 0x80	
    unsigned char function;           		//offset 1 - function 0x3C
   
	unsigned char type;						//offset 2  - Barcode Type:
											//   0 - PLU
											//   1 - Tender	                                   
											//   2 - Department
											//   3 - Promotion : now we use	only promotion                                   
											//   4 - Loyalty
											//   5 - Points	                                   
											//   6 - Segment
											//   7 - Save\Recall	                                   
											//   8 - Utility
	unsigned char BarcodeLen;				//offset 3 - Barcode length

	struct									//ofsset 4
	{
		unsigned char opt_NoSaleMode		:1;
		unsigned char opt_cancel			:1;	
		unsigned char optNUMCpn				:6;
	}Options;

	unsigned char Barcode[30];				//offset 5  BCD - Barcode buffer

	unsigned char uchFallbackType;			//offset 35	
	long		  lAmount;					//offset 36

	char          chNUMCoupon[4];			//offset 40
	

    struct   trans_tail_  tail;				//offset 44
};

/*----------------------------------------------------------------------
TRANS_INFO3_BREAKDOWN_DATA
Opcode:		0x80
Subopcode:	0x3D
-----------------------------------------------------------------------*/
struct trs_info3_breakdown_data_   //PER plu per tax group
{
	unsigned char opcode;					//0 
	unsigned char subOpcode;				//1

	unsigned char ItemCode[7];				//2     PLU Code (BCD)
	long          lItemNetPrice;			//9     PLU Exclusive price (before tax disregard discount)
	long          lItemQty;					//13	PLU Qty
	long          lItemNetAmount;			//17    PLU Exclusive amount (before tax disregard discount)
	long          lItemNetDiscount;			//21	Exclusive PLU total apportionment 
    long          lTotalBeforeDiscount;		//25    Inclusive Amount (disregard discount)
	long          lDiscount;				//29    Inclusive PLU total apportionment 
	long		  lTaxableAmount;			//33	??? lTotalBeforeDiscount - lDiscount - lTaxAmount or Proportionate Taxable Amount
	long		  lTaxAmount;				//37	Calculated by Taxculator
	unsigned char uchTaxCode;				//41    Tax code

	unsigned char	bIsPLU		:1;			//42
	unsigned char	bIsZeroRated :1;		//42    FSD231586 - StoreLine Philippines Legal Requirement for Tax Deduction
	unsigned char   bIsVatExempt :1;		//42    FSD231586 - StoreLine Philippines Legal Requirement for Tax Deduction
	unsigned char	bNUFlags	:5;
	
	unsigned char NotUsed;					//43

	struct trans_tail_ tail;     //44
};

/*----------------------------------------------------------------------
TRANS_INFO3_SUMMARY_DATA
Opcode:		0x80
Subopcode:	0x3E
-----------------------------------------------------------------------*/
struct trs_info3_summary_data_   //per PLU
{	
	unsigned char opcode;					//0 
	unsigned char subOpcode;				//1

	unsigned char ItemCode[7];				//2     PLU Code (BCD)
	long          lItemNetPrice;			//9     PLU Exclusive price (before tax disregard discount)
	long          lItemQty;					//13	PLU Qty
	long          lItemNetAmount;			//17    PLU Exclusive amount (before tax disregard discount)
	long          lItemNetDiscount;			//21	Exclusive PLU total apportionment 
    long          lTotalBeforeDiscount;		//25    Inclusive Amount (disregard discount)
	long          lDiscount;				//29    Inclusive PLU total apportionment 
	long		  lTaxableAmount;			//33	lTotalBeforeDiscount - lDiscount - lTaxAmount
	long		  lTaxAmount;				//37	Calculated by Taxculator

	unsigned char	bIsPLU		:1;			//41
	unsigned char	bIsZeroRated :1;		//42    FSD231586 - StoreLine Philippines Legal Requirement for Tax Deduction
	unsigned char   bIsVatExempt :1;		//42    FSD231586 - StoreLine Philippines Legal Requirement for Tax Deduction
	unsigned char	bNUFlags	:5;

	unsigned char NotUsed[2];				//42
	
	struct trans_tail_ tail;
};

/*----------------------------------------------------------------------
Bug #222023
TRANS_INFO3_CHANGE_POS_STATUS
Opcode:		0x80
Subopcode:	0x42
-----------------------------------------------------------------------*/
struct trs_info3_change_pos_status_ 
{
	unsigned char opcode;			//0 - TRANS_INFO3
	unsigned char subOpcode;		//1 - TRANS_INFO3_CHANGE_POS_STATUS

	unsigned char uchPosStatus;		//2

	unsigned char NotUsed[41];		//3

	struct trans_tail_ tail;		//44
};

struct trs_info3_invoice_info_ 
{
	unsigned char opcode;			//0 - TRANS_INFO3
	unsigned char subOpcode;		//1 - TRANS_INFO3_INVOICE_INFO

	unsigned char bVoid			:1;			//2
	unsigned char bDuplicate	:1;			//2
	unsigned char bTrainingMode :1;			//2
	unsigned char bNU			:5;			//2

	unsigned char uchInvoiceNumberLen;		//3
	unsigned char bcdInvoiceNumber[20];		//4

	unsigned char NotUsed[20];				//24

	struct trans_tail_ tail;				//44
};

//FSD#139444_ApportTrs
struct trs_info3ApportionmentInfoVariousRewards_
{
	unsigned char opcode;                     //0	<Opcode Value="0x80"/>
	unsigned char function;                   //1	<Opcode Value="0x44"/> TRANS_INFO3_APPORTIONMENT_INFO_VARIOUS_REWARDS

	long			lPromotionNumber;				//2
	unsigned char	uchPluCodeBcd[7];				//6
	long			lAmount;						//13
	unsigned short	ushDep;							//17
	
	//FSD#139444_ApportTrsPoints
	unsigned char	uchRewardTypeApport;			//19	1 - AsTender (=RewardTypeApportionmentInTrs_AsTender); 
													//		2 - AsPoints (=RewardTypeApportionmentInTrs_AsPoints)

	long			lRewardDestinationType;			//20	FSD#387067

	char fillerNU[20];								//24

	struct trans_tail_ tail;						//44
};

//  TRANS_INFO3_PROMO_TRIGER_ITEMS             (unsigned char)	0x45 //FSD75153

struct trs_info3PromoTrigerItems_
{
	unsigned char opcode;                     //0	<Opcode Value="0x80"/>
	unsigned char function;                   //1	<Opcode Value="0x45"/> TRANS_INFO3_PROMO_TRIGER_ITEMS

	long			lPromotionNumber;				//2
	unsigned char	uchPluCodeBcd[7];				//6
	unsigned long	ulRecieptTargetMsgNumber;		//13
 
	char fillerNU[27];								//17

	struct trans_tail_ tail;						//44
};

// FSD#234817 UniqueVoucherIssuence 0x80,0x46 TRANS_INFO3_UNIQUE_SERIAL_ISSUANCE
struct trs_info3_UniqueSerialReturnTrs_
{
	unsigned char opcode;                   //0	
	unsigned char function;                 //1	

	unsigned char uchReturnType;			//2

	long lUniqueSerialNo;					//3
	
	unsigned char bcdExpirationDate[3];		//7

	unsigned char bOnline		:1;			//10
	unsigned char NU			:7;

	unsigned char sBarcode[10];				//11 Barcode number in BCD
	
	unsigned char ucMethod;				    //21

	unsigned char bcdExpirationTyme[3];		//22	TD#357677

	char fillerNU[19];						//25

	struct trans_tail_ tail;				//44
};

//FSD#222936
struct trs_info3_extra_long_barcode_
{
	unsigned char opcode;							//0	<Opcode Value="0x80"/>
	unsigned char function;							//1	<Opcode Value="0x47"/> TRANS_INFO3_EXTRA_LONG_BARCODE
	
	char sBarcode[40];								//2
	unsigned char uchBarcodeLength;					//42
	unsigned char bPluBarcode	:1;					//43 - Bit 0
	unsigned char bIsExtraLongbarcode		:1;		//43
	unsigned char bIsRedemption				:1;		//43
	unsigned char bIsAlphanumeric			:1;		//43
	unsigned char bNotUsed					:4;		//43
	
	struct trans_tail_ tail;						//44
};

//FSD217889
struct trs_info3_refund_invoice_no_
{
	unsigned char opcode;							//0	<Opcode Value="0x80"/>
	unsigned char function;							//1 <Opcode Value="0x48"/> TRANS_INFO3_REFUND_INVOICE_NO

	char sInvoiceNo[20];							//2
	char sDate[3];									//22

	char nu[19];									//25

	struct trans_tail_ tail;						//44
};

//FSD416124
struct trs_info4_invoice_reference_document_
{
	unsigned char opcode;							//0	<Opcode Value="0x90"/>
	unsigned char function;							//1 <Opcode Value="0x11"/> TRANS_INFO4_INVOICE_REFERENCE_DOCUMENT
	
	char sInvoiceNo[20];							//2
	char sDate[3];									//22
	
	char nu[19];									//25
	
	struct trans_tail_ tail;						//44
};

/*----------------------------------------------------------------------
TD261267
TRANS_INFO3_TICKET_FRAME_EXT
Opcode:		0x80
Subopcode:	0x49
-----------------------------------------------------------------------*/
struct trs_info3_ticket_frame_ext_
{
	unsigned char opcode;							//0	<Opcode Value="0x80"/>
	unsigned char function;							//1	<Opcode Value="0x49"/> TRANS_INFO3_TICKET_FRAME_EXT
	
	unsigned short ushTicketType;					//2		1 - EFT POST VOID
													//		2 - ...
	unsigned char date[3];							//4	Date (YYMMDD in BCD) //FSD#371778_V.2
	unsigned char time[3];							//7	Date (YYMMDD in BCD) //FSD#371778_V.2
	
	unsigned short ushOrgTicketNo;					//10 //TD#412887 	
	short shOrgPosID;								//12 //TD#412887 

	unsigned char bHomeDeliveryTicket		:1;		//14 //FSD422790
	unsigned char bNU						:7;		//14
	unsigned char nu[29];							//15

	struct trans_tail_ tail;						//44
};

//FSD#253338
struct trs_info3_ExtCustomerAccount_
{
	unsigned char opcode;							//0	<Opcode Value="0x80"/>
	unsigned char function;							//1	<Opcode Value="0x4A"/> TRANS_INF03_EXT_CUSTOMER_ACCOUNT
	
	long lFirstDiscount;							//2
	long lNextDiscount;								//6

	unsigned char NUsed[34];						//10

	struct trans_tail_ tail;						//44
};

/*----------------------------------------------------------------------
Opcode: 0xD0
PLU sale extention record 6
FSD 251772 - Substitution item in customer order
-----------------------------------------------------------------------*/
struct trs_plu_sale_ext6_
{
	unsigned char uchOpcode;					//0		0xD0 <Opcode Value="0xD0" />

	long cst_ord_ordered_qty;					//1
	long cst_ord_pick_qty;						//5

	char sBCDCodeSubstitutedItem[7];			//9

	unsigned char  bSubstitutionItemSupplied :1;//16
	unsigned char  bLotNumberSupplied        :1;//16	//FSD408776
    unsigned char  bSelfScanPriceOverrideFlg :1;//16    //TD#437444
	unsigned char  nonUsed					 :5;//16
	
	unsigned char sLotNumber[20];               //17	//FSD408776
	unsigned char szIssueNo[2];                 //37    //FSD415370 - add issue number to trs
	unsigned char uchPluPosMessage;             //39    //TD#436854
	unsigned char uchDepPosMessage;             //40    //TD#436854
	unsigned char uchNotUsed[3];                //41

	struct trans_tail_ tail;					//44
};

/*----------------------------------------------------------------------
Opcode: 0xD1
PLU sale exten price
TD#317757 Exten price due to del/pnp charges - write it into a separate transaction
TD#323733 Exten item price due to del/pnp charges - write it into this transaction
TD#325092 Calculate separately Del/PnP fee per item and write into D1 trs - added additonal data: Del/Pnp fees, GST on them, flags 

-----------------------------------------------------------------------*/
struct trs_plu_sale_exten_price_
{
	unsigned char opcode;						//0		0xD1 <Opcode Value="0xD1" />
	unsigned char function;						//1		0x8D
	unsigned char subfunction;					//2		0-exten price, exten item price
												//		
	long exten_price;							//3			exten price on invoice (sales_amount)
	long exten_item_price;					    //7			exten item price (selling_price)

	unsigned char bDelFeeValueOrPerCarton	:1;	//11		flags: if TRUE, take Del/PnPFee from this trs //TD#325092
	unsigned char bPNPFeeValueOrPerCarton	:1;		
	unsigned char nu						:6;

	long lDelFeePerLineItem;					//12	
	long lPNPFeePerLineItem;					//16
	long lGSTDelFeePerLineItem;					//20
	long lGSTPNPFeePerLineItem;					//24


	unsigned char code[7];						//28		Item number (BCD)
	unsigned char NU[9];						//35

	struct trans_tail_ tail;					//44
};


struct trs_info3_saver_summary_		//FSD 260167
{
	unsigned char opcode;			//0	<Opcode Value="0x80"/>
	unsigned char function;			//1	<Opcode Value="0x4B"/> 

	long		  triggers_count;	//2
	long		  discount_amount;	//6
	unsigned char description[20];	//10

	unsigned char uchNotUsed[14];   //30
	

	struct trans_tail_ tail;		//44
};


//TRANS_INFO3_APPORTIONMENT_ITEMS
struct trs_info3_apportionment_items_ 
{
	unsigned char opcode;		//0x80		//0	<Opcode Value="0x80"/>
    unsigned char function;     //0x4C		//1	<Opcode Value="0x4C"/>

    long lItemSeq;							//2
	unsigned char  chPluCode[7];			//6
	unsigned short sDept;					//13
	unsigned char  Prom[5];					//15

	long lPrice;							//20		 
	long lPromNum;							//24 
	unsigned char RewardType;				//28
	long lDiscountAmount;					//29 
	unsigned char bInfoOnly	:1;				//33
	unsigned char bRefundPromotion :1;		//#348812
	unsigned char bNU		:6;
	long lItemSubSeq;						//34
	unsigned char NU[6];					//38
	struct trans_tail_  tail;				//44
};

//FSD265316 Refunds enhancement
#define REFUND_COMMENT_LEN 25

struct trs_info3_refund_invoice_
{
	unsigned char opcode;		//0x80		//0	<Opcode Value="0x80"/>
    unsigned char function;     //0x4D		//1	<Opcode Value="0x4D"/>

	unsigned short	origInvNo;				//2
	unsigned char 	bcdOrigInvDate[3];		//4			//ddmmyy 
	short			reasonCode;				//7
	char			refundComment[REFUND_COMMENT_LEN]; //9
	short			authorisedByCashierNo;  //34
									
	unsigned long lOriginalInvoiceNumber;	//36
	
	unsigned char NU[4];					//40

	struct trans_tail_  tail;				//44
};

//FSD259732 
struct trs_info3_non_fiscal_sale_cross_referenace_
{
	unsigned char opcode;		//0x80		//0	<Opcode Value="0x80"/>
    unsigned char function;     //0x4F		//1	<Opcode Value="0x4F"/>


	unsigned short  ushDocTicketNumber;                 //2
	unsigned short	ushDocPosNumber ;	                //4			
    
	unsigned short ushDocDay;                           //6
	unsigned short ushDocMonth;                         //8
	unsigned short ushDocYear;                          //10
	unsigned short ushDocHour;                          //12
	unsigned short ushDocMinute;                        //14
	unsigned short ushDocSecond;                        //16
		
		
	unsigned char NU[26];					            //18

	struct trans_tail_  tail;				            //44
};

// FSD#250726
struct trs_info3_z_report_data_
{
	unsigned char opcode;			// 0	0x80	TRANS_INFO3
    unsigned char function;    		// 1	0x50	TRANS_INFO3_Z_REPORT_DATA
	
	unsigned char uchDataId;		// 2

	long lDataValue;				// 3

	unsigned char uchDecimalPoint;  // 7

	unsigned char NU[36];			// 8

	struct trans_tail_ tail;		// 44
};

#define POS_TEST_TYPE_FUEL_TEST 1

struct trs_info3_pos_test_ //277645
{
	unsigned char opcode;			// 0	0x80	TRANS_INFO3
    unsigned char function;    		// 1	0x51	TRANS_INFO3_POS_TEST
	
	unsigned char uchTestType;		// 2	1 - FUEL TEST etc.
	
	union
	{
		struct  
		{
			unsigned char  uchID;			// 3
			
			unsigned char  uchSubID[7];		// 4
			
			long lPrice;					// 11
			long lQty;						// 15
			long lAmt;						// 19
			
			unsigned char NU[21];			// 23
		}FuelTestData;
			
	};
	

	struct trans_tail_ tail;		// 44
};

/*----------------------------------------------------------------------
FSD#268329: Logical Offline Transaction - Reset sequence ID
TRANS_INFO3_TRS_SEND_CONTROL
Opcode:		0x80
Subopcode:	0x52
-----------------------------------------------------------------------*/
struct trs_info3_trs_send_control_
{
	unsigned char opcode;			// 0	<Opcode Value="0x80"/> TRANS_INFO3
	unsigned char function;			// 1	<Opcode Value="0x52"/> TRANS_INFO3_TRS_SEND_CONTROL

	unsigned char bStopSendTransactionsToMFS:1;	// 2
	unsigned char bNU:7;

	unsigned char NU[41];			// 3

	struct trans_tail_ tail;		// 44
};



/*----------------------------------------------------------------------
//TSC - PayPoint - CR #235029
TRANS_INFO3_EXTERNAL_ITEM_INFO
Opcode:		0x80
Subopcode:	0x53
-----------------------------------------------------------------------*/
struct trs_info3_external_item_info_
{
	unsigned char opcode;			// 0	<Opcode Value="0x80"/> TRANS_INFO3
	unsigned char function;			// 1	<Function Value="0x53"/> TRANS_INFO3_EXTERNAL_ITEM_INFO

	unsigned short ushProviderID;	            // 2
	unsigned short ushExternalSchemeID;	        // 4
	long		   lExternalTransactionNumber; 	// 6
	unsigned char  ExternalItemDescription[25];	// 10

	//flags1
	unsigned char bNegativeItem     :1;	// 35
	unsigned char bNU:7;
	
	unsigned char NU[8];			// 36

	struct trans_tail_ tail;		// 44
};

/*----------------------------------------------------------------------
//FSD#159229 - SEAL-BAGS
TRANS_INFO3_SEALED_BAG
Opcode:		0x80
Subopcode:	0x54
-----------------------------------------------------------------------*/
struct trs_info3_sealed_bag_info_
{
	unsigned char opcode;				// 0	<Opcode Value="0x80"/> TRANS_INFO3
	unsigned char function;				// 1	<Function Value="0x54"/> TRANS_INFO3_SEALED_BAG_INFO

	/* 
	Action Type:
		1- Add 
		2- Delete
		3- Cancel (seal number record will not be modified)
		4- Edit (for FO use)
	*/
	unsigned char  uchActionType;		// 2


	unsigned short ushCashierId;		// 3 //Id of cashier related to the seal number
	unsigned short ushPOSId;			// 5 //Where seal number was inputted
	unsigned char  sSealNumberBCD[4];	// 7 //BCD

	unsigned char opt_reprocess     :1;          // 11 (for FO use)
    unsigned char nu                :7;
    unsigned short ushAuthCashierId;             // 12  
    unsigned char NU[30];                        // 14


	struct trans_tail_ tail;			// 44
};

/*----------------------------------------------------------------------
TRANS_INFO3_STD_FINAL_CONFIRMATION  FSD259707
Opcode:		0x80
Subopcode:	0x55
-----------------------------------------------------------------------*/
struct trs_info3_STD_final_confirmation_
{
	unsigned char opcode;		//0x80		//0	<Opcode Value="0x80"/>
    unsigned char function;     //0x55		//1	<Opcode Value="0x4F"/>
		
	unsigned char NU[42];					            //2

	struct trans_tail_  tail;				            //44
};

struct trs_manual_discount_info_	//TD290433
{
    unsigned char opcode;						//0 0x80	
    unsigned char function;						//1 0x59	

    unsigned short ushSuperVisorNumber;			//2
	long lDiscountAmountOrPercent;				//4
	long lTotalAmount;							//8
	unsigned char uchDiscountNumber;			//12
	char szPluCode[7];							//13
	unsigned short shDep;						//20
	unsigned char  bPercentDiscount		:1;		//22	1= percent  0= amount
	unsigned char  bItemOrTotalDiscount	:1;			  //1= on total	0= item
	unsigned char  bItemOrDep			:1;			  //1= item		0= department
	unsigned char  bNotUsed				:5;
	long			lPromNo;					//23
	char                       FillerNotUsed[17]; //27

	struct   trans_tail_  tail;					//44
};


struct trs_info3_customer_accnt_ // FSD 230254
{
    unsigned char opcode;                    // offset-0   // 0x80 
    unsigned char subopcode;                 // offset-1   // 0x60 
	
	unsigned char custAccount[10];           // offset-2   // BCD
	
	unsigned char customerNotFoundInQdx :1;  // offset-12
	unsigned char customerBlocked       :1;
	unsigned char notUsed               :6;
	
	long amountCharge;                        // offset-13
	
	unsigned char accntLen;                   // offset-17
	unsigned char nUsed[26];
	
    struct   trans_tail_  tail;               // offset-44
};

struct trs_info3_purchase_ // FSD 230254
{
    unsigned char opcode;                    // offset-0    //0x80 
    unsigned char subopcode;				 // offset-1    //0x61 
	
	unsigned char purchaseOrder[15];         // offset-2
	unsigned char purchaseName[25];          // offset-17
	
	unsigned char nUsed[2];                  // offset-44
	
	
    struct   trans_tail_  tail;
};

struct trs_info3_customer_name_ // FSD 230254
{
    unsigned char opcode;					// offset-0   //0x80
    unsigned char subopcode;				// offset-1   //0x62
	
	unsigned char customerName[35];         // offset-2
	unsigned char nUsed[7]; 
	
    struct   trans_tail_  tail;             // offset-44
};

struct trs_info3_ola_card_denial_data_
{
	unsigned char opcode;          //0x80
    unsigned char function;       //0x63


	//	Total Available 42
	unsigned char bcdExpiryDate[2];  //2  //MMYY
	unsigned char account_no[10];	//4  BCD
	unsigned char merchant_no[15];	//14
	long amount;					//29
	short account_len;				//33
	unsigned char NU[9];			//35

	struct   trans_tail_  tail;
};


struct trs_info3_fiscal_eod_tax_
{
	unsigned char opcode;          //0x80
    unsigned char function;        //0x65

	__int64 ia64VatTotalA;         //2
	__int64 ia64VatTotalB;         //10
	__int64 ia64VatTotalC;         //18
	__int64 ia64VatTotalD;         //26
	__int64 ia64VatTotalE;         //34

	char nu[2];                    //42

	struct trans_tail_ tail;       //44
};

struct trs_info3_fiscal_eod_tax2_serial_
{
	unsigned char opcode;          //0x80
    unsigned char function;        //0x66

	__int64 ia64VatTotalF;         //2
	__int64 ia64VatTotalG;         //10

	char bcdDate[3];               //18
	char bcdTime[3];               //21
	char snzSerialNumber[20];      //24 - Space filled.

	struct trans_tail_ tail;       //44
};

struct trs_fuel_voucher_used_
{
	unsigned char opcode;			//0		0x80
    unsigned char function;			//1		0x67

	unsigned char voucher[7];		//2		voucher number
	long lTrsAmt;					//9		transaction amount
	long lPromID;					//13	Member promo #

	char bOffline:1;				//17	offline voucher #
	char bRSM2POS:1;				//17	RSM has sent this voucher to the POS
	char bFlagsNU:6;				//17	

	unsigned char CPL;				//18	cents off per litre
	unsigned char bcdExpDate[3];	//19	voucher expiry date
	char NotUsed[22];				//22	Not used


	struct trans_tail_ tail;       //44
};



//FSD#159243
struct trs_info3_SS_PluDepExt_
{
	unsigned char opcode;          //0x80
    unsigned char function;       //0xEE	TRANS_INFO3_SS_INFO_PLU_DEP_EXT

	unsigned char chSSDescr[20];		// 2
	short		  shLenDesc;			// 22

	unsigned char bPluDescr		:1;		// 24
	unsigned char bDepDesc		:1;
	unsigned char bNUDescr		:6;

	unsigned char NUSSDescr[19];		// 25

	struct	trans_tail_ tail;
};


/*----------------------------------------------------------------------
TRANS_INFO3_EXT_LOYALTY_REWARD
FSD316298
Opcode:		0x80
Subopcode:	0x5A
-----------------------------------------------------------------------*/
struct trans_info3_ext_loyalty_reward_
{
	unsigned char opcode;		//0x80		//0
    unsigned char function;     //0x5A		//1
	unsigned char subfunction;				//2
	
	unsigned char bStart :1;				//3
	unsigned char bEnd   :1;				//3
	unsigned char bnu    :6;				//3

	union
	{
		struct
		{
			long lCustomerBalance;					//4
			long lVisitReward;						//8
			long lTicketReward;						//12
			long lMixAndMatchReward;				//16
			long lTotalTicketReward;				//20
			long lBonusAdvantageReward;				//24
			long lBonusDepartmentReward;			//28
			long lBonusVisitReward;					//32
			long lBonusMixAndMatchReward;			//36
			long lBonusTicketReward;				//40
		} data1;

		struct  
		{
			long lBonusItemSupplierReward;			//4
			long lBonusItemBrandReward;				//8
			
			char nu[32];							//12
		} data2;

		struct
		{
			long lReward;							//4
			unsigned char uchPluNumber[7];			//8
			
			char nu[29];							//15

		} data3;

		struct
		{
			long lReward;							//4
			unsigned short ushDepartment;			//8

			char nu[34];							//10
		} data4;
	};

	struct trans_tail_  tail;				//44
};

//FSD34249_V4
struct trs_info3_ExtMedia6_
{
	unsigned char opcode;		//0x80		//0	Opcode Value="0x80"
    unsigned char function;     //0x5B		//1	Opcode Value="0x5B"  TRANS_INFO3_EXT_MEDIA6
		
	unsigned char bExtBarcodeValidatTCS					:1;	//2
	unsigned char bNUExtBarcodeValit					:7;

	unsigned char uchExtCouponProviderTenderTypeID;			//3
	long lForfeitAmount;                                    //4 FSD392122

	unsigned char NU[36];					            //8

	struct trans_tail_  tail;				            //44
};

//FSD305075
struct trs_info3_pos_report_totals_
{
	unsigned char opcode;				//0	0x80
    unsigned char function;				//1	0x69

	long lVatableSales;					//2
	long lSaleToGoverment;				//6
	long lVatExemptSRCitizen;			//10
	long lRegularDiscount;				//14
	long lSRCitizenDiscount5percent;	//18
	long lSRCitizenDiscount20percent;	//22
	long lPWDDiscount;					//26
	long lVatAdjustment;				//30
	long lFWV;							//34
	long lEWT;							//38
	unsigned char NU[2];				//42

	struct	trans_tail_ tail;			//44
};

//CR334690
struct trs_info3_online_coupon_reward_promo_
{
	unsigned char opcode;				        // 0		0x80	TRANS_INFO3	
	unsigned char function;						// 1		0x6C	TRANS_INFO3_ONLINE_COUPON_RWRD_PROMO

	long lAmount;								// 2	
	short shQty;								// 6
	long lPromotionID;							// 8
	short shResult;								// 12
	unsigned char sCouponCode[12];				// 14
	
	unsigned char bPrintBarcode	:1;				// 26
	unsigned char NU			:7;				// 26

	unsigned char NU2[17];			            // 27

	struct   trans_tail_  tail;                 // 44
};


//CR334690
struct trs_info3_online_coupon_reward_display_line_
{
	unsigned char opcode;				        // 0		0x80	TRANS_INFO3	
	unsigned char function;						// 1		0x6D	TRANS_INFO3_ONLINE_COUPON_RWRD_DISP_LINE

	unsigned char sLine[27];                    // 2	

	unsigned char NU[15];			            // 29

	struct   trans_tail_  tail;                 // 44
};

//CR334690
struct trs_info3_online_coupon_reward_rsp_
{
	unsigned char opcode;				        // 0		0x80	TRANS_INFO3	
	unsigned char function;						// 1		0x6E	TRANS_INFO3_ONLINE_COUPON_RWRD_RSP

	unsigned char sCouponCode[12];				// 2
	
	unsigned char bPrintBarcode	:1;				// 14
	unsigned char NU			:7;				// 14

	unsigned char NU2[29];			            // 15

	struct   trans_tail_  tail;                 // 44
};

//FSD#321725
struct trs_info3_cust_srv_question_ext2_
{
	unsigned char opcode;				        // 0		0x80	TRANS_INFO3	
	unsigned char function;						// 1		0x6F	TRANS_INFO3_CUST_SRV_QUESTION_EXT2
	unsigned char email[40];					//2

    unsigned char NU[2];						//42
	struct   trans_tail_  tail;                 // 44
};

//TD#340518
struct trs_info3_clubcard_details_msr_info_
{
	unsigned char opcode;				// 0  	<Opcode Value="0x80" />
	unsigned char function;				// 1  	<Opcode Value="0x70" />

	unsigned char szCustomerName[25];	// 2
	
	unsigned char NU[17];				// 27        

	struct trans_tail_ tail;			// 44
};



//TD#332305
struct trs_info3_DiscountExt_
{
    unsigned char opcode;							// 0	TRANS_INFO3			0x80
    unsigned char function;							// 1	TRANS_INFO3_DISCOUNT_EXT1	0xEF

	long	 lSeqNumAttachedItem;					// 2

	unsigned char bOptCancel			:1;			// 6
	unsigned char bOptSubtract			:1;
	unsigned char bNUDiscExt			:6;

	long lStoreFundedAmount;						//7
	long lSupplierFundedAmount;						//11
	long lRetailerFundedAmount;						//15
	
	unsigned char uchNusedInfo3DiscountExt[25];		// 19

	struct trans_tail_ tail;						// 44
};

struct trs_member_account_
{
	unsigned char opcode;							// 0	TRANS_INFO3					0x80
    unsigned char function;							// 1	TRANS_INFO3_MEMBER_ACCOUNT	0xF0

	long lMemberAccount;							// 2

	char NotUsed[38];								// 6

	struct trans_tail_ tail;						// 44
};

/*----------------------------------------------------------------------
TRANS_INFO3_ONLINE_ORDER
Opcode:		0x80
Subopcode:	0x71
-----------------------------------------------------------------------*/
struct trs_info3_online_order_
{
	unsigned char opcode;        //0  	<Opcode Value="0x80" />
	unsigned char function;      //1  	<Opcode Value="0x71" />

	unsigned char OrderNumber[5];          //2  BCD

 	unsigned char OrderDate[3];            //7  Date (YYMMDD in BCD)
 	unsigned char OrderTime[3];            //10 Time (HHMMSS in BCD)


	unsigned char szPurchaseOrderNo[30];	//13 String

	unsigned char reserved;                //43

	struct   trans_tail_  tail;  //44

};

/*----------------------------------------------------------------------
CR337587
TRANS_INFO3_MM_REF_NUM
Opcode:		0x80
Subopcode:	0x72
-----------------------------------------------------------------------*/
struct trs_info3_mm_ref_num_
{
	unsigned char opcode;			//0  	<Opcode Value="0x80" />
	unsigned char function;			//1  	<Opcode Value="0x72" />

	unsigned char ucRefIndex;		//2		Value can be 1 or 2
	
	char ref_num[31];				//3 
	
	unsigned char reserved[10];		//34

	struct   trans_tail_  tail;  //44

};

//TD347902
struct trs_info3_tax_section_
{
	unsigned char opcode;			//0  	<Opcode Value="0x80" />
	unsigned char function;			//1  	<Opcode Value="0x73" />

	unsigned char bStart		:1; //2
	unsigned char bEnd			:1;
	unsigned char bNU			:6;

	unsigned char reserved[41];		//3

	struct   trans_tail_  tail;  //44

};

struct trs_info3_plu_sell_end_
{
	unsigned char opcode;			//0  	<Opcode Value="0x80" />
	unsigned char function;			//1  	<Opcode Value="0x74" />

	unsigned char bReturnPriceChange	:1; //2
	unsigned char bNU					:7;

	unsigned char reserved[41];		//3

	struct   trans_tail_  tail;  //44

};

struct trs_info3_DataBar_Elements_
{
	unsigned char opcode;				//0  	<Opcode Value="0x80" />
	unsigned char function;				//1  	<Opcode Value="0x75" />
	
	unsigned char AINumber[5];				//2		AI number
	unsigned char AIData[36];			//7		Data
	unsigned char bCancel			:1; //43
	unsigned char bWasCancel		:1;
	unsigned char bNU				:6;					

	struct   trans_tail_  tail;			//44
};


//FSD#365331
struct trs_info3_DataBar_Recover_
{
	unsigned char opcode;				//0  	<Opcode Value="0x80" />
	unsigned char function;				//1  	<Opcode Value="0x85" />
	
	long		lPrice;				//2		AI number
	long		lQTY;				//6		Data

	unsigned char NU[34];			//10
	
	struct   trans_tail_  tail;			//44
};


// Epic 350205 - this stores NZL transaction ID (not to be confused with POS transactions)
//             - initially empty but updated after a succesful wager request
struct trs_info3_online_purchase_nzl_id_
{
	unsigned char opcode;    				//0	<Opcode Value="0x80"/>
	unsigned char function;  				//1	<Opcode Value="0x78"/>  TRANS_INFO3_ONLINE_PURCHASE_NZL_ID

	char TransactionID[41];                 //2 from NZL spec:<xs:simpleType name="InternalTransactionID"> <xs:maxLength value="40"/>
	unsigned char unused[1];                //43

	struct   trans_tail_  tail;				//44
};

// FSD350935
struct trs_info3_environnemental_tax_
{
	unsigned char opcode;					//0	<Opcode Value="0x80"/>
	unsigned char function;					//1	<Opcode Value="0x76"/>  TRANS_INFO3_ENVIRONNEMENTAL_TAX
	
	long lETaxAmount;						//2
	unsigned char nu[38];					//6
	
	struct   trans_tail_  tail;				//44
};

//CR#357297
struct trs_info3_pos_report_totals_ext_
{
	unsigned char opcode;				//0	0x80
    unsigned char function;				//1	0x77
	long lOverTender;					//2
	unsigned char NU[38];				//6
	struct	trans_tail_ tail;			//44
};

//FSD347594 GSE Balance enquiry
struct trs_info3_charge_posting
{
	unsigned char opcode;			//0  	<Opcode Value="0x80" />
	unsigned char function;			//1  	<Opcode Value="0xF1" />
	
	unsigned char bFromGSE			:1; //2
	unsigned char bCustomerBlocked	:1;
	unsigned char bChargePosting	:1;
	unsigned char bCustChargePosting:1;
	unsigned char bNU				:4;
	
	long cp_balance;					//3
    long cp_limit;						//7
	unsigned short block_code;			//11
	long	lCustNum;					//13
	unsigned char reserved[27];			//17
	
	struct   trans_tail_  tail;			//44
	
};

// Epic 350305 - stores NZL details for "IK" products - book/game/ticket numbers (extracted from barcode)
//             - status is updated after wager request is made
struct trs_info3_online_purchase_nzl_ik_
{
	unsigned char opcode;                   //0	<Opcode Value="0x80"/>
	unsigned char function;                 //1	<Opcode Value="0x79"/>  TRANS_INFO3_ONLINE_PURCHASE_NZL_IK

	unsigned short gameNumber;              //2 decoded from barcode (3 digits)
	long bookNumber;                        //4 decoded from barcode (5 digits)
	unsigned short tickNumber;              //8 decoded from barcode (3 digits)

	char unused[34];                        //10

	struct   trans_tail_  tail;				//44
};

struct trs_info3_target_message_
{
	unsigned char opcode;						//0	<Opcode Value="0x80"/>
	unsigned char function;						//1	<Opcode Value="0x80"/>  TRANS_INFO3_TARGET_MESSAGE_PROMOTION
	
	long lPromNumber;							//2
	long lTargetMessageID;						//6
	unsigned char uchLastTriggeredPromotion;	//10
	long discount_amount;						//11

	long lCount;								//15
	unsigned char uchTargetMessageType;			//19
	long lSaversCount;							//20
	unsigned char uchReceiptSeperation;			//24
	unsigned char uchPromType;					//25

	unsigned char nu[18];						//26

	struct   trans_tail_  tail;				//44
};

struct trs_info3_invoice_printing_request_
{
	unsigned char opcode;						//0	<Opcode Value="0x80"/>
	unsigned char function;						//1	<Opcode Value="0x81"/>  TRANS_INFO3_INVOICE_PRINTING_REQUEST

	unsigned char bPrintInvoice:1;				//2 
	unsigned char nu:7;							//2
	
	unsigned char nu2 [41];						//3
	
	struct   trans_tail_  tail;				//44
};

struct trs_info3_nif_
{
	unsigned char opcode;						//0	<Opcode Value="0x80"/>
	unsigned char function;						//1	<Opcode Value="0x82"/>  TRANS_INFO3_NIF

	union
	{
		struct V1_
		{
			unsigned char szNIF[10];			//2 NIF (9 digits + NULL).
			unsigned char nuv1[12];				//12
		} V1;

		struct V2_
		{
			unsigned char NIF[20];				//2 NIF.
			unsigned char CountryIsoCode[2];	//22 Country ISO Code (2 characters).
		} V2;
	};
	
	unsigned char chTrsVersion;					//24 0 : V1. 1: V2.
	unsigned char nu[19];						//25

	struct   trans_tail_  tail;				//44
};

struct trs_info3_customer_ext_
{
	unsigned char opcode;					//0	<Opcode Value="0x80"/>
	unsigned char function;					//1	<Opcode Value="0xF5"/>  TRANS_INFO3_CUSTOMER_EXT

	unsigned char bCheqAllowed			:1; //2
	unsigned char bNU					:7;

	unsigned char Not_Used[41];				//3

	struct   trans_tail_  tail;				//44

};

struct trs_info3_capture_phone_number_		//For FSD387834
{
	unsigned char opcode;					//0	<Opcode Value="0x80"/>
	unsigned char function;					//1	<Opcode Value="0xF6"/>  TRANS_INFO3_CAPTURE_CUSTOMER_PHONE_NUMBER
	
	unsigned char uchCustomerNumber[10];	//2		Customer number in BCD	
	unsigned char uchPhoneNumber[13];		//12	Phone number as string
	unsigned long	lStoreID;				//25	Store id
	unsigned char Not_Used[15];				//29
	
	struct   trans_tail_  tail;				//44
};



//FSD???ReceiptNonFiscal
struct trs_info3_DocumentNumFiscalFormat_
{
	unsigned char opcode;								//0	<Opcode Value="0x80"/>
	unsigned char function;								//1	<Opcode Value="0xF3"/>  TRANS_INFO3_DOCUMENT_NUM_FISCAL_FORMAT
	
	unsigned char bDocumNumChanged				:1;		//2 
	unsigned char nuDocFF						:7;		//2
	
	long ulLegalReceiptSequenceNumber;					//3

	char sPosShortFormat[10];							//7 FSD#455027 

	unsigned char nu2 [27];								//17
	
	struct   trans_tail_  tail;							//44
};


//FSD367024 ASW - Add Promotion info to Tlog
struct trs_info3_PromotionInfo_
{
	unsigned char opcode;								//0	<Opcode Value="0x80"/>
	unsigned char function;								//1	<Opcode Value="0xF4"/>  TRANS_INFO3_PROMOTION_INFO
	
	unsigned long ulPromotionNumber;					//2	
	unsigned char sDescription[20];						//6
	unsigned char uchNu__;						        //26  Not used

	unsigned char  bcdPluCode[7];						//27  Item number (if discount given to an item)
    unsigned short ushDeptNo;							//34  Department number 
	unsigned short ushPluUsedQty;						//36            
	long lPoints;										//38
	unsigned short ushPromTriggered;					//42  Num Of Time promotion was triggered.
	
	struct   trans_tail_  tail;							//44
};

//TD#362727
struct trs_info3_ManualPromotion_
{
	unsigned char opcode;								//0	<Opcode Value="0x80"/>
	unsigned char function;								//1	<Opcode Value="0x83"/>  TRANS_INFO3_MANUAL_PROMOTION
	
	unsigned long	ulPromotionNumber;					//2
	long			lManualDiscoutValue;				//6
	unsigned char   uchPosStatus;                       //10

	unsigned char NU[33];								//11
	
	struct   trans_tail_  tail;							//44
};

struct trs_info3_reset_cust_info_
{
	unsigned char opcode;								//0 <Opcode Value="0x80"/>  TRANS_INFO3
	unsigned char function;								//1 <Opcode Value="0x84"/>  TRANS_INFO3_RESET_CUST_INFO
	unsigned char sub_function;							//2 - Corresponds to the sub_function of trs_cust_info_ (60x11)
														//    except for 0 (which is customer number)
	unsigned char sCustomerNumber[20];					//3
	unsigned char NU[21];								//23
	
	struct   trans_tail_  tail;							//44
};
//FSD#366569  - start
struct trs_info3_security_number_info_
{
	unsigned char opcode;								//0 <Opcode Value="0x80"/>  TRANS_INFO3
	unsigned char function;								//1 <Opcode Value="0xF7"/>  TRANS_INFO3_SECURITY_NUMBER
	unsigned long ulSecurityNumberOld;					//2
	unsigned long ulSecurityNumberNew;					//6
	unsigned char NU[34];								//10
	
	struct   trans_tail_  tail;							//44
};
struct trs_info3_security_number_sale_info_
{
	unsigned char	opcode;								//0 <Opcode Value="0x80"/>  TRANS_INFO3
	unsigned char	function;								//1 <Opcode Value="0xF8"/>  TRANS_INFO3_SECURITY_NUMBER_SALE

	unsigned long	ulPreviousSecurityNumber;			//2
	long			lTotalAmountBeforeDiscount;			//6
	long			lTotalAmountToPay;					//10
	unsigned long	ulNewSecurityNumber;				//14
	unsigned short	ushTicketNo;						//18	//TD#391999

	unsigned char	NU[24];								//20

	struct   trans_tail_  tail;							//44
};
struct trs_info3_pos_totals_per_vat_info_
{
	unsigned char	opcode;								//0 <Opcode Value="0x80"/>  TRANS_INFO3
	unsigned char	function;							//1 <Opcode Value="0xF9"/>  TRANS_INFO3_POS_TOTALS_PER_VAT
	
	unsigned char	uchVATId;							//2
	unsigned long	ulVATRate;							//3
	long			lVATAmount;							//7
	long			lSaleIncludeVAT;					//11
	
	unsigned char NU[29];								//15
	
	struct   trans_tail_  tail;							//44
};
//FSD#366569  - end

/*
TRANS_INFO3_BARCODE_GENERATION
AlessandroS
FSD368305
*/
struct trs_info3_barcode_generation_
{
    unsigned char opcode;         //0 0x80
    unsigned char function;       //1 0xFA

	//char szBarcodeGeneration[42];     //2
	unsigned char BCDBarcodeGeneration[21];
	char szUnused [21];

    struct   trans_tail_  tail; //44
};

struct trs_info3_online_service_session_data_
{
	unsigned char opcode;         //0 0x80
    unsigned char function;       //1 0x86

	unsigned char uchIdentification[26];	//2
	unsigned char NU[16];					//28

	struct   trans_tail_  tail; //44

};

struct trs_info3_online_service_session_data_ext_
{
	unsigned char opcode;         //0 0x80
    unsigned char function;       //1 0x87

	unsigned char uchBarcodeData[32];	//2
	unsigned char uchRefundOption[4];	//34
	unsigned char NU[6];				//38
		
	struct   trans_tail_  tail; //44
};

//FSD394140
struct trs_info3_long_user_id_
{
	unsigned char opcode;					//0	TRANS_INFO3	- 0x80
	unsigned char function;				//1	TRANS_INFO3_LONG_USER_ID - 0x90

	long user_id;							//2	
	char long_user_id[10];							//6
	unsigned char NU[28];				//16
	struct trans_tail_ tail;				//44
};

//FSD#391853
struct trs_info3_link_points_
{
	unsigned char	opcode;				//0 <Opcode Value="0x80"/>  TRANS_INFO3
	unsigned char	function;			//1 <Opcode Value="0xFB"/>  TRANS_INFO3_LINK_POINTS

	char szLastReferenceNumber[16];		//2
	char szLastLinkCard[17];			//18
	long lPointsDollarValueBalance;		//35	(of last link card)
	
	unsigned char NU[5];				//39
		
	struct   trans_tail_  tail;			//44
};

//FSD#391853
struct trs_info3_link_points_ext_
{
	unsigned char	opcode;				//0 <Opcode Value="0x80"/>  TRANS_INFO3
	unsigned char	function;			//1 <Opcode Value="0xFE"/>  TRANS_INFO3_LINK_POINTS_EXT

	char szHighPriorityCardNumber[17];	//2
	unsigned char bHighPriorityCardOnline	:1;	//19
	unsigned char bHighPriorityCardIsCredit	:1;	//19
	unsigned char bLinkPointsRedemption		:1;	//19
	unsigned char bBlockRedemptionIndicator	:1;	//19
	unsigned char bNU						:4;	//19

	char szNRICNumber[10];				//20 FSD#394167
	unsigned char uchNRICCardState;			//30 FSD#394167 (online/offline/manual)
	unsigned char uchNRICCardType;			//31 FSD#394167 (Credit Card/ Link Card/NRIC card)
	
	unsigned char NU[12];				//32
	
	struct   trans_tail_  tail;			//44
};

struct trs_info3_allowable_tenders_
{
	unsigned char	opcode;			        	//0 <Opcode Value="0x80"/>  TRANS_INFO3
	unsigned char	function;		        	//1 <Opcode Value="0xFC"/>  TRANS_INFO3_ALLOWABLE_TENDERS

	unsigned char szAllowableTendersData[40];   //2
	unsigned char NU[2];			        	//42
		
	struct   trans_tail_  tail;                 //44
};

//FSD#397828 CIF on fiscal ticket.
struct trs_info3_CIF_
{
	unsigned char	opcode;			        	//0 <Opcode Value="0x80"/>  TRANS_INFO3
	unsigned char	function;		        	//1 <Opcode Value="0xFD"/>  TRANS_INFO3_CIF
	
	unsigned char CIF_Number[10];				//2
	__int64		  PredefinedMaxValue;			//12

	unsigned char bRO_WasUsed				:1;	//20:0
	unsigned char bCIF_Canceled				:1; //20:1
	unsigned char bNUCIF					:6;

	char LenCifNumber;							//21

	unsigned char NU[22];			        	//22
	
	struct   trans_tail_  tail;                 //44
};

//FSD396380
struct trs_info3_mobile_payment_data_
{
	unsigned char opcode;					//0	TRANS_INFO3	- 0x80
	unsigned char subopcode;				//1	TRANS_INFO3_MOBILE_PAYMENT_DATA - 0x88
	
	unsigned char uchMobilePaymentID[16];	//2	Mobile Payment ID - recieved from GSE
	unsigned char reserved[26];				//18
	
	struct trans_tail_ tail;				//44
};

//FSD#397567 - start
struct trs_info3_QR_code_process_
{
	unsigned char opcode;					//0	TRANS_INFO3	- 0x80
	unsigned char function;					//1	TRANS_INFO3_QR_CODE_PROCESS - 0x89
	
	unsigned char uchStatus;					//2
											// started	= 1 
											// ended	= 2 
	unsigned char bIsEnded	: 1;			//3
	unsigned char bNu		: 7;	

	char nu[40];							//4

	struct trans_tail_ tail;				//44
};

//FSD#397567 - end

//FSD#394167
struct trs_info3_nric_
{
	unsigned char	opcode;					//0 <Opcode Value="0x80"/>  TRANS_INFO3
	unsigned char	function;				//1 <Opcode Value="0xFF"/>  TRANS_INFO3_NRIC
	
	char szHighPriorityNRICNumber[10];		//2
	unsigned char uchHighPriorityCardState;	//12 (0-online/1-offline/2-manual)
	unsigned char uchHighPriorityCardType;	//13 (//1-NRIC card/2-Link Card/6-Credit Card)
	long lNRICRebateAmount;					//14

	unsigned char bNRICFinalTransaction	:1;	//18 (bit 0)
	unsigned char bNU					:7;	//18

	char szNRICNumber[10];					//19
	unsigned char uchNRICCardState;			//29 (0-online/1-offline/2-manual)
	unsigned char uchNRICCardType;			//30 (//1-NRIC card/2-Link Card/6-Credit Card)
	
	unsigned char NU[13];					//31
	
	struct   trans_tail_  tail;				//44
};

struct trs_msg5_plu_ext3_
{
	unsigned char opcode;      						//0 <Opcode Value="0x80" />
	unsigned char function;    						//1 <Opcode Value="0x91" />

	unsigned char opt_dep_sale			   :1;		//2
	unsigned char opt_nu                   :7;	    //2

	unsigned char descr_msg_plu[30];				//3
	unsigned char link_plu_code[7];					//33

	unsigned short dep_no;							//40

	unsigned char not_used[2];                      //42

	struct   trans_tail_  tail;						//44
};

//FSD414790 
struct trs_info3_price_change_
{
    unsigned char opcode;						//0  <Opcode Value="0x80" />    TRANS_INFO3
    unsigned char function;						//1  <Opcode Value="0x92" />    TRANS_INFO3_FORTRESS
	unsigned char subfunction;				    //2	 <Opcode Value=	0x02  />	FORTRESS_PRICE_CHANGE


    unsigned char bPriceVerify				:1; //3
    unsigned char bManualPrice	            :1; //3
    unsigned char bPriceOverride	        :1; //3
    unsigned char Nu	                    :5; //3
                                                 
	unsigned char ApprovalCodeMethod ;          //4  (0 =Manual/ 1 = Automatic)  
	
    unsigned char PluCode[7];	                //5	 //bcd				
	
    long   lOrgPrice;							//12
    long   lReducedPrice;						//16
    
    unsigned char	sApprovalCode[5];           //20 

	unsigned char not_used[19];                 //25

	struct   trans_tail_  tail;					//44
};

//FSD#391853_V7
struct trs_info4_link_points_ext2_
{
	unsigned char opcode;						//0	<Opcode Value="0x90"/>
	unsigned char function;						//1	<Opcode Value="0x01"/>  TRANS_INFO4_LINK_POINTS_EXT2
	
	char sHashedHighPriorityCardNumber[40];		//2 Hashed High Priority Card Number (40 characters).

	unsigned char NU[2];						//42
	
	struct   trans_tail_  tail;					//44
};

struct trs_info3_token_information_
{
    unsigned char opcode;         //0  <Opcode Value="0x80" />    TRANS_INFO3
    unsigned char subopcode;      //1  <Opcode Value="0x93" />    TRANS_INFO3_TOKEN_INFORMATION
	
	
	unsigned char BCDCardToken[9];  //2              //bcd
	
	unsigned char not_used[33];     //11
	
	struct   trans_tail_  tail;     //44
};

/*----------------------------------------------------------------------
TRANS_INFO3_END_OF_PRINTING
TD#423706,TD#423702
Opcode:		0x80
Subopcode:	0x95
-----------------------------------------------------------------------*/
struct trs_info3_end_of_printing_
{
	unsigned char opcode;         //0  <Opcode Value="0x80" />    TRANS_INFO3
    unsigned char function;      //1  <Opcode Value="0x95" />    TRANS_INFO3_END_OF_PRINTING

	unsigned char not_used[42];     //2
	struct   trans_tail_  tail;     //44
};

//418554
typedef enum Info4SlipType_
{
	i4stUndef=0,
	i4stStandardReceipt=1,
	i4stFuelVoucher=2,
	i4stFuelDocket=3,
	i4stCouponPrinting=4,
	i4stPhoneVoucher=5,
	i4stEFTPOSSlip=6,
	i4sTargetMsgVoucher=7
} Info4SlipType;

/*-------------------------------------------------------------------------------------------------
Opcode: 0x90 subopcode:0x02     
Foodstuffs Wellington #418554: this transaction is used to identify what type of slip is to come. 
It is used for reprint last transaction from compressed text
-------------------------------------------------------------------------------------------------*/
struct trs_info4_slip_type_
{
	unsigned char	opcode;				//0		0x90
	unsigned char	function;			//1		0x02
	unsigned short	ushType;			//2		See Info4SlipType

	unsigned char	bStart		:1;		//4		Start of slip/receipt
	unsigned char	bEnd		:1;		//4		End of slip/receipt
	unsigned char	bNU			:6;		//4

	unsigned char	filler[39];			//5
	struct trans_tail_  tail;			//44
};


//CRD413428. Shoprite Giftcard
struct trs_info4_gift_card_
{
	unsigned char opcode;					//0	<Opcode Value="0x90"/>
	unsigned char function;					//1	<Opcode Value="0x03"/>  TRANS_INFO4_GIFT_CARD

	char cActionType;						//2		6 = Topup, 7 = Giftcard replace
	unsigned char sGiftcardNumber[10];		//3		BCD format
	unsigned char sOldGiftcardNumber[10];	//13	BCD format
	long lBalanceAmount;					//23

	unsigned char	Activation		:1;		//27		Start of slip/receipt
	unsigned char	bNU				:7;		//27


	unsigned char NU[16];					//28
	
	struct   trans_tail_  tail;				//44
};

/*----------------------------------------------------------------------
create for FSD418766 - C&C - PA document and customer enhancement
-----------------------------------------------------------------------*/
struct trs_info4_DDT_details_
{
	unsigned char opcode;							//0	<Opcode Value="0x90"/>
	unsigned char function;							//1	<Opcode Value="0x04"/> TRANS_INFO4_DDT_DETAILS

	unsigned char uchTextType;						//2	1- CIG text , 2- CUP text , 3- CCC text
	char sTextTransaction[30];						//3
	unsigned char uchNotUsed[11];					//33

	struct trans_tail_ tail;						//44
};

//FSD420610- Self scanning extension 3
struct trs_info4_self_scanning_ext3_
{
    unsigned char opcode;			    	//<Opcode Value="0x90"/>      //offset 0
    unsigned char function;			    	//<Opcode Value="0x05"/>	  //offset 1

    unsigned char uchPartialRescanExecuted; // 0-No, 1-Random, 2-Forced  //offset 2
	unsigned short ushPartialRescanCashier;                              //offset 3 
	unsigned short ushNumPartialRescanItems;                             //offset 5

	unsigned char uchFullRescanIndicator;      // 0-No, 1-Yes            //offset 7
    unsigned short ushRescanCounter;                                     //offset 8
	
	char nu[34];						                                 //offset 10

    struct   trans_tail_  tail;		                                     //offset 44                                
};

//FSD420610- Self scanning Rescan details transaction
struct trs_info4_Rescan_details_
{
    unsigned char opcode;			//<Opcode Value="0x90"/> //offset 0
    unsigned char function;			//<Opcode Value="0x06"/> //offset 1

    unsigned char uchRescanType;   // 1-partial,2-full //offset 2
	unsigned char bcdPluCode[7];                       //offset 3
	long lPluPrice;                                    //offset 10

	unsigned char uchRescanTrsPassed; //0-Missed, 
	                                  //1-Scanned      //offset 14 

	char nu[29];					                   //offset 15

    struct   trans_tail_  tail;		                   //offset 44
};

//FSD#411629
struct TrsInfo4FirstLastTicketsData_
{
    unsigned char opcode;			//<Opcode Value="0x90"/> //offset 0
    unsigned char function;			//<Opcode Value="0x07"/> //offset 1		TRANS_INFO4_FIRST_LAST_TICKETS_DATA_REPORT

	unsigned short	FirstTicketNumber;					//2
	unsigned short	LastTicketNumber;					//4

	unsigned char	DateFirstTicket[3];					//6
	unsigned char	TimeFirstTicket[3];					//9
	unsigned char	DateLastTicket[3];					//12
	unsigned char	TimeLastTicket[3];					//15

	char nu[26];										//18
	
    struct   trans_tail_  tail;							//44
};

/*----------------------------------------------------------------------
TRANS_INFO4_EXT_LOYALTY_MESSAGES
#422014
Opcode:		0x90
Subopcode:	0x08
-----------------------------------------------------------------------*/
struct trs_info4_ext_loyalty_messages_
{
	unsigned char opcode;		//0x90		//0
    unsigned char function;     //0x08		//1
	
	unsigned char uchMessageType;			//2
	unsigned char uchLineNumber;			//3
	unsigned char uchLineOffset;			//4
	unsigned char uchLength;				//5
	char data[38];							//6
	
	struct trans_tail_  tail;				//44
};

//FSD#421963
struct TrsInfo4CombinedDocum_
{
	unsigned char	opcode;				//0		0x90
	unsigned char	function;			//1		0x0A	TRANS_INFO4_COMBINE_MULTIPLE_DOCUMENTS

	unsigned short	ushCombinedDocType;			//2		for combined document

	unsigned char	bStart				:1;		//4		Start retrieve trs
	unsigned char	bEnd				:1;		//4		End retrieve combined documents
	unsigned char	bStartDocum			:1;		//4		Start Document
	unsigned char	bEndDocum			:1;		//4		End Document
	unsigned char	bRetrieveSuccess	:1;		//4
	unsigned char	bNU					:3;		//4

	unsigned char	MaxQtyDocum;				//5
	unsigned char	Index;						//6

	short			StatusRetrive;				//7

	unsigned short	OriginalTransID;			//9
	unsigned short	OriginalPosNo;				//11
	unsigned short	DocType;					//13	For single document
	unsigned char	bcdOriginalTransDate[3];	//15

	unsigned long	SeqNo;						//18
	long			OrgAmount;					//22
	char			TypeTrs;					//26
	unsigned char	NewStatus;					//27

	unsigned char	filler[16];					//28

	struct trans_tail_  tail;			//44
	
};

//FSD406085
struct TrsInfo4TriggerPromotion_
{
	unsigned char  opcode;                           //0	<Opcode Value="0x90"/>
	unsigned char  function;                         //1	<Opcode Value="0x0B"/> TRANS_INFO4_TRIGGER_PROMOTION
	unsigned char  promotionId[5];					 //2		    
	long		   promotionCount;					 //7
	unsigned long  lQualifySpent;					 //11
	unsigned long  numitemspartecipating;			 //15	// AlbertoA FSd 41651
	unsigned char reward_type;						 //19	// AlbertoA FSd 41651
	unsigned char reward_destination;				 //20	// AlbertoA FSd 41651
	unsigned char	uchExternalReferenceID[10];		 //21	//BCD
	unsigned char uchExternalReferenceIDLen;		 //31	//BCD //FSD55670
	unsigned char notuse[12];						 //32
		
	struct   trans_tail_  tail;                     //44
};

//FSD#426710
struct trs_info3_ECommerceOrder_
{
	unsigned char  opcode;                          //0	<Opcode Value="0x80"/>
	unsigned char  function;                        //1	<Opcode Value="0x5C"/> TRANS_INFO3_E_COMMERCE_ORDER
	unsigned char  status;							//2 //FSD#426710 p1d3
	unsigned char  bcdOrderNumber[10];				//3 //FSD#426710 p1d3

	unsigned char NU[31];							//13
	
	struct   trans_tail_  tail;                     //44
};

//TD#432674
struct TrsInfo4LogDiffTrs_
{
	unsigned char	opcode;								//0	<Opcode Value="0x90"/>
	unsigned char	function;							//1	<Opcode Value="0x0C"/> TRANS_INFO4_LOG_DIFF_TRS

	unsigned char	bTrsEndTicketSent			:1;		//2
	unsigned char	bNUTrsCanc					:7;		//2

	unsigned char NU[41];								//3
	
	struct   trans_tail_  tail;							//44
};

//FSD#226065_Ver5_020615D
struct TrsInfo4ParkingExitCode_
{
	unsigned char	opcode;								//0	<Opcode Value="0x90"/>
	unsigned char	function;							//1	<Opcode Value="0x0D"/> TRANS_INFO4_PARKING_EXIT_CODE

	unsigned char bcdExitCode[19];						//2	BCD 
	
	unsigned char NU[23];								//21
	
	struct   trans_tail_  tail;							//44
};

struct trs_info4_axia_customer_details_
{
    unsigned char	opcode;									//0 0x90	<Opcode Value="0x90"/>
    unsigned char	function;								//1 0x0E	<Opcode Value="0x0F"/>TRANS_INFO4_AXIA_CUSTOMER_DETAILS
	
	unsigned char sCustomerNumber[20];						//2  BCD. Left padded with 0's or A's.
	
	unsigned char nu[22];									//22
	
	struct trans_tail_	tail;								//44 TRS tail
};

// Epic 435446 US 1
struct trs_points_apportionment_
{
	unsigned char opcode;                       //0x90 <Opcode Value="0x90" />
	unsigned char function;                     //0x10 <Opcode Value="0x10" />   90x10 TRANS_INFO4_POINTS_APPORTIONMENT

	long lEarnedAmount;                         // 2   points to a/c (apportioned per plu)
	long lRedeemedAmount;                       // 6   points from a/c
	unsigned long ulMemberAccountID;            // 10  a/c the points go into (or taken from)
	unsigned char uchDecimalPlaceInReward;      // 14  number of decimal places in the points value
	unsigned char promotionId[5];               // 15  promotion that triggered the reward
	unsigned char plu_code[7];                  // 20  item for which points are apportioned
	char nu_fill_1;                             // 27  not used
	long qty;                                   // 28  item quantity
	unsigned short dept;                        // 32  Department number (same type as dept in 01, 02 transactions)
	char nu_32[10];                             // 34  not used

	struct   trans_tail_  tail;                 // 44
};

/*----------------------------------------------------------------------
FSD432409 Alphanumeric Customer Survey 
Opcode:		0x80
Subopcode:	0x96
-----------------------------------------------------------------------*/
struct trs_info3_alpha_numeric_cust_survey_
{
    unsigned char opcode;							// 0	TRANS_INFO3			0x80
    unsigned char function;							// 1	TRANS_INFO3_ALPHA_NUMERIC_CUST_SURVEY		0x96

	unsigned char bStartTrs					:1;		// 2	Mark start trs
	unsigned char bEndTrs					:1;		// 2	Mark end trs
	unsigned char bNU						:6;		// 2

	unsigned char uchLenOfDataInTrs;				// 3	//Length of data in trs

	unsigned char uchData[40];						// 4
	struct   trans_tail_  tail;                 // 44
};


struct trs_info4_coupon_info_
{
	unsigned char opcode;							// 0	TRANS_INFO4			0x90
    unsigned char function;							// 1	TRANS_INFO4_COUPON_INFO		0x16

	unsigned char barcode[20];						//2		BCD - Barcode buffer
	long lAmount;									//22
	short qty;										//26

	unsigned char filler[16];						//28

	struct   trans_tail_  tail;                 // 44
};


//FSD438581
#define SubFuncTrsBarcodePrgTenderTypeExt_Basic			1
#define SubFuncTrsBarcodePrgTenderTypeExt_Cont1			2

struct TrsInfo4BarcodeTenderTypeExt_
{
	unsigned char	opcode;									//0	<Opcode Value="0x90"/>
	unsigned char	function;								//1	<Opcode Value="0x12"/> TRANS_INFO4_EXT_BARCODE_PRG_TENDER_TYPE
	unsigned char	SubFunc;								//2	1 - basic; 2 - continue1.....


	union BarcodePrgInfoExt_												//3
	{
		struct BarcodePrgInfoExt_General_									//3
		{
			unsigned char data[41];
		}general;

		//Barcode programming trs. extension with type Tender: basic
		struct BarcodePrgInfoExt_Basic_										//3
		{
			unsigned char Type;											//3

			unsigned char bExternalValidRequired				:1;	//4
			unsigned char bWasCanceled							:1;
			unsigned char bCancel								:1;
			unsigned char bNULinkTender							:5;

			unsigned char barcode[30];								//5

			unsigned char BarcodeLen;								//35
			unsigned char CouponStatus;								//36: 1 - internally validated; 2 - internally rejected; 3 - externally validated; 4 - externally rejected
			long		  Amount;									//37
			unsigned short TenderNo;								//41
			

			unsigned char NU[1];									//43
		}basic;

		//Barcode programming trs. extension with type Tender: Continue1
		struct BarcodePrgInfoExt_cont1_									//3
		{
			char			RemoteSiteID[28];						//3   BCD type, size???? ask
			unsigned char	LenRemoteSiteID;						//31
			char			ErrorReason[4];							//32

			unsigned char ExpiryDate[6];							//36	//YYMMDD
			unsigned char uchOlaMessageType;						//42

			unsigned char NUCont1[1];								//43
		}Cont1;

	}inf;

	
	struct   trans_tail_  tail;												//44
};

//FSD438581
//Tender transaction extension
//SubFunc=1: for tender trs. extension ( for barcode programming where type = Tender )
#define SubFunc_TenderTrsBarcodePrgExternalValidExtension				1
struct TrsInfo4TenderExt_
{
	unsigned char	opcode;									//0	<Opcode Value="0x90"/>
	unsigned char	function;								//1	<Opcode Value="0x13"/> TRANS_INFO4_EXT_TENDER_TRS_BARCODE_LINKED_TENDER
	unsigned char	SubFunc;								//2

	union TenderTrsExt_
	{
		struct DataLinkedTenderBarcodePrgExt_
		{
			unsigned char data[41];
		}DataLinkedTenderBarcodePrgExt;
		
		//Tender transaction extension for barcode where type = Tender
		struct LinkedTenderBarcodePrgExt_
		{
			//	unsigned char bExtensionTenderTrsBarcodePrg		:1;	//3
			unsigned char bWasCanceled							:1;
			unsigned char bCancel								:1;
			unsigned char bNUCodeTender							:6;

			unsigned long SeqNoFirstOriginalTrsBarcodePrgExt;		//4
	
			unsigned short TenderNo;								//8
			
			char		  ReferenceIdLinkedTender[28];			//10 BCD //After web-service coupons integration
			unsigned char LenReferenceIdLinkedTender;				//38
			long		  tenderTransSeqNumber;						//39
			

			unsigned char NU[1];									//43
		}LinkedTenderBarcodePrgExt;

	}TenderTrsExt;
	
	struct   trans_tail_  tail;								//44
};

struct trs_Card_Onl_Voucher_			//AlbertoA FSD 441887
{
	unsigned char	opcode;						//0	0xCD TRANS_CARD_ONL_VOUCHER
	
	unsigned char	TransSeqNumber[30];			//1
	unsigned char 	uchTransSeqNumberLength;	//31
	short 			TrxResult;			 		//32	//0 OK  -1 KO
	unsigned char	ServiceType;				//34	Upb Service Type For meal service
	
	char			nu[9];						//35
	
	struct trans_tail_	tail;					//44	TRS tail

};

struct TrsInfo4TaxDetails_     //FSD447653
{
    unsigned char opcode;         //0     //0x90 
    unsigned char subOpcode;      //1     //0x17  
                
    unsigned char tax_no;         //2
    unsigned long rate;           //3
    unsigned char name[12];       //7
    unsigned char sign[2];        //19
    unsigned char type;           //21
   
                
    unsigned char reserved[22];   //22
    struct   trans_tail_  tail;   //44
};

struct trsInfo4MMConfirmDeclineReason_     //CR448058
{
    unsigned char opcode;         //0     //0x90 
    unsigned char subOpcode;      //1     //0x18  or 0x19

    unsigned short plu_seq;       //2    
    unsigned char reason[40]; 	  //4
    struct   trans_tail_  tail;   //44
};


struct TrsInfo4DocumentDetails_     //FSD451172
{
    unsigned char opcode;					//0     //0x90 
    unsigned char subOpcode;				//1    	//0x1A  	
                
    unsigned char uchInvoiceType;			//2      'E' E-Invoice, 'A'-E-archive
    unsigned char sTaxOfficeNum[12];        //3
    unsigned char sReferenceNum[16];        //15
                   
    unsigned char reserved[13];             //31

    struct   trans_tail_  tail;             //44
};

struct trsInfo4UniqueTicketNumber_			//AlessandroS FSD450176
{
	unsigned char opcode;					//0     //0x90 
    unsigned char subOpcode;				//1    	//0x1B  	
                
	unsigned char uchUniqIDBuff[16];		//2
	unsigned char bIndicatorFlag        :1;	//18
	unsigned char bUnusedFlags          :7;
	unsigned char reserved[25];				//19

    struct   trans_tail_  tail;             //44
};


//FSD448663
struct trsInfo4NewIngeVoucher_  //0x90 0x1D
{
    unsigned char opcode;       //0		TRANS_INFO4
    unsigned char subopcode;	//1		TRANS_INFO4_NEW_INGE_VOUCHER

    unsigned char ActionType;   //2      values: 1 - Activation, 
		                                 //2 - Confirmation, 
										 //3 - Cancellation 
										 //4-Void/Error-new
	
	unsigned char bcdRefNumber[5]; //3      bcd , reference number identifying the item .
								   //		produced by the mobile card provider .

	unsigned char ucTransType;	   //8  Values: 0 - Reload Mobile, 1 - Gift Card 


	union //9
	{
		//activation type is "1" 
		struct 
		{
			unsigned char bcdGenCode[8];		 // 9
			unsigned char bcdUniqueTrsNumber[3]; // 17 
			unsigned char uchGenCodeLength;		 // 20
			unsigned char uchDataBar;  //new     // 21
			unsigned char szBalanceAmount[12];   // 22
			unsigned char uscNU[5];              // 34
		} activationAction;

		//confirmation type is "2"
		struct 
		{
			unsigned char bcdPINCode[16];		//9
			unsigned char bcdPINSerialCode[10]; //25
			unsigned char cEntryMode;           //35
			unsigned char uscNU[3];             //36
		} confirmAction;
		
	}data;	

	unsigned char uscNU[5];                 //39
    struct   trans_tail_  tail;				//44
};

//FSD450172
struct trsInfo4EWalletIdentification_		//0x90 0x1E
{
    unsigned char opcode;					//0		TRANS_INFO4
    unsigned char subopcode;				//1		TRANS_INFO4_EWALLET_IDENTIFICATION

	unsigned char uchProviderID;			//2

	unsigned char bSucceeded			:1;	//3
	unsigned char bVoided				:1;	//3
	unsigned char bNU					:6; //3

	unsigned char bcdEWalletID[10];			//4		BCD
	unsigned char bcdTicketID[7];			//14	BCD
	
	unsigned char nu[23];					//21
    struct   trans_tail_  tail;				//44
};

//FSD450172
struct trsInfo4EWalletPayment_				//0x90 0x1F
{
    unsigned char opcode;					//0		TRANS_INFO4
    unsigned char subopcode;				//1		TRANS_INFO4_EWALLET_PAYMENT

	unsigned char uchProviderID;			//2
	
	unsigned char bVoided				:1;	//3
	unsigned char bNU					:7; //3
	
	unsigned char bcdEWalletID[10];			//4		BCD
	unsigned char bcdTicketID[7];			//14	BCD

	unsigned char nu[23];					//21
    struct   trans_tail_  tail;				//44
};

//FSD#455027
struct trs_info_doc_seq_ext_				//0x90 0x20
{
    unsigned char opcode;            //0	TRANS_INFO4
    unsigned char function;          //1	TRANS_INFO_DOCUMENT_SEQ_EXT	
            
	char  sPosShortFormat[10];		 //2
	unsigned char filler[32];        //12

    struct   trans_tail_  tail;      //44
};


struct trs_info_perf_test_start_	//0x90 0x21
{
    unsigned char opcode;            //0	TRANS_INFO4
    unsigned char subopcode;          //1	TRANS_INFO4_PERFORMANCE_TEST_START
	
	time_t	start_time;
	
	short	shNumberOfTickets;
	short	shNumberOfItems;
	
	short	delay_between_items_sec;
	unsigned char bPrint;
	unsigned char bApplyPromotion;

	unsigned char unused[30];
	
	
    struct   trans_tail_  tail;      //44
};
struct trs_info_perf_test_end_	//0x90 0x22
{
    unsigned char opcode;            //0	TRANS_INFO4
    unsigned char subopcode;          //1	TRANS_INFO4_PERFORMANCE_TEST_END
	
	time_t end_time;
	long elapsed_time_in_seconds;
	long total_sale_amount;
	long total_promotions_amount;
    
	unsigned char unused[26];
	
    struct   trans_tail_  tail;      //44
};
union  trans_
{
	unsigned char data[TRANS_LEN];	//BCD
	struct 	trs_general_          general;
	struct 	trs_log_func_         log;
	struct 	trs_float_            t_float;
	struct 	trs_cash_lift_        t_cash_lift;
	struct 	trs_declare_			 t_declare;
	struct 	trs_paidout_receipt_  t_paid_rcpt;
	struct 	trs_ticket_frame_     frame;
	struct 	trs_plu_sale_         plu_sale;
	struct 	trs_plu_sale_ext_     plu_sale_ext;
	struct 	trs_plu_sale_ext2_    plu_sale_ext2;
	struct 	trs_plu_nonfnd_       plu_nonfnd;
	struct 	trs_dep_sale_         dep_sale;
	struct 	trs_dep_sale_ext_     dep_sale_ext;
	struct 	trs_discount_         discount;
	struct 	trs_coupon_           t_coupon;
	struct	trs_smart_card_coupon_	t_elec_coupon; // Smart card coupon transaction
	struct	trs_smart_card_coupon_ext_ t_elec_coupon_info; // Smart card coupon info transaction
	struct  trs_smart_TV_card_data_ t_smart_card_info; // Smart card information
	struct  trs_gift_card_act_	 t_gift_card_act; //activation of gift card FSD22770
	struct 	trs_ticket_tax_       ticket_tax;
	struct 	trs_ticket_tax_       ticket_tax_RBT;	//FSD16204 RewardByTender (RBT)
	struct 	trs_ticket_total_     ticket_total;
	struct 	trs_media_            t_media;
	struct  trs_media_ext_			 t_media_ext;
	struct  trs_media_ext2_		 t_media_ext2;
	struct  trs_media_ext3_		 t_media_ext3;
	struct  trs_media_ext4_		 t_media_ext4; //FSD3582
	struct  trs_commission_	    trs_commission;
	struct 	trs_eft_com_          eft_com;
	struct 	trs_birthday_         t_birthday;
	struct 	trs_tax_exempt_       t_tax_exempt;
	struct 	trs_car_              t_car;
	struct 	trs_times_            t_times;
	struct 	trs_chksum_           t_chksum;
	struct 	trs_bkgd_load_        t_bkgd_load;
	struct 	trs_account_          t_account;
	struct 	trs_bagger_           t_bagger;
	struct 	trs_charge_posting_   t_cp;
	struct 	trs_cost_percent_     t_cost_percent;
	struct 	trs_supervisor_       t_supervisor;
	struct 	trs_buyaid_           t_buyaid;
	struct 	trs_staff_            t_staff;
	struct 	trs_ecca_             t_ecca;
	struct 	trs_new_ecca_			 new_ecca;
	struct  trs_eft_media_			 eft_media;
	struct  trs_eft_print_reject_ eft_print_reject;
	struct 	trs_cust_info_        cust_info;
	struct 	trs_sku_				    t_sku;
	struct 	trs_assistant_		 	 t_asst;
	struct 	trs_prom_info_		 	 prom_info;
	struct  trs_prom_info_ext        prom_info_ext3; //TD#316773 //FSD#258806
	struct 	trs_clubcard_			 clubcard;
	struct 	trs_clubcard_ext		 clubcard_ext;	//Issue #7703SL
	struct 	trs_clubcard_info_		 clubcard_info;
	struct	trs_loyalty_cust_		 loyalty_cust;
	struct 	trs_points_			 	 points;
	struct 	trs_fuel_reward_		 fuel_reward;
	struct	trs_voucher_			 voucher;
	struct 	trs_track_				 track;
	struct 	trs_cash_in_draw_	 	 cash_in_draw;
	struct 	trs_wrong_password_   wrong_password;
	struct 	trs_freq_shopper_     t_fs;
	struct 	trs_unlock_upd_		 unlock_upd;
	struct	trs_redemption_		 redemption;
	struct 	trs_tndr_cpn_			 tndr_cpn;
	struct 	trs_bad_account_		 bad_accnt;
	struct 	trs_chq_grty_			 chq_grty;
	struct 	trs_auth_price_diff_  auth_price;
	struct  trs_check_fee_			 check_fee;
	struct 	trs_trans_index_		 trans_index;
	struct  trs_alert_ 			    alert;
	struct	trs_alert_fiscal_problem_	alert_fiscal_problem;
	struct	trs_alert_trans_send_	alert_trans_send;
	struct 	trs_alert_batch_		 alert_batch;
	struct  trs_alert_board_msg_	 board_msg;
	struct  trs_alert_post_version_	 post_version;
	struct	trs_alert_FiscDateVsOSDate_	alert_FiscDateVsOSDate;
	struct 	trs_file_refresh_		 alert_refresh;
	struct  trs_alert_alarm_srv_	 alert_alarm_srv;    
    struct	trs_alert_printer_error_	alert_printer_error;
    struct	trs_alert_cust_disp_error_	alert_cust_disp_error;
	struct	trs_alert_scale_error_		alert_scale_error;
	struct  trs_alert_fatal_error_		alert_fatal_error;
	struct 	trs_location_			 location;
	struct  trs_extra_card_	    extra_card;
	struct 	trs_ola_result_		 ola_result;
	struct  trs_ola_req_			 ola_req;
	struct  trs_ola_ack_			 ola_ack;
	struct  trs_ola_ans_			 ola_ans;
	struct 	trs_ola_free_			 ola_free;
	struct	trs_ola_printing_	 trs_ola_printing;
	struct  trs_ola_refferal_		trs_ola_refferal;
	struct  trs_ola_transref_		trs_ola_transref;
	struct	trs_ola_result_ext_	 ola_result_ext;
	struct	trs_ola_abort_	   	 ola_abort;
	struct  trs_info_eft_declined_ trs_info_eft_declined;
	struct  trs_ticket_trailer_   trail;
	struct 	trs_printout_			 printout;
	struct  trs_price_override_   prc_ovrd;
	struct  trs_q_length_			 q_length;
	struct 	trs_eft_print_data_	    eft_print_data;
	struct  trs_alcohol_restricted_  t_alcohol;
	struct 	trs_host_batch_			 batch;
	struct  trs_eft_info_data_        trs_eft_info_data; 
	struct  trs_msg_min_age_		    msg_min_age;
	struct  trs_fly_buy_ 		       fly_buy; 
	struct  trs_charge_reverse_bal_	 charge_rvbal;
	struct  trs_trading_stamps_  	 trading_stamps;
	struct 	trs_coupon_info_		    coupon_info;
	struct 	trs_member_freq_shopper_ t_mem_fs;
	struct  trs_reorg_print_		    reorg_print;
	struct  trs_adv_freq_shop_       adv_freq_shop;  
	struct  trs_freq_shop_card_      freq_shop_card;
	struct  trs_retrans_			    retrans;
	struct  trs_prom_cross_          prom_cross;
	struct  trs_zip_printout_	    	 zip_printout;
	struct  trs_zip_printout_wide_    	 zip_wide;
	struct  trs_freq_shop_saving_	 freq_shop_saving;
	struct  trs_savings_plus_        savings_plus;
	struct	trs_s_card_icc_			trs_s_card_icc;
	struct	trs_s_card_till_		trs_s_card_till;
	struct	trs_s_card_issuer_		trs_s_card_issuer;
	struct	trs_s_card_cvm_list_	trs_s_card_cvm_list;
	struct	trs_s_card_script_results_ trs_s_card_script_results;
	struct	trs_s_card_icc_ext_		trs_s_card_icc_ext;
	struct  trs_sales_on_account_    sales_on_account;
	struct  trs_customer_survey_     customer_survey; 						
	struct  trs_community_partner_	 community_partner;
	struct  trs_bonus_buy_           bonus_buy;
	struct  trs_ej_info_bad_account_		ej_bad_account;    
	struct  trs_ej_info_price_inquery_		ej_price_inquery;
	struct  trs_ej_info_control_check_		ej_control_check; 
	struct  trs_ej_info_age_id_				ej_age_id;
	struct  trs_alert_indyme_				alert_indyme; 
	struct  trs_balance_inquiry_			balance_inquiry; 
	struct  trs_eft_req1_					eft_req1; //EFT_FIN
	struct  trs_eft_req2_					eft_req2; //EFT_FIN
	struct  trs_eft_resp1_					eft_resp1; //EFT_FIN
	struct  trs_eft_resp2_					eft_resp2; //EFT_FIN
	struct  trs_item_on_sale_				item_on_sale;
	struct  promotion_coupon_required_		prom_cpn_req; //PROM_CPN_REQ
	struct	trs_drive_off_					d_off;  // PosPump: DriveOff
	struct	trs_finish_media_				finish_media;//haris
	struct  trs_fuel_pay_at_pump_info_		pay_at_pump_info;
	struct	trs_msg5_plu_					trs_msg5_plu; //CR8_BIGY
	struct  trs_msg5_plu_ext_				trs_msg5_plu_ext;   //CR#6910
	struct  trs_msg5_plu_ext2_				trs_msg5_plu_ext2;	//CR#6910
	struct  trs_pharmacy_item_				trs_pharmacy_item;	//FSD26364 - log batch number and expiry date
	struct  trs_pharmacy_item2_				trs_pharmacy_item2;	//FSD26364 -log doctors name and patient name
	struct  trs_reward_tender				reward_tender;
	struct  trs_alert_post_mail_			alert_post_mail; //POST_MAIL
	struct  trs_saved_ticket_				saved_ticket;
	struct 	trs_recall_trans_				recall_trans;
	struct	trs_alert_pkg_					alert_pkg;			//Code Distribution
	struct	trs_eft_nomad_media_			eft_nmd_media;			//CLICKS_EFT
	struct	trs_eft_nomad_print_slip1_		eft_nmd_prn_slp1;		//CLICKS_EFT
	struct	trs_eft_nomad_print_slip2_		eft_nmd_prn_slp2;		//CLICKS_EFT
	struct	trs_eft_nomad_print_slip3_		eft_nmd_prn_slp3;		//CLICKS_EFT
	struct	trs_eft_nomad_owner_name_		eft_nmd_owner_name;	//CLICKS_EFT
	struct	trs_eft_nomad_budget_			eft_nmd_budget;		//CLICKS_EFT
	struct	trs_eft_nomad_cheque_			eft_nmd_cheque;		//CLICKS_EFT
	struct  trs_eft_nomad_trx_key_			eft_nmd_trx_key; //EFT_NOMAD
	struct	trs_priceline_abn_    			prln_abn;				//PrLn_CRQ3
	struct  trs_info_oem_points_			t_oem_points;			//USA development
	struct  trs_staff_card_					staff_card;
	struct	trs_cust_at_sot_    			trs_cust_at_sot;		//ROW
	struct  trs_gift_basket_				trs_gift_basket;		// ROW
	struct  trs_handle_nmd_					handle_nmd;			//EFT_NMD_CLICKS
	struct  trs_prn_nmd_					trs_prn_nmd;			//EFT_NMD_CLICKS
	struct  trs_loyalty_msg_				trs_loyalty_msg;		//Loyalty message
	struct  trs_info_grid_calc_				trs_info_grid_calc;		//ROW (Price calc. process)
	struct  trs_info_price_calc_			trs_info_price_calc;   //ROW (Price calc.process)
	struct  trs_info_sundry_product_		trs_info_sundry_product; //ROW
	struct  trs_info_rtn_voucher_			rtn_voucher;
	struct  trs_info_add_credit_limit_		trs_info_add_credit_limit;		//ROW:Metro
	struct  trs_info_inv_pmt_				inv_pmt;
	struct  trs_info_charge_paym_			trs_info_charge_paym;				//ROW:Metro,SALE_PROC:ACCT_PAYM_ALL_TENDERS
	struct  trs_info_deliv_chrg_			trs_info_deliv_chrg;    // Delivery charges info trans
	struct  trs_info_rep_code_				trs_info_rep_code;      // Rep code info transaction 
	 struct	trs_info_oem_club_data_			trs_info_oem_club_data;		// info about the clubs 
	struct  trs_info_self_scanning_			trs_info_self_scanning;
	struct  trs_info_self_scanning_ext_		trs_info_self_scanning_ext;
	struct  trs_info_inv_recall_			trs_info_inv_recall;
	struct  trs_info_inv_reprint_			inv_reprint;
	struct  trs_info_lang_select_			lang_select; //Multi-Language
	struct  trs_total_key_					trs_total_key;
	struct  trs_info_non_merc_				non_merc;
	struct  trs_loyalty_mail_info_			trs_loyalty_mail;
	struct  trs_info_excl_calc_             trs_info_excl_calc;
	struct  trs_info_supp_data_             trs_info_supp_data;
	struct  trs_info_barcode_prog_          trs_info_barcode_prog;
	struct  trs_info_inv_req_               trs_info_inv_req;
	struct  trs_info_oem_sec_opt_in_		t_oem_opt_in;			//USA development, opt-in option
	struct  trs_create_clubcard_			trs_create_clubcard;
	struct  trs_info_segment_				trs_segment;
	struct  trs_info_coupon_redemption_		trs_coupon_redemption;
	struct  trans_info_rolltainer_item_		trans_info_rolltainer_item;
	struct  trs_quick_update_               trs_quick_update;
	struct  trs_info_belgacom_              trs_info_belgacom_;
	struct  trs_info_points_ext_            trs_info_points_ext;
	struct	trs_chipcard_info_		        trs_info_chipcard;
	struct  trs_phone_card_act_				trs_phone_card_act;			//Enh #9749 PHONE_CARD Hannaford AmyG
	struct  trs_onl_info_script_sales_      trs_onl_info_script_sales;
	struct  trs_info_script_paym_           trs_info_script_paym;
	struct	trs_chipcard_handle_msg_		trs_info_chipcard_msg_handle;
	struct	trs_info_barcode_details_       trs_info_barcode_details; //FS1064
	struct  trs_info_order_status_          trs_info_order_status; //row CR#00014 customer orders
	struct	trs_sigcap_hdr_					trs_sigcap_hdr;				//Enh #10812 Signature Capture AmyG
	struct	trs_sigcap_data_				trs_sigcap_data;			//Enh #10812 Signature Capture AmyG
	struct	trs_new_seq_num_				trs_new_seq_num; // FS1079
	struct	trs_alert_transact_err_			trs_alert_transact_err; // FS1079
	struct  trs_info_ticket_points_         trs_info_ticket_points;
	struct  trs_info_service_desk_vchr_     trs_info_service_desk_vchr;
	struct  trs_info_order_number_          trs_info_order_number;
	struct  trs_info_price_list_id_         trs_info_price_list_id;   //haris      
	struct  trs_info_cust_acct_ID_          trs_info_cust_acct_ID;       //FS1081
	struct  trs_info_cust_acct_tendering_   trs_info_cust_acct_tendering; //FS1081
	struct  trs_info_barcode_coupon_        trs_info_barcode_coupon; //FS1094
	struct	trs_info_offline_eft_			trs_info_offline_eft;	//Enh #13271 Offline EFT trs. AmyG
	struct	trs_info_pos_report_			trs_info_pos_report; //FS1085
	struct  trs_reprint_					trs_reprint;
	struct  trs_info_invoice_header_        trs_info_inv_header; //FS1088
	struct  trs_info_document_seq_          trs_info_doc_seq;
	struct  trs_info_reason_code_           trs_info_reason_code; //FS1115
	struct  trs_info_reduce_tax_scheme_     trs_info_reduce_tax_scheme; //FS1117
	struct	trs_wrong_version_alert_		trs_alert_version; // Version control deps
	struct  trs_info_cust_center_           trs_info_cust_center;//FS1126 - customer center transaction.  
	struct  trs_info_cust_address_          trs_info_cust_address;//FS1126 - customer address.
	struct  trs_info_tender_additional_     trs_info_tndr_addin_data; //FS1081.
    struct  trs_info_online_purchase_item_  trs_info_online_purchase_item; //FS15934
	struct  trs_ola_e_pay_result_           trs_ola_e_pay_result;          //FS15934
	struct  trs_ola_e_pay_result_ext_       trs_ola_e_pay_result_ext;      //FS15934
	struct  trs_ola_e_pay_result_ext2_		trs_ola_e_pay_result_ext2;	// FSD28793
	struct  trs_ola_auth_guid_				trs_ola_auth_guid;			//CR#6387
	struct  trs_ola_serialnumber_ext_		trs_ola_serialnumber_ext;	//N#6755
	struct  trs_ola_pinnumber_ext_2_		trs_ola_pinnumber_ext_2;	//N#6546, CR#3037
	struct  trs_info_order_prom_apport_		trs_info_order_prom_apport; //FS18285
	struct  trs_info_form_					trs_info_form; //FS19041
	struct  trs_info2_form_ext_				trs_info2_form_ext;		//FSD52912
	struct  trs_gift_card_act_ext_			trs_gift_card_act_ext;	//Issue #2711SL FSD22770
	struct	trs_manualy_settlement_			trs_manualy_settlement;
	struct	trs_info_denomination_			trs_info_denomination; //FS18338
	struct  trs_info_sequence_              trs_info_sequence;    //FS18339
	struct  trs_plu_sale_ext_3_				trs_plu_sale_ext_3; //FS20126
	struct  trs_info_parcel_                trs_info_parcel;     //FS18343
	struct  trs_info_charge_data_           trs_info_chrg_data;  //FS18343
	struct  trs_info_t7e_					trs_info_t7e;
	struct  trs_info_t7e_ext_				trs_info_t7e_ext;
	struct  trs_info_cash_lift_				trs_info_cash_lift; //FS21416
	struct  trs_info_deposit_               trs_info_deposit;   //Fs18341
	struct  trs_eft_settle_					trs_eft_settle;
	struct  trs_info_vensafe_				trs_info_vensafe;	//FS22935
	struct  trs_alert_host_lookup_          alert_host_lookup; //FS22361
	struct  trs_info_ecca_ext_				trs_info_ecca_ext; //#955
	struct	trs_zipped_text_				trs_zipped_text;
	struct  trs_zipped_wide_text_			trs_zipped_wide_text;   //#134117
	struct	trans_info_bill_payment_		trans_info_bill_payment;
	struct  trs_info_lay_by_                trs_info_lay_by;        //FS19171
	struct  trs_online_info_lay_by_         trs_online_info_lay_by; //FS19171
	struct  trs_dep_lay_by_                 trs_dep_lay_by;			//FS19171_LayBysTax
	struct	trs_stamps_duty_				trs_stamps_duty; 
	struct  trs_info_ext_sundry_product_	trs_info_ext_sundry_product;
	struct	trs_scanpoint_save_report_		trs_scanpoint_save_report;
	struct	trs_info_fuel_disc_cpn_			trs_info_fuel_disc_cpn;
	struct	trs_misc_frame_					trs_misc_frame; //!yaron!
	struct	trs_misc_end_					trs_misc_end; //!yaron!
	struct	trs_info2_misc_trs_				trs_info2_misc_trs; //!yaron!
	struct  trs_info_archive_invoice_       trs_info_archive_invoice;  //FS3199
	struct  trs_invo_retrieve_invoice_      trs_invo_retrieve_invoice; //FS3199
	struct	trs_trace_data_					trs_trace_data;
	struct  trs_ola_gift_card_result_		trs_ola_gift_card_result;  //FS3012
	struct  trs_ola_gift_card_result_ext_	trs_ola_gift_card_result_ext;  //FSD153313
	struct  trs_info_ticket_status_			trs_info_ticket_status;
    struct	trs_info_redeem_voucher_        trs_info_redeem_voucher;   //CR #4005	
	struct	trs_info_unique_counters_		trs_info_unique_counters;
	struct  trs_info2_fiscal_eod_			trs_info2_fiscal_eod;
	struct  trs_info_interim_use_			trs_info_interim_use;
	struct  trs_info_gross_subtotal_		trs_info_gross_subtotal; //FSD3583
	struct  trs_info2_bill_payment_			trs_info2_bill_payment;  //FS4002
	struct  trs_manualy_settlement_ext_     trs_manualy_settlement_ext; //FSD1798
	struct  trs_bulk_giftcard_sale_			trs_bulk_giftcard_sale;		//FSD1798
	struct  trs_giftcard_enquiry_			trs_giftcard_enquiry;		//FSD1798
	struct  trs_discount_ext_				trs_discount_ext;			//CR4862
	struct  trs_discount_ext2_				trs_discount_ext2;			//FSD44261
	struct	trs_info_tpf_recall_			trs_info_tpf_recall;		//N#6933
	struct  trs_alert_giftcard_enquiry_		trs_alert_giftcard_enquiry; //FSD1798
	struct	trs_ola_bill_payment_result_	trs_ola_bill_payment_result;//FS4002
	struct  trs_info2_local_barcode_		trs_info2_local_barcode;	//FSD3582 
	struct	trs_info2_local_barcode_ext_	trs_info2_local_barcode_ext;//FSD13078
	struct  trs_info2_member_account_       trs_info2_member_account;   //FS3649
	struct  trs_info2_ticket_type_			trs_info2_ticket_type;      //FS1333
	struct  trs_info2_layby_financial_      trs_info2_layby_financ;     //FS1333
	struct trs_info2_giftcard_activate_		trs_info2_giftcard_activate;//FSD1798
	struct	trs_info2_zipcode_				trs_info2_zipcode;			//FSD4930
	struct trs_ola_result_ext2_				trs_ola_result_ext2;		//FS5721
	struct  trs_ext_cust_info_				trs_ext_cust_info;			//FSD6785
	struct  trs_cheque_verif_data_			trs_cheque_verif_data;		//FSD6785
	struct  trs_info2_loyalty_transmission_pointer_ trs_info2_loyalty_transmission_pointer;//FSD3585
	struct  trs_info2_addition_ticket_total_ trs_info2_add_ticket_ttl;	//FSD2733
	struct  trs_info2_pos_report_bn_         trs_info2_pos_report_bn;		//FSD2733
	struct trs_info2_ExtractHeaderDetails_   trs_info2_ExtractHeaderDetails; //FSD6814
	struct trs_info2_ExtractCustomerDetails_ trs_info2_ExtractCustomerDetails;  //FSD6814
	struct trs_info2_ExtractLineDetails_     trs_info2_ExtractLineDetails;   //FSD6814
	struct trs_info2_ExtractTenderDetails_   trs_info2_ExtractTenderDetails; //FSD6814 
	struct trs_info2_ExtractTaxDetails_      trs_info2_ExtractTaxDetails;    //FSD6814
	struct trs_info2_ExtractTotalDetails_    trs_info2_ExtractTotalDetails;  //FSD6814
	struct trs_info2_ExtractCustDiscountDetails_ trs_info2_ExtractCustDiscountDetails; //FSD6814
	struct trs_info2_ext_loyalty_reward_	 trs_info2_ext_loyalty_reward;	 //FS3585
	struct trs_info2_item_additional_info_   trs_info2_item_additional_info; //FSD6248
	//haris
	struct trs_info2_unique_id_seq_			 trs_info2_unique_id_seq;		//FSD7345
	struct trs_gnrl_cust_info_				 trs_gnrl_cust_info;			//FSD6248
	struct trs_info2_plu_with_emb_price_	 trs_info2_plu_with_emb_price;	//CR#9244
	struct trs_info2_layby_acc_detail_        trs_info2_layby_acc_detail;     //FS6248
	struct trs_phone_card_act_ext_			 trs_phone_card_act_ext;		//Issue #8532SL
	struct trs_prepaid_wireless_			 trs_prepaid_wireless;			//Issue #8532SL
	struct trs_prepaid_wireless_ext_		 trs_prepaid_wireless_ext;		//Issue #8532SL
	struct trs_prepaid_wireless_ext2_		 trs_prepaid_wireless_ext2;		//Issue #8532SL
	struct trs_ext_data_					 trs_ext_data;					// 0x95 transaction - ext data.
	struct trs_info2_fiscal_sub_total_		 trs_info2_fiscal_sub_total;	//DR#6625
	struct trs_info2_add_segment_			 trs_info2_add_segment;
	struct trs_info2_init_loyalty_card_		 trs_info2_init_loyalty_card;   //FSD6795
	struct trs_info2_init_loyalty_card_ext_	 trs_info2_init_loyalty_card_ext; //FSD53587
	struct trs_info2_delayed_fiscal_prom_line_	 trs_info2_delayed_fiscal_prom_line;//FSD8152
	struct trs_info2_eft_session_				 trs_info2_eft_session;			//MorA FSD #7610	
	struct trs_info2_ola_session_			trs_info2_ola_session;			//Generic Services
	struct trs_info3_ola_session_ext_		trs_info3_ola_session_ext;
	struct trs_info3_online_identifier_		trs_info3_online_identifier;
	struct trs_info2_ola_identifier_Key_	trs_info2_ola_identifier_Key;   //Generic Services
	struct trs_ola_IdentifyNumber_ext_		trs_ola_IdentifyNumber_ext;			//FS3012
	struct trs_ola_UniqID_ext_				trs_ola_UniqID_ext;					//FSD26804
	struct trs_info2_end_ticket_vouchers_	trs_info2_end_ticket_vouchers; // FSD9034
	struct trs_media_ext6_                  trs_media_ext6;             //FSD7148 	
    struct trs_media_ext7_                  trs_media_ext7;             //FSD7148
	struct trs_media_ext8_                  trs_media_ext8;             //FDS7148
	struct trs_media_ext9_					trs_media_ext9;             //FDS54176
	struct trs_non_post_void_eft_		    trs_non_post_void_eft;		 //FSD11456
	struct trs_info2_gift_vouch_acc_conversion_	trs_info2_GVAccountConv;		//FSD7148_OfflineGiftVouch
	struct trs_info2_tax_voucher_printed_	trs_info2_tax_voucher_printed;
	struct trs_info2_post_void_				trs_info2_post_void; //FSD9306
	struct trs_info2_end_of_ticket_apportmnt_	trs_info2_end_of_ticket_apportmnt; //work around for ver. 8710 .
	struct trs_info2_layby_message_			trs_info2_layby_message;	//FSD6248 LayBy
	struct trs_invo2_post_void_resell_		trs_invo2_post_void_resell; //FSD9306
	struct trs_ola_loyalty_update_result_	trs_ola_loyalty_update_result; //FSD11780
    struct trs_info2_guid_					trs_info2_guid; //FSD7315
    struct trs_info2_print_line_			trs_info2_print_line;//FSD7315   
    struct trs_info2_print_confirm_			trs_info2_print_confirm; //FSD7315
    struct trs_info2_print_footer_			trs_info2_print_footer ; //FSD7315
	struct trs_info2_cancel_prom_apportion_	trs_info2_cancel_prom_apportion;	//#12818
	struct trs_info2_ticket_start_time_		trs_info2_ticket_start_time;		//Fortress
	struct trs_info2_bill_payment_ext0_		trs_info2_bill_payment_ext0;  //FSD2615
    struct trs_info2_bill_payment_ext1_		trs_info2_bill_payment_ext1;  //FSD2615
	struct trs_info2_bill_payment_ext2_     trs_info2_bill_payment_ext2; //FSD2615
	struct trs_info2_bill_payment_ext3_     trs_info2_bill_payment_ext3; //FSD2615
    struct trs_info2_bill_payment_biller_name_ext_  trs_info2_bill_payment_biller_name_ext; //FSD2615
    struct trs_info2_bill_payment_account_number_ext_  trs_info2_bill_payment_account_number_ext; //FSD2615
	struct trs_info2_bill_payment_barcode_ext_  trs_info2_bill_payment_barcode_ext; //FSD2615
	struct trs_transaction_description_		trs_transaction_description;		//Fortress
	struct trs_info_parking_card_			trs_info_parking_card; //FSD10526
	struct trs_info2_two_po_				trs_info2_two_po; //FSD10094 - 2 Person Operation
	struct trs_info2_gen_seg_info_			trs_info2_gen_seg_info; //FSD 8152 , C4 Carta-Pass .
	struct  trs_info2_scale_check_			trs_info2_scale_check; //FSD9032
    struct trs_info2_prompt_cashier_response_ trs_info2_prompt_cashier_response; //FSD11022 
	struct trs_info2_complementary_group_	trs_info2_complementary_group; //FSD 11803
	struct trs_log_func_long_password_		trs_log_func_long_password;			//FSD 13459
    struct trs_info2_independent_print_line_ trs_info2_independent_print_line ; //FSD7315
	struct trs_info2_stock_mng_info_		trs_info2_stock_mng_info;		//FSD11252
	struct trs_info_ticket_frame_			trs_info_ticket_frame;			//#15302
	struct trs_info2_employee_card_			trs_info2_employee_card;		//FSD13421 - EmployeeCard
	struct trs_info2_print_item_footer_     trs_info2_print_item_footer; //FSD7315 
	struct trs_info2_forms_collection_		trs_info2_forms_collection;		//#15639
    struct trs_info2_bill_payment_advice_guid_ trs_info2_bill_payment_advice_guid ; //FSD2615
    struct trs_info2_bill_payment_advice_tender_ trs_info2_bill_payment_advice_tender; //FSD2615
    struct trs_info2_bill_payment_advice_barcode_  trs_info2_bill_payment_advice_barcode; //FSD2615
    struct trs_ola_airtime_ext0_   trs_ola_airtime_ext0; //FSD7148 -16820
    struct trs_ola_airtime_ext1_   trs_ola_airtime_ext1;  //FSD7148 -16821
    struct trs_info2_pickup_bag_			trs_info2_pickup_bag;	//FSD14665
	struct trs_info2_pick_up_tender_  trs_info2_tender_record; //FSD3923
	struct trs_info2_voucher_reward_		trs_info2_voucher_reward;		//FSD14348
	struct trs_info2_header_trigger_		trs_info2_header_trigger;		//FSD14348
	struct trs_info2_issue_number_alloc_request_ trs_info2_issue_number_alloc_request;//FSD12841
	struct trans_info2_fiscal_end_ticket_	trs_info2_fiscal_end_ticket;	
	struct trs_info_store_count_             trs_info_store_count;   //FSD15846
	struct TrsInfoBarcodeToEjdetails_		TrsInfoBarcodeToEjdetails; //FSD10789
	struct trs_info2_prom_ext_				trs_info2_prom_ext;	//FSD14741
	struct trs_info2_prom_ext2_				trs_info2_prom_ext2;//FSD16361
	struct trs_info2_cheque_details_		trs_info2_cheque_details;		//FSD16187
	struct trs_gift_card_batch_header_		trs_gift_card_batch_header;	// Issue #9564SL: Gift Card Batch Activation
	struct trs_gift_card_batch_details_		trs_gift_card_batch_details; // Issue #9564SL: Gift Card Batch Activation
	struct trs_alert_gift_card_batch_		trs_alert_gift_card_batch;	// Issue #9564SL: Gift Card Batch Activation
	struct trs_info2_online_purchase_ext_	trs_info2_online_purchase_ext;
	struct  trs_info2_third_part_loyalty_    trs_info2_third_part_loyalty;
	struct  trs_info2_dummy_points_              trs_info2_dummy_points;
	struct  trs_info2_Third_Party_Data_			trs_info2_Third_Party_Data; //FSD16060
	struct	trs_info2_Refund_Item_Data_			trs_info2_Refund_Item_Data; //FSD16060
	struct trs_info2_member_account_update_		trs_info2_member_account_update; //FSD16201
	struct trs_ticket_info_tax_					trs_ticket_info_tax; //20789
	struct trs_info_expense_				trs_info_expense;	//FSD14423
	struct trs_info2_atm_data_              trs_info2_atm_data; //FSD14667
	struct trs_info2_self_scan_text_line_	trs_info2_self_scan_text_line; // FSD19186
	struct trs_info2_subitem_				trs_info2_subitem;		//FSD20957
	struct trs_info2_price_update_atPOS_	trs_info2_price_update_atPOS;	//FSD16243
	struct promotion_coupon_required_ext_		prom_cpn_req_ext;			//FSD18888
	struct trs_info2_special_totals_		trs_info2_special_totals; // FSD18559
	struct	trs_info2_promotion_section_	trs_info2_promotion_section;	//FSD14741
	struct	trs_info2_security_number_		trs_info2_security_number;	//security number
	struct  trs_info2_trigger_count_        trs_info2_trigger_count;    //FSD13861
	struct  trs_info2_confirmed_promotion_	trs_info2_confirmed_promotion; //FSD16207
	struct trs_info2_dynamic_attribute_		trs_info2_dynamic_attribute; //FSD14082
	struct trs_info2_dynamic_attribute_value_ trs_info2_dynamic_attribute_value;	//FSD41496
	struct trs_info2_barcode_display_		trs_info2_barcode_display;
	struct  trs_info2_gift_multi_redem_		trs_info2_gift_multi_redem;	// FSD 16855
	struct trs_info2_ola_result_ext3_		trs_info2_ola_result_ext3; //YaelB. Add support for Alpha-Numeric terminal id
	struct trs_info2_ORC_plu_sales_			trs_info2_ORC_plu_sales;//FSD16361
	struct trs_info2_ORC_combined_promo_net_sales_ trs_info2_ORC_combined_promo_net_sales;//FSD16361
	struct trs_info2_ORC_reward_split_by_redemption_info_ trs_info2_ORC_reward_split_by_redemption_info;//FSD16361
	struct trs_info2_ORC_reward_split_by_redemption_info_ext_ trs_info2_ORC_reward_split_by_redemption_info_ext;//FSD16361
	struct trs_info2_updated_ext_card_		trs_info2_updated_ext_card;//FSD 16852
	struct trs_ola_card_authentication_	    trs_ola_card_authentication; //FSD23009
	struct trs_ola_secure_data_             trs_ola_secure_data;         //FSD23009 
	struct trs_ola_certificate_details_     trs_ola_certificate_details; //FSD23009
	struct  trs_info2_Table_Number_			trs_info2_Table_Number; //FSD18936 #26236
	struct trs_info2_Kms_Trs_Msg_			trs_info2_Kms_Trs_Msg;//FSD18937 #27165
	struct trs_info2_eft_inserted_in_tender_mode_	trs_info2_eft_inserted_in_tender_mode; // FSD 27622
	struct trs_info2_eft_ext_session_		trs_info2_eft_ext_session;	// FSD 29694
	struct trs_invoice_vat_calculation_		trs_invoice_vat_calculation;
	struct trs_alert_file_distribution_		trs_alert_file_distribution; //FSD27939		
	struct trs_info2_data_					trs_info2_data;	//FSD25302
	struct trs_info2_cash_change_correction_	trs_info2_cash_change_correction; //FSD16283
	struct trs_info2_pos_shift_	            trs_info2_pos_shift;	  
	struct trs_info2_inge_voucher_			trs_info2_inge_voucher; // FSD#28462, FSD#59750
	struct trs_info2_inge_voucher_ext_		trs_info2_inge_voucher_ext; // FSD#59750
	struct trs_info2_cashier_discount_		trs_info2_cashier_discount;	//29725
	struct trs_customer_count_				trs_customer_count; //Bug#29984
	struct trs_info2_fiscal_sales_			trs_info2_fiscal_sales;  // Enh #12593SL - BrianS
	struct trs_freedom_customer_ID_			trs_freedom_customer_ID;	//Enh #13526SL
	struct trs_info2_ebtwic_				trs_info2_ebtwic;			//Issue #8897SN EBTWIC
	struct trs_info2_ignore_				trs_info2_ignore;			//FSD24344
	struct trs_info2_ppt_gift_card_extra_data_	trs_info2_ppt_gift_card_extra_data; //FSD22770
	struct trs_info2_fsa_					trs_info2_fsa;	//FSD13919SL
	struct trs_media_ext5_					t_media_ext5;	//FSD13919SL
	struct trs_info2_alternative_plu_sale_  trs_info2_alternative_plu_sale;
#ifdef PRJ_ROW
	struct	trs_info_trade_prom_calc_		trs_info_trade_prom_calc;
#endif
	struct	trs_info2_general_card_			trs_info2_general_card;		//FSD29692
	struct trs_info2_manual_eod_			trs_info2_manual_eod;		//FSD16273
	struct trs_info2_status_                trs_info2_status;           //FSD29690         
	struct  trs_ola_gift_card_addInf_		trs_ola_gift_card_addInf;  //FSD29721
	struct  trs_info2_parking_voucher_	    trs_info2_parking_voucher;  //FSD30642
	struct trs_info2_fuel_mode_changed_		trs_info2_fuel_mode_changed;	// FSD 26154 sec. 7.4-7.8
	struct trs_info2_EmplCorporNo_			trs_info2_EmplCorporNo;		//FSD6916
	struct trs_alert_auto_fuel_mngt_		trs_alert_auto_fuel_mngt;	//FSD30537
	struct trs_alert_CombinedUserSecurity_  trs_alert_CombinedUserSecurity;//FSD56626
	struct trs_redemption_summary_			trs_redemption_summary;		//#34702 - performance issue
	struct trs_pickup_counter_				trs_pickup_counter;			//FSD50476	
	struct trs_info2_accumulated_vat_retrn_	trs_info2_accumulated_vat_retrn;	//FSD28669-Accumulated Vat return
	struct trs_info2_vat_return_media_	    trs_info2_vat_return_media;	        //FSD28669-Accumulated Vat return
	//haris
	struct trs_info2_bill_payment_data_		trs_info2_bill_payment_data; //FSD26778
	struct trs_info2_ola_payment_card_result_     trs_info2_ola_payment_card_result;
	struct trs_info2_send_prom_response_	trs_info2_send_prom_response;	//YaelB Belgium
	struct trs_info2_pcard_					trs_info2_pcard;
	struct trs_info2_pcard1_					pcard1;
	struct trs_info2_pcard2_					pcard2;
	struct trs_info2_pcard3_					pcard3;
	struct trs_info2_pcard4_					pcard4;
	struct trs_info2_ticket_scheme_         trs_info2_ticket_scheme;     //FSD36846
	struct trs_info2_online_purchase_ext2_  trs_info2_online_purchase_ext2; //FSD21868	
	struct trs_info2_online_purchase_ext3_  trs_info2_online_purchase_ext3; //FSD40047	
	struct trs_ola_PCIDSS_HashedPAN_		trs_HashedPAN;					//PCIDSS
	struct trs_ola_EFT_Devices_Probe_		trs_EFTDevicesProbe;			//FSD 57796
//RSCL_BLOCK:START
	struct trs_info2_rscl_log_in_				trs_info2_rscl_log_in;			
//RSCL_BLOCK:END
	//TRANS_SCOT start
	struct trs_scot_log_in_						trs_scot_log_in;
	struct trs_scot_force_weight_				trs_scot_force_weight;
	struct trs_scot_security_weight_violation_	trs_scot_security_weight_violation;
	struct trs_scot_security_weight_learning_	trs_scot_security_weight_learning;
	struct Trs_SCO_General_						Trs_SCO_General;

	//TRANS_SCOT End

	struct trs_info2_etopup_item_data_ trs_info2_etopup_item_data;	// FSD45606
	struct trs_info2_etopup_item_data_ext1_ trs_info2_etopup_item_data_ext1;	// FSD45606
	struct trs_info2_electronic_voucher_		trs_info2_electronic_voucher;		// FSD42115
	struct trs_info2_swap_payment_				trs_info2_swap_payment;				// FSD36846
	struct trs_info2_fuel_data_					trs_info2_fuel_data;				// FSD36846
	struct trs_info2_location_					trs_info2_location;					// FSD41208
	struct trs_info2_self_scan_rescan_diff_		trs_info2_self_scan_rescan_diff;	// FSD28467
	struct trs_info2_ext_pos_form_				trs_info2_ext_pos_form;				// FSD46343
	struct trs_info2_eft_cashout_rounding_		trs_info2_eft_cashout_rounding;		// FSD42120
	struct trs_info2_plu_data_					trs_info2_plu_data;					// FSD42113
	struct trs_general_long_data_				trs_general_long_data;				// FSD42325
	struct trs_general_long_data2_				trs_general_long_data2;				// FSD90637
	struct trs_info2_return_extra_information_			trs_info2_return_extra_information;			//FSD30639
	struct trs_info2_return_voucher_sequence_number_	trs_info2_return_voucher_sequence_number;	//FSD30639
	struct trs_info2_rpc_cc_deposit_			trs_info2_rpc_cc_deposit;			//FSd48165 FSD28354
	struct trs_info2_giftcard_extra_data_		trs_info2_giftcard_extra_data;		//FSD45975
	struct trs_Info2EmvAuthenticData_			trs_Info2EmvAuthenticData; //FSD45186 
	struct trs_info2_mark_fiscal_unsecure_trs_		trs_info2_mark_fiscal_unsecure_trs;		//FSD40832
	struct trs_info2_home_shopping_details_		trs_info2_home_shopping_details;			// #50118
	struct trs_gift_card_act_ext2_				trs_gift_card_act_ext2;		//#16122SL
	struct trs_info2_gift_card_act_ext3_		trs_info2_gift_card_act_ext3;		//FSD55425
	struct trs_info2_remac_response_	info2_remac_response;
	struct trs_plu_sale_ext_4_					trs_plu_sale_ext_4;					// FSD52741 Ticket Saving Enhancements For Drive-Offs
	struct trs_info2_hash_PAN_US_				trs_info2_hash_PAN_US; //Issue #17534SL
	struct trs_info2_ola_summary_				trs_info2_ola_summary;
	struct trs_info2_item_restricted_trs_		trs_info2_item_restricted_trs; //FSD55819
	struct trs_info2_gift_receipt_trs_			trs_info2_gift_receipt_trs;	   //FSD55832
	struct trs_info2_parent_return_type_		trs_info2_parent_return_type;  //FSD52912
	struct trs_info2_customer_details_trs_             trs_info2_customer_details_trs; //FSD54877
	struct trs_info2_customer_details_ext_trs_             trs_info2_customer_details_ext_trs; //FSD54877
	struct trs_points_ext_						trs_point_ext;						// FSD44261
	struct trs_info2_foreign_currency_trs_		trs_info2_foreign_currency_trs; //FSD55806
	struct	trs_info2_mmbr_prom_schemes_		trs_info2_mmbr_prom_schemes; //#55079
	struct trs_info2_loyalty_card_exchange_		trs_info2_lyalty_card_exchange;//FSD57203
	struct trs_info2_cash_voucher_				trs_info2_cash_voucher; //FSD58540 Cash Voucher
	struct trs_lanehawk_clear_item_				trs_lanehawk_clear_item; //SL_US Issue #17615 [ShlomitG]
	struct trs_reddem_MA_online_query_			trs_reddem_MA_online_query;
	struct trs_info2_ola_extra_data_header_		trs_info2_ola_extra_data_header; //Global Transaction
	struct trs_info2_ola_extra_data_			trs_info2_ola_extra_data; //Global Transaction
	struct trs_info2_log_function_trigger_		trs_info2_log_function_trigger;	//FSD61079.
	struct trs_info2_emv_chip_cards_			trs_info2_emv_chip_cards;	//FSD52846
	struct	trs_info2_qbuster_					qbuster; //priceline
	struct trs_extra_card2_						extra_card2; // FSD#59744
	struct trs_customer_survey_ext_			    trs_customer_survey_ext; // TD#64966
	struct trs_ola_trans_id_ ola_trans_id; //#2888 Syncro
	struct trs_plu_sale_ext5_					trs_plu_sale_ext5;		//FSD 61034
	struct trs_dep_sale_ext2_					trs_dep_sale_ext2;		//FSD 61034
	struct trs_ola_activation_code_ext_			trs_ola_activation_code_ext; //FSD61084
   struct trs_ola_card_data_             ola_card_data;//haris
	struct trs_info2_reference_number_          trs_info2_reference_number;  //FSD62787
	struct trs_info2_update_trs_				trs_info2_update_trs;
	struct	trs_info2_clean_trscache_			trs_info2_clean_trscache; //#67438
	struct trs_info2_extra_code_				trs_info2_extra_code;	//FSD245239
	struct trs_info3_vending_session_			trs_info3_vending_session; //FSD59806
	struct trs_info3_fuel_function_triggering_  trs_info3_fuel_function_triggering;  //FSD58646,FSD67994
	struct trs_info3_online_purchase_ext_		trs_info3_online_purchase_ext; //FSD61084
	struct trs_info3_purchase_order_num_		info3_purchase_order_num;
	struct trs_info3_fiscal_item_sale_error_	trs_info3_fiscal_item_sale_error; //FSD67680
	struct trs_info3_clubcard_info_ext_			trs_info3_clubcard_info_ext; // TD#53437
	struct  trs_info3_load_barcode_to_DB_		trs_info3_load_barcode_to_DB;	//FSD67534
	struct  trs_info3_ANPR_Data_				trs_info3_ANPR_Data;	//FSD58656
	struct trs_changed_working_date_			trs_changed_working_date;
	struct trs_enhanced_coupon_details_			trs_enhanced_coupon_details; //FSD64199
	struct trs_info_barcode_details_ext_		trs_info_barcode_details_ext; //FSD64199
	struct trs_info3_databar_					trs_info3_databar; //FSD28013
	struct trs_info80_CCVoucher_details_ext_	TIinfo80CCVoucherDetailsExt;	//FSD66628
	struct trs_octopus_data_					trs_octopus_data;  //FSD55426, FSD61519
	struct trs_alert_load_qdx_after_short_EOD_	trs_alert_load_qdx_after_short_EOD;	//FSD70125
	struct trs_info2_rss_data1_					trs_info2_rss_data1; //FSD28013
	struct trs_info2_rss_data2_					trs_info2_rss_data2; //FSD28013
	struct trs_info2_rss_data3_					trs_info2_rss_data3; //FSD216989
	struct trs_info3_online_purchase_item_ext_  trs_info3_online_purchase_item_ext; //FSD67194
	struct trs_document_						trs_document;
	struct trs_info3_online_reward_message_id_		trs_info3_online_reward_message_id; // FSD#85881
	struct trs_info3_online_reward_promotion_data_  trs_info3_online_reward_promotion_data; // FSD#85881
	struct trs_info3_online_reward_redemption_data_ trs_info3_online_reward_redemption_data; // FSD#85881
	struct trs_info3_online_reward_guid_			trs_info3_online_reward_guid; // FSD#85881
	struct trs_info3_online_reward_image_			trs_info3_online_reward_image; // FSD#85881
	struct trs_info3_online_reward_print_line_		trs_info3_online_reward_print_line; // FSD#85881
	struct trs_info3_non_payment_                   trs_info3_non_payment; //FSD61185
	struct trs_info3_self_scan_summary_				trs_info3_self_scan_summary; //FSD95450
	struct trs_info3_generic_card_                  trs_info3_generic_card;//FSD61180 
	struct trs_info3_external_voucher_              trs_info3_external_voucher; //FSD61180
	struct trs_info3_print_point_promo_				trs_info3_print_point_promo;
	struct trs_info3_prom_totals_				trs_info3_prom_totals; // #108211
	struct trs_info3_session_print_data_            trs_info3_session_print_data; //FSD61180
	struct trs_ola_debt_coverage_response_          trs_ola_debt_coverage_response; //FSD61185
	struct trs_ola_debt_coverage_response_ext_      trs_ola_debt_coverage_response_ext; //FSD61185
	struct trs_ola_debt_coverage_response_ext2_      trs_ola_debt_coverage_response_ext2; //Bug#247732
	struct trs_info2_inge_voucher_ext2_				trs_info2_inge_voucher_ext2; // TD#116482
	struct trs_info3_eft_status_					trs_info3_eft_status;	//FSD93620: PCI Interface Change
	struct trs_info3_NewMoney_Remote_Request_header_	trs_info3_NewMoneyRemoteRequestHeader;	//FSD90244_NewMoneyRequest
	struct trs_info3_NewMoney_Remote_Request_detail_	trs_info3_NewMoneyRemoteRequestDetail;	//FSD90244_NewMoneyRequest
	struct trs_segment_sales_					trs_segment_sales;			//KobiM - FSD121574
	//FSD121064 - MorA 4.8.2010 - Start
	struct trs_info3_query_tender_promo_		trs_info3_query_tender_promo;
	//FSD121064 - MorA 4.8.2010 - End
	struct trs_ola_error_						trs_ola_error;//haris
	struct trs_info3_prism_emv_data_				trs_info3_prism_emv_data;  //TD108436
	struct trs_info3_ticket_total_data_			trs_info3_ticket_total_data; //FSD 134730
	struct trs_info3_SCOT_item_restriction_		trs_info3_SCOT_item_restriction;//SCOT 
	struct trs_info3_ext_loyalty_error_key_		trs_info3_ext_loyalty_error_key;
	struct trs_info3_ext_loyalty_error_data_	trs_info3_ext_loyalty_error_data;
    struct trs_info3_attribute_transaction_     trs_info3_attribute_transaction;//FSD121160 Attribute Transaction
	struct trs_info3_online_purchase_ext4_		trs_info3_online_purchase_ext4;
	struct trs_info3_online_purchase_ext5_		trs_info3_online_purchase_ext5;
	struct trs_request_time_					trs_request_time;				
	struct trs_request_time2_					trs_request_time2;				
	struct trs_request_time3_					trs_request_time3;				
	struct trs_basket_items_						trs_basket_items;	//FSD106540
	struct trs_info3_loyalty_masked_account_	trs_info3_loyalty_masked_account;
	struct trs_info3_masked_account_			trs_info3_masked_account;
	struct trs_info3_ola_purchase_item_confirmation_failed_		trs_info3_ola_purchase_item_confirmation_failed; //OmerR FSD157230
	struct trs_info3_voided_online_items_in_saved_trs_ 			trs_info3_voided_online_items_in_saved_trs; //OmerR FSD157230
	struct trs_fiscal_signature_data_				trs_fiscal_signature_data; //FSD217889
	struct trs_fiscal_signature_data_for_printing_	trs_fiscal_signature_data_for_printing; //FSD217889
	struct trs_info3_coupon_conditional_override_	trs_info3_coupon_conditional_override;	//FSD#139444
	struct trs_info3_breakdown_data_				trs_info3_breakdown_data;
	struct trs_info3_summary_data_					trs_info3_summary_data;
	struct trs_info3_change_pos_status_				trs_info3_change_pos_status;	//#222023
	struct trs_info3_invoice_info_					trs_info3_invoice_info;	//#222023
	struct trs_info3ApportionmentInfoVariousRewards_	trs_info3ApportionmentInfoVariousRewards; //FSD#139444_ApportTrs
	struct trs_info3PromoTrigerItems_				trs_info3PromoTrigerItems; //fsd75153
	struct trs_info3_UniqueSerialReturnTrs_			trs_info3_UniqueSerialReturnTrs; // FSD#234817
	struct trs_info3_extra_long_barcode_			trs_info3_extra_long_barcode;	//FSD222936
	struct trs_info3_refund_invoice_no_				trs_info3_refund_invoice_no; //FSD217889
	struct trs_info3_ticket_frame_ext_				trs_info3_ticket_frame_ext;	  //TD261267
	struct trs_info3_ExtCustomerAccount_			trs_info3_ExtCustomerAccount; //FSD#253338
	struct trs_plu_sale_ext6_						trs_plu_sale_ext6;			//FSD 251772
	struct trs_info3_saver_summary_					trs_info3_saver_summary;	//FSD 260167
	struct trs_info3_apportionment_items_			trs_info3_apportionment_items; //receipt layout
	struct trs_info3_refund_invoice_				trs_info3_refund_invoice; //FSD265316 Refunds enhancement
	struct trs_info3_tax_reason_					trs_info3_tax_reason; //FSD217889
	struct trs_info3_non_fiscal_sale_cross_referenace_  trs_info3_non_fiscal_sale_cross_referenace; //FSD259732 
	struct trs_info3_z_report_data_					trs_info3_z_report_data; // FSD#250726
	struct trs_info3_pos_test_						trs_info3_pos_test; //277645
	struct trs_info3_trs_send_control_				trs_info3_trs_send_control; //FSD#268329
	struct trs_info3_external_item_info_			trs_info3_external_item_info; //TSC - PayPoint - CR #235029
	struct trs_info3_sealed_bag_info_               trs_info3_sealed_bag_info;//FSD#159229
	struct trs_info3_STD_final_confirmation_		trs_info3_STD_final_confirmation; //FSD259707
	struct trs_info3_self_scanning_ext2_			trs_info3_self_scanning_ext2; //#271222
	struct trs_info3_discount_ext_					trs_info3_discount_ext; //#257939
	struct trs_info3_wiwallet_sku_					trs_info3_wiwallet_sku; //#294724
	struct trs_manual_discount_info_			    trs_manual_discount_info; //#294724
	struct trs_info3_customer_accnt_                trs_info3_customer_accnt; // FSD 230254
	struct trs_info3_purchase_                      trs_info3_purchase;       // FSD 230254
	struct trs_info3_customer_name_                 trs_info3_customer_name;  // FSD 230254
	struct trs_info3_ola_card_denial_data_			trs_info3_ola_card_denial_data; //FSD296959
	struct trs_info3_fiscal_eod_tax_				trs_info3_fiscal_eod_tax; //FSD298942
	struct trs_info3_fiscal_eod_tax2_serial_		trs_info3_fiscal_eod_tax2_serial; //FSD298942
	struct trs_fuel_voucher_used_					fuel_voucher_used;
	struct trs_plu_sale_exten_price_				trs_plu_sale_exten_price;	//TD#317757
	struct trs_info3_SS_PluDepExt_					trs_info3_SS_PluDepExt;	// FSD#159243
	struct trans_info3_ext_loyalty_reward_			trans_info3_ext_loyalty_reward; // FSD316298
	struct	trs_info3_ExtMedia6_					trs_info3_ExtMedia6;	//FSD34249_V4
	struct trs_info3_pos_report_totals_				trs_info3_pos_report_totals; //FSD305075
	struct trs_info3OnlinePurchaseDataToPrint_		trs_info3OnlinePurchaseDataToPrint; //FSD#298969
	struct trs_info3OnlinePurchaseData_				trs_info3OnlinePurchaseData; //FSD#298969  //TD#384162
	struct trs_info3_online_coupon_reward_promo_	trs_info3_online_coupon_reward_promo; //CR334690
	struct trs_info3_online_coupon_reward_display_line_  trs_info3_online_coupon_reward_display_line;  //CR334690
	struct trs_info3_online_coupon_reward_rsp_		trs_info3_online_coupon_reward_rsp; //CR334690
	struct trs_info3_cust_srv_question_ext2_		trs_info3_cust_srv_question_ext2;	//FSD321725
	struct trs_info3_clubcard_details_msr_info_		trs_info3_clubcard_details_msr_info; //TD#340518
	struct trs_info3_DiscountExt_					trs_info3_DiscountExt; //TD#332305
    struct trs_info3_online_order_					trs_info3_online_order; //FSD334265 FSW
	struct trs_info3_mm_ref_num_					trs_info3_mm_ref_num; //CR337587
	struct trs_member_account_						trs_member_account;
	struct trs_info3_tax_section_					trs_info3_tax_section;
	struct trs_info3_plu_sell_end_					trs_info3_plu_sell_end;
	struct trs_info3_DataBar_Elements_				trs_info3_DataBar_Elements;
	struct trs_info3_DataBar_Recover_				trs_info3_DataBar_Recover; //FSD#365331
	struct trs_info3_online_purchase_nzl_id_		trs_info3_online_purchase_nzl_id; //Epic 350305
	struct trs_info3_pos_report_totals_ext_			trs_info3_pos_report_totals_ext; //CR#357297
	struct trs_info3_charge_posting					trs_info3_charge_posting;  //FSD347594 GSE Balance enquiry
	struct trs_info3_online_purchase_nzl_ik_		trs_info3_online_purchase_nzl_ik; //Epic 350305
	struct trs_plu_sale_ext7_						trs_plu_sale_ext7;		//FSD#358503
	struct trs_info3_target_message_				trs_info3_target_message;
	struct trs_info3_environnemental_tax_			trs_info3_environnemental_tax; //FSD350935
	struct trs_info3_invoice_printing_request_		trs_info3_invoice_printing_request; //FSD350935
	struct trs_info3_DocumentNumFiscalFormat_		trs_info3_DocumentNumFiscalFormat; //FSD???ReceiptNonFiscal
	struct trs_info3_PromotionInfo_					trs_info3_PromotionInfo;
	struct trs_info3_ManualPromotion_				trs_info3_ManualPromotion; //TD#362727
	struct trs_alert_pos_unbalanced_general_		trs_alert_pos_unbalanced_general;
	struct trs_alert_pos_unbalanced_apportionment_	trs_alert_pos_unbalanced_apportionment;
	struct trs_media_ext10_							trs_media_ext10;             //CR378184
	struct trs_info3_nif_							trs_info3_nif; //#380596
	struct trs_info3_customer_ext_					trs_info3_customer_ext; //#380596
	struct trs_info3_capture_phone_number_			trs_info3_capture_phone_number;	//FSD387834
	struct trs_info3_reset_cust_info_				trs_info3_reset_cust_info;
	struct trs_info3_security_number_info_			trs_info3_security_number_info;		//FSD#366569
	struct trs_info3_security_number_sale_info_		trs_info3_security_number_sale_info;//FSD#366569
	struct trs_info3_pos_totals_per_vat_info_		trs_info3_pos_totals_per_vat_info;	//FSD#366569

	struct trs_info3_barcode_generation_			trs_info3_barcode_generation;  //FSD368305 PickUp Barcode
	struct trs_info3_online_service_session_data_		trs_info3_online_service_session_data;	//FSD370728
	struct trs_info3_online_service_session_data_ext_	trs_info3_online_service_session_data_ext; //FSD370728
	struct trs_info3_long_user_id_						trs_info3_long_user_id; //FSD#394140
	struct trs_info3_link_points_					trs_info3_link_points;	//FSD#391853
	struct trs_alert_invoice_PDF_                   trs_alert_invoice_PDF_failure; //FSD395537
	struct trs_info3_allowable_tenders_             trs_info3_allowable_tenders; //FSD392122_AllTndrs
	struct trs_info3_CIF_							trs_info3_CIF; //FSD#397828
	struct trs_info3_mobile_payment_data_		    trs_info3_mobile_payment_data;	//FSD396380
	struct trs_info3_QR_code_process_				trs_info3_QR_code_process; //FSD#397567
	struct trs_info3_link_points_ext_				trs_info3_link_points_ext;	//FSD#391853
	struct trs_info3_nric_							trs_info3_nric;				//FSD#394167
	struct trs_msg5_plu_ext3_                       trs_msg5_plu_ext3;          //CRL413907
	struct trs_info3_price_change_                  trs_info3_price_change;     //FSD414790 
	struct trs_extended_warranty_					trs_extended_warranty;      //FSD414790
	struct trs_info4_link_points_ext2_				trs_info4_link_points_ext2;	//FSD#391853_V7
	struct	trs_info4_slip_type_					slip_type;
	struct trs_trade_in1_							trs_trade_in1;				//FSD#414790-GreenSection
	struct trs_trade_in2_							trs_trade_in2;				//FSD#414790-GreenSection
	struct trs_trade_in3_							trs_trade_in3;				//FSD#414790-GreenSection
	struct trs_trade_in4_							trs_trade_in4;				//FSD#414790-GreenSection
	struct trs_trade_in5_							trs_trade_in5;				//FSD#414790-GreenSection
	struct trs_trade_in6_							trs_trade_in6;				//FSD#414790-GreenSection
	struct trs_serial_number_						trs_serial_number;			//FSD#414790-GreenSection
	struct trs_remark_line_							trs_remark_line;			//FSD414790
	struct trs_info3_token_information_				trs_info3_token_information; //FSD#414169
	struct trs_info3_end_of_printing_				trs_info3_end_of_printing;	//TD#423706,TD#423702
	struct trs_info4_gift_card_						trs_info4_gift_card;		//CRD413428
	struct trs_info4_DDT_details_					trs_info4_DDT_details;		//FSD418766 - C&C - PA document and customer enhancement
	struct trs_alert_failed_to_copy_receipt_pdf_file_		trs_alert_failed_to_copy_receipt_pdf_file;
	struct trs_info4_self_scanning_ext3_            trs_info4_self_scanning_ext3;//FSD420610
	struct trs_info4_Rescan_details_                trs_info4_rescan_details;    //FSD420610
	struct TrsInfo4FirstLastTicketsData_			TrsInfo4FirstLastTicketsData; //FSD#411629
	struct trs_info4_ext_loyalty_messages_			trs_info4_ext_loyalty_messages; // #422014
	struct trs_media_ext11_							trs_media_ext11;             //#425633
	struct trs_pos_item_message_					trs_pos_item_message;       //FSD403679 - PIM Enhancement
	struct TrsInfo4CombinedDocum_					TrsInfo4CombinedDocum;		//FSD#421963
	struct TrsInfo4TriggerPromotion_                TrsInfo4TriggerPromotion;   //FSD406085
	struct trs_info3_ECommerceOrder_                trs_info3_ECommerceOrder;   //FSD#426710
	struct TrsInfo4LogDiffTrs_						TrsInfo4LogDiffTrs;			//TD#432674
	struct TrsInfo4ParkingExitCode_					TrsInfo4ParkingExitCode;	//FSD#226065_Ver5_020615D
	struct trs_info4_local_barcode_ext2_			trs_info4_local_barcode_ext2;
	struct trs_info4_axia_customer_details_			trs_info4_axia_customer_details;
	struct trs_points_apportionment_				trs_points_apportionment;   // Epic 435446 US 1
	struct trs_info4_invoice_reference_document_	trs_info4_invoice_reference_document; //FSD416124
	struct trs_info3_alpha_numeric_cust_survey_		trs_info3_alpha_numeric_cust_survey;  //FSD432409
	struct TrsInfo4BarcodeTenderTypeExt_			TrsInfo4BarcodeTenderTypeExt; //FSD438581
	struct TrsInfo4TenderExt_						TrsInfo4TenderExt; //FSD438581
	struct trs_plu_sale_ext8_						trs_plu_sale_ext8;		//FSD#439874
	struct trs_chip_card_info_						trs_chip_card_info;
	struct trs_info4_coupon_info_                   trs_info4_coupon_info;
	struct trs_Card_Onl_Voucher_					trs_Card_Onl_Voucher;	//AlbertoA FSD 441887
	struct TrsInfo4TaxDetails_                      TrsInfo4TaxDetails;     //FSD447653
    struct trsInfo4MMConfirmDeclineReason_          trsInfo4MMConfirmDeclineReason;
    struct TrsInfo4DocumentDetails_                 TrsInfo4DocumentDetails;  //FSD451172
	struct trsInfo4UniqueTicketNumber_				trsInfo4UniqueTicketNumber; //AlessandroS FSD450176
	struct trsInfo4NewIngeVoucher_                  trsInfo4NewIngeVoucher;//FSD448663
	struct trsInfo4EWalletIdentification_			trsInfo4EWalletIdentification;	//FSD450172
	struct trsInfo4EWalletPayment_					trsInfo4EWalletPayment;			//FSD450172
	struct trs_info2_layby_calc_tax_				layby_calc_tax;
	struct trs_item_tax_adj_						trs_item_tax_adj;
	struct trs_info_doc_seq_ext_					trs_info_doc_seq_ext;			//FSD455027
	struct trs_info_perf_test_start_				trs_info_perf_test_start;
	struct trs_info_perf_test_end_					trs_info_perf_test_end;
};

#ifdef __cplusplus 
class MarkDontSendTransHandler
{
	private: BOOL m_bSavedDoNotSendTrans;
		 
	public: MarkDontSendTransHandler(char *fileName, unsigned long lineNumber);
	public: ~MarkDontSendTransHandler();
	public: BOOL getSaveDoNotSendTrans() {return m_bSavedDoNotSendTrans;}
};
#endif


#ifdef _LPOS_PACK_
	#pragma pack()
#endif

#endif

