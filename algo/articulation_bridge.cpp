vector<pp> get_bridges( graph g, int vertices ) {
	vector<int> disc(vertices, -1), low(vertices), st;
	int count = -1;
	int root = g.begin()->X;
	int root_children = 0;

	for( auto i : g ) {
		dfs( i.X, g, disc, low, count );
	}

	debug( disc );
	debug( low );

	vector<pp> bridges;
	for( auto i : g ) {
		for( auto ix : i.Y ) {
			int u = i.X, v = ix.X;
			
			if( low[i.X] < low[ix.X] )  
				bridges.push_back( make_pair( i.X, ix.X ) );
		}
	}

	return bridges;

}