import java.io.BufferedReader;
import java.io.InputStreamReader;

import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;

public class Translator {
    public static void main(String[] args) throws Exception {
	// As of v4.7, the use of the `CharStreams` interface is the preferred
	// method for creating a `CharStream` from an input source.
	//
	// In older versions, dedicated interfaces were used in-place of the
	// current design (e.g., `ANTLRInputStream`).
	BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
	CharStream input = CharStreams.fromReader(reader);

	// Create a lexer and tokenize the character stream.
	ArrayInitLexer lexer = new ArrayInitLexer(input);
	CommonTokenStream tokens = new CommonTokenStream(lexer);

	// Parse the token stream and create a parse tree.
	ArrayInitParser parser = new ArrayInitParser(tokens);
	ParseTree tree = parser.init();

	// Create a generic parse tree walker that can trigger callbacks.
	ParseTreeWalker walker = new ParseTreeWalker();
	walker.walk(new ShortToUnicodeString(), tree);

	System.out.println();
    }
}
