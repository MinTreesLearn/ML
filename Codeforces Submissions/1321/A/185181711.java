import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
public class CF1212{
	public static void main(String[] args) throws IOException{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		reader.readLine();
		String[] robotIncScore = reader.readLine().split(" "); 
		String[] bionicSolverScore = reader.readLine().split(" "); 
		System.out.println(getMaxScoreAllowed(robotIncScore, bionicSolverScore));
	}
	public static int getMaxScoreAllowed(String[] robotIncScore, String[] bionicSolverScore){
		int totalQuestionsSolvesByRobotInc = 0;
		int totalQuestionsSolvesByBionicSolver = 0;
		for(int i=0; i<robotIncScore.length; i++){
			int robotIncCurrentScore = Integer.parseInt(robotIncScore[i]);
			int bionicSolverCurrentScore = Integer.parseInt(bionicSolverScore[i]);
			
			if(robotIncCurrentScore == 1 && bionicSolverCurrentScore == 0){
				totalQuestionsSolvesByRobotInc++;
			}else if(robotIncCurrentScore == 0 && bionicSolverCurrentScore == 1){
				totalQuestionsSolvesByBionicSolver++;
			}
		}
		if( totalQuestionsSolvesByRobotInc == 0 || 
			(totalQuestionsSolvesByBionicSolver == totalQuestionsSolvesByRobotInc && totalQuestionsSolvesByRobotInc == robotIncScore.length)
		){
			return -1;
		}
		if(totalQuestionsSolvesByBionicSolver == totalQuestionsSolvesByRobotInc){
			return 2;
		}else if(totalQuestionsSolvesByRobotInc > totalQuestionsSolvesByBionicSolver){
			return 1;
		}
		totalQuestionsSolvesByBionicSolver++;
		return totalQuestionsSolvesByBionicSolver/totalQuestionsSolvesByRobotInc + 
			((totalQuestionsSolvesByBionicSolver%totalQuestionsSolvesByRobotInc==0)?0:1);
	}
}