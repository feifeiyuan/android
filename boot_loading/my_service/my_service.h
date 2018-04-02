#include<stdio.h>
#include<string.h>
#include <stdarg.h>
#include <unistd.h>

#define LOG_NDEBUG 	0
#define LOG_TAG 	"my_tag"
#include "utils/Log.h"

#define CLUSTER_NUM			4
#define CLUSTER_RX_LEN		3 // for each clutser rx is 3
#define CLUSTER_GROUP_LEN	9 
#define MAX_N				861

#define LITTLE_ONE			0
#define LITTLE_TWO			1
#define LITTLE_THREE		2
#define ANANKE_ONE			3
#define ANANKE_TWO			4
#define ANANKE_THREE		5
#define ANANKE_FOUR			6
#define PROMETHUES			7
#define SOC					8

struct dvfs_table{
	unsigned long int freq;
	unsigned long int vdd;
};

struct cluster_rx{
	float arry_rx[CLUSTER_GROUP_LEN+1];// add taux
};




