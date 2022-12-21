import java.util.*;

public class PropertyFileLoader extends PropertyFileBaseListener {
    Map<String, String> props = new TreeMap<String, String>();

    @Override
    public void exitProp(PropertyFileParser.PropContext ctx) {
	String id = ctx.ID().getText();
	String value = ctx.STRING().getText();

	props.put(id, value);
    }
}
