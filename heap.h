typedef struct Record {
	int id;
	char name[15];
	char surname[20];
	char city[10];
} Record;

/*
 * Η συνάρτηση HP_CreateIndex χρησιμοποιείται για τη δημιουργία και 
 * κατάλληλη αρχικοποίηση ενόςάδειου αρχείου σωρού με όνομα fileName. 
 * Σε περίπτωση που εκτελεστεί επιτυχώς, επιστρέφεται 0,
 * ενώ σε διαφορετική περίπτωση -1.
 */
int HP_CreateFile(char *fileName/* όνομααρχείου */);


/*
 * Η συνάρτηση HP_OpenFile ανοίγει το αρχείο με όνομα filename 
 * και διαβάζει από το πρώτο μπλοκ την πληροφορία που αφορά το 
 * αρχείο σωρού. Επιστρέφει τον αναγνωριστικό αριθμό ανοίγματος 
 * αρχείου,όπως αυτός επιστράφηκε από το επίπεδο διαχείρισης μπλοκ 
 * ή -1 σε περίπτωση σφάλματος. Αν το αρχείο που ανοίχτηκε δεν πρόκειται 
 * για αρχείο σωρού, τότε αυτό θεωρείται επίσης περίπτωση σφάλματος.
 */
int HP_OpenFile(
	char *fileName 		/* όνομα αρχείου */ 
	);

/* 
 * Η συνάρτηση  HP_CloseFile  κλείνει το αρχείο που προσδιορίζεται 
 * από τον αναγνωριστικό αριθμόανοίγματος fileDesc. Σε περίπτωση 
 * που εκτελεστεί επιτυχώς, επιστρέφεται 0, ενώ σε διαφορετική περίπτωση -1
 */

int HP_CloseFile(
	int fileDesc 		/* αναγνωριστικός αριθμός ανοίγματος αρχείου */ 
	);

/*
 * Η συνάρτηση HP_InsertEntry χρησιμοποιείται για την εισαγωγή μίας 
 * εγγραφής στο αρχείο σωρού. Ο αναγνωριστικός αριθμός ανοίγματος του 
 * αρχείου δίνεται με την fileDesc ενώ η εγγραφή προςεισαγωγή προσδιορίζεται 
 * από τη δομή record. Η εγγραφή προστίθεται στο τέλος του αρχείου, μετά την 
 * τρέχουσα τελευταία εγγραφή. Σε περίπτωση που εκτελεστεί επιτυχώς, επιστρέφεται 0,
 * ενώ   σεδιαφορετική περίπτωση -1.
 */
int HP_InsertEntry(
	int fileDesc,		/* αναγνωριστικός αριθμός ανοίγματος αρχείου */
	Record record		/* δομή που προσδιορίζει την εγγραφή */
	);

/* 
 * Η συνάρτηση αυτή χρησιμοποιείται για την εκτύπωση όλων των εγγραφών που υπάρχουν 
 * στο αρχείο σωρού οι οποίες έχουν τιμή στο πεδίο με όνομα fieldName ίση με value. 
 * Το fileDesc είναι ο αναγνωριστικός αριθμός ανοίγματος του αρχείου, όπως αυτός έχει
 * επιστραφεί από το επίπεδο διαχείρισης μπλοκ. Η παράμετρος fieldName μπορεί να παίρνει 
 * μία από τις εξής τιμές: “id”, “name”,“surname” ή “city”, αναφερόμενη στα αντίστοιχα 
 * πεδία μιας εγγραφής.
 */
void HP_GetAllEntries(
	int fileDesc,		/* αναγνωριστικός αριθμός ανοίγματος αρχείου */
	char* fieldName,	/* όνομα του πεδίου για το οποίο γίνεται ο έλεγχος */
	void *value			/* τιμή του πεδίου προς σύγκριση */
	);
 