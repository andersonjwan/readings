import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.InputStreamReader;

import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;

public class Main {
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

	PropertyFileLexer lexer = new PropertyFileLexer(input);
	CommonTokenStream tokens = new CommonTokenStream(lexer);

	PropertyFileParser parser = new PropertyFileParser(tokens);
	ParseTree tree = parser.file();

	ParseTreeWalker walker = new ParseTreeWalker();
	PropertyFileLoader loader = new PropertyFileLoader();

	walker.walk(loader, tree);
	System.out.println(loader.props);
    }
}
