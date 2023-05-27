import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Random;
import java.util.Vector;


public class _Gen_Set {
	//*How to use*
	//1. Modify the variable inputFile="C:/CPUScheduler/inputFiles" for your computer.
	//2. Create the corresponding folder.
	//3. Execute.	
	
	//A task is specified by T(period), C(wort-case execution time), D(relavie deadline).
	//A task set includes multiple tasks.
	//Each single file contains 1000 task sets.
	//We consider 10 different seeds and 10 different distribution, and thus 100,000 task set are generated in total. 
	//We assume that D=T always.
	//Every single line of a generated file represents platform information as follows.
	//[#of processors] [#of task in task set] [system utilization] [system density] [T of task1] [C of task1] [D of task1]
	
	public static final int max_period = 1000;		//maximum period that a task can have
	public static final int max_num_task = 1000;	//maximum number of tasks that a task can have 
	public static final int proc[]={1,2,4,8,16,32,48,64};	//will be used to determine the number of processors  
	
	public static final double error = 0.000000001;	//ignore currently
	
	public static void main(String[] args) {		
		run();	
	}

	public static void run () {
		for (int seed=1; seed<=GlobalData.maxSeed; seed++) {	//10 different seeds are exploited to generate random task sets
			Random ran = new Random(seed);

			for (int logm=0; logm<=GlobalData.maxNumProcessor; logm++) {	//"0" indicates that we target uniprocessor platform; "1" does it for 2-processors platform. 
				int m=proc[logm];
				for (int dist=0; dist<GlobalData.maxDist; dist++) { //10 different distributions are exploited to generate random task sets 
					try{
						String inputFileName = GlobalData.inputFileFolder+"/"+"_"+m+"_"+dist+"_"+seed+".in";
						PrintWriter inputPw = new PrintWriter(new FileWriter(inputFileName)); // open a input file to test that there exists the corresponding file
						inputPw.close();
					} catch (IOException e) { 
						System.out.println("io error while opening a file");
					}
					try{
						String inputFileName = GlobalData.inputFileFolder+"/"+"_"+m+"_"+dist+"_"+seed+".in";

						PrintWriter inputPw = new PrintWriter(new FileWriter(inputFileName,true)); // open a input file in which task set will be written
						System.out.println(inputFileName);
						
						double T[]=new double[max_num_task];
						double C[]=new double[max_num_task];
						double D[]=new double[max_num_task];
						int n=0;
						boolean isValid=false;
						for (int sim=0; sim<1000; sim++) {
							if (isValid) {
								double ranU=getRanU(dist, ran);

								T[n] = 1+(int)((ran.nextDouble())*(max_period-1)+1);
								C[n] = 1+(int)(T[n]*ranU);								
								D[n]=T[n];								
								n++;
							} else {
								T=new double[max_num_task];
								C=new double[max_num_task];
								D=new double[max_num_task];
								for (int i=0; i<m+1; i++) {
									double ranU=getRanU(dist, ran);
									T[i] = 1+(int)((ran.nextDouble())*(max_period-1)+1);
									C[i] = 1+(int)(T[i]*ranU);
									//D[i] = C[i]+(int)((T[i]-C[i]+1)*ran.nextDouble());									
									D[i]=T[i];									
								}
								n=m+1;
							}
							if (validTaskSet(T,C,D,n,m)) {
								double density=0;
								double util=0;
								for (int i=0; i<n; i++) {
									density+=C[i]/Math.min(T[i],D[i]);
									util+=C[i]/T[i];
								}
								isValid=true;
								String output2 = m+" "+n+" "+((int)(util*100.0)/100.0)+" "+((int)(density*100.0)/100.0)+" ";
								for (int i=0; i<n; i++) {
									output2+=T[i]+" "+C[i]+ " "+D[i]+ " ";
								}
								inputPw.println(output2);
							} else {
								sim--;
								isValid=false;
							}
						}
						inputPw.close();
					} catch (IOException e) { 
						System.out.println("io error while writing data");
					}
				}
			}
		}
	}

	public static double getRanU(int dist, Random ran) {
		double ranU=0;
		if (dist<5) {
			double ratio = dist*0.2+0.1;
			ranU= (ran.nextDouble() <= ratio) ? ran.nextDouble()*0.5+0.5 : ran.nextDouble()*0.5;
		} else {
			ranU=2;
			while (ranU>1) {
				double lambda = 1.0/((dist-5)*0.2+0.1);
				ranU = -Math.log(1-ran.nextDouble())/lambda;

			}
		}
		return ranU;
	}

	public static boolean validTaskSet(double T[], double C[], double D[], int n, int m) {
		double density=0;
		double util=0;
		for (int i=0; i<n; i++) {
			density+=C[i]/Math.min(T[i],D[i]);
			util+=C[i]/T[i];
		}
		int t= 0;
		Vector<Double> periods = new Vector<Double>();
		for (int j=0; j<n; j++) {
			periods.add(T[j]);
		}
		double lcm = LCM.generateLCM(periods);
		if (util > m) return false; 
		else if (density > m) { 
			for (t=0; t<=lcm; t++) {
				double curdbf=0;
				for (int j=0; j<n; j++) {
					double a = ffdbf(t,(int)(T[j]+error),(int)(C[j]+error),(int)(D[j]+error));
					curdbf += a;
				}
				if (curdbf > (double)t*(double)m) {
					return false;
				}
			}
		}
		return true;
	}

	public static int ffdbf(int t, int T, int C, int D) {
		int dbfvalue = (t+T-D)/T;
		dbfvalue *= C;
		int r = t % T;
		if (r>D-C && r<D) dbfvalue+=(C-D+r);

		return dbfvalue;
	}
}
