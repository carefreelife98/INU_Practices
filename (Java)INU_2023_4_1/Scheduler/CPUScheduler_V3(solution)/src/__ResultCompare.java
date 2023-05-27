
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class __ResultCompare {

	public static final double error = 0.0000001;
	public static final int proc[]={1,2,4,8,16,32,48,64};
	public static final int max_num_task = 1000;	
    public static int TT=0, TF=0, FT=0, FF =0;
	public static void main(String[] args) {

		int ref1[] = {1004};
		int ref2[] = {1005};

		int isSporadic = 0;
		int type = 0;
		
		for (int i=0; i<=GlobalData.maxNumProcessor;i++) {
			System.out.println("m="+proc[i]);
			System.out.println(Integer.toString( ref1[0])+" "+Integer.toString( ref2[0]));
			
			for (int dist=0; dist<GlobalData.maxDist; dist++) {
				compare(1000,ref1, ref2,i,i,isSporadic,type,dist,dist);	
			}			
			System.out.println("total : "+FF+"/"+FT+"/"+TF+"/"+TT);
			TT= TF= FT= FF =0;
			System.out.println();
		}
	}

	public static void compare(int period, int ref1[], int ref2[], int logm_from, int logm_to, int isSporadic, int type, int dist_from, int dist_to) {
		int T[]=new int[max_num_task];
		int C[]=new int[max_num_task];
		int D[]=new int[max_num_task];
		double n=0;
		int total=0;

		int tt=0, tf=0,ft=0,ff=0;

		// TODO Auto-generated method stub

		for (int seed=1; seed<=GlobalData.maxSeed; seed++) {
			for (int logm=logm_from; logm<=logm_to; logm++) {
				int m=proc[logm];
				for (int dist=dist_from; dist<=dist_to; dist++){

					try{

						String inputFileName = GlobalData.inputFileFolder+"/"+"_"+m+"_"+dist+"_"+seed+".in";
						FileReader fr = new FileReader(inputFileName);
						BufferedReader br = new BufferedReader(fr);

						String ref1FileName[] = new String[ref1.length];
						String ref2FileName[] = new String[ref2.length];
						FileReader fr1[] = new FileReader[ref1.length];
						FileReader fr2[] = new FileReader[ref2.length];
						BufferedReader br1[] = new BufferedReader[ref1.length];
						BufferedReader br2[] = new BufferedReader[ref2.length];
						String s1[] = new String[ref1.length];
						String s2[] = new String[ref2.length];
						StringTokenizer st1[] = new StringTokenizer[ref1.length];
						StringTokenizer st2[] = new StringTokenizer[ref2.length];
						int sw1[] = new int[ref1.length];
						int sw2[] = new int[ref2.length];

						for (int i=0; i<ref1.length; i++) {
							ref1FileName[i] = GlobalData.outputFileFolder+"/"+"_"+m+"_"+dist+"_"+seed+"_"+ref1[i]+".out";
							fr1[i] = new FileReader(ref1FileName[i]);
							br1[i] = new BufferedReader(fr1[i]);
						}

						for (int i=0; i<ref2.length; i++) {
							ref2FileName[i] = GlobalData.outputFileFolder+"/"+"_"+m+"_"+dist+"_"+seed+"_"+ref2[i]+".out";
							fr2[i] = new FileReader(ref2FileName[i]);
							br2[i] = new BufferedReader(fr2[i]);
						}

						for (int sim=0; sim<1000; sim++) {
							total++;
							int result1=0, result2=0;
							for (int i=0; i<ref1.length; i++) {
								s1[i]=br1[i].readLine();
								st1[i]= new StringTokenizer(s1[i]);
								sw1[i]= Integer.parseInt(st1[i].nextToken()); 
								result1+=sw1[i];
							}
							for (int i=0; i<ref2.length; i++) {
								s2[i]=br2[i].readLine();
								st2[i]= new StringTokenizer(s2[i]);
								sw2[i]= Integer.parseInt(st2[i].nextToken());
								result2+=sw2[i];
							}

							String s = br.readLine();
							StringTokenizer st = new StringTokenizer(s);
							int numProcessor = Integer.parseInt(st.nextToken());
							int numTask = Integer.parseInt(st.nextToken());
							double util = Double.parseDouble(st.nextToken());
							double den = Double.parseDouble(st.nextToken());
							n+=numTask;

							for (int i=0; i<numTask; i++) {
								T[i]=(int)(Double.parseDouble(st.nextToken())+error);
								C[i]=(int)(Double.parseDouble(st.nextToken())+error);
								D[i]=(int)(Double.parseDouble(st.nextToken())+error);
							}

							if (result1==0 && result2==0) ff++;
							else if (result1==0 && result2>0) 
								ft++;																					
							else if (result1>0 && result2==0) 
								tf++;																
							else if (result1>0 && result2>0) 
								tt++;																
						}
						br.close();
						
						for (int i=0; i<ref1.length; i++) 
							br1[i].close();
						
						for (int i=0; i<ref2.length; i++) 
							br2[i].close();
						

					} catch (IOException e) { 
						System.out.println("io error "+e.getMessage());
					}
				}
			}
		}
		FF +=ff; TF += tf; FT += ft; TT += tt;
		System.out.println("FF/FT/TF/TT "+ff+"/"+ft+"/"+tf+"/"+tt+"  "+(n/total)+" "+(ff+ft+tf+tt));
	}
}
