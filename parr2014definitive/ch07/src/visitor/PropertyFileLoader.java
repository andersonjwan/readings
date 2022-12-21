import java.util.*;

public class PropertyFileLoader extends PropertyFileBaseVisitor<Void> {
    Map<String, String> props = new TreeMap<String, String>();

    public Void visitProp(PropertyFileParser.PropContext ctx) {
	String id = ctx.ID().getText();
	String value = ctx.STRING().getText();

	props.put(id, value);
	return null;
    }
}
