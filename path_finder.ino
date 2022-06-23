int board[6][6]={
	{14,3,7,13,15,15},
	{15,9,2,1,3,12},
	{6,8,2,7,5,7},
	{11,6,1,0,12,9},
	{15,9,6,1,7,5},
	{14,8,11,14,1,12}
};
int adj[36][4]={0};

int* give_adj(int i, int j)
{
	int config=board[i][j];
	int cell=6*i+j+1;
	int *ret=(int *)malloc(sizeof(int)*4);
	switch(config)
	{
		case 0 : ret[0]=cell+1;ret[1]=cell-1;ret[2]=cell+6;ret[3]=cell-6;break;
		case 1 : ret[0]=cell+1;ret[1]=cell-1;ret[2]=cell-6;ret[3]=0;break;
		case 2 : ret[0]=cell+1;ret[1]=cell+6;ret[2]=cell-6;ret[3]=0;break;
		case 3 : ret[0]=cell+1;ret[1]=cell-1;ret[2]=cell+6;ret[3]=0;break;
		case 4 : ret[0]=cell-1;ret[1]=cell-6;ret[2]=cell+6;ret[3]=0;break;
		case 5 : ret[0]=cell+1;ret[1]=cell-6;ret[2]=0;ret[3]=0;break;
		case 6 : ret[0]=cell+1;ret[1]=cell+6;ret[2]=0;ret[3]=0;break;
		case 7 : ret[0]=cell-1;ret[1]=cell+6;ret[2]=0;ret[3]=0;break;
		case 8 : ret[0]=cell-1;ret[1]=cell-6;ret[2]=0;ret[3]=0;break;
		case 9 : ret[0]=cell+6;ret[1]=cell-6;ret[2]=0;ret[3]=0;break;
		case 10: ret[0]=cell+1;ret[1]=cell-1;ret[2]=0;ret[3]=0;break;
    	case 11: ret[0]=cell-6;ret[1]=0;ret[2]=0;ret[3]=0;break;
    	case 12: ret[0]=cell-1;ret[1]=0;ret[2]=0;ret[3]=0;break;
 		case 13: ret[0]=cell+6;ret[1]=0;ret[2]=0;ret[3]=0;break; 
 		case 14: ret[0]=cell+1;ret[1]=0;ret[2]=0;ret[3]=0;break;
    	case 15: ret[0]=0;ret[1]=0;ret[2]=0;ret[3]=0;break;


	}
	return ret;
}

void update_adj()
{
	for(int i=0;i<6;i++)
	{
		for (int j=0;j<6;j++)
		{
			int *temp;
			temp=give_adj(i,j);
			adj[6*i+j][0]=temp[0];
			adj[6*i+j][1]=temp[1];
			adj[6*i+j][2]=temp[2];
			adj[6*i+j][3]=temp[3];
		}
	}
}



void setup() {
  Serial.begin(9600);
  update_adj();
  for (int i=0;i<36;i++)
  	{
  		for(int j=0;j<4;j++)
  			Serial.print(adj[i][j]);
  		Serial.println();
  	}
}

void loop() {
}