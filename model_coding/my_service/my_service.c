#include<cpu_power_cal.h>

// table
struct structor1{
	struct test_table node1[6];
	struct test_table node2[6];
	struct test_table node3[6];
	struct test_table node4[6];
}test_obj={
	      {{100000, 750000},{110000, 800000},{120000, 850000},{140000, 900000},{150000, 950000},{160000, 1000000}},
	      {{100000, 750000},{110000, 800000},{120000, 850000},{140000, 900000},{150000, 950000},{160000, 1000000}},
	      {{100000, 750000},{110000, 800000},{120000, 850000},{140000, 900000},{150000, 950000},{160000, 1000000}},
	      {{100000, 750000},{110000, 800000},{120000, 850000},{140000, 900000},{150000, 950000},{160000, 1000000}}
};

// thermal model
struct cluster_group{
	char *name;
	signed int cpu_n;
	float clutser_temp;
	float arry_tn[CLUSTER_RX_LEN];
	struct cluster_rx cluster_Rx_group[CLUSTER_RX_LEN];
	
}cluster_group_mem[CLUSTER_GROUP_LEN]={
			{"Little1", LITTLE_ONE, 0.0, {0.0, 0.0, 0.0},
			{{{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}},
			 {{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}},
			{{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}}}},
			{"Little2", LITTLE_TWO, 0.0, {0.0, 0.0, 0.0},
			{{{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}},
			 {{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}},
			{{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}}}},
			{"Little3", LITTLE_THREE, 0.0, {0.0, 0.0, 0.0},
			{{{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}},
			 {{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}},
			{{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}}}},
			{"Ananke1", ANANKE_ONE, 0.0, {0.0, 0.0, 0.0},
			{{{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}},
			 {{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}},
			{{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}}}},
			{"Ananke2", ANANKE_TWO, 0.0, {0.0, 0.0, 0.0},
			{{{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}},
			 {{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}},
			{{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}}}},
			{"Ananke3", ANANKE_THREE, 0.0, {0.0, 0.0, 0.0},
			{{{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}},
			 {{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}},
			{{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}}}},
			{"Ananke4", ANANKE_FOUR, 0.0, {0.0, 0.0, 0.0},
			{{{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}},
			 {{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}},
			{{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}}}},
			{"prometheus", PROMETHUES, 0.0, {0.0, 0.0, 0.0},
			{{{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}},
			 {{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}},
			{{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}}}},
			{"SOC", SOC, 0.0, {0.0, 0.0, 0.0},
			{{{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}},
			 {{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}},
			{{1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}}}},
};

// power model
struct power_modle{
	float v_0;
	
	float p1;
	float p2;
	
    float t_a;
    float t_b;
    float t_c;
    float t_d;
   
    float t_e;
    float t_f;
    float t_g;
    float t_h;
}my_modle[CLUSTER_NUM]={
	{0.1, 0.1,0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1},
	{0.1, 0.1,0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1},
	{0.1, 0.1,0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1},
	{0.1, 0.1,0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1}
};


// thermal model
int deal_arry_p(int *arry_p, int n)
{
	int p_key = 0;
	int temp_key = 0;
	if(n<90){
		p_key = n/71;
		arry_p[p_key] = (p_key==0)?1:0;
	}else if(n<MAX_N){
		p_key = (n-90)/100+1;
		temp_key = n-n/100*100;      
		arry_p[p_key] = ((temp_key>=61)&&(temp_key<=90))?0:1;
	}
	return arry_p[p_key]?p_key:0;
}

float cal_txn(int n, float *arry_Rx,float *tn_1)
{
	float arithmetic = 0.0;
	float t1n = 0.0;
	int arry_p_index = 0;
	if(n==0){
		return t1n;
	}
	int arry_p[CLUSTER_GROUP_LEN] = {0,0,0,0,0,0,0,0,0};
	arry_p_index = deal_arry_p(arry_p, n);
	arithmetic = arry_p[arry_p_index]*arry_Rx[arry_p_index];
	t1n = arithmetic*arry_Rx[CLUSTER_GROUP_LEN]+(1-arry_Rx[CLUSTER_GROUP_LEN])*(*tn_1);
	*tn_1 = t1n;
	return t1n;
}

// write data to node
int store_cur_data(float power_total, char *store_file_path){
	FILE *fp_store_data = NULL;
	if((fp_store_data=fopen(store_file_path,"w"))==NULL){
		ALOGD("can not open the file:%s\n", store_file_path);
		return -1;
	}
	fprintf(fp_store_data, "%.3f\n", power_total);
	fclose(fp_store_data);
	fp_store_data = NULL;
	return 0;
}

// read data from node
long int get_cur_data(char *get_file_path) {
	FILE *fp_get_data = NULL;
	long int cur_data = 0;
	
	if((fp_get_data=fopen(get_file_path,"r"))==NULL){
		ALOGD("can not open the file:%s\n", get_file_path);
		return -1;
	}
	fscanf(fp_get_data,"%ld",&cur_data);
	fclose(fp_get_data);
	fp_get_data = NULL;
	return cur_data;
}


// match freq to vdd 
float find_v(struct test_table *cluster, int len, unsigned long cur_f){
	int i = 0;
	for(i=0;i<len;i++){
		if(cluster[i].freq == cur_f ){
				return cluster[i].vdd;
		}
	}
	return 0;
}

float match_f_to_v(unsigned long cur_f, int cluster){
	unsigned long c_v = 0;
	switch(cluster){
		case 1://node1
			c_v = find_v(test_obj.node1,sizeof(test_obj.node1)/sizeof(test_obj.node1[0]),cur_f);
			break;
		case 2://node2
			c_v = find_v(test_obj.node2,sizeof(test_obj.node2)/sizeof(test_obj.node2[0]),cur_f);
			break;
		case 3://node3
			c_v = find_v(test_obj.node3,sizeof(test_obj.node3)/sizeof(test_obj.node3[0]),cur_f);
			break;
		case 4:// node4
			c_v = find_v(test_obj.node4,sizeof(test_obj.node4)/sizeof(test_obj.node4[0]),cur_f);
			break;
		default:
			break;
	}
	return c_v*1.0/1000000;
}

// cal power for each core
float cal_each(signed int cpu_n, float c_t){
	float cx_ret = 0.0;
	unsigned long cpu_freq = 0;
	float f_cpu_freq = 0.0;
	char ch_cpu_n[10] = {cpu_n +'0'};
	char cpu_cur_freq[100] = "/sys/devices/system/cpu/cpu";
	float cx_v = 0.0;
	float p_dyn = 0.0;
	float p_leak = 0.0;
	float t_scale = 0.0;
	float v_scale = 0.0;
	int index = 0;
	strcat(cpu_cur_freq, ch_cpu_n);
	strcat(cpu_cur_freq, "/cpufreq/scaling_cur_freq");
	switch(cpu_n){
		case LITTLE_ONE	:
		case LITTLE_TWO	:
		case LITTLE_THREE :
			index = 0;
			cpu_freq = get_cur_data(cpu_cur_freq);
			
			break;
		case ANANKE_ONE	:
		case ANANKE_TWO	:
		case ANANKE_THREE :
		case ANANKE_FOUR :
			index = 1;
			cpu_freq = get_cur_data(cpu_cur_freq);
			break;
		case PROMETHUES:
			index = 2;
			cpu_freq = get_cur_data(cpu_cur_freq);
			break;
		case SOC:
			index = 3;
			cpu_freq = 110000; 
			break;
	}
	cx_v = match_f_to_v(cpu_freq, index+1);
	f_cpu_freq = cpu_freq*1.0/1000000;
	p_dyn = my_modle[index].p1*f_cpu_freq*cx_v*cx_v/(my_modle[index].v_0*my_modle[index].v_0);
	t_scale = my_modle[index].t_a*c_t*c_t*c_t+my_modle[index].t_b*c_t*c_t+my_modle[index].t_c*c_t+my_modle[index].t_d;
	v_scale = my_modle[index].t_e*cx_v*cx_v*cx_v + my_modle[index].t_f*cx_v*cx_v + my_modle[index].t_g*cx_v+my_modle[index].t_h;
	p_leak = my_modle[index].p2*t_scale*v_scale;
	cx_ret = p_dyn + p_leak;
	return cx_ret;
}


int main()
{
	int i = 0;
	int j = 0; 
	int k = 0;
	int start_index = 0;
	int n = 0;
	float each_temp = 0.0;
	float arry_temp[4] = {0.0};
	float arry_temp[CLUSTER_GROUP_LEN] ={0};
	int times = 10;
	struct timeval start, end;
	float timeuse = 0.0;
	
	while(1){
		gettimeofday( &start, NULL );
		for(k=0; k<times; k++){// 1 secound cal power
			n = n<MAX_N?start_index++:MAX_N;
			for(i=0;i<CLUSTER_GROUP_LEN;i++){
				for(j=0;j<CLUSTER_RX_LEN;j++){
					cluster_group_mem[i].clutser_temp += cal_txn(n, cluster_group_mem[i].cluster_Rx_group[j].arry_rx, &cluster_group_mem[i].arry_tn[j]);
				}
				cluster_group_mem[i].clutser_temp +=25;
				if(k==times-1){
					arry_temp[i] = cluster_group_mem[i].clutser_temp;
				}
				cluster_group_mem[i].clutser_temp = 0.0;
			}
			usleep(100000);
		}
		
		for(i=0; i<CLUSTER_GROUP_LEN; i++){
			each_temp = cal_each(cluster_group_mem[i].cpu_n,arry_temp[i]);
			switch(i){
				case LITTLE_ONE	:
				case LITTLE_TWO	:
				case LITTLE_THREE :
					arry_temp[0] +=each_temp;
					break;
				case ANANKE_ONE	:
				case ANANKE_TWO	:
				case ANANKE_THREE :
				case ANANKE_FOUR :
					arry_temp[1] +=each_temp;
					break;
				case PROMETHUES:
					arry_temp[2] +=each_temp;
					break;
				case SOC:
					arry_temp[3] +=each_temp;
					break;	
			}
		}
		
		store_cur_data(arry_temp[0], "/sys/my_node/cluster0_power");
		store_cur_data(arry_temp[1], "/sys/my_node/node1_power");
		store_cur_data(arry_temp[2], "/sys/my_node/node2_power");
		store_cur_data(arry_temp[3], "/sys/my_node/node4_power");
		memset(arry_temp,0,sizeof(arry_temp)/sizeof(arry_temp[0]));
		gettimeofday( &end, NULL );
		timeuse = (1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec - start.tv_usec)/1000.0;
	}

	return 0;
}
