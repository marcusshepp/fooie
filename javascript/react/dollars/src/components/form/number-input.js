import React from 'react';

import Input from './input';


export default class NumberInput extends React.Component {
	render(){
		return(
			<Input 
				label_text={ this.props.label_text }
				type="number"
				step={ this.props.decimal ? "0.01" : "" } />
		);
	}
}
