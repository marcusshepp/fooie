import React from 'react';


export default class Item extends React.Component {
	render(){
		return (
			<div>
				<div>{ this.props.data.name }</div>
				<div>{ this.props.data.price }</div>
			</div>
		);
	}
}

