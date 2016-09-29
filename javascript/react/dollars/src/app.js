import React from 'react';
import { render } from 'react-dom';

import ItemCreate from './components/item-create';
import ItemList from './components/item-list';


var items = [
	{
		date_created: 'today',
		name: 'foo',
		where_from: 'there',
		price: 1.99,
		number_of_times_purchased: 3,
		category: 1
	},
	{
		date_created: 'yesterday',
		name: 'bar',
		where_from: 'here',
		price: 20.04,
		number_of_times_purchased: 99,
		category: 4
	}
]


class Dollars extends React.Component {
	render(){
		return (
			<div>
				<ItemCreate />
				<ItemList />
			</div>
		);
	}
}

render(<Dollars />, document.getElementById('app'));
