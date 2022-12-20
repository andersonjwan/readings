// Generated from java-escape by ANTLR 4.11.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link DOTParser}.
 */
public interface DOTListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link DOTParser#graph}.
	 * @param ctx the parse tree
	 */
	void enterGraph(DOTParser.GraphContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#graph}.
	 * @param ctx the parse tree
	 */
	void exitGraph(DOTParser.GraphContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#stmtList}.
	 * @param ctx the parse tree
	 */
	void enterStmtList(DOTParser.StmtListContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#stmtList}.
	 * @param ctx the parse tree
	 */
	void exitStmtList(DOTParser.StmtListContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#stmt}.
	 * @param ctx the parse tree
	 */
	void enterStmt(DOTParser.StmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#stmt}.
	 * @param ctx the parse tree
	 */
	void exitStmt(DOTParser.StmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#attrStmt}.
	 * @param ctx the parse tree
	 */
	void enterAttrStmt(DOTParser.AttrStmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#attrStmt}.
	 * @param ctx the parse tree
	 */
	void exitAttrStmt(DOTParser.AttrStmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#attrList}.
	 * @param ctx the parse tree
	 */
	void enterAttrList(DOTParser.AttrListContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#attrList}.
	 * @param ctx the parse tree
	 */
	void exitAttrList(DOTParser.AttrListContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#aList}.
	 * @param ctx the parse tree
	 */
	void enterAList(DOTParser.AListContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#aList}.
	 * @param ctx the parse tree
	 */
	void exitAList(DOTParser.AListContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#edgeStmt}.
	 * @param ctx the parse tree
	 */
	void enterEdgeStmt(DOTParser.EdgeStmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#edgeStmt}.
	 * @param ctx the parse tree
	 */
	void exitEdgeStmt(DOTParser.EdgeStmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#edgeRHS}.
	 * @param ctx the parse tree
	 */
	void enterEdgeRHS(DOTParser.EdgeRHSContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#edgeRHS}.
	 * @param ctx the parse tree
	 */
	void exitEdgeRHS(DOTParser.EdgeRHSContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#edgeOp}.
	 * @param ctx the parse tree
	 */
	void enterEdgeOp(DOTParser.EdgeOpContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#edgeOp}.
	 * @param ctx the parse tree
	 */
	void exitEdgeOp(DOTParser.EdgeOpContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#nodeStmt}.
	 * @param ctx the parse tree
	 */
	void enterNodeStmt(DOTParser.NodeStmtContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#nodeStmt}.
	 * @param ctx the parse tree
	 */
	void exitNodeStmt(DOTParser.NodeStmtContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#nodeId}.
	 * @param ctx the parse tree
	 */
	void enterNodeId(DOTParser.NodeIdContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#nodeId}.
	 * @param ctx the parse tree
	 */
	void exitNodeId(DOTParser.NodeIdContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#port}.
	 * @param ctx the parse tree
	 */
	void enterPort(DOTParser.PortContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#port}.
	 * @param ctx the parse tree
	 */
	void exitPort(DOTParser.PortContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#subgraph}.
	 * @param ctx the parse tree
	 */
	void enterSubgraph(DOTParser.SubgraphContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#subgraph}.
	 * @param ctx the parse tree
	 */
	void exitSubgraph(DOTParser.SubgraphContext ctx);
	/**
	 * Enter a parse tree produced by {@link DOTParser#id}.
	 * @param ctx the parse tree
	 */
	void enterId(DOTParser.IdContext ctx);
	/**
	 * Exit a parse tree produced by {@link DOTParser#id}.
	 * @param ctx the parse tree
	 */
	void exitId(DOTParser.IdContext ctx);
}