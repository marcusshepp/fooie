import React from 'react';

import Item from './item';


export default class ItemList extends React.Component {
	
	render(){
		return (
			<div>
				{ this.props.items.map(function(item){
	return (
		<Item 
			key={ item.id }
			data={ item }
			/>
	);
}) }
			</div>
		);
	}

}

