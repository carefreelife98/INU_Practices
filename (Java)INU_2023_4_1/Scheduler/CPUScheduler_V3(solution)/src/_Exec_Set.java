import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.Comparator;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.Vector;



public class _Exec_Set {
	public static final int proc[]={1,2,4,8,16,32,48,64};
	public static final int max_period = 1000;		//maximum period that a task can have

	public static final double error = 0.000000001;	//ignore currently


	public static void main(String[] args) {		
	
		System.setProperty("java.util.Arrays.useLegacyMergeSort", "true");								
				
//		exec(10);	//RM scheduling
//		exec(11);	//EDF scheduling
		
		exec(1003);	// DA test for any scheduling algorithm on multiprocessor platforms
		exec(1004);
		exec(1005);
		
	}
	public static void exec(int scheduler) {

		for (int seed=1; seed<=GlobalData.maxSeed; seed++) {
			for (int logm=0; logm<=GlobalData.maxNumProcessor; logm++) {
				int m=proc[logm];
				for (int dist=0; dist<GlobalData.maxDist; dist++) {										
						try{
							String inputFileName = GlobalData.inputFileFolder+"/"+"_"+m+"_"+dist+"_"+seed+".in";
							FileReader fr = new FileReader(inputFileName);
							BufferedReader br = new BufferedReader(fr);
							br.close();
							
							String outputFileName = GlobalData.outputFileFolder+"/"+"_"+m+"_"+dist+"_"+seed+"_"+scheduler+".out";
							PrintWriter outputPw = new PrintWriter(new FileWriter(outputFileName));
							outputPw.close();
						} catch (IOException e) { 
							System.out.println("io error while openning a file");
						}
						try{					
							String inputFileName = GlobalData.inputFileFolder+"/"+"_"+m+"_"+dist+"_"+seed+".in";
							FileReader fr = new FileReader(inputFileName);
							BufferedReader br = new BufferedReader(fr);

							String outputFileName = GlobalData.outputFileFolder+"/"+"_"+m+"_"+dist+"_"+seed+"_"+scheduler+".out";
							PrintWriter outputPw = new PrintWriter(new FileWriter(outputFileName));

							System.out.println(outputFileName);

							for (int taskSetNumber=0; taskSetNumber<1000; taskSetNumber++) {

								String s= br.readLine();	//read a single line (= platform information) in a input file
	
								StringTokenizer st = new StringTokenizer(s);	//create a tokenizer

								int numProcessor=Integer.parseInt(st.nextToken());	//read the first token
								if (numProcessor!= m) 								
									System.out.println("ERROR");								
								
								PlatformInfo pInfo = new PlatformInfo();
								
								pInfo.numTask = Integer.parseInt(st.nextToken());	// read the number of tasks in a task set 
								pInfo.util = Double.parseDouble(st.nextToken());	// read the system utilization of the task set
								pInfo.den = Double.parseDouble(st.nextToken());	// read the system density of the task set
								pInfo.taskSetNumber = taskSetNumber;	
								pInfo.scheduler = scheduler;
								pInfo.numProcessor = m;																															
								
								for (int j=0; j<pInfo.numTask; j++) 
								{
									int TCD[] = new int[3];
									TCD[0] = (int)Double.parseDouble(st.nextToken()); //T
									TCD[1] = (int)Double.parseDouble(st.nextToken()); //C
									TCD[2] = (int)Double.parseDouble(st.nextToken()); //D									
									pInfo.tasks.add(new Task(TCD[0],TCD[1],TCD[2]));	
								}																																																														
								
								if(scheduler<1000)
								{
									Simulator simulator = new Simulator();
									outputPw.println(simulator.run(pInfo));	
								}
								else
								{
									if(scheduler==1002||scheduler==1004||scheduler==1005)
									{
										Comparator<Task> comp = RMComparator();	 	//for RM tests
										Collections.sort(pInfo.tasks,comp);										
									}								
									Analysis analysis = new Analysis();
									outputPw.println(analysis.run(pInfo));
								}																
							}
							outputPw.close();
							br.close();

						} catch (IOException e) { 
							System.out.println("io error while writing data");
						}
					
				}
			}
			(Runtime.getRuntime()).gc();
		}
	}
	
	public static Comparator<Task> RMComparator() {
		return new Comparator<Task>() {
			public int compare(Task task1, Task task2) {								
				return (task1.Period<task2.Period ? -1 : task1.Period>task2.Period ? 1 : -1 );			
				}
		};
	}
}
