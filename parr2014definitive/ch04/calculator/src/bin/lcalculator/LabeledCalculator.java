import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.InputStreamReader;

import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;

public class LabeledCalculator {
    public static void main(String[] args) throws Exception {
	BufferedReader reader = null;

	// If an argument is supplied, read from that (assuming its a file); else,
	// read from `stdin`.
	if (args.length > 0) {
	    reader = new BufferedReader(new FileReader(new File(args[0])));
	} else {
	    reader = new BufferedReader(new InputStreamReader(System.in));
	}

	CharStream input = CharStreams.fromReader(reader);

	LabeledExprLexer lexer = new LabeledExprLexer(input);
	CommonTokenStream tokens = new CommonTokenStream(lexer);

	LabeledExprParser parser = new LabeledExprParser(tokens);
	ParseTree tree = parser.prog();

	EvalVisitor visitor = new EvalVisitor();
	visitor.visit(tree);
    }
}
