import React from 'react';


export default class Label extends React.Component {
	render(){
		return (
			<label htmlFor={ this.props.for }>
				{ this.props.text }
				{ this.props.required ? "*" : "" }: 
			</label>
		);
	}
}
