import java.util.Map;
import java.util.HashMap;

public class EvalVisitor extends LabeledExprBaseVisitor<Integer> {
    Map<String, Integer> memory = new HashMap<String, Integer>();

    @Override
    public Integer visitAssignStat(LabeledExprParser.AssignStatContext ctx) {
	String id = ctx.ID().getText(); // retrieve variable name
	int value = visit(ctx.expr()); // evaluate right-hand-side for value

	// Store variable and value in memory.
	memory.put(id, value);
	return value;
    }

    @Override
    public Integer visitPrintStat(LabeledExprParser.PrintStatContext ctx) {
	Integer value = visit(ctx.expr());
	System.out.println(value);

	return 0;
    }

    @Override
    public Integer visitIntExpr(LabeledExprParser.IntExprContext ctx) {
	return Integer.valueOf(ctx.INT().getText());
    }

    @Override
    public Integer visitIdExpr(LabeledExprParser.IdExprContext ctx) {
	String id = ctx.ID().getText();

	if (memory.containsKey(id)) {
	    return memory.get(id);
	}

	return 0;
    }

    @Override
    public Integer visitMultDivExpr(LabeledExprParser.MultDivExprContext ctx) {
	int left = visit(ctx.expr(0)); // evaluate left-hand-side value
	int right = visit(ctx.expr(1)); // evaluate right-hand-side value

	if (ctx.op.getType() == LabeledExprParser.MUL) {
	    return left * right;
	} else {
	    return left / right;
	}
    }

    @Override
    public Integer visitAddSubExpr(LabeledExprParser.AddSubExprContext ctx) {
	int left = visit(ctx.expr(0)); // evaluate left-hand-side value
	int right = visit(ctx.expr(1)); // evaluate right-hand-side value

	if (ctx.op.getType() == LabeledExprParser.ADD) {
	    return left + right;
	} else {
	    return left - right;
	}
    }

    @Override
    public Integer visitParenExpr(LabeledExprParser.ParenExprContext ctx) {
	return visit(ctx.expr());
    }

    /**
     * Custom functionality implemented to provide a clear command in the
     * language to clear all previous variable assignments.
     */
    @Override
    public Integer visitClearStat(LabeledExprParser.ClearStatContext ctx) {
	memory.clear();
	return 0;
    }
}
