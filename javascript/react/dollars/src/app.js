import React from 'react';
import { render } from 'react-dom';

import ItemCreate from './components/item-create';
import ItemList from './components/item-list';


var items = [
	{
		id: 1,
		date_created: '1/2/16',
		name: 'foo',
		where_from: 'there',
		price: 1.99,
		number_of_times_purchased: 3,
		category: 1
	},
	{
		id: 2,
		date_created: '5/06/16',
		name: 'bar',
		where_from: 'here',
		price: 20.04,
		number_of_times_purchased: 99,
		category: 4
	}
]


class Dollars extends React.Component {
	constructor(){
		super()
		this.state = {
			items,
		}
	}
	render(){
		return (
			<div>
				<ItemCreate />
				<ItemList items={ this.state.items }/>
			</div>
		);
	}
}

render(<Dollars />, document.getElementById('app'));
