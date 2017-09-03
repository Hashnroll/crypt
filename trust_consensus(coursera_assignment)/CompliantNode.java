import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;
import java.util.Random;

/* CompliantNode refers to a node that follows the rules (not malicious)*/
public class CompliantNode implements Node {
	
	
	int numNodes = 100;
	static int numTx = 500;
	private static HashSet<Transaction> txsPool = new HashSet<Transaction>(numTx);
	
	ArrayList<Integer> providers; //those nodes whom this node listens
	
    public CompliantNode(double p_graph, double p_malicious, double p_txDistribution, int numRounds) {
        // IMPLEMENT THIS
    	providers = new ArrayList<Integer>(numNodes);
    }

    public void setFollowees(boolean[] followees) {
        // IMPLEMENT THIS
    	for (int i = 0; i < numNodes; i++) {
    		if (followees[i]){
    			providers.add(i);
    		}
    	}
    }

    public void setPendingTransaction(Set<Transaction> pendingTransactions) {
        // IMPLEMENT THIS
    	for (Transaction tx : pendingTransactions){
    		if (!txsPool.contains(tx))
    			txsPool.add(tx);
    	}
    }
    
    public Set<Transaction> sendToFollowers() {
        // IMPLEMENT THIS
    	if (Math.random() < 0.5){
    		Random random = new Random();
    		Transaction newTx = new Transaction(1);
    		txsPool.add(newTx);
    	}
    	return txsPool;
    }

    public void receiveFromFollowees(Set<Candidate> candidates) {
        // IMPLEMENT THIS
    	/*for (Candidate candidate : candidates){
    		if(!providers.contains(candidate.sender))
    			continue;
    		if(!txsPool.contains(candidate.tx))
    			txsPool.add(candidate.tx);
    	}*/
    }
}
