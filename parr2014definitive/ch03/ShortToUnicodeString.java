/**
 * Convert short array initializer lists (e.g., `{1, 2, 3}`) to unicode-based
 * strings (e.g., `"\u0001\u0002\u0003"`).
 */
public class ShortToUnicodeString extends ArrayInitBaseListener {
    /**
     * Translate `{` to `"`.
     */
    @Override
    public void enterInit(ArrayInitParser.InitContext ctx) {
	System.out.print("\"");
    }

    /**
     * Translate `}` to `"`.
     */
    @Override
    public void exitInit(ArrayInitParser.InitContext ctx) {
	System.out.print("\"");
    }

    /**
     * Translate integers to four-digit hexadecimal strings prefixed with \\u.
     *
     * It should be noted that this method assumes there are no nested array
     * initializers (i.e., `{1, {2, 3}}` is not valid but `{1, 2, 3}` is).
     */
    @Override
    public void enterValue(ArrayInitParser.ValueContext ctx) {
	int value = Integer.valueOf(ctx.INT().getText());
	System.out.printf("\\u%04x", value);
    }
}
